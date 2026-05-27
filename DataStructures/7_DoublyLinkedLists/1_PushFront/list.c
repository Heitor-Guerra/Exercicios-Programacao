#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define ERROR_VALUE -1

/**
 * @brief Construct a new double linked list object
 *  Allocates memory for a new double linked list and returns a pointer to it.
 * @return List*
 * Pointer to the newly allocated double linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the double linked list using list_destroy().
 *
 */
List *list_construct() {
    List* l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

/**
 * @brief Returns the size of the double linked list.
 *  Returns the number of nodes in the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @return int
 * Number of nodes in the double linked list.
 *
 */
int list_size(List *l) {
    return l->size;
}

/**
 * @brief Pushes a new node to the front of the double linked list.
 *  Allocates memory for a new node and inserts it at the front of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param data
 * Pointer to the data to be stored in the new node.
 *
 */
void list_push_front(List *l, data_type data) {
    Node* newNode = node_construct(data, NULL, l->head);
    if(l->head == NULL) {
        l->head = newNode;
        l->last = newNode;
    } else {
        l->head->prev = newNode;
        l->head = newNode;
    }
    l->size++;
}

/**
 * @brief Pushes a new node to the back of the double linked list.
 *
 * @param l
 * Pointer to the double linked list.
 * @param data
 * data to be stored in the new node.
 */
void list_push_back(List *l, data_type data) {
    Node* newNode = node_construct(data, l->last, NULL);
    if(l->last == NULL) {
        l->head = newNode;
        l->last = newNode;
    } else {
        l->last->next = newNode;
        l->last = newNode;
    }
    l->size++;
}

/**
 * @brief Print the elements of the double linked list.
 *  Print the elements of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 *
 */
void list_print(List *l, void (*print_fn)(data_type)) {
    printf("[");
    Node* n = l->head;
    while(n != NULL) {
        print_fn(n->value);
        if(n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]");
}

/**
 * @brief Print the elements of the double linked list in reverse order.
 * Print the elements of the double linked list in reverse order.
 * @param l
 * Pointer to the double linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 */
void list_print_reverse(List *l, void (*print_fn)(data_type)) {
    printf("[");
    Node* n = l->last;
    while(n != NULL) {
        print_fn(n->value);
        if(n->prev != NULL) {
            printf(", ");
        }
        n = n->prev;
    }
    printf("]");
}

/**
 * @brief Returns the data stored in the node at the given index.
 * @param l
 * Pointer to the double linked list.
 * @param i
 * Index of the node.
 * @return data_type
 * Data stored in the node at the given index.
 *
 */
data_type list_get(List *l, int i) {
    if(i < 0 || i >= l->size) {
        printf("Index Out of Bounds");
        return ERROR_VALUE;
    }
    Node *n = l->head;
    for(int j = 0; j < i; j++) {
        n = n->next;
    }
    return n->value;
}

/**
 * @brief Remove the first node of the double linked list and returns its data.
 * @param l
 * Pointer to the double linked list.
 * @return data_type
 * Pointer to the data stored in the first node of the double linked list that was removed.
 *
 */
data_type list_pop_front(List *l) {
    if(l->size <= 0) {
        printf("Empty list");
        return ERROR_VALUE;
    }
    
    Node *n = l->head;
    if(n->next != NULL) {
        n->next->prev = NULL;
    } else {
        l->last = NULL;
    }
    l->head = n->next;
    l->size--;
    data_type val = n->value;
    node_destroy(n);

    return val;
}

/**
 * @brief Remove the last node of the double linked list and returns its data.
 * @param l
 * Pointer to the double linked list.
 * @return data_type
 * Data stored in the last node of the double linked list that was removed.
 */
data_type list_pop_back(List *l) {
    if(l->size <= 0) {
        printf("Empty list");
        return ERROR_VALUE;
    }
    
    Node *n = l->last;
    if(n->prev != NULL) {
        n->prev->next = NULL;
    } else {
        l->head = NULL;
    }
    l->last = n->prev;
    l->size--;

    data_type val = n->value;
    node_destroy(n);

    return val;
}

/**
 * @brief Create a new list given by the reverse of the given list.
 * @param l
 * Pointer to the double linked list.
 * @return List*
 * Pointer to the newly allocated double linked list.
 */
List *list_reverse(List *l);

/**
 * @brief Removes all nodes from the double linked list.
 * Removes all nodes from the double linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the double linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the data stored in the nodes.
 */
void list_clear(List *l);

/**
 * @brief Removes all nodes with the given value from the double linked list.
 * Removes all nodes with the given value from the double linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the double linked list.
 * @param val
 * Value to be removed from the double linked list.
 */
void list_remove(List *l, data_type val);

/**
 * @brief Removes all duplicate values from the double linked list.
 * Removes all duplicate values from the double linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the double linked list.
 * @note
 * The double linked list must be sorted.
 */
void list_unique(List *l);

/**
 * @brief Adds all nodes from the given list to the end of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @param m
 * Pointer to the double linked list to be added to the end of the double linked list.
 */
void list_cat(List *l, List *m);

/**
 * @brief Sorts the double linked list.
 * Sorts the double linked list.
 * @param l
 * Pointer to the double linked list.
 */
void list_sort(List *l);

/**
 * @brief Destroys the double linked list.
 *  Frees the memory allocated for the double linked list and all its nodes.
 * @param l
 * Pointer to the double linked list.
 *
 */
void list_destroy(List *l) {
    Node *n = l->head;
    while(n != NULL) {
        Node* next = n->next;
        node_destroy(n);
        n = next;
    }
    free(l);
}

/**
 * @brief Returns an iterator to the first node of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @return ListIterator*
 * Pointer to the iterator.
 */
ListIterator *list_front_iterator(List *l);

/**
 * @brief Returns an iterator to the last node of the double linked list.
 * @param l
 * Pointer to the double linked list.
 * @return ListIterator*
 * Pointer to the iterator.
 */
ListIterator *list_back_iterator(List *l);

/**
 * @brief Returns the data stored in the node and updates the iterator to point to the next node.
 * @param it
 * Pointer to the iterator.
 * @return data_type*
 * Pointer to the data stored in the current node.
 */
data_type *list_iterator_next(ListIterator *it);

/**
 * @brief Returns the data stored in the node and updates the iterator to point to the previous node.
 * @param it
 * Pointer to the iterator.
 * @return data_type*
 * Pointer to the data stored in the current node.
 */
data_type *list_iterator_previous(ListIterator *it);

/**
 * @brief Returns true if the iterator is over.
 * @param it
 * Pointer to the iterator.
 * @return 1 if the iterator is over, and 0 otherwise.
 */
int list_iterator_is_over(ListIterator *it);

/**
 * @brief Free the memory allocated to the iterator.
 * @param it
 * Pointer to the iterator.
 */
void list_iterator_destroy(ListIterator *it);
