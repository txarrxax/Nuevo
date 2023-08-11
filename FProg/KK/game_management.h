/**
 * @brief Implementation of the GAME_MANAGEMENT module
 * @file game_management.h
*/

#include "game.h"

#ifndef GAME_MANAGEMENT_H_

/**
 * @brief It reads the data file and allocates memory
 * 
 * @param game a pointer to a game
 * @param filename the name of the data file
 * @return OK if everything goes well, ERROR if not
*/
Status game_management_load_players(Game *game, const char *filename);

#endif /*GAME_MANAGEMENT_H_*/