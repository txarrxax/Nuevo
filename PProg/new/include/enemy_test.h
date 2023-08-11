/**
 * @brief It declares the tests for the enemy module
 *
 * @file enemy_test.h
 * @author Diego Fernández
 * @version 2.0
 * @date 07-03-2023
 * @copyright GNU Public License
 */

#include <types.h>
#include <test.h>
#include <enemy.h>

/**
 * @brief sample id for testing purposes
 */
#define TEST_ID 499

/**
 * @brief sample name for testing purposes
 */
#define TEST_NAME "Alan"

/**
 * @brief sample health points for testing purposes
 */
#define TEST_HEALTH 100

/**
 * @brief sample strenght points for testing purposes
 */
#define TEST_STRENGTH 20

/**
 * @test test enemy creation
 * @post Non NULL pointer to enemy
 */
void test1_enemy_create();

/**
 * @test test enemy creation
 * @post Pointer to enemy with default attributes
 */
void test2_enemy_create();

/**
 * @test test freeing of memory allocated for enemy
 * @pre NULL pointer
 * @post Output == ERROR
 */
void test1_enemy_destroy();

/**
 * @test test freeing of memory allocated for enemy
 * @pre Pointer to enemy
 * @post Output == OK if the memory for the enemy was successfully allocated,
 * output == ERROR otherwise
 */
void test2_enemy_destroy();

/**
 * @test test enemy id getter
 * @pre NULL pointer
 * @post Output == NO_ID
 */
void test1_enemy_get_id();

/**
 * @test test enemy id getter
 * @pre Pointer to enemy with an id initialized to TEST_ID
 * @post Output == TEST_ID
 */
void test2_enemy_get_id();

/**
 * @test test enemy id setter
 * @pre NULL pointer, TEST_ID
 * @post Output == ERROR
 */
void test1_enemy_set_id();

/**
 * @test test enemy id setter
 * @pre pointer to enemy, NO_ID
 * @post Output == ERROR
 */
void test2_enemy_set_id();

/**
 * @test test enemy location getter
 * @pre NULL pointer
 * @post Output == NO_ID
 */
void test1_enemy_get_location();

/**
 * @test test enemy location getter
 * @pre pointer to enemy with location id initialized to TEST_ID
 * @post Output == TEST_ID
 */
void test2_enemy_get_location();

/**
 * @test test enemy location setter
 * @pre NULL pointer, TEST_ID
 * @post Output == ERROR
 */
void test1_enemy_set_location();

/**
 * @test test enemy location setter
 * @pre pointer to enemy, NO_ID
 * @post Output == ERROR
 */
void test2_enemy_set_location();

/**
 * @test test enemy name getter
 * @pre NULL pointer
 * @post Output == NULL
 */
void test1_enemy_get_name();

/**
 * @test test enemy name getter
 * @pre pointer to enemy with name initialized to TEST_NAME
 * @post Non null pointer to a string identical to TEST_NAME
 */
void test2_enemy_get_name();

/**
 * @test test enemy name setter
 * @pre NULL pointer, TEST_NAME
 * @post Output == ERROR
 */
void test1_enemy_set_name();

/**
 * @test test enemy name setter
 * @pre pointer to enemy, NULL pointer
 * @post Output == ERROR
 */
void test2_enemy_set_name();

/**
 * @test test enemy health getter
 * @pre NULL pointer
 * @post Output == -1
 */
void test1_enemy_get_health();

/**
 * @test test enemy health getter
 * @pre pointer to enemy with health initialized to TEST_HEALTH
 * @post Output == TEST_HEALTH
 */
void test2_enemy_get_health();

/**
 * @test test enemy health setter
 * @pre NULL pointer, TEST_HEALTH
 * @post Output == ERROR
 */
void test1_enemy_set_health();

/**
 * @test enemy health setter
 * @pre pointer to enemy, TEST_HEALTH
 * @post Output == OK
 */
void test2_enemy_set_health();

/**
 * @test test enemy printer
 * @pre NULL pointer
 * @post Output == ERROR
 */
void test1_enemy_print();

/**
 * @test test enemy printer
 * @pre pointer to enemy
 * @post Output == OK
 */
void test2_enemy_print();

/**
 * @test test enemy strength getter
 * @pre NULL pointer
 * @post Output == 0
 */
void test1_enemy_get_strength();

/**
 * @test test enemy strength getter
 * @pre pointer to enemy with health initialized to TEST_HEALTH
 * @post Output == TEST_STRENGTH
 */
void test2_enemy_get_strength();

/**
 * @test test enemy strength setter
 * @pre NULL pointer
 * @post Output == ERROR
 */
void test1_enemy_set_strength();

/**
 * @test enemy strenght setter
 * @pre pointer to enemy, TEST_STRENGTH
 * @post Output == OK
 */
void test2_enemy_set_strength();
