/** 
 * @brief It implements the player module
 * 
 * @file player.c
 * @author Miguel Ángel Sacristán
 * @version 1.0 
 * @date 08-02-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"




/*
 * player_create allocates memory for a new player and its members
 */
Player *player_create(Id id){
    Player *newPlayer = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;
    
    newPlayer = (Player *) malloc(sizeof(Player));
    if (newPlayer == NULL)
        return NULL;

    newPlayer->player_object = NULL;
    newPlayer->id = id;
    
    strcpy(newPlayer->name, "");
    return newPlayer;
}

/*
 * player_destroy frees the memory of an existing player
 */
STATUS player_destroy(Player *player){
    if (!player)
        return ERROR;
    
    free(player);
    return OK;
}

/*
 * player_get_id gets the id of a player
 */
Id player_get_id (Player *player){
    if (!player)
        return NO_ID;

    return player->id;
}

/*
 * player_get_location gets the location of a player
 */
Id player_get_location (Player *player){
    if (!player)
        return NO_ID;

    return player->location;
}

/*
 * player_get_name gets the name of a player
 */
char *player_get_name(Player *player){
    if (!player)
        return NULL;

    return player->name;
}

/*
 * player_get_object gets the object of a player
 */
Object *player_get_object(Player *player){
    if (!player)
        return NULL;

    return player->player_object;
}

/*
 * player_set_id assigns an id to a player
 */
STATUS player_set_id(Player *player, Id id){
    if (!player || !id)
        return ERROR;

    player->id = id;
    return OK;
}

/*
 * player_set_location sets a location to a player
 */
STATUS player_set_location(Player *player, Id location){
    if (!player || !location)
        return ERROR;

    player->location=location;
    return OK;
}

/*
 * player_set_object assigns an object to a player
 */
STATUS player_set_object (Player *player, Object *object){
    if (!player)
        return ERROR;

    player->player_object = object;
    return OK;
}

/*
 * player_set_name assigns a name to a player
 */
STATUS player_set_name (Player *player, char *name){
    if (!player || !name)
        return ERROR;

    strcpy(player->name, name);
    return OK;    
}

/*
 * player_print prints the player id, location, name and object
 */
STATUS player_print (Player *player){
    if (!player)
        return ERROR;

    fprintf(stdout, "Player Id: %ld\n Player Location: %ld\n Player Name: %s\n", player->id, player->location, player->name);
    return object_print(player->player_object);
}
