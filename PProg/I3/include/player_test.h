/**
 * @brief It declares the tests for the player module
 *
 * @file player_test.h
 * @author Álvaro Grande
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Test player creation
 * @pre Player
 * @post Output == ERROR
 */
void test1_player_create();

/**
 * @test Test player creation
 * @pre Player
 * @post Non NULL pointer to player
 */
void test2_player_create();

/**
 * @test Test function for player_id getting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_get_id();

/**
 * @test Test function for player_id getting
 * @pre Player
 * @post Player_id == Supplied id
 */
void test2_player_get_id();

/**
 * @test Test function for player_id setting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_set_id();

/**
 * @test Test function for player_id setting
 * @pre Player
 * @post Player Id == Supplied id
 */
void test2_player_set_id();

/**
 * @test Test function for player_inventory getting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_get_inventory();

/**
 * @test Test function for player_inventory getting
 * @pre Player
 * @post Not NULL pointer to player_inventory
 */
void test2_player_get_inventory();

/**
 * @test Test function for player item adding
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_add_item();

/**
 * @test Test function for player item adding
 * @pre Player
 * @post Output == OK
 */
void test2_player_add_item();

/**
 * @test Test function for player item deleting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_del_item();

/**
 * @test Test function for player item deleting
 * @pre Player
 * @post Output == OK
 */
void test2_player_del_item();

/**
 * @test Test function for player_location getting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_get_location();

/**
 * @test Test function for player_location getting
 * @pre Player
 * @post Player_location == Supplied location
 */
void test2_player_get_location();

/**
 * @test Test function for player_location setting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_set_location();

/**
 * @test Test function for player_location setting
 * @pre Player
 * @post Output == OK
 */
void test2_player_set_location();

/**
 * @test Test function for player_name getting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_get_name();

/**
 * @test Test function for player_name getting
 * @pre Player
 * @post Player_name == Supplied name
 */
void test2_player_get_name();

/**
 * @test Test function for player_name setting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_set_name();

/**
 * @test Test function for player_name setting
 * @pre Player
 * @post Output == OK
 */
void test2_player_set_name();

/**
 * @test Test function for player_health getting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_get_health();

/**
 * @test Test function for player_health getting
 * @pre Player
 * @post Player_health == Supplied health
 */
void test2_player_get_health();

/**
 * @test Test function for player_health setting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_set_health();

/**
 * @test Test function for player_health setting
 * @pre Player
 * @post Output == OK
 */
void test2_player_set_health();

/**
 * @test Test function for player print
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_print();

/**
 * @test Test function for player print
 * @pre Player
 * @post Output == OK
 */
void test2_player_print();

/**
 * @test Test function for player inv cap setting
 * @pre Player NULL
 * @post Output == ERROR
 */
void test1_player_set_inv_cap();

/**
 * @test Test function for player inv cap setting
 * @pre Player
 * @post Output == OK
 */
void test2_player_set_inv_cap();

#endif
