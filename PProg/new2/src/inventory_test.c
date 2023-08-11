/**
 * @brief It tests the inventory module
 * @file inventory_test.c
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */
#include <stdio.h>
#include <stdlib.h>
#include <inventory.h>
#include <inventory_test.h>
#include <test.h>

/**
 * @brief Max number of tests
 */
#define MAX_TESTS 29

/**
 * @brief Cap value for test
 */
#define TEST_CAP 3

/**
 * @brief Main function for INVENTORY unit tests
 */
int main(int argc, char **argv) {
  int test = 0;
  int all  = 1;

  if (argc < 2)
    printf("Running all test for module Inventory:\n");
  else {
    test = atoi(argv[1]);
    all  = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
    }
  }

  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  if (all || test == 3) test1_inventory_destroy();
  if (all || test == 4) test2_inventory_destroy();
  if (all || test == 5) test1_inventory_set_max_objs();
  if (all || test == 6) test2_inventory_set_max_objs();
  if (all || test == 7) test3_inventory_set_max_objs();
  if (all || test == 8) test1_inventory_get_max_objs();
  if (all || test == 9) test2_inventory_get_max_objs();
  if (all || test == 10) test1_inventory_add_object();
  if (all || test == 11) test2_inventory_add_object();
  if (all || test == 12) test3_inventory_add_object();
  if (all || test == 13) test1_inventory_del_object();
  if (all || test == 14) test2_inventory_del_object();
  if (all || test == 15) test3_inventory_del_object();
  if (all || test == 16) test4_inventory_del_object();
  if (all || test == 17) test1_inventory_print();
  if (all || test == 18) test1_inventory_print();
  if (all || test == 19) test1_inventory_is_empty();
  if (all || test == 20) test2_inventory_is_empty();
  if (all || test == 21) test3_inventory_is_empty();
  if (all || test == 22) test1_inventory_has_object();
  if (all || test == 23) test2_inventory_has_object();
  if (all || test == 24) test3_inventory_has_object();
  if (all || test == 25) test4_inventory_has_object();
  if (all || test == 26) test1_inventory_get_objs();
  if (all || test == 27) test2_inventory_get_objs();
  if (all || test == 28) test1_inventory_set_cap();
  if (all || test == 29) test2_inventory_set_cap();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_inventory_create() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(i != NULL);

  inventory_destroy(i);
}

void test2_inventory_create() {
  Inventory *i = inventory_create();

  PRINT_TEST_RESULT(inventory_get_max_objs(i) == DEF_SIZE);
  inventory_destroy(i);
}

void test1_inventory_destroy() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(inventory_destroy(i) == OK);
}

void test2_inventory_destroy() {
  PRINT_TEST_RESULT(inventory_destroy(NULL) == ERROR);
}

void test1_inventory_set_max_objs() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(inventory_set_max_objs(i, TEST_MAX_OBJS) == OK);

  inventory_destroy(i);
}

void test2_inventory_set_max_objs() {
  PRINT_TEST_RESULT(inventory_set_max_objs(NULL, TEST_MAX_OBJS) == ERROR);
}

void test3_inventory_set_max_objs() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(inventory_set_max_objs(i, -1) == ERROR);

  inventory_destroy(i);
}

void test1_inventory_get_max_objs() {
  Inventory *i;

  i = inventory_create();
  inventory_set_max_objs(i, TEST_MAX_OBJS);
  PRINT_TEST_RESULT(inventory_get_max_objs(i) == TEST_MAX_OBJS);

  inventory_destroy(i);
}

void test2_inventory_get_max_objs() {
  PRINT_TEST_RESULT(inventory_get_max_objs(NULL) == -1);
}

void test1_inventory_add_object() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(i, TEST_ID1) == OK);

  inventory_destroy(i);
}

void test2_inventory_add_object() {
  PRINT_TEST_RESULT(inventory_add_object(NULL, TEST_ID1) == ERROR);
}

void test3_inventory_add_object() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(i, NO_ID) == ERROR);

  inventory_destroy(i);
}

void test1_inventory_del_object() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_del_object(i, TEST_ID1) == OK);

  inventory_destroy(i);
}

void test2_inventory_del_object() {
  PRINT_TEST_RESULT(inventory_del_object(NULL, TEST_ID1) == ERROR);
}

void test3_inventory_del_object() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_del_object(i, TEST_ID2) == ERROR);

  inventory_destroy(i);
}

void test4_inventory_del_object() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_del_object(i, NO_ID) == ERROR);

  inventory_destroy(i);
}

void test1_inventory_print() {
  PRINT_TEST_RESULT(inventory_print(NULL) == ERROR);
}

void test2_inventory_print() {
  Inventory *i = inventory_create();
  if (!i) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(inventory_print(i) == OK);
  inventory_destroy(i);
}

void test1_inventory_is_empty() {
  Inventory *i;

  i = inventory_create();
  PRINT_TEST_RESULT(inventory_is_empty(i) == TRUE);

  inventory_destroy(i);
}

void test2_inventory_is_empty() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_is_empty(i) == FALSE);

  inventory_destroy(i);
}

void test3_inventory_is_empty() {
  PRINT_TEST_RESULT(inventory_is_empty(NULL) == FALSE);
}

void test1_inventory_has_object() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_has_object(i, TEST_ID1) == TRUE);

  inventory_destroy(i);
}

void test2_inventory_has_object() {
  PRINT_TEST_RESULT(inventory_has_object(NULL, TEST_ID1) == FALSE);
}

void test3_inventory_has_object() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_has_object(i, TEST_ID2) == FALSE);

  inventory_destroy(i);
}

void test4_inventory_has_object() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_has_object(i, NO_ID) == FALSE);

  inventory_destroy(i);
}

void test1_inventory_get_objs() {
  Inventory *i;

  i = inventory_create();
  inventory_add_object(i, TEST_ID1);
  PRINT_TEST_RESULT(inventory_get_objs(i) != NULL);

  inventory_destroy(i);
}

void test2_inventory_get_objs() {
  PRINT_TEST_RESULT(inventory_get_objs(NULL) == NULL);
}

void test1_inventory_set_cap() {
  PRINT_TEST_RESULT(inventory_set_cap(NULL, TEST_CAP) == ERROR);
}

void test2_inventory_set_cap() {
  Inventory *i = inventory_create();
  if (!i) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(inventory_set_cap(i, -1) == ERROR);
  inventory_destroy(i);
}
