/**
 * @brief Implementation of GAME module
 * @file game.h
*/

#include "player.h"

#ifndef GAME_H_

/**
 * @brief Number of aircraft carriers
*/
#define NUM_AIRCRAFTCARRIER 1

/**
 * @brief Number of submarines
*/
#define NUM_SUBMARINE 3

/**
 * @brief Number of destroyers
*/
#define NUM_DESTROYER 3

/**
 * @brief Number of cruisers
*/
#define NUM_CRUISER 2

/**
 * @brief Aircraft acrrier's length
*/
#define LENGTH_AIRCRAFTCARRIER 4

/**
 * @brief Submarine's length
*/
#define LENGTH_SUBMARINE 3

/**
 * @brief Destroyer's length
*/
#define LENGTH_DESTROYER 2

/**
 * @brief Cruiser's length
*/
#define LENGTH_CRUISER 1

/**
 * @brief Game structure
*/
typedef struct _Game Game;

/**
 * @brief It creates a new game, allocating memory for it
 * 
 * @param game a pointer to a pointer to a game
 * @return OK if everything goes well, ERROR if not
*/
Status *game_create(Game **game);

/**
 * @brief It initializes a game from a file
 * 
 * @param game a pointer to a game
 * @param filename the name of a file
 * @return OK if everything goes well, ERROR if not
*/
Status game_create_from_file(Game **game, const char *filename);

/**
 * @brief It destroys a game, freeing the allocated memory for it
 * 
 * @param game a pointer to a game
 * @return OK if everything goes well, ERROR if not
*/
Status game_destroy(Game *game);

#endif