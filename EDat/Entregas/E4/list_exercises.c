#include "list_exercises.h"
#include "elements.h"
#include "list.h"
#include "types.h"

void list_delete(List *pl, const void *elem, elem_cmp_fn compare){
    Node *pn = NULL, *pm = NULL;

    /*check arguments*/
    if (!pl || !elem || !compare || list_isEmpty(pl)) return;

    /*set the pointer to a node to the first node of the list*/
    pn = pl->first;

    /*check if the first node needs to be deleted*/
    if (compare(pn->info, elem) == 0){
        /*check if it is the last (and only) node in the list*/
        if (pn->next == NULL){
            /*delete de the node*/
            free(pl->first);
            pl->first = NULL;
            
        }
        else{
            /*delete the ndde*/
            pl->first = pn->next;
            free(pn);
        }
    }
    else{
        /*iterate over the nodes of the list*/
        while (pn->next != NULL){
            /*check if the current node needs to be deleted*/
            if (compare(pn->next->info, elem) == 0){
                /*assign new pointers and delete the node*/
                pm = pn->next->next;
                free(pn->next);
                pn->next = pm;
            }
            else
                /*move the pointer to the next node*/
                pn = pn->next;
        }
    }
}


List *list_copy(List *pl){
    List *pl_copy = NULL;
    Node *node_copy = NULL, *last = NULL,*pn = NULL;

    /*check arguments*/
    if (!pl) return NULL;

    /*create the new list*/
    pl_copy = list_new();
    if (!pl_copy) return NULL;

    /*check if the origin list is empty*/
    if (list_isEmpty(pl)) return pl_copy;

    /*create a new node for the new list*/
    node_copy = node_new();
    if(!node_copy) return NULL;

    /*copy the first node of the origin list in the node of the new list*/
    pn = pl->first;
    node_copy->info = pl->first->info;
    pl_copy->first = node_copy;
    last = node_copy;

    /*iterate over the nodes of the origin list*/
    while (pn->next != NULL){
        /*create a new node*/
        node_copy->next = node_new();
        if (!node_copy->next) return NULL;

        /*move the pointers to the nodes of both list one position forward*/
        node_copy = node_copy->next;
        pn = pn->next;

        /*copy the node of the origin list in the node of the new list*/
        node_copy->info =pn->info;
        last->next = node_copy;
        last = node_copy;
    }

    return pl_copy;
}
