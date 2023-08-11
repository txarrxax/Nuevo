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
 * @brief Test object free
 * @pre Pointer to object
 * @post OK
 */
void test1_object_destroy();

/**
 * @brief Test object free
 * @pre NULL
 * @post ERROR
 */
void test2_object_destroy();

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

/**
 * @brief Test function for object_hidden getting
 * @pre Object NULL
 * @post Output == TRUE
 */
void test1_object_get_hidden();

/**
 * @brief Test function for object _hidden getting
 * @pre Object
 * @post Object_hidden = Default object_hidden
 */
void test2_object_get_hidden();

/**
 * @brief Test function for object_hidden setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_hidden();

/**
 * @brief Test function for object_hidden setting
 * @pre Object
 * @post Object_hidden = Supplied object_hidden
 */
void test2_object_set_hidden();

/**
 * @brief Test function for object_movable getting
 * @pre Object NULL
 * @post Output == FALSE
 */
void test1_object_get_movable();

/**
 * @brief Test function for object_movable getting
 * @pre Object
 * @post Object_movable = Default object_movable
 */
void test2_object_get_movable();

/**
 * @brief Test function for object_movable setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_movable();

/**
 * @brief Test function for object_movable setting
 * @pre Object
 * @post Object_movable = Supplied object_movable
 */
void test2_object_set_movable();

/**
 * @brief Test function for object_dependency getting
 * @pre Object NULL
 * @post Output == NO_ID
 */
void test1_object_get_dependency();

/**
 * @brief Test function for object_dependency getting
 * @pre Object
 * @post Object_dependency = Default object_dependency
 */
void test2_object_get_dependency();

/**
 * @brief Test function for object_dependency setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_dependency();

/**
 * @brief Test function for object_dependency setting
 * @pre Object
 * @post Object_dependency = Supplied object_dependency
 */
void test2_object_set_dependency();

/**
 * @brief Test function for object_open getting
 * @pre Object NULL
 * @post Output == NO_ID
 */
void test1_object_get_open();

/**
 * @brief Test function for object_open getting
 * @pre Object
 * @post Object_open = Default object_open
 */
void test2_object_get_open();

/**
 * @brief Test function for object_open setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_open();

/**
 * @brief Test function for object_open setting
 * @pre Object
 * @post Object_open = Supplied object_open
 */
void test2_object_set_open();

/**
 * @brief Test function for object_illuminate getting
 * @pre Object NULL
 * @post Output == FALSE
 */
void test1_object_get_illuminate();

/**
 * @brief Test function for object_illuminate getting
 * @pre Object
 * @post Object_iluminate = Default object_illuminate
 */
void test2_object_get_illuminate();

/**
 * @brief Test function for object_illuminate setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_illuminate();

/**
 * @brief Test function for object_illuminate setting
 * @pre Object
 * @post Object_illuminate = Supplied object_illuminate
 */
void test2_object_set_illuminate();

/**
 * @brief Test function for object_turnedon getting
 * @pre Object NULL
 * @post Output == FALSE
 */
void test1_object_get_turnedon();

/**
 * @brief Test function for object_turnedon getting
 * @pre Object
 * @post Object_turnedon = Default object_turnedon
 */
void test2_object_get_turnedon();

/**
 * @brief Test function for object_turnedon setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_turnedon();

/**
 * @brief Test function for object_turnedon setting
 * @pre Object
 * @post Object_turnedon = Supplied object_turnedon
 */
void test2_object_set_turnedon();

/**
 * @brief Test function for object_stats getting
 * @pre Object NULL
 * @post Output == FALSE
 */
void test1_object_get_stats();

/**
 * @brief Test function for object_stats getting
 * @pre Object
 * @post Object_stats = Default object_stats
 */
void test2_object_get_stats();

/**
 * @brief Test function for object_stats setting
 * @pre Object NULL
 * @post Output == ERROR
 */
void test1_object_set_stats();

/**
 * @brief Test function for object_stats setting
 * @pre Object
 * @post Object_stats = Supplied object_stats
 */
void test2_object_set_stats();

#endif