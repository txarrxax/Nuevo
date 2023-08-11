/**
 * @brief It declares the tests for the inventory module
 *
 * @file inventory_test.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @brief sample max number of objects for testing purpose
*/
#define TEST_MAX_OBJS 5

/**
 * @brief sample id for testing purpose
*/
#define TEST_ID1 10

/**
 * @brief sample id for testing purpose
*/
#define TEST_ID2 20

/**
 * @test test inventory creation
 * @post Pointer to inventory with default attributes
*/
void test1_inventory_create();

/**
 * @test test inventory destruction
 * @pre Pointer to inventory
 * @post OK
*/
void test1_inventory_destroy();

/**
 * @test test inventory destruction
 * @pre NULL
 * @post ERROR
*/
void test2_inventory_destroy();

/**
 * @test test inventory max_objs setter
 * @pre Pointer to inventory, TEST_MAX_OBJS
 * @post OK
*/
void test1_inventory_set_max_objs();

/**
 * @test test inventory max_objs setter
 * @pre NULL, TEST_MAX_OBJS
 * @post ERROR
*/
void test2_inventory_set_max_objs();

/**
 * @test test inventory max_objs setter
 * @pre Pointer to inventory, -1
 * @post ERROR
*/
void test3_inventory_set_max_objs();

/**
 * @test test inventory max_objs getter
 * @pre Pointer to inventory
 * @post MAX_OBJS
*/
void test1_inventory_get_max_objs();

/**
 * @test test inventory max_objs getter
 * @pre NULL
 * @post -1
*/
void test2_inventory_get_max_objs();

/**
 * @test test inventory object adder
 * @pre Pointer to inventory, TEST_ID1
 * @post OK
*/
void test1_inventory_add_object();

/**
 * @test test inventory object adder
 * @pre NULL, TEST_ID1
 * @post ERROR
*/
void test2_inventory_add_object();

/**
 * @test test inventory object adder
 * @pre Pointer to inventory, NO_ID
 * @post ERROR
*/
void test3_inventory_add_object();

/**
 * @test test inventory object deleter
 * @pre Pointer to inventory, TEST_ID1
 * @post OK
*/
void test1_inventory_del_object();

/**
 * @test test inventory object deleter
 * @pre NULL, TEST_ID1
 * @post ERROR
*/
void test2_inventory_del_object();

/**
 * @test test inventory object deleter
 * @pre Pointer to inventory, TEST_ID2
 * @post ERROR
*/
void test3_inventory_del_object();

/**
 * @test test inventory object deleter
 * @pre Pointer to inventory, NO_ID
 * @post ERROR
*/
void test4_inventory_del_object();

/**
 * @test test inventory empty checker
 * @pre Pointer to empty inventory
 * @post TRUE
*/
void test1_inventory_is_empty();

/**
 * @test test inventory empty checker
 * @pre Pointer to not empty inventory
 * @post FALSE
*/
void test2_inventory_is_empty();

/**
 * @test test inventory empty checker
 * @pre NULL
 * @post TRUE
*/
void test3_inventory_is_empty();

/**
 * @test test inventory object checker
 * @pre Pointer to inventory, TEST_ID1
 * @post TRUE
*/
void test1_inventory_has_object();

/**
 * @test test inventory object checker
 * @pre Pointer to inventory, TEST_ID2
 * @post TRUE
*/
void test2_inventory_has_object();

/**
 * @test test inventory object checker
 * @pre NULL, TEST_ID1
 * @post TRUE
*/
void test3_inventory_has_object();

/**
 * @test test inventory object checker
 * @pre Pointer to inventory, NO_ID
 * @post TRUE
*/
void test4_inventory_has_object();

/**
 * @test test inventory objects getter
 * @pre Pointer to inventory
 * @post Pointer to a set of objects
*/
void test1_inventory_get_objs();

/**
 * @test test inventory objects getter
 * @pre NULL
 * @post NULL
*/
void test2_inventory_get_objs();

#endif