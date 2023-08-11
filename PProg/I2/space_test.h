/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

#include "space.h"
#include "test.h"


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

void test1_space_set_name();
void test2_space_set_name();
void test3_space_set_name();

void test1_space_set_north();
void test2_space_set_north();

void test1_space_set_south();
void test2_space_set_south();

void test1_space_set_east();
void test2_space_set_east();

void test1_space_set_west();
void test2_space_set_west();

void test1_space_get_name();
void test2_space_get_name();

void test1_space_get_north();
void test2_space_get_north();

void test1_space_get_south();
void test2_space_get_south();

void test1_space_get_east();
void test2_space_get_east();

void test1_space_get_west();
void test2_space_get_west();

void test1_space_get_id();
void test2_space_get_id();

void test1_space_add_object();
void test2_space_add_object();
void test3_space_add_object();

void test1_space_destroy_object();
void test2_space_destroy_object();
void test3_space_destroy_object();

void test1_space_get_numberOfObjects();
void test2_space_get_numberOfObjects();

void test1_space_get_objects();
void test2_space_get_objects();

void test1_space_checkObject();
void test2_space_checkObject();
void test3_space_checkObject();

void test1_space_set_gDesc();
void test2_space_set_gDesc();
void test3_space_set_gDesc();

void test1_space_get_gDesc();
void test2_space_get_gDesc();

#endif