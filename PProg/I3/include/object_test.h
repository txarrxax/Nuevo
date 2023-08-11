/**
 * @brief It declares the tests for the object module
 *
 * @file object_test.h
 * @author Álvaro Grande
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @brief sample id for testing purposes
 */
#define TEST_OBJ_ID 5

/**
 * @brief sample name for testing purposes
 */
#define TEST_OBJ_NAME "obj"

/**
 * @brief sample name for testing purposes
 */
#define TEST_OBJ_DESC "desc"

/**
 * @brief Test object creation
 * @pre Object ID
 * @post Non NULL pointer to object
 */
void test1_object_create();

/**
 * @brief Test object creation
 * @pre Object ID
 * @post Object_ID == Supplied Object ID
 */
void test2_object_create();

/**
 * @brief Test function for object id getting
 * @pre Object NULL
 * @post Output == NO_ID
 */
void test1_object_get_id();

/**
 * @brief Test function for object id getting
 * @pre Object ID
 * @post Object_ID == Supplied Object ID
 */
void test2_object_get_id();

/**
 * @brief Test function for object id setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_id();

/**
 * @brief Test function for object id setting
 * @pre Object ID
 * @post Object_ID == Supplied Object ID
 */
void test2_object_set_id();

/**
 * @brief Test function for object name getting
 * @pre Object NULL
 * @post Output == NULL
 */
void test1_object_get_name();

/**
 * @brief Test function for object name getting
 * @pre Object
 * @post Object_name == Initialiced object_name
 */
void test2_object_get_name();

/**
 * @brief Test function for object name setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_name();

/**
 * @brief Test function for object name setting
 * @pre Object Name
 * @post Object_Name == Supplied Object Name
 */
void test2_object_set_name();

/**
 * @brief Test function for object desc getting
 * @pre Object NULL
 * @post Output == NULL
 */
void test1_object_get_desc();

/**
 * @brief Test function for object desc getting
 * @pre Object
 * @post Object_Desc == Supplied Object Desc
 */
void test2_object_get_desc();

/**
 * @brief Test duntion for object desc setting
 * @pre Object NULL
 * @post Object_ID == Supplied Object ID
 */
void test1_object_set_desc();

/**
 * @brief Test function for object desc setting
 * @pre Object ID
 * @post Object_ID == Supplied Object ID
 */
void test2_object_set_desc();

/**
 * @brief Test function for object print
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_print();

/**
 * @brief Test function for object print
 * @pre Object ID
 * @post Output == OK
 */
void test2_object_print();

#endif