/**
 * @brief It tests object module
 *
 * @file object_test.c
 * @author Álvaro Grande
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <object_test.h>
#include <object.h>
#include <test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Total number of tests
 */
#define MAX_TESTS 16

/**
 * @brief Main function for SPACE unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1)
    test1_object_create();
  if (all || test == 2)
    test2_object_create();
  if (all || test == 3)
    test1_object_get_id();
  if (all || test == 4)
    test2_object_get_id();
  if (all || test == 5)
    test1_object_set_id();
  if (all || test == 6)
    test2_object_set_id();
  if (all || test == 7)
    test1_object_get_name();
  if (all || test == 8)
    test2_object_get_name();
  if (all || test == 9)
    test1_object_set_name();
  if (all || test == 10)
    test2_object_set_name();
  if (all || test == 11)
    test1_object_get_desc();
  if (all || test == 12)
    test2_object_get_desc();
  if (all || test == 13)
    test1_object_set_desc();
  if (all || test == 14)
    test2_object_set_desc();
  if (all || test == 15)
    test1_object_print();
  if (all || test == 16)
    test2_object_print();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_object_create() {
  Object *o = object_create();

  PRINT_TEST_RESULT(o != NULL);
  object_destroy(o);
}

void test2_object_create() {
  Object *o = object_create();

  PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
  object_destroy(o);
}

void test1_object_get_id() { PRINT_TEST_RESULT(object_get_id(NULL) == NO_ID); }

void test2_object_get_id() {
  Object *o = object_create();

  object_set_id(o, TEST_OBJ_ID);
  PRINT_TEST_RESULT(object_get_id(o) == TEST_OBJ_ID);
  object_destroy(o);
}

void test1_object_set_id() {
  PRINT_TEST_RESULT(object_set_id(NULL, TEST_OBJ_ID) == ERROR);
}

void test2_object_set_id() {
  Object *o = object_create();

  object_set_id(o, TEST_OBJ_ID);
  PRINT_TEST_RESULT(object_get_id(o) == TEST_OBJ_ID);
  object_destroy(o);
}

void test1_object_get_name() {
  PRINT_TEST_RESULT(object_get_name(NULL) == NULL);
}

void test2_object_get_name() {
  Object *o = object_create();

  object_set_name(o, TEST_OBJ_NAME);
  PRINT_TEST_RESULT(strcmp(object_get_name(o), TEST_OBJ_NAME) == 0);
  object_destroy(o);
}

void test1_object_set_name() {
  PRINT_TEST_RESULT(object_set_name(NULL, TEST_OBJ_NAME) == ERROR);
}

void test2_object_set_name() {
  Object *o = object_create();

  object_set_name(o, TEST_OBJ_NAME);
  PRINT_TEST_RESULT(strcmp(object_get_name(o), TEST_OBJ_NAME) == 0);
  object_destroy(o);
}

void test1_object_get_desc() {
  PRINT_TEST_RESULT(object_get_desc(NULL) == NULL);
}

void test2_object_get_desc() {
  Object *o = object_create();

  object_set_desc(o, TEST_OBJ_DESC);
  PRINT_TEST_RESULT(strcmp(object_get_desc(o), TEST_OBJ_DESC) == 0);
  object_destroy(o);
}

void test1_object_set_desc() {
  PRINT_TEST_RESULT(object_set_desc(NULL, TEST_OBJ_DESC) == ERROR);
}

void test2_object_set_desc() {
  Object *o = object_create();

  object_set_desc(o, TEST_OBJ_DESC);
  PRINT_TEST_RESULT(strcmp(object_get_desc(o), TEST_OBJ_DESC) == 0);
  object_destroy(o);
}

void test1_object_print() { PRINT_TEST_RESULT(object_print(NULL) == ERROR); }

void test2_object_print() {
  Object *o = object_create();

  PRINT_TEST_RESULT(object_print(o) != ERROR);
  object_destroy(o);
}
