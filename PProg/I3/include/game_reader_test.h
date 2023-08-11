/**
 * @brief It declares the tests for the game reader module
 *
 * @file game_reader_test.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 09-04-2023
 * @copyright GNU Public License
 */

#ifndef GAME_READER_TEST_H
#define GAME_READER_TEST_H

/**
 * @brief sample data filename for testing purpose
*/
#define TEST_FILENAME "test.dat"

/**
 * @brief sample wrong data filename for testing purpose
*/
#define TEST_WRONG_FILENAME "data.dat"

/**
 * @test test game reader load of spaces
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
*/
void test1_game_reader_load_spaces();

/**
 * @test test game reader load of spaces
 * @pre NULL, TEST_FILENAME
 * @post ERROR
*/
void test2_game_reader_load_spaces();

/**
 * @test test game reader load of spaces
 * @pre Pointer to game, NULL
 * @post ERROR
*/
void test3_game_reader_load_spaces();

/**
 * @test test game reader load of spaces
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
*/
void test4_game_reader_load_spaces();

/**
 * @test test game reader load of objects
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
*/
void test1_game_reader_load_objects();

/**
 * @test test game reader load of objects
 * @pre NULL, TEST_FILENAME
 * @post ERROR
*/
void test2_game_reader_load_objects();

/**
 * @test test game reader load of objects
 * @pre Pointer to game, NULL
 * @post ERROR
*/
void test3_game_reader_load_objects();

/**
 * @test test game reader load of objects
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
*/
void test4_game_reader_load_objects();

/**
 * @test test game reader load of player
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
*/
void test1_game_reader_load_player();

/**
 * @test test game reader load of player
 * @pre NULL, TEST_FILENAME
 * @post ERROR
*/
void test2_game_reader_load_player();

/**
 * @test test game reader load of player
 * @pre Pointer to game, NULL
 * @post ERROR
*/
void test3_game_reader_load_player();

/**
 * @test test game reader load of player
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
*/
void test4_game_reader_load_player();

/**
 * @test test game reader load of enemies
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
*/
void test1_game_reader_load_enemies();

/**
 * @test test game reader load of enemies
 * @pre NULL, TEST_FILENAME
 * @post ERROR
*/
void test2_game_reader_load_enemies();

/**
 * @test test game reader load of enemies
 * @pre Pointer to game, NULL
 * @post ERROR
*/
void test3_game_reader_load_enemies();

/**
 * @test test game reader load of enemies
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
*/
void test4_game_reader_load_enemies();

/**
 * @test test game reader load of links
 * @pre Pointer to game, TEST_FILENAME
 * @post OK
*/
void test1_game_reader_load_links();

/**
 * @test test game reader load of links
 * @pre NULL, TEST_FILENAME
 * @post ERROR
*/
void test2_game_reader_load_links();

/**
 * @test test game reader load of links
 * @pre Pointer to game, NULL
 * @post ERROR
*/
void test3_game_reader_load_links();

/**
 * @test test game reader load of links
 * @pre Pointer to game, TEST_WRONG_FILENAME
 * @post ERROR
*/
void test4_game_reader_load_links();

#endif