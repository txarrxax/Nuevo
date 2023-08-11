/**
 * @brief It declares the tests for the set module
 *
 * @file set_test.c
 * @author Álvaro Grande
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <set_test.h>
#include <set.h>
#include <test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Total number of tests
 */
#define MAX_TESTS 14

/**
 * @brief Initial size of sets
 */
#define INIT_SIZE 4

/**
 * @brief Main function for SET unit tests.
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
    printf("Running all test for the module Set:\n");
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
    test1_set_create();
  if (all || test == 3)
    test1_set_add();
  if (all || test == 4)
    test2_set_add();
  if (all || test == 5)
    test1_set_del();
  if (all || test == 6)
    test2_set_del();
  if (all || test == 7)
    test1_set_is_empty();
  if (all || test == 8)
    test2_set_is_empty();
  if (all || test == 9)
    test1_set_print();
  if (all || test == 10)
    test2_set_print();

  if (all || test == 11)
    test1_set_get_size();
  if (all || test == 12)
    test2_set_get_size();
  if (all || test == 13)
    test1_set_get_ids();
  if (all || test == 14)
    test2_set_get_ids();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create() {
  int result;
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_create() {
  int result;
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = set_is_empty(s) == TRUE;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test1_set_add() {
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  set_add(s, TEST_ID);
  PRINT_TEST_RESULT(!set_is_empty(s));
  set_destroy(s);
}

void test2_set_add() {
  int result;
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = set_add(s, NO_ID);
  PRINT_TEST_RESULT(!result);
  set_destroy(s);
}

void test1_set_del() {
  int result;
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (set_add(s, TEST_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = set_del(s, TEST_ID);
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_del() {
  int result;
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (set_add(s, TEST_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = set_del(s, TEST_ID + 1);
  PRINT_TEST_RESULT(!result);
  set_destroy(s);
}

void test1_set_is_empty() {
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  PRINT_TEST_RESULT(set_is_empty(s));
  set_destroy(s);
}

void test2_set_is_empty() {
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (set_add(s, TEST_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  PRINT_TEST_RESULT(!set_is_empty(s));
  set_destroy(s);
}

void test1_set_print() {
  int result;
  Set *s;
  if (!(s = set_create())) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (set_add(s, TEST_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = set_print(s) == OK;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_print() {
  int result;
  result = set_print(NULL) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test1_set_get_size() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_size(s) == -1);
}

void test2_set_get_size() {
  Set *s = set_create();
  int result;
  if (!s)
    PRINT_TEST_RESULT(FALSE);

  result = set_get_size(s);
  PRINT_TEST_RESULT(result == 0);
  set_destroy(s);
}

void test1_set_get_ids() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_ids(s) == NULL);
}

void test2_set_get_ids() {
  Set *s = set_create();
  const Id *ids;
  int i = 0, result = 1;
  if (!s)
    PRINT_TEST_RESULT(FALSE);

  ids = set_get_ids(s);

  for (; i < INIT_SIZE; i++) {
    if (ids[i] != NO_ID)
      result = 0;
  }

  PRINT_TEST_RESULT(result);
  set_destroy(s);
}
