#include "forward_list.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Construct a new Linked List:: Linked List object
 *  Allocates memory for a new linked list and returns a pointer to it.
 * @return ForwardList*
 * Pointer to the newly allocated linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the linked list using forward_list_destroy().
 *
 */
ForwardList *forward_list_construct() {
    ForwardList* f = (ForwardList*)malloc(sizeof(ForwardList));
    f->head = NULL;
    // f->last = NULL;
    f->size = 0;
    
    return f;
}

/**
 * @brief Returns the size of the linked list.
 *  Returns the number of nodes in th e linked list.
 * @param l
 * Pointer to the linked list.
 * @return int
 * Number of nodes in the linked list.
 *
 */
int forward_list_size(ForwardList *l) {
    return l->size;
}

/**
 * @brief Pushes a new node to the front of the linked list.
 *  Allocates memory for a new node and inserts it at the front of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param data
 * Pointer to the data to be stored in the new node.
 *
 */
void forward_list_push_front(ForwardList *l, data_type data) {
    Node* n = node_construct(data, l->head);
    l->head = n;
    l->size++;    
    // if(l->size == 1) {
    //     l->last = n;
    // }
}

/**
 * @brief Pushes a new node to the back of the linked list.
 *  Allocates memory for a new node and inserts it at the front of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param data
 * Pointer to the data to be stored in the new node.
 *
 */
// void forward_list_push_back(ForwardList *l, data_type data) {
//     Node* n = node_construct(data, NULL);
//     Node* last = l->last;
//     l->last = n;
//     l->size++;    
//     if(l->size == 1) {
//         l->head = n;
//     } else {
//         last->next = n;
//     }
// }


/**
 * @brief Print the elements of the linked list.
 *  Print the elements of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param print_fn
 * Pointer to the function to print data_type values.
 *
 */
void forward_list_print(ForwardList *l, void (*print_fn)(data_type)) {
    Node* n = l->head;
    printf("[");
    while(n != NULL) {
        print_fn(n->value);
        n = n->next;
        if(n != NULL){
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * @brief Returns the data stored in the node at the given index.
 * @param l
 * Pointer to the linked list.
 * @param i
 * Index of the node.
 * @return data_type
 * Data stored in the node at the given index.
 *
 */
data_type forward_list_get(ForwardList *l, int i) {
    if(i >= l->size || i < 0) {
        printf("Index out of Bounds for get");
        exit(1);
    }


    Node* n = l->head;
    for(int j = 0; j < i; j++) {
        n = n->next;
    }

    return n->value;
}

/**
 * @brief Remove the first node of the linked list and returns its data.
 * @param l
 * Pointer to the linked list.
 * @return data_type
 * Pointer to the data stored in the first node of the linked list that was removed.
 *
 */
data_type forward_list_pop_front(ForwardList *l) {
    if(l->head == NULL){
        printf("Empty list");
        return 0;
    }
    data_type val = l->head->value;
    Node* next = l->head->next;
    node_destroy(l->head);
    l->head = next;
    l->size--;

    return val;
}

/**
 * @brief Create a new list given by the reverse of the given list.
 * @param l
 * Pointer to the linked list.
 * @return ForwardList*
 * Pointer to the newly allocated linked list.
 */
ForwardList *forward_list_reverse(ForwardList *l) {
    ForwardList* nl = forward_list_construct();
    while(l->size > 0) {
        forward_list_push_front(nl, forward_list_pop_front(l));
    }
    return nl;
}

/**
 * @brief Removes all nodes from the linked list.
 * Removes all nodes from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @note
 * The caller is responsible for freeing the memory allocated for the data stored in the nodes.
 */
void forward_list_clear(ForwardList *l) {
    while(l->size > 0) {
        forward_list_pop_front(l);
    }
}

/**
 * @brief Removes all nodes with the given value from the linked list.
 * Removes all nodes with the given value from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @param val
 * Value to be removed from the linked list.
 */
void forward_list_remove(ForwardList *l, data_type val) {    
    Node* n = l->head;
    Node* ant = NULL;
    while(n != NULL) {
        Node* next = n->next;
        if(val == n->value) {
            if(n != l->head) {
                ant->next = next;
                node_destroy(n);
                n = ant;
            } else {
                node_destroy(n);
                l->head = next;
            }
            l->size--;
        }

        ant = n;
        n = next;
    }
}

/**
 * @brief Removes all duplicate values from the linked list.
 * Removes all duplicate values from the linked list and frees the memory allocated for them.
 * @param l
 * Pointer to the linked list.
 * @note
 * The linked list must be sorted.
 */
void forward_list_unique(ForwardList *l);
///////////////////////////////////

/**
 * @brief Adds all nodes from the given list to the end of the linked list.
 * @param l
 * Pointer to the linked list.
 * @param m
 * Pointer to the linked list to be added to the end of the linked list.
 */
void forward_list_cat(ForwardList *l, ForwardList *m) {
    while(m->size > 0) {
        data_type val = forward_list_pop_front(m);
        forward_list_push_front(l, val);
    }
}

/**
 * @brief Sorts the linked list.
 * Sorts the linked list.
 * @param l
 * Pointer to the linked list.
 */
void forward_list_sort(ForwardList *l);
///////////////////////////////////

/**
 * @brief Destroys the linked list.
 *  Frees the memory allocated for the linked list and all its nodes.
 * @param l
 * Pointer to the linked list.
 *
 */
void forward_list_destroy(ForwardList *l) {
    Node* n = l->head;
    while(n != NULL) {
        Node* next = n->next;
        node_destroy(n);
        n = next;
    }
    free(l);
}


/**
 * @brief Returns an iterator to the first node of the linked list.
 * @param l
 * Pointer to the linked list.
 * @return ListIterator*
 * Pointer to the iterator.
 */
ListIterator *list_iterator_construct(ForwardList *l) {
    ListIterator* i = (ListIterator*)malloc(sizeof(ListIterator));
    i->current = l->head;
    return i;
}

/**
 * @brief Free the memory allocated to the iterator.
 * @param it
 * Pointer to the iterator.
 */
void list_iterator_destroy(ListIterator *it) {
    free(it);
}

/**
 * @brief Returns the data stored in the node and updates the iterator to point to the next node.
 * @param it
 * Pointer to the iterator.
 * @return data_type
 * Pointer to the data stored in the current node.
 */
data_type* list_iterator_next(ListIterator *it) {
    data_type* val = &it->current->value;
    it->current = it->current->next;
    return val;
}

/**
 * @brief Returns true if the iterator is over.
 * @param it
 * Pointer to the iterator.
 * @return 1 if the iterator is over, and 0 otherwise.
 */
bool list_iterator_is_over(ListIterator *it) {
    return it->current == NULL;
}
