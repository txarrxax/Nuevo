/**
 * @brief It declares the tests for the game reader module
 *
 * @file game_management_test.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 09-04-2023
 * @copyright GNU Public License
 */

#ifndef game_management_TEST_H
#define game_management_TEST_H

/**
 * @brief sample data filename for testing purpose
 */
#define TEST_FILENAME "test.dat"

/**
 * @brief sample wrong data filename for testing purpose
 */
#define TEST_WRONG_FILENAME "data.dat"

/**
 * @brief sample data filename for testing purpose
 */
#define SAVE_FILE "save.dat"

/**
 * @test test game reader load of spaces
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
 */
void test1_game_management_load_spaces();

/**
 * @test test game reader load of spaces
 * @pre NULL, TEST_FILENAME
 * @post ERROR
 */
void test2_game_management_load_spaces();

/**
 * @test test game reader load of spaces
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_load_spaces();

/**
 * @test test game reader load of spaces
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
 */
void test4_game_management_load_spaces();

/**
 * @test test game reader load of objects
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
 */
void test1_game_management_load_objects();

/**
 * @test test game reader load of objects
 * @pre NULL, TEST_FILENAME
 * @post ERROR
 */
void test2_game_management_load_objects();

/**
 * @test test game reader load of objects
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_load_objects();

/**
 * @test test game reader load of objects
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
 */
void test4_game_management_load_objects();

/**
 * @test test game reader load of player
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
 */
void test1_game_management_load_player();

/**
 * @test test game reader load of player
 * @pre NULL, TEST_FILENAME
 * @post ERROR
 */
void test2_game_management_load_player();

/**
 * @test test game reader load of player
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_load_player();

/**
 * @test test game reader load of player
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
 */
void test4_game_management_load_player();

/**
 * @test test game reader load of enemies
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
 */
void test1_game_management_load_enemies();

/**
 * @test test game reader load of enemies
 * @pre NULL, TEST_FILENAME
 * @post ERROR
 */
void test2_game_management_load_enemies();

/**
 * @test test game reader load of enemies
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_load_enemies();

/**
 * @test test game reader load of enemies
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
 */
void test4_game_management_load_enemies();

/**
 * @test test game reader load of links
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
 */
void test1_game_management_load_links();

/**
 * @test test game reader load of links
 * @pre NULL, TEST_FILENAME
 * @post ERROR
 */
void test2_game_management_load_links();

/**
 * @test test game reader load of links
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_load_links();

/**
 * @test test game reader load of links
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
 */
void test4_game_management_load_links();

/**
 * @test test game reader save spaces
 * @pre Pointer to game, SAVE_FILE
 * @post OK
 */
void test1_game_management_save_spaces();

/**
 * @test test game reader save spaces
 * @pre NULL, SAVE_FILE
 * @post ERROR
 */
void test2_game_management_save_spaces();

/**
 * @test test game reader save spaces
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_save_spaces();

/**
 * @test test game reader save objects
 * @pre Pointer to game, SAVE_FILE
 * @post OK
 */
void test1_game_management_save_objects();

/**
 * @test test game reader save objects
 * @pre NULL, SAVE_FILE
 * @post ERROR
 */
void test2_game_management_save_objects();

/**
 * @test test game reader save objects
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_save_objects();

/**
 * @test test game reader save player
 * @pre Pointer to game, SAVE_FILE
 * @post OK
 */
void test1_game_management_save_player();

/**
 * @test test game reader save player
 * @pre NULL, SAVE_FILE
 * @post ERROR
 */
void test2_game_management_save_player();

/**
 * @test test game reader save player
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_save_player();

/**
 * @test test game reader save enemies
 * @pre Pointer to game, SAVE_FILE
 * @post OK
 */
void test1_game_management_save_enemies();

/**
 * @test test game reader save enemies
 * @pre NULL, SAVE_FILE
 * @post ERROR
 */
void test2_game_management_save_enemies();

/**
 * @test test game reader save enemies
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_save_enemies();

/**
 * @test test game reader save links
 * @pre Pointer to game, SAVE_FILE
 * @post OK
 */
void test1_game_management_save_links();

/**
 * @test test game reader save links
 * @pre NULL, SAVE_FILE
 * @post ERROR
 */
void test2_game_management_save_links();

/**
 * @test test game reader save links
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test3_game_management_save_links();

#endif