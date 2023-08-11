/**
 * @brief Implementation of the GAME_MANAGEMENT module
 * @file game_management.c
*/

#include "game_management.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * game_management_load_players reads the data file and allocates memory
*/
Status game_management_load_players(Game *game, const char *filename){
    FILE *f = NULL;
    char line[MAX_WORD] = "";
    char name[MAX_WORD] = "";
    char *toks = NULL;
    Id id = NO_ID;
    Player *p1 = NULL, *p2 = NULL;
    Status st = OK;

    /*check arguments*/
    if (!game || !filename) return ERROR;

    f = fopen(filename, "r");
    if (!f) return ERROR;

    while (fgets(line, MAX_WORD, f)){
        if (strcmp("#p:", line, 3) == 0){
            toks = strtok(line +3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
        }

        p1 = player_create()
    }

}