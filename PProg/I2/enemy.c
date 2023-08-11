/** 
 * @brief It implements the enemy module
 * 
 * @file enemy.c
 * @author Alberto Tarrasa
 * @version 1.0 
 * @date 21-02-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enemy.h"

/**
 * enemy_create creates a new enemy, allocating memory and initializing it
*/
Enemy *enemy_create (Id id){
    Enemy *newEnemy = NULL;

    /* error control */
    if (id == NO_ID)
        return NULL;
    
    /* allocate memory */
    newEnemy = (Enemy *) malloc(sizeof(Enemy));
    if (!newEnemy)
        return NULL;
    
    /* set initial values */
    newEnemy->id = id;
    newEnemy->health = 5;
    strcpy(newEnemy->name, "");
    return newEnemy;
}

/**
 * enemy_destroy frees the memory of an existing enemy
*/
STATUS enemy_destroy (Enemy *enemy){
    /* error control */
    if (!enemy)
        return ERROR;
    
    /* memory free */
    free(enemy);
    return OK;
}

/**
 * enemy_get_id gets the id of an enemy
*/
Id enemy_get_id (Enemy *enemy){
    /* error control */
    if (!enemy)
        return NO_ID;
    
    return enemy->id;
}

/**
 * enemy_get_location gets the location of an enemy
*/
Id enemy_get_location (Enemy *enemy){
    /* error control */
    if (!enemy)
        return NO_ID;
    
    return enemy->location;
}

/**
 * enemy_get_name gets the name of an enemy
*/
char *enemy_get_name (Enemy *enemy){
    /* error control */
    if (!enemy)
        return NULL;
    
    return enemy->name;
}

/**
 * enemy_get_health gets the health points of an enemy
*/
int enemy_get_health (Enemy *enemy){
    /* error control */
    if (!enemy)
        return -1;
    
    return enemy->health;
}

/**
 * enemy_set_id sets the id number of an enemy
*/
STATUS enemy_set_id (Enemy *enemy, Id id){
    /* error control */
    if (!enemy || id == NO_ID)
        return ERROR;
    
    enemy->id = id;
    return OK;
}

/**
 * enemy_set_location sets the id location of an enemy
*/
STATUS enemy_set_location (Enemy *enemy, Id location){
    /* error control */
    if (!enemy || location == NO_ID)
        return ERROR;
    
    enemy->location = location;
    return OK;
}

/**
 * enemy_set_name sets the name of an enemy
*/
STATUS enemy_set_name (Enemy *enemy, char *name){
    /* error control */
    if (!enemy || !name)
        return ERROR;
    
    strcpy(enemy->name, name);
    return OK;
}

/**
 * enemy_set_health sets the health points of an enemy
*/
STATUS enemy_set_health (Enemy *enemy, int health){
    /* error control */
    if (!enemy || health < 0)
        return ERROR;
    
    enemy->health = health;
    return OK;
}

/**
 * enemy_print prints the id, location, name and health points of an enemy
*/
STATUS enemy_print (Enemy *enemy){
    /* error control */
    if (!enemy)
        return ERROR;
    
    fprintf(stdout, "Enemy Id: %ld\nEnemy Location: %ld\nEnemy Name: %s\nEnemy Health: %d\n", enemy->id, enemy->location, enemy->name, enemy->health);
    return OK;
}