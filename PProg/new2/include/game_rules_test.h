/**
 * @brief It implements the tests for the game rules module
 *
 * @file game_rules_test.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 04-05-2023
 * @copyright GNU Public License
 */

#ifndef GAME_RULES_TEST_H_
#define GAME_RULES_TEST_H_

/**
 * @brief sample int for testing purpose
 */
#define INT 1

/**
 * @brief sample data filename for testing purpose
 */
#define FILE_NAME "test.dat"

/**
 * @brief test game rules creation
 * @pre Pointer to game
 * @post Pointer to grules
 */
void test1_game_rules_init();

/**
 * @brief test game rules creation
 * @pre NULL
 * @post NULL
 */
void test2_game_rules_init();

/**
 * @brief test game rules creation from file
 * @pre Pointer to game, FILE_NAME
 * @post Pointer to grules
 */
void test1_game_rules_init_from_file();

/**
 * @brief test game rules creation from file
 * @pre Pointer to game, NULL
 * @post NULL
 */
void test2_game_rules_init_from_file();

/**
 * @brief test game rules creation from file
 * @pre NULL, FILE_NAME
 * @post NULL
 */
void test3_game_rules_init_from_file();

/**
 * @brief test game rules free
 * @pre Pointer to grules
 * @post OK
 */
void test1_game_rules_destroy();

/**
 * @brief test game rules free
 * @pre NULL
 * @post ERROR
 */
void test2_game_rules_destroy();

/**
 * @brief test game rules implementation
 * @pre Pointer to game, Pointer to grules
 * @post OK
 */
void test1_game_rules_implement();

/**
 * @brief test game rules implementation
 * @pre Pointer to game, NULL
 * @post ERROR
 */
void test2_game_rules_implement();

/**
 * @brief test game rules implementation
 * @pre NULL, Pointer to grules
 * @post ERROR
 */
void test3_game_rules_implement();

/**
 * @brief test game rules reset
 * @pre Pointer to grules
 * @post OK
 */
void test1_game_rules_reset_rules();

/**
 * @brief test game rules reset
 * @pre NULL
 * @post ERROR
 */
void test2_game_rules_reset_rules();

/**
 * @brief test game rules rule getter
 * @pre Pointer to grules, -1
 * @post NULL
 */
void test1_game_rules_get_rule();

/**
 * @brief test game rules rule getter
 * @pre NULL, INT
 * @post NULL
 */
void test2_game_rules_get_rule();

/**
 * @brief test game rules number of rules getter
 * @pre Pointer to grules
 * @post 0
 */
void test1_game_rules_get_num_rules();

/**
 * @brief test game rules number of rules getter
 * @pre NULL
 * @post -1
 */
void test2_game_rules_get_num_rules();

#endif
