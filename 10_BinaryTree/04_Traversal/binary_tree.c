#include "binary_tree.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  KeyValPair *kvp;
  struct Node *left;
  struct Node *right;
} Node;

struct BinaryTree {
  Node *root;
  CmpFn cmpFn;
  KeyDestroyFn keyDestroyFn;
  ValDestroyFn valDestroyFn;
};

Node *node_construct(Node *left, Node *right, void *key, void *val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->left = left;
  newNode->right = right;
  newNode->kvp = key_val_pair_construct(key, val);

  return newNode;
}

void node_destroy(Node *n, KeyDestroyFn keyD, ValDestroyFn valD) {
  keyD(n->kvp->key);
  valD(n->kvp->value);
  key_val_pair_destroy(n->kvp);
  free(n);
}

KeyValPair *key_val_pair_construct(void *key, void *val) {
  KeyValPair *kvp = (KeyValPair *)malloc(sizeof(KeyValPair));
  kvp->key = key;
  kvp->value = val;

  return kvp;
}

void key_val_pair_destroy(KeyValPair *kvp) { free(kvp); }

BinaryTree *binary_tree_construct(CmpFn cmp_fn, KeyDestroyFn key_destroy_fn,
                                  ValDestroyFn val_destroy_fn) {

  BinaryTree *bt = (BinaryTree *)malloc(sizeof(BinaryTree));
  bt->cmpFn = cmp_fn;
  bt->keyDestroyFn = key_destroy_fn;
  bt->valDestroyFn = val_destroy_fn;
  bt->root = NULL;

  return bt;
}

void binary_tree_add(BinaryTree *bt, void *key, void *value) {
  Node *newNode = node_construct(NULL, NULL, key, value);
  if (bt->root == NULL) {
    bt->root = newNode;
    return;
  }

  Node *n = bt->root;

  while (n != NULL) {
    if (bt->cmpFn(key, n->kvp->key) < 0) {
      if (n->left == NULL) {
        n->left = newNode;
        return;
      }
      n = n->left;
    } else if (bt->cmpFn(key, n->kvp->key) > 0) {
      if (n->right == NULL) {
        n->right = newNode;
        return;
      }
      n = n->right;
    } else {
      node_destroy(newNode, bt->keyDestroyFn, bt->valDestroyFn);
      return;
    }
  }
}

Node *bt_add_rec(Node *n, void *key, void *val, CmpFn cmpFn) {
  if (n == NULL) {
    return node_construct(NULL, NULL, key, val);
  }

  if (cmpFn(key, n->kvp->key) > 0) {
    n->right = bt_add_rec(n->right, key, val, cmpFn);
  } else if (cmpFn(key, n->kvp->key) < 0) {
    n->left = bt_add_rec(n->left, key, val, cmpFn);
  }

  return n;
}

void binary_tree_add_recursive(BinaryTree *bt, void *key, void *value) {
  bt->root = bt_add_rec(bt->root, key, value, bt->cmpFn);
}

int binary_tree_empty(BinaryTree *bt) { return bt->root == NULL; }

Node *bt_min_rec(Node *n) {
  if (n == NULL) {
    return NULL;
  }

  if (n->left == NULL) {
    return n;
  } else {
    return bt_min_rec(n->left);
  }
}

Node *bt_max_rec(Node *n) {
  if (n == NULL) {
    return NULL;
  }

  if (n->right == NULL) {
    return n;
  } else {
    return bt_min_rec(n->right);
  }
}

