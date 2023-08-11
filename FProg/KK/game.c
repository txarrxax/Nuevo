/**
 * @brief Implementation of the GAME module
 * @file game.c
*/

#include "game.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Game structure
*/
struct _Game{
    Player *player1;
    Player *player2;
};

/**
 * game_create creates a new game, allocating memory for it
*/
Status *game_create(Game **game){
    
    /*check arguments*/
    if (!game) return ERROR;

    *game = (Game *)malloc(sizeof(Game));
    if (!game) return ERROR;

    return OK;
}

/**
 * game_create_from_file initializes a game from a file
*/
Status game_create_from_file(Game **game, const char *filename){

    /*check arguments*/
    if (!game || !filename) return ERROR;

    if (game_create(game) == ERROR) return ERROR;

    if (game_management_load_players(game, filename) == ERROR) return ERROR;

    return OK;
}