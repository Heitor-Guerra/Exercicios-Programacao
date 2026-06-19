#include "hash.h"
#include "list.h"
#include <stdlib.h>

struct HashTable {
  List **buckets;
  int hashSize;
  int numElements;
  HashFunction hashFn;
  CmpFunction cmpFn;
};

struct HashTableIterator {
  HashTable *hash;
  Node *current;
  int hashIdx;
  int idx;
};

// constroi a hash
HashTable *hash_table_construct(int table_size, HashFunction hash_fn,
                                CmpFunction cmp_fn) {
  HashTable *h = (HashTable *)malloc(sizeof(HashTable));
  h->hashSize = table_size;
  h->hashFn = hash_fn;
  h->cmpFn = cmp_fn;

  h->numElements = 0;
  h->buckets = (List **)malloc(table_size * sizeof(List *));
  for (int i = 0; i < table_size; i++) {
    h->buckets[i] = list_construct();
  }

  return h;
}

// funcao para insercao/atualizacao de pares chave-valor em O(1).
// Se a chave ja existir, atualiza o valor e retorna o valor antigo para
// permitir desalocacao.
void *hash_table_set(HashTable *h, void *key, void *val) {
  int hash = h->hashFn(h, key);

  Node *n = h->buckets[hash]->head;
  while (n != NULL) {
    HashTableItem *i = (HashTableItem *)n->value;
    if (h->cmpFn(key, i->key) == 0) {
      void *t = i->val;
      i->val = val;
      return t;
    }

    n = n->next;
  }

  HashTableItem *i = (HashTableItem *)malloc(sizeof(HashTableItem));
  i->key = key;
  i->val = val;
  h->numElements++;
  list_push_front(h->buckets[hash], i);

  return NULL;
}

// retorna o valor associado com a chave key ou NULL se ela nao existir em O(1).
void *hash_table_get(HashTable *h, void *key) {
  int hash = h->hashFn(h, key);

  Node *n = h->buckets[hash]->head;
  while (n != NULL) {
    HashTableItem *i = (HashTableItem *)n->value;
    if (h->cmpFn(key, i->key) == 0) {
      return i->val;
    }

    n = n->next;
  }

  return NULL;
}

// remove o par chave-valor e retorna o valor ou NULL se nao existir tal chave
// em O(1).
void *hash_table_pop(HashTable *h, void *key) {
  int hash = h->hashFn(h, key);

  Node *n = h->buckets[hash]->head;
  Node *ant = NULL;
  while (n != NULL) {
    HashTableItem *i = (HashTableItem *)n->value;

    Node *next = n->next;
    if (h->cmpFn(key, i->key) == 0) {
      if (ant != NULL) {
        ant->next = next;
      } else {
        h->buckets[hash]->head = next;
      }

      if (next != NULL) {
        next->prev = ant;
      } else {
        h->buckets[hash]->last = ant;
      }

      void *val = i->val;
      free(i->key);
      node_destroy(n);
      h->numElements--;
      return val;
    }
    ant = n;
    n = n->next;
  }

  return NULL;
}

// numero de buckets
int hash_table_size(HashTable *h) { return h->hashSize; }

// numero de elementos inseridos
int hash_table_num_elems(HashTable *h) { return h->numElements; }

// libera o espaco alocado para a tabela hash
void hash_table_destroy(HashTable *h) {
  for (int i = 0; i < h->hashSize; i++) {
    Node *n = h->buckets[i]->head;
    while (n != NULL) {
      HashTableItem *i = (HashTableItem *)n->value;
      free(i->key);
      free(i->val);

      n = n->next;
    }
    list_destroy(h->buckets[i]);
  }
  free(h->buckets);
  free(h);
}

// cria um novo iterador para a tabela hash
HashTableIterator *hash_table_iterator(HashTable *h) {
  HashTableIterator *it =
      (HashTableIterator *)malloc(sizeof(HashTableIterator));
  it->current = h->buckets[0]->head;
  it->hash = h;
  it->hashIdx = 0;
  it->idx = 0;

  return it;
}

// retorna 1 se o iterador chegou ao fim da tabela hash ou 0 caso contrario
int hash_table_iterator_is_over(HashTableIterator *it) {
  return it->idx == it->hash->numElements;
}

// retorna o proximo par chave valor da tabela hash
HashTableItem *hash_table_iterator_next(HashTableIterator *it) {
  while (it->current == NULL) {
    it->hashIdx++;
    it->current = it->hash->buckets[it->hashIdx]->head;
  }

  HashTableItem *ret = (HashTableItem *)it->current->value;
  it->current = it->current->next;
  it->idx++;
  return ret;
}

// desaloca o iterador da tabela hash
void hash_table_iterator_destroy(HashTableIterator *it) { free(it); }
