/**
 * @brief It declares the tests for the game module
 *
 * @file game_test.h
 * @author Álvaro Grande
 * @author Diego Fernández
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
 * @brief sample id for testing purposes
 */
#define TEST_ID 4

/**
 * @brief sample argument for testing purposes
 */
#define TEST_ARG "a"

/**
 * @brief sample player health for testing purposes
 */
#define TEST_PLAYER_HEALTH 5

/**
 * @brief sample position for testing purposes
 */
#define TEST_POSITION -2

/**
 * @brief sample size for testing purposes
 */
#define TEST_SIZE 4

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
 * @test Tests function for game destroy
 * @pre valid Game pointer
 * @post Output == OK
 */
void test2_game_destroy();

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
void test1_game_print_data();

/**
 * @test Tests function for game printing
 * @pre Game
 * @post Output == OK
 */
void test2_game_print_data();

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

/**
 * @test test game description setter
 * @pre NULL game pointer
 * @post Output == ERROR
 */
void test1_game_set_last_description();

/**
 * @test test game description setter
 * @pre NULL desc pointer
 * @post Output == ERROR
 */
void test2_game_set_last_description();

/**
 * @test test game description setter
 * @pre longer than expected input
 * @post Output == ERROR
 */
void test3_game_set_last_description();

/**
 * @test test game description getter
 * @pre valid input game pointer with initialized descrition
 * @post Output == initialized description
 */
void test1_game_get_last_description();

/**
 * @test test game description getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test2_game_get_last_description();

/**
 * @test test game dialogue setter
 * @pre NULL game pointer
 * @post Output == ERROR
 */
void test1_game_set_last_dialogue();

/**
 * @test test game dialogue setter
 * @pre NULL desc pointer
 * @post Output == ERROR
 */
void test2_game_set_last_dialogue();

/**
 * @test test game dialogue setter
 * @pre longer than expected input
 * @post Output == ERROR
 */
void test3_game_set_last_dialogue();

/**
 * @test test game dialogue getter
 * @pre valid input game pointer with initialized descrition
 * @post Output == initialized dialogue
 */
void test1_game_get_last_dialogue();

/**
 * @test test game dialogue getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test2_game_get_last_dialogue();

/**
 * @test test id-based object getter
 * @pre NULL game pointer
 * @post OUTPUT == NULL
 */
void test1_game_get_object_from_id();

/**
 * @test test id-based object getter
 * @pre game with several objects, valid Id
 * @post expected object
 */
void test2_game_get_object_from_id();

/**
 * @test test name-based object getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test1_game_get_object_from_name();

/**
 * @test test name-based object getter
 * @pre game with several objects, valid name
 * @post expected object
 */
void test2_game_get_object_from_name();

/**
 * @test test space id getter
 * @pre NULL game pointer
 * @post Output == NO_ID
 */
void test1_game_get_space_id_at();

/**
 * @test test space id getter
 * @pre game pointer with initialized spaces
 * @post expected id
 */
void test2_game_get_space_id_at();

/**
 * @test test space array getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test1_game_get_all_spaces();

/**
 * @test test space array getter
 * @pre game with initialized spaces
 * @post an array with the initialized spaces
 */
void test2_game_get_all_spaces();

/**
 * @test test object array getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test1_game_get_all_objects();

/**
 * @test test object array getter
 * @pre game with initialized objects
 * @post an array with the initialized objects
 */
void test2_game_get_all_objects();

/**
 * @test test getter of number of links
 * @pre NULL game pointer
 * @post Output == -1
 */
void test1_game_get_num_links();

/**
 * @test test getter of number of links
 * @pre valid game pointer with no links
 * @post Output == 0
 */
void test2_game_get_num_links();

/**
 * @test test link array getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test1_game_get_all_links();

/**
 * @test test link array getter
 * @pre game with initialized links
 * @post initialized links
 */
void test2_game_get_all_links();

/**
 * @test test enemy nullifier
 * @pre NULL game pointer
 * @post Output == ERROR
 */
void test1_game_no_enemy();

/**
 * @test test enemy nullifier
 * @pre game with initialized enemy
 * @post enemy getter will return NULL
 */
void test2_game_no_enemy();

/**
 * @test test id-based link getter
 * @pre NULL game pointer
 * @post Output == NULL
 */
void test1_game_get_link_from_id();

/**
 * @test test id-based link getter
 * @pre game with initialized links
 * @post expected link
 */
void test2_game_get_link_from_id();

#endif
