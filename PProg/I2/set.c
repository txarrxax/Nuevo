#include <stdio.h>
#include "set.h"

/** It creates a new empty set
 */
Set *set_create () {
    Set *set;
    set = (Set*) malloc(sizeof(Set));
    if (!set)
        return NULL;
    set->ids = (Id*) malloc(sizeof(Id));
    if (!set->ids)
        return NULL;
    set->n_ids = 0;
    return set;
}

/** It destroys a set
 */
void set_destroy (Set *set) {
    free(set->ids);
    free(set);
}

/** It adds an id to a set
 */
STATUS set_addId (Set *set, Id new_id) {
    Id *aux;

    if (!set || !new_id)
        return ERROR;
    if (set_isFull(set) == FALSE){
        set->ids[set->n_ids]=new_id;
        set->n_ids++;
        return OK;
    }
    aux = (Id*) realloc(set->ids, (set->n_ids+1)*sizeof(Id));
    if (!set->ids)
        return ERROR;
    set->ids = aux;
    set->ids[set->n_ids]=new_id;
    set->n_ids++;
    return OK;
}

/** It deletes an id from a set
 */
STATUS set_destroyId (Set *set, Id del_id) {
    long i,j;
    if (!set || !del_id)
        return ERROR;
    for (i=0; i<set->n_ids; i++){
        if (set->ids[i]==del_id){
            for (j=i; j<(set->n_ids-1); j++){
                set->ids[j]=set->ids[j+1];
            }
            set->ids[set->n_ids-1]=NO_ID;
            set->n_ids--;
            return OK;
        }
    }
    return ERROR;
}

/** It deletes the last id added to a set
 */
STATUS set_destroyLastId (Set *set) {
    if (!set)
        return ERROR;
    if (set->n_ids == 0)
        return ERROR;
    set->n_ids--;
    set->ids[set->n_ids]=NO_ID;
    return OK;
}

/** It check if the array with the ids is full
 */
BOOL set_isFull (Set *set) {
    if (!set || !set->ids)
        return FALSE;
    if ((sizeof(Id)*set->n_ids) < sizeof(set->ids)){
        return FALSE;
    }
    return TRUE;
}

/** It searches for an id in a set
 */
BOOL set_checkId(Set *set, Id id){
    long i;
    if (!set || !id) {
        return FALSE;
    }
    for (i=0; i<set->n_ids; i++) {
        if (id == set->ids[i])
            return TRUE;
    }
    return FALSE;
}

/** It gets the number of ids stored in a set
 */
int set_getNumberOfElements(Set *set) {
    if (!set)
        return -1;
    return set->n_ids;
}

/** It prints the information of a set
 */
STATUS set_print (FILE *pf, Set *set) {
    long i;
    if (!set || !pf)
        return ERROR;
    fprintf(pf, "Set: ");
    for (i=0; i<set->n_ids; i++){
        fprintf(pf, "%ld ", set->ids[i]);
    }
    return OK;
}