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
#define MAX_TESTS 46

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
  int all  = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all  = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  if (all || test == 3) test1_object_destroy();
  if (all || test == 4) test2_object_destroy();
  if (all || test == 5) test1_object_get_id();
  if (all || test == 6) test2_object_get_id();
  if (all || test == 7) test1_object_set_id();
  if (all || test == 8) test2_object_set_id();
  if (all || test == 9) test1_object_get_name();
  if (all || test == 10) test2_object_get_name();
  if (all || test == 11) test1_object_set_name();
  if (all || test == 12) test2_object_set_name();
  if (all || test == 13) test1_object_get_desc();
  if (all || test == 14) test2_object_get_desc();
  if (all || test == 15) test1_object_set_desc();
  if (all || test == 16) test2_object_set_desc();
  if (all || test == 17) test1_object_print();
  if (all || test == 18) test2_object_print();
  if (all || test == 19) test1_object_get_hidden();
  if (all || test == 20) test2_object_get_hidden();
  if (all || test == 21) test1_object_set_hidden();
  if (all || test == 22) test2_object_set_hidden();
  if (all || test == 23) test1_object_get_movable();
  if (all || test == 24) test2_object_get_movable();
  if (all || test == 25) test1_object_set_movable();
  if (all || test == 26) test2_object_set_movable();
  if (all || test == 27) test1_object_get_dependency();
  if (all || test == 28) test2_object_get_dependency();
  if (all || test == 29) test1_object_set_dependency();
  if (all || test == 30) test2_object_set_dependency();
  if (all || test == 31) test1_object_get_open();
  if (all || test == 32) test2_object_get_open();
  if (all || test == 33) test1_object_set_open();
  if (all || test == 34) test2_object_set_open();
  if (all || test == 35) test1_object_get_illuminate();
  if (all || test == 36) test2_object_get_illuminate();
  if (all || test == 37) test1_object_set_illuminate();
  if (all || test == 38) test2_object_set_illuminate();
  if (all || test == 39) test1_object_get_turnedon();
  if (all || test == 40) test2_object_get_turnedon();
  if (all || test == 41) test1_object_set_turnedon();
  if (all || test == 42) test2_object_set_turnedon();
  if (all || test == 43) test1_object_get_stats();
  if (all || test == 44) test2_object_set_stats();
  if (all || test == 45) test1_object_set_stats();
  if (all || test == 46) test2_object_set_stats();

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

void test1_object_destroy() {
  Object *o = object_create();

  PRINT_TEST_RESULT(object_destroy(o) == OK);
}

void test2_object_destroy() {
  PRINT_TEST_RESULT(object_destroy(NULL) == ERROR);
}

void test1_object_get_id() {
  PRINT_TEST_RESULT(object_get_id(NULL) == NO_ID);
}

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

void test1_object_print() {
  PRINT_TEST_RESULT(object_print(NULL) == ERROR);
}

void test2_object_print() {
  Object *o = object_create();

  PRINT_TEST_RESULT(object_print(o) != ERROR);
  object_destroy(o);
}

void test1_object_get_hidden() {
  PRINT_TEST_RESULT(object_get_hidden(NULL) == TRUE);
}

void test2_object_get_hidden() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_hidden(object) == TRUE);
  object_destroy(object);
}

void test1_object_set_hidden() {
  PRINT_TEST_RESULT(object_set_hidden(NULL, TRUE) == ERROR);
}

void test2_object_set_hidden() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_hidden(object, FALSE) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    object_destroy(object);
    return;
  }

  PRINT_TEST_RESULT(object_get_hidden(object) == FALSE);
  object_destroy(object);
}

void test1_object_get_movable() {
  PRINT_TEST_RESULT(object_get_movable(NULL) == FALSE);
}

void test2_object_get_movable() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_movable(object) == FALSE);
  object_destroy(object);
}

void test1_object_set_movable() {
  PRINT_TEST_RESULT(object_set_movable(NULL, TRUE) == ERROR);
}

void test2_object_set_movable() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_movable(object, TRUE) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    object_destroy(object);
    return;
  }

  PRINT_TEST_RESULT(object_get_movable(object) == TRUE);
  object_destroy(object);
}

void test1_object_get_dependency() {
  PRINT_TEST_RESULT(object_get_dependency(NULL) == NO_ID);
}

void test2_object_get_dependency() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_dependency(object) == NO_ID);
  object_destroy(object);
}

void test1_object_set_dependency() {
  PRINT_TEST_RESULT(object_set_dependency(NULL, TEST_OBJ_ID) == ERROR);
}

void test2_object_set_dependency() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_dependency(object, TEST_OBJ_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    object_destroy(object);
    return;
  }

  PRINT_TEST_RESULT(object_get_dependency(object) == TEST_OBJ_ID);
  object_destroy(object);
}

void test1_object_get_open() {
  PRINT_TEST_RESULT(object_get_open(NULL) == NO_ID);
}

void test2_object_get_open() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_open(object) == NO_ID);
  object_destroy(object);
}

void test1_object_set_open() {
  PRINT_TEST_RESULT(object_set_open(NULL, TEST_OBJ_ID) == ERROR);
}

void test2_object_set_open() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_open(object, TEST_OBJ_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    object_destroy(object);
    return;
  }

  PRINT_TEST_RESULT(object_get_open(object) == TEST_OBJ_ID);
  object_destroy(object);
}

void test1_object_get_illuminate() {
  PRINT_TEST_RESULT(object_get_illuminate(NULL) == FALSE);
}

void test2_object_get_illuminate() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_illuminate(object) == FALSE);
  object_destroy(object);
}

void test1_object_set_illuminate() {
  PRINT_TEST_RESULT(object_set_illuminate(NULL, TRUE) == ERROR);
}

void test2_object_set_illuminate() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_illuminate(object, TRUE) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    object_destroy(object);
    return;
  }

  PRINT_TEST_RESULT(object_get_illuminate(object) == TRUE);
  object_destroy(object);
}

void test1_object_get_turnedon() {
  PRINT_TEST_RESULT(object_get_turnedon(NULL) == FALSE);
}

void test2_object_get_turnedon() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_turnedon(object) == FALSE);
  object_destroy(object);
}

void test1_object_set_turnedon() {
  PRINT_TEST_RESULT(object_set_turnedon(NULL, TRUE) == ERROR);
}

void test2_object_set_turnedon() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_turnedon(object, TRUE) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    object_destroy(object);
    return;
  }

  PRINT_TEST_RESULT(object_get_turnedon(object) == TRUE);
  object_destroy(object);
}

void test1_object_get_stats() {
  PRINT_TEST_RESULT(object_get_stats(NULL) == 0);
}

void test2_object_get_stats() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_stats(object) == 0);
  object_destroy(object);
}

void test1_object_set_stats() {
  PRINT_TEST_RESULT(object_set_stats(NULL, TEST_OBJ_ID) == ERROR);
}

void test2_object_set_stats() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (object_set_stats(object, TEST_OBJ_ID) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(object_get_stats(object) == TEST_OBJ_ID);
  object_destroy(object);
}