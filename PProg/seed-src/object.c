/** 
 * @brief It implements the object module
 * 
 * @file object.c
 * @author Alberto Tarrasa
 * @version 1.0 
 * @date 06-02-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/**
 * @brief Object
 *
 * This struct stores all the information of an object
 */
struct _Object{
    Id id;                   /*!< Id number of the object, it must be unique */
    char name[WORD_SIZE +1]; /*!< Name of the object */
};

/** object_create allocates memory for a new object
 * and initializes it members
 */
Object* object_create (Id id){
    Object *newObject = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;
    
    newObject = (Object *) malloc(sizeof(Object));
    if (newObject == NULL){
        return NULL;
    }

    /* Initialization of an object */
    newObject->id = id;
    newObject->name[0] = '\0';

    return newObject;
}

/** object_destroy frees the previous memory allocation
 * for a object
 */
STATUS object_destroy (Object* object){
    if (!object){
        return ERROR;
    }

    free(object);
    object = NULL;
    return OK;
}

/** It gets the id of an object
 */
Id object_get_id (Object* object){
    if (!object){
        return NO_ID;
    }

    return object->id;
}

/** It sets the name of an object
 */
STATUS object_set_name (Object* object, char* name){
    if (!object || !name){
        return ERROR;
    }

    if (!strcpy(object->name, name)){
        return ERROR;
    }

    return OK;
}

/** It gets the name of an object
 */
const char* object_get_name (Object* object){
    if (!object){
        return NULL;
    }

    return object->name;
}

/** It prints the object information
 */
STATUS object_print (Object* object){
    /* Error control */
    if (!object){
        return ERROR;
    }

    /* Print the id and the name of the object*/
    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
}