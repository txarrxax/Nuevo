/**
 * @brief It tests the enemy module
 * 
 * @file enemy_test.c
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 27-02-2023
 * @copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"
#include "enemy_test.h"
#include "test.h"

#define MAX_TESTS 22

/**
 * @brief Main function for ENEMY unit tests.
 */

int main (int argc, char** argv){
    int test = 0;
    int all = 1;

    if (argc < 2)
        printf("Running all test for module Enemy:\n");
    else{
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS){
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) test1_enemy_create();
    if (all || test == 2) test2_enemy_create();
    if (all || test == 3) test1_enemy_get_id();
    if (all || test == 4) test2_enemy_get_id();
    if (all || test == 5) test1_enemy_get_location();
    if (all || test == 6) test2_enemy_get_location();
    if (all || test == 7) test1_enemy_get_name();
    if (all || test == 8) test2_enemy_get_name();
    if (all || test == 9) test1_enemy_get_health();
    if (all || test == 10) test2_enemy_get_health();
    if (all || test == 11) test1_enemy_set_id();
    if (all || test == 12) test2_enemy_set_id();
    if (all || test == 13) test3_enemy_set_id();
    if (all || test == 14) test1_enemy_set_location();
    if (all || test == 15) test2_enemy_set_location();
    if (all || test == 16) test3_enemy_set_location();
    if (all || test == 17) test1_enemy_set_name();
    if (all || test == 18) test2_enemy_set_name();
    if (all || test == 19) test3_enemy_set_name();
    if (all || test == 20) test1_enemy_set_health();
    if (all || test == 21) test2_enemy_set_health();
    if (all || test == 22) test3_enemy_set_health();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_enemy_create(){
    int result;
    Enemy *e;
    e = enemy_create(1);
    result = e != NULL;
    PRINT_TEST_RESULT(result);
    enemy_destroy(e);
}

void test2_enemy_create(){
    Enemy *e;
    e = enemy_create(2);
    PRINT_TEST_RESULT(enemy_get_id(e) == 2);
    enemy_destroy(e);
}

void test1_enemy_get_id(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_get_id(e) == 1);
    enemy_destroy(e);
}

void test2_enemy_get_id(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_id(e) == NO_ID);
}

void test1_enemy_get_location(){
    Enemy *e;
    e = enemy_create(1);
    enemy_set_location(e, 1);
    PRINT_TEST_RESULT(enemy_get_location(e) == 1);
    enemy_destroy(e);
}

void test2_enemy_get_location(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_location(e) == NO_ID);
}

void test1_enemy_get_name(){
    Enemy *e;
    e = enemy_create(1);
    enemy_set_name(e, "enemy");
    PRINT_TEST_RESULT(strcmp(enemy_get_name(e), "enemy") == 0);
    enemy_destroy(e);
}

void test2_enemy_get_name(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_name(e) == NULL);
}

void test1_enemy_get_health(){
    Enemy *e;
    e = enemy_create(1);
    enemy_set_health(e, 5);
    PRINT_TEST_RESULT(enemy_get_health(e) == 5);
    enemy_destroy(e);
}

void test2_enemy_get_health(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_health(e) == -1);
}

void test1_enemy_set_id(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_id(e, 2) == OK);
    enemy_destroy(e);
}

void test2_enemy_set_id(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_id(e, 2) == ERROR);
}

void test3_enemy_set_id(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_id(e, NO_ID) == ERROR);
    enemy_destroy(e);
}

void test1_enemy_set_location(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_location(e, 1) == OK);
    enemy_destroy(e);
}

void test2_enemy_set_location(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_location(e, 1) == ERROR);
}

void test3_enemy_set_location(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_location(e, NO_ID) == ERROR);
    enemy_destroy(e);
}

void test1_enemy_set_name(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_name(e, "enemy") == OK);
    enemy_destroy(e);
}

void test2_enemy_set_name(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_name(e, "enemy") == ERROR);
}

void test3_enemy_set_name(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_name(e, NULL) == ERROR);
    enemy_destroy(e);
}

void test1_enemy_set_health(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_health(e, 10) == OK);
    enemy_destroy(e);
}

void test2_enemy_set_health(){
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_health(e, 10) == ERROR);
}

void test3_enemy_set_health(){
    Enemy *e;
    e = enemy_create(1);
    PRINT_TEST_RESULT(enemy_set_health(e, -1) == ERROR);
    enemy_destroy(e);
}