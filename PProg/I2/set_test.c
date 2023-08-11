/**
 * @brief It tests the set module
 * 
 * @file set_test.c
 * @author Miguel Angel Sacristan
 * @version 1.0
 * @date 03-03-2023
 * @copyright GNU Public License
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 16

/**
 * @brief Main function for ENEMY unit tests.
 */

int main (int argc, char** argv){
    int test = 0;
    int all = 1;

    if (argc < 2)
        printf("Running all test for module Set:\n");
    else{
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS){
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }
    if (all || test == 1) test1_set_create();
    if (all || test == 2) test1_set_addId();
    if (all || test == 3) test2_set_addId();
    if (all || test == 4) test3_set_addId();
    if (all || test == 5) test1_set_destroyId();
    if (all || test == 6) test2_set_destroyId();
    if (all || test == 7) test3_set_destroyId();
    if (all || test == 8) test1_set_destroyLastId();
    if (all || test == 9) test2_set_destroyLastId();
    if (all || test == 10) test1_set_isFull();
    if (all || test == 11) test2_set_isFull();
    if (all || test == 12) test1_set_checkId();
    if (all || test == 13) test2_set_checkId();
    if (all || test == 14) test3_set_checkId();
    if (all || test == 15) test1_set_getNumberOfElements();
    if (all || test == 16) test2_set_getNumberOfElements();
    

    PRINT_PASSED_PERCENTAGE;
    return 1;
}

void test1_set_create(){
    int result;
    Set *s;
    s = set_create();
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

void test1_set_addId() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_addId(s, 1) == OK);
    set_destroy(s);
}

void test2_set_addId() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_addId(s, 1) == ERROR);
}

void test3_set_addId() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_addId(s, NO_ID));
    set_destroy(s);
}

void test1_set_destroyId() {
    Set *s;
    s = set_create();
    set_addId(s, 1);
    PRINT_TEST_RESULT(set_destroyId(s, 1) == OK);
    set_destroy(s);
}

void test2_set_destroyId() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_destroyId(s, 1) == ERROR);
}

void test3_set_destroyId() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_destroyId(s, NO_ID) == ERROR);
    set_destroy(s);
}

void test1_set_destroyLastId() {
    Set *s;
    s = set_create();
    set_addId(s, 1);
    PRINT_TEST_RESULT(set_destroyLastId(s) == OK);
    set_destroy(s);
}

void test2_set_destroyLastId() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_destroyLastId(s) == ERROR);
}

void test1_set_isFull() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_isFull(s) == FALSE);
    set_destroy(s);
}

void test2_set_isFull() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_isFull(s) == FALSE);
}

void test1_set_checkId() {
    Set *s;
    s = set_create();
    set_addId(s, 2);
    PRINT_TEST_RESULT(set_checkId(s, 2) == TRUE);
    set_destroy(s);
}

void test2_set_checkId() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_checkId(s, 2) == FALSE);
}

void test3_set_checkId() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_checkId(s, NO_ID) == FALSE);
    set_destroy(s);
}

void test1_set_getNumberOfElements() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_getNumberOfElements(s) != -1);
    set_destroy(s);
}

void test2_set_getNumberOfElements() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_getNumberOfElements(s) == -1);
}