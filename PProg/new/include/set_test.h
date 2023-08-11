/**
 * @brief It declares the tests for the set module
 *
 * @file set_test.h
 * @author Álvaro Grande
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @brief sample id for testing purposes
 */
#define TEST_ID 5

/**
 * @test Test set creation
 * @pre Set ID
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @pre Set ID
 * @post Set_ID == Supplied Set Id
 */
void test2_set_create();

/**
 * @brief Test set free
 * @pre Pointer to set
 * @post OK
 */
void test1_set_destroy();

/**
 * @brief Test set free
 * @pre NULL
 * @post ERROR
 */
void test2_set_destroy();

/**
 * @test Test function set_is_empty
 * @pre Empty set
 * @post Output == TRUE
 */
void test1_set_is_empty();

/**
 * @test Test function set_is_empty
 * @pre Set ID
 * @post Output == FALSE
 */
void test2_set_is_empty();

/**
 * @test Test function for set addition
 * @pre Set ID
 * @post Set_id == Supplied Set Id
 */
void test1_set_add();

/**
 * @test Test function for set addition
 * @pre Set ID
 * @post Output == ERROR
 */
void test2_set_add();

/**
 * @test Test function for set deletion
 * @pre Set ID
 * @post Set_id deleted == Supplied Set Id
 */
void test1_set_del();

/**
 * @test Test function for set deletion
 * @pre Set ID
 * @post Output == ERROR
 */
void test2_set_del();

/**
 * @test Test function for set printing
 * @pre Set ID
 * @post Set printed == Supplied Set
 */
void test1_set_print();

/**
 * @test Test function for set printing
 * @pre Set = NULL
 * @post Output == ERROR
 */
void test2_set_print();

/**
 * @test Test funtion for set_size getting
 * @pre Set = NULL
 * @post Output == -1
 */
void test1_set_get_size();

/**
 * @test Test funtion for set_size getting
 * @pre Set ID (empty set)
 * @post Output == 0
 */
void test2_set_get_size();

/**
 * @test Test funtion for set_ids getting
 * @pre Set = NULL
 * @post Output == ERROR
 */
void test1_set_get_ids();

/**
 * @test Test funtion for set_ids getting
 * @pre Set ID
 * @post Ids != NO_ID
 */
void test2_set_get_ids();

/**
 * @test Test funtion for set_has_id
 * @pre Set = NULL
 * @post Output == FALSE
 */
void test1_set_has_id();

/**
 * @test Test funtion for set_has_id
 * @pre Id == NO_ID
 * @post Output == FALSE
 */
void test2_set_has_id();

#endif
