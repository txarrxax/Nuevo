/**
 * @brief It declares the tests for the enemy module
 *
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 27-02-2023
 * @copyright GNU Public License
 */

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

/**
 * @test Test enemy creation
 * @pre Enemy ID
 * @post Non NULL pointer to enemy
 */
void test1_enemy_create();
void test2_enemy_create();

void test1_enemy_get_id();
void test2_enemy_get_id();

void test1_enemy_get_location();
void test2_enemy_get_location();

void test1_enemy_get_name();
void test2_enemy_get_name();

void test1_enemy_get_health();
void test2_enemy_get_health();

void test1_enemy_set_id();
void test2_enemy_set_id();
void test3_enemy_set_id();

void test1_enemy_set_location();
void test2_enemy_set_location();
void test3_enemy_set_location();

void test1_enemy_set_name();
void test2_enemy_set_name();
void test3_enemy_set_name();

void test1_enemy_set_health();
void test2_enemy_set_health();
void test3_enemy_set_health();

#endif