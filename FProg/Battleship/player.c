/**
 * @brief Implementation of the PLAYER module
 * @file player.c
*/

#include "player.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * Player structure 
*/
struct _Player{
    Id id;
    char name[MAX_WORD];
    Board *board;
};

/**
 * player_create creates a new player, allocating memory for it
*/
Player *player_create(const Id id, const int rows, const int columns){
    Player *player = NULL;

    /*check arguments*/
    if (id == NO_ID || rows < ROW_MIN || rows > ROW_MAX || columns < COLUMN_MIN || columns > COLUMN_MAX) return NULL;

    player = (Player *)malloc(sizeof(Player));
    if (!player) return NULL;
    
    player->id = id;
    (player->name)[0] = '\0';

    player->board = board_create(rows, columns);
    if (!player->board){
        free(player);
        return NULL;
    }

    return player;
}

/**
 * player_destroy destroys a player, freeing the allocated memory for it
*/
Status player_destroy(Player *player){

    /*check arguments*/
    if (!player) return ERROR;

    board_destroy(player->board);
    free(player);

    return OK;
}

/**
 * player_get_id gets a player's id number
*/
Id player_get_id(const Player *player){
    
    /*check arguments*/
    if (!player) return NO_ID;

    return player->id;
}

/**
 * player_set_name sets a player's name
*/
Status player_set_name(Player *player, const char *name){

    /*check arguments*/
    if (!player || !name) return ERROR;

    strcpy(player->name, name);

    return OK;
}

/**
 * player_get_name gets a player's name
*/
char *player_get_name(const Player *player){
    
    /*check arguments*/
    if (!player) return NULL;

    return (char*)player->name;
}

/**
 * player_get_board gets a player's board
*/
Board *player_get_board(const Player *player){
    
    /*check arguments*/
    if (!player) return NULL;

    return player->board;
}

/**
 * player_print prints the information related to a player
*/
void player_print(const Player *player){

    /*check arguments*/
    if (!player) return;

    printf("PLAYER:\n");
    printf("\tplayer id: %d\n", player->id);
    printf("\tplayer name: %s\n", player->name);
    printf("\tplayer board:\n");

    board_print(player->board);
}