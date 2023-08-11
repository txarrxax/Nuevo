#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct _Node{
    void *info;
    struct _Node *next;
};

struct _List{
    Node *first;
};

/* node_new creates and initializes a new node */
Node *node_new(){
    Node *n = NULL;

    /* allocate memory for the new node */
    n = (Node *)malloc(sizeof(Node));
    if (!n) return NULL;

    /* set the initial values */
    n->info = NULL;
    n->next = NULL;

    return n;
}

/* list_new creates and initializes a new list */
List *list_new(){
    List *l = NULL;

    /* allocate memory for the new list */
    l = (List *)malloc(sizeof(List));
    if (!l) return NULL;

    /* set the initial values */
    l->first = NULL;

    return l;
}

/* list_free frees the memory allocated for a list */
void list_free(List *l){
    /* error checks */
    if (!l) return;

    /* clear out the list */
    while (!list_isEmpty(l))
        list_popFront(l);
    
    /* free the memory allocated */
    free(l);
}

/* list_isEmpty checks if a list is empty */
Bool list_isEmpty(const List *l){
    /* error checks */
    if (!l) return TRUE;

    /* check the list */
    if (!l->first) return TRUE;

    return FALSE;
}

/* list_pushFront pushes an element to the first position of a list */
Status list_pushFront(List *l, const void *e){
    Node *n = NULL;

    /* error checks */
    if (!l || !e) return ERROR;

    /* create a new node */
    n = node_new();
    if (!n) return ERROR;

    /* set the new values */
    n->info = (void *)e;
    n->next = l->first;
    l->first = n;

    return OK;
}

/* list_pushBack pushes an element to the last position of a list */
Status list_pushBack(List *l, const void *e){
    Node *n1 = NULL, *n2 = NULL;

    /* error checks */
    if (!l || !e) return ERROR;

    /* create a new node */
    n1 = node_new();
    if (!n1) return ERROR;

    /* set the new values */
    n1->info = (void *)e;

    /* case 1: empty list -> insert at initial position */
    if (list_isEmpty(l))
        l->first = n1;

    /* case 2: not empty list -> traverse the list an insert */
    else{
        n2 = l->first;
        while (n2->next)
            n2 = n2->next;
        n2->next = n1;
    }

    return OK;
}

/* list_popFront pops the element in the first position of a list */
void *list_popFront(List *l){
    Node *n = NULL;
    void *e = NULL;

    /* error checks */
    if (!l || list_isEmpty(l)) return NULL;

    /* set the new values */
    n = l->first;
    e = n->info;
    l->first = n->next;

    /* free the memory allocated for the poped element */
    free(n);

    return e;
}

/* list_popBack pops the element in the last position of a list */
void *list_popBack(List *l){
    Node *n = NULL;
    void *e = NULL;

    /* error checks */
    if (!l || list_isEmpty(l)) return NULL;

    /* set the new values */
    /* case 1: list with only one element -> pop the first element */
    if (!l->first->next){
        e = l->first->info;

        free(l->first);
        l->first = NULL;
    }

    /* case 2: list with more than one element -> pop the last element */
    else{
        n = l->first;
        while (n->next->next)
            n = n->next;
        e = n->next->info;

        free(n->next);
        n->next = NULL;
    }

    return e;
}

