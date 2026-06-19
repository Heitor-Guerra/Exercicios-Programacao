#include "hash.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_VALUE NULL

struct HashTable {
  List **bucket;
  int tableSize;
  int numElements;
  HashFunction hashFn;
  CmpFunction cmpFn;
};

struct HashTableIterator {
  HashTable *hash;
  int hashIdx;
  Node *current;
  int idx;
};

// constroi a hash
HashTable *hash_table_construct(int table_size, HashFunction hash_fn,
                                CmpFunction cmp_fn) {
  HashTable *h = (HashTable *)malloc(sizeof(HashTable));
  h->cmpFn = cmp_fn;
  h->hashFn = hash_fn;
  h->tableSize = table_size;
  h->numElements = 0;
  h->bucket = (List **)malloc(table_size * sizeof(List *));

  for (int i = 0; i < table_size; i++) {
    h->bucket[i] = list_construct();
  }

  return h;
}

// funcao para insercao/atualizacao de pares chave-valor em O(1).
// Se a chave ja existir, atualiza o valor e retorna o valor antigo para
// permitir desalocacao.
void *hash_table_set(HashTable *h, void *key, void *val) {
  int hash = h->hashFn(h, key);

  Node *n = h->bucket[hash]->head;
  while (n != NULL) {
    HashTableItem *item = (HashTableItem *)n->value;
    if (h->cmpFn(item->key, key) == 0) {
      void *ret = item->val;
      item->val = val;
      return ret;
    }
    n = n->next;
  }

  HashTableItem *item = (HashTableItem *)malloc(sizeof(HashTableItem));
  item->key = key;
  item->val = val;
  h->numElements++;
  list_push_front(h->bucket[hash], item);
  return NULL;
}

// retorna o valor associado com a chave key ou NULL se ela nao existir em O(1).
void *hash_table_get(HashTable *h, void *key) {
  int hash = h->hashFn(h, key);

  Node *n = h->bucket[hash]->head;
  while (n != NULL) {
    HashTableItem *item = (HashTableItem *)n->value;
    if (h->cmpFn(item->key, key) == 0) {
      return item->val;
    }
    n = n->next;
  }

  return ERROR_VALUE;
}

// remove o par chave-valor e retorna o valor ou NULL se nao existir tal chave
// em O(1).
void *hash_table_pop(HashTable *h, void *key) {
  int hash = h->hashFn(h, key);

  Node *n = h->bucket[hash]->head;
  while (n != NULL) {
    HashTableItem *item = (HashTableItem *)n->value;
    if (h->cmpFn(key, item->key) == 0) {
      void *ret = item->val;
      free(item->key);
      list_remove(h->bucket[hash], item);
      return ret;
    }
    n = n->next;
  }

  return NULL;
}

// numero de buckets
int hash_table_size(HashTable *h) { return h->tableSize; }

// numero de elementos inseridos
int hash_table_num_elems(HashTable *h) {
  int numEl = 0;
  for (int i = 0; i < h->tableSize; i++) {
    numEl += list_size(h->bucket[i]);
  }
  return numEl;
}

// libera o espaco alocado para a tabela hash
void hash_table_destroy(HashTable *h) {
  for (int i = 0; i < h->tableSize; i++) {
    Node *n = h->bucket[i]->head;

    while (n != NULL) {
      HashTableItem *item = (HashTableItem *)n->value;
      free(item->key);
      free(item->val);
      n = n->next;
    }
    list_destroy(h->bucket[i]);
  }
  free(h->bucket);
  free(h);
}

// cria um novo iterador para a tabela hash
HashTableIterator *hash_table_iterator(HashTable *h) {
  HashTableIterator *it =
      (HashTableIterator *)malloc(sizeof(HashTableIterator));
  it->hash = 0;
  it->hashIdx = 0;
  it->current = h->bucket[0]->head;
  it->idx = 0;

  return it;
}

// retorna 1 se o iterador chegou ao fim da tabela hash ou 0 caso contrario
int hash_table_iterator_is_over(HashTableIterator *it) {
  return it->idx >= it->hash->numElements;
}

// retorna o proximo par chave valor da tabela hash
HashTableItem *hash_table_iterator_next(HashTableIterator *it) {
  while (it->current == NULL) {
    it->hashIdx++;
    it->current = it->hash->bucket[it->hashIdx]->head;
  }

  HashTableItem *item = (HashTableItem *)it->current->value;
  it->current = it->current->next;
  it->idx++;

  return item;
}

// desaloca o iterador da tabela hash
void hash_table_iterator_destroy(HashTableIterator *it) { free(it); }

Vector *hash_to_vector(HashTable *h) {
  Vector *v = vector_construct();
  for (int i = 0; i < h->tableSize; i++) {
    Node *n = h->bucket[i]->head;
    while (n != NULL) {
      vector_push_back(v, n->value);
      n = n->next;
    }
  }

  return v;
}
