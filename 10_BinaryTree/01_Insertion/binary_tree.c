#include "binary_tree.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

typedef int (*CmpFn)(void *, void *);
typedef void (*KeyDestroyFn)(void *);
typedef void (*ValDestroyFn)(void *);

typedef struct Node {
    KeyValPair* kvp;
    struct Node* left;
    struct Node* right;
} Node;


struct BinaryTree {
    Node* root;
    CmpFn cmpFn;
    KeyDestroyFn keyDestroyFn;
    ValDestroyFn valDestroyFn;
};



Node* node_construct(Node* left, Node* right, void* key, void* val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->kvp = key_val_pair_construct(key, val);

    return newNode;
}

KeyValPair *key_val_pair_construct(void *key, void *val) {
    KeyValPair* kvp = (KeyValPair*)malloc(sizeof(KeyValPair));
    kvp->key = key;
    kvp->value = val;

    return kvp;
}

void key_val_pair_destroy(KeyValPair *kvp) {
    free(kvp);
}



BinaryTree *binary_tree_construct(
    CmpFn cmp_fn, KeyDestroyFn key_destroy_fn,
    ValDestroyFn val_destroy_fn) {
    
    BinaryTree* bt = (BinaryTree*)malloc(sizeof(BinaryTree));
    bt->cmpFn = cmp_fn;
    bt->keyDestroyFn = key_destroy_fn;
    bt->valDestroyFn = val_destroy_fn;
    bt->root = NULL;

    return bt;
}


void binary_tree_add(BinaryTree *bt, void *key, void *value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->kvp = key_val_pair_construct(key, value);

    if(bt->root == NULL) {
        bt->root = newNode;
        return;
    }

    Node* n = bt->root;

    while(n != NULL) {
        if(bt->cmpFn(key, n->kvp->key) < 0) {
            if(n->left == NULL) {
                n->left = newNode;
                return;
            }
            n = n->left;
        } else if (bt->cmpFn(key, n->kvp->key) > 0) {
            if(n->right == NULL) {
                n->right = newNode;
                return;
            }
            n = n->right;
        } else {
            free(newNode);
            bt->keyDestroyFn(key);
            bt->valDestroyFn(value);
            return;
        }
    }
}

Node* bt_add_rec(Node* n, void* key, void* val, CmpFn cmpFn) {
    if(n == NULL) {
        return node_construct(NULL, NULL, key, val);
    }

    if(cmpFn(key, n->kvp->key) > 0) {
        n->right = bt_add_rec(n->right, key, val, cmpFn);
    } else if(cmpFn(key, n->kvp->key) < 0) {
        n->left = bt_add_rec(n->left, key, val, cmpFn);
    }

    return n;
}

void binary_tree_add_recursive(BinaryTree *bt, void *key, void *value) {
    bt->root = bt_add_rec(bt->root, key, value, bt->cmpFn);
}

int binary_tree_empty(BinaryTree *bt) {
    return bt->root == NULL;
}

void binary_tree_remove(BinaryTree *bt, void *key);

KeyValPair *binary_tree_min(BinaryTree *bt);

KeyValPair *binary_tree_max(BinaryTree *bt);

KeyValPair *binary_tree_pop_min(BinaryTree *bt);

KeyValPair *binary_tree_pop_max(BinaryTree *bt);

Vector *binary_tree_interval(BinaryTree *bt, void *min_key, void *max_key);

void* bt_get_rec(Node* n, void *key, CmpFn cmpFn) {
    if(n == NULL) {
        return NULL;
    }

    if(cmpFn(key, n->kvp->key) < 0) {
        return bt_get_rec(n->left, key, cmpFn);
    } else if(cmpFn(key, n->kvp->key) > 0) {
        return bt_get_rec(n->right, key, cmpFn);
    } else {
        return n->kvp->value;
    }
}

void *binary_tree_get(BinaryTree *bt, void *key) {
    return bt_get_rec(bt->root, key, bt->cmpFn);
}

void bt_destroy_rec(Node* n, KeyDestroyFn keyD, ValDestroyFn valD) {
    if(n == NULL) {
        return;
    }

    bt_destroy_rec(n->left, keyD, valD);
    bt_destroy_rec(n->right, keyD, valD);
    keyD(n->kvp->key);
    valD(n->kvp->value);
    free(n->kvp);
    free(n);
}

void binary_tree_destroy(BinaryTree *bt) {
    Node* n = bt->root;

    bt_destroy_rec(n, bt->keyDestroyFn, bt->valDestroyFn);
    
    free(bt);
}



// a funcao abaixo pode ser util para debug, mas nao eh obrigatoria.
void binary_tree_print(BinaryTree *bt);
Vector *binary_tree_inorder_traversal(BinaryTree *bt);
Vector *binary_tree_preorder_traversal(BinaryTree *bt);
Vector *binary_tree_postorder_traversal(BinaryTree *bt);
Vector *binary_tree_levelorder_traversal(BinaryTree *bt);

Vector *binary_tree_inorder_traversal_recursive(BinaryTree *bt);
Vector *binary_tree_preorder_traversal_recursive(BinaryTree *bt);
Vector *binary_tree_postorder_traversal_recursive(BinaryTree *bt);
