/**
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Álvaro Grande
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @brief sample id for testing purposes
 */
#define TEST_ID 5

/**
 * @test Test space creation
 * @pre Space ID
 * @post Non NULL pointer to space
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL)
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_id getting
 * @pre Space ID
 * @post Output == OK
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre Space = NULL
 * @post Output == ERROR
 */
void test2_space_get_id();

/**
 * @test Test function for space_name getting
 * @pre Space ID
 * @pre space_name = "adios"
 * @post space_name == "adios"
 */
void test1_space_get_name();

/**
 * @test Test function for space_name setting
 * @pre Space = NULL
 * @post Output == NULL
 */
void test2_space_get_name();

/**
 * @test Test space_object adding
 * @pre Space ID
 * @post Output == OK
 */
void test1_space_add_object();

/**
 * @test Test space_object adding
 * @pre Space  = NULL
 * @post Output == ERROR
 */
void test2_space_add_object();

/**
 * @test Test space_object deletion
 * @pre Space ID
 * @post Output == OK
 */
void test1_space_del_object();

/**
 * @test Test space_object deletion
 * @pre Space = NULL
 * @post Output == ERROR
 */
void test2_space_del_object();

/**
 * @test Test function space_has_object
 * @pre Space ID
 * @pre space_object = TEST_ID
 * @post Output == OK
 */
void test1_space_has_object();

/**
 * @test Test function space_has_object
 * @pre Space = NULL
 * @post Output == ERROR
 */
void test2_space_has_object();

/**
 * @test Test function for space_description setting
 * @pre Space ID
 * @pre space_description = DESC_SAMPLE
 * @post Output == OK
 */
void test1_space_set_description();

/**
 * @test Test function for space_description setting
 * @pre Space ID
 * @pre space_description = NULL
 * @post Output == ERROR
 */
void test2_space_set_description();

/**
 * @test Test function for space_description setting
 * @pre Space = NULL
 * @pre space_description = DESC_SAMPLE
 * @post Output == ERROR
 */
void test3_space_set_description();

/**
 * @test Test function for space_description getting
 * @pre Space ID
 * @pre space_description = DESC_SAMPLE
 * @post space_description == DESC_SAMPLE
 */
void test1_space_get_description();

/**
 * @test Test function for space_description getting
 * @pre Space = NULL
 * @pre space_description = DESC_SAMPLE
 * @post Output = ERROR
 */
void test2_space_get_description();

#endif
