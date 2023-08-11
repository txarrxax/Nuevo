/**
 * @brief It declares the tests for the game module
 *
 * @file game_test.h
 * @author Álvaro Grande
 * @version 2.0
 * @date 07-03-2023
 * @copyright GNU Public License
 */

#ifndef GAME_TEST_H
#define GAME_TEST_H

#include <game.h>
#include <link.h>
#include <object.h>
#include <player.h>
#include <space.h>
#include <test.h>
#include <types.h>

/**
 * @brief sample filename for testing purposes
 */
#define TEST_FILENAME "file.txt"

/**
 * @brief sample id for testing purpose
*/
#define TEST_ID 4

/**
 * @brief sample argument for testing purpose
*/
#define TEST_ARG "a"

/**
 * @brief sample player health for testing purpose
*/
#define TEST_PLAYER_HEALTH 5

/**
 * @brief sample position for testing purpose
*/
#define TEST_POSITION -2

/**
 * @test Tests function for game creating from file
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_create_from_file();

/**
 * @test Tests function for game creating from file
 * @pre File == NULL
 * @post Output == ERROR
 */
void test2_game_create_from_file();

/**
 * @test Tests function for game destroy
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_destroy();

/**
 * @test Tests function for game_space adding
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_add_space();

/**
 * @test Tests function for game_space adding
 * @pre Space NULL
 * @post Output == ERROR
 */
void test2_game_add_space();

/**
 * @test Tests function for game_space getting
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_get_space();

/**
 * @test Tests function for game_space getting
 * @pre Id = NO_ID
 * @post Output == ERROR
 */
void test2_game_get_space();

/**
 * @test Tests function for game updating
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_update();

/**
 * @test Tests function for game creating from file
 * @pre arg = NULL
 * @post Output == ERROR
 */
void test2_game_update();

/**
 * @test Tests function for game_is_over
 * @pre Game NULL
 * @post Output == TRUE
 */
void test1_game_is_over();

/**
 * @test Tests function for game_is_over
 * @pre player_health > 0
 * @post Output == TRUE
 */
void test2_game_is_over();

/**
 * @test Tests function for game_last_command getting
 * @pre Game NULL
 * @post Output == NO_CMD
 */
void test1_game_get_last_command();

/**
 * @test Test function for game_last_command getting
 * @pre Game
 * @post Output == NO_CMD
 */
void test2_game_get_last_command();

/**
 * @test Tests function for game printing
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_print_data();

/**
 * @test Tests function for game printing
 * @pre Game
 * @post Output == OK
 */
void test2_print_data();

/**
 * @test Tests function for game_object_location getting
 * @pre Game NULL
 * @post Output == NO_ID
 */
void test1_game_get_object_location();

/**
 * @test Tests function for game_object_location getting
 * @pre Object NULL
 * @post Output == NO_ID
 */
void test2_game_get_object_location();

/**
 * @test Tests function for game_object adding
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_add_object();
/**
 * @test Tests function for game_objects adding
 * @pre Object NULL
 * @post Output == ERROR
 */

void test2_game_add_object();

/**
 * @test Tests function for game_player getting
 * @pre Game NULL
 * @post Output == NULL
 */
void test1_game_get_player();

/**
 * @test Tests function for game_player getting
 * @pre Game
 * @post Output == game_player
 */
void test2_game_get_player();

/**
 * @test Tests function for game_enemy getting
 * @pre Game NULL
 * @post Output == NULL
 */
void test1_game_get_enemy();

/**
 * @test Tests function for game_enemy getting
 * @pre Game
 * @post Output == game_enemy
 */
void test2_game_get_enemy();

/**
 * @test Tests function for game_number_of_object getting
 * @pre Game NULL
 * @post Output == -1
 */
void test1_game_get_number_of_objects();

/**
 * @test Tests function for game_number_of_objects getting
 * @pre Game
 * @post Output == game_num_obj
 */
void test2_game_get_number_of_objects();

/**
 * @test Tests function for game_object getting from position
 * @pre Game NULL
 * @post Output == NULL
 */
void test1_game_get_object_from_position();

/**
 * @test Tests function for game_object getting from position
 * @pre position < 0
 * @post Output == NULL
 */
void test2_game_get_object_from_position();

/**
 * @test Tests function for game_last_command_exit getting
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_get_last_command_exit();

/**
 * @test Tests function for game_last_command_exit getting
 * @pre Game
 * @post Output == game_last_cmd_exit
 */
void test2_game_get_last_command_exit();

/**
 * @test Tests function for game_connection_status getting
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_get_connection_status();

/**
 * @test Tests function for game_connection_status getting
 * @pre dir -1
 * @post Output == ERROR
 */
void test2_game_get_connection_status();

/**
 * @test Tests function for game_connection getting
 * @pre Game NULL
 * @post Output == NO_ID
 */
void test1_game_get_connection();

/**
 * @test Tests function for game_connection getting
 * @pre space NO_ID
 * @post Output == NO_ID
 */
void test2_game_get_connection();

/**
 * @test Tests function for game_link adding
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_add_link();

/**
 * @test Tests function for game_link adding
 * @pre Link NULL
 * @post Output == ERROR
 */
void test2_game_add_link();

/**
 * @test Tests function for game creation
 * @pre NULL
 * @post Output == ERROR
 */
void test1_game_create();

/**
 * @test Tests function for game creation
 * @pre Game
 * @post Game_last_cmd == NO_CMD
 */
void test2_game_create();

/**
 * @test Test function for space_obj_desc getting
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_game_get_space_obj_desc();

/**
 * @test Test function for space_obj_desc getting
 * @pre Space NULL
 * @post Output ERROR
 */
void test2_game_get_space_obj_desc();

#endif