void bt_remove_rec(Node *n, Node *parent, void *key, BinaryTree *bt) {
  if (n == NULL) {
    return;
  }

  if (bt->cmpFn(key, n->kvp->key) > 0) {
    bt_remove_rec(n->right, n, key, bt);
  } else if (bt->cmpFn(key, n->kvp->key) < 0) {
    bt_remove_rec(n->left, n, key, bt);
  } else {
    if (n->left == NULL && n->right == NULL) {
      if (parent == NULL) {
        bt->root = NULL;
      } else if (parent->left == n) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else if (n->left == NULL) {
      if (parent == NULL) {
        bt->root = n->right;
      } else if (parent->left == n) {
        parent->left = n->right;
      } else {
        parent->right = n->right;
      }
    } else if (n->right == NULL) {
      if (parent == NULL) {
        bt->root = n->left;
      } else if (parent->left == n) {
        parent->left = n->left;
      } else {
        parent->right = n->left;
      }
    } else {
      Node *successor = bt_min_rec(n->right);
      KeyValPair *temp = n->kvp;
      n->kvp = successor->kvp;
      successor->kvp = temp;

      bt_remove_rec(n->right, n, successor->kvp->key, bt);
      return;
    }
    node_destroy(n, bt->keyDestroyFn, bt->valDestroyFn);
  }
}

void binary_tree_remove(BinaryTree *bt, void *key) {
  bt_remove_rec(bt->root, NULL, key, bt);
}

KeyValPair *binary_tree_min(BinaryTree *bt) {
  return bt_min_rec(bt->root)->kvp;
}

KeyValPair *binary_tree_max(BinaryTree *bt) {
  return bt_max_rec(bt->root)->kvp;
}

KeyValPair *binary_tree_pop_min(BinaryTree *bt) {
  if (bt == NULL || bt->root == NULL) {
    return NULL;
  }
  Node *n = bt->root;
  Node *parent = NULL;

  while (n->left != NULL) {
    parent = n;
    n = n->left;
  }
  if (parent != NULL) {
    parent->left = n->right;
  } else {
    bt->root = n->right;
  }
  KeyValPair *ret = n->kvp;
  free(n);
  return ret;
}

KeyValPair *binary_tree_pop_max(BinaryTree *bt) {
  if (bt == NULL || bt->root == NULL) {
    return NULL;
  }
  Node *n = bt->root;
  Node *parent = NULL;

  while (n->right != NULL) {
    parent = n;
    n = n->right;
  }
  if (parent != NULL) {
    parent->right = n->left;
  } else {
    bt->root = n->left;
  }
  KeyValPair *ret = n->kvp;
  free(n);
  return ret;
}

Vector *binary_tree_interval(BinaryTree *bt, void *min_key, void *max_key);

void *bt_get_rec(Node *n, void *key, CmpFn cmpFn) {
  if (n == NULL) {
    return NULL;
  }

  if (cmpFn(key, n->kvp->key) < 0) {
    return bt_get_rec(n->left, key, cmpFn);
  } else if (cmpFn(key, n->kvp->key) > 0) {
    return bt_get_rec(n->right, key, cmpFn);
  } else {
    return n->kvp->value;
  }
}

void *binary_tree_get(BinaryTree *bt, void *key) {
  return bt_get_rec(bt->root, key, bt->cmpFn);
}

void bt_destroy_rec(Node *n, KeyDestroyFn keyD, ValDestroyFn valD) {
  if (n == NULL) {
    return;
  }

  bt_destroy_rec(n->left, keyD, valD);
  bt_destroy_rec(n->right, keyD, valD);
  node_destroy(n, keyD, valD);
}

void binary_tree_destroy(BinaryTree *bt) {
  Node *n = bt->root;

  bt_destroy_rec(n, bt->keyDestroyFn, bt->valDestroyFn);

  free(bt);
}

void bt_print_rec(Node *n) {
  if (n == NULL) {
    printf("NULL");
    return;
  }
  printf("(%d, ", *(int *)n->kvp->value);
  bt_print_rec(n->left);
  printf(", ");
  bt_print_rec(n->right);
  printf(")");
}

// a funcao abaixo pode ser util para debug, mas nao eh obrigatoria.
void binary_tree_print(BinaryTree *bt) { bt_print_rec(bt->root); }

void bt_inorder_rec(Node *n, Vector *v) {
  if (n == NULL) {
    return;
  }
  KeyValPair *copy = key_val_pair_construct(n->kvp->key, n->kvp->value);
  bt_inorder_rec(n->left, v);
  vector_push_back(v, copy);
  bt_inorder_rec(n->right, v);
}

Vector *binary_tree_inorder_traversal_recursive(BinaryTree *bt) {
  Vector *v = vector_construct();
  bt_inorder_rec(bt->root, v);

  return v;
}

void bt_preorder_rec(Node *n, Vector *v) {
  if (n == NULL) {
    return;
  }
  KeyValPair *copy = key_val_pair_construct(n->kvp->key, n->kvp->value);
  vector_push_back(v, copy);
  bt_preorder_rec(n->left, v);
  bt_preorder_rec(n->right, v);
}

Vector *binary_tree_preorder_traversal_recursive(BinaryTree *bt) {
  Vector *v = vector_construct();
  bt_preorder_rec(bt->root, v);

  return v;
}

void bt_postorder_rec(Node *n, Vector *v) {
  if (n == NULL) {
    return;
  }
  KeyValPair *copy = key_val_pair_construct(n->kvp->key, n->kvp->value);
  bt_postorder_rec(n->left, v);
  bt_postorder_rec(n->right, v);
  vector_push_back(v, copy);
}

Vector *binary_tree_postorder_traversal_recursive(BinaryTree *bt) {
  Vector *v = vector_construct();
  bt_postorder_rec(bt->root, v);

  return v;
}
