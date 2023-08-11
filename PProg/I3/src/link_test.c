/**
 * @brief It tests the link module
 *
 * @file link_test.c
 * @author Álvaro Grande
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <link.h>
#include <link_test.h>
#include <test.h>

/**
 * @brief Max number of tests
*/
#define MAX_TESTS 26

/**
 * @brief sample id for testing purpose
*/
#define TEST_LINK_ID 5

/**
 * @brief sample name for testing purpose
*/
#define TEST_LINK_NAME "LINK"

/**
 * @brief Main function for LINK unit tests
 */
int main(int argc, char **argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for the module Link:\n");
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
    test1_link_create();
  if (all || test == 2)
    test2_link_create();
  if (all || test == 3)
    test3_link_create();
  if (all || test == 4)
    test1_link_get_id();
  if (all || test == 5)
    test2_link_get_id();
  if (all || test == 6)
    test1_link_get_name();
  if (all || test == 7)
    test2_link_get_name();
  if (all || test == 8)
    test1_link_get_origin();
  if (all || test == 9)
    test2_link_get_origin();
  if (all || test == 10)
    test1_link_get_dest();
  if (all || test == 11)
    test2_link_get_dest();
  if (all || test == 12)
    test1_link_get_direction();
  if (all || test == 13)
    test2_link_get_direction();
  if (all || test == 14)
    test1_link_get_status();
  if (all || test == 15)
    test2_link_get_status();
  if (all || test == 16)
    test1_link_set_name();
  if (all || test == 16)
    test2_link_set_name();
  if (all || test == 17)
    test1_link_set_origin();
  if (all || test == 18)
    test2_link_set_origin();
  if (all || test == 19)
    test1_link_set_dest();
  if (all || test == 20)
    test2_link_set_dest();
  if (all || test == 21)
    test1_link_set_direction();
  if (all || test == 22)
    test2_link_set_direction();
  if (all || test == 23)
    test1_link_set_status();
  if (all || test == 24)
    test2_link_set_status();
  if (all || test == 25)
    test1_link_print();
  if (all || test == 26)
    test2_link_print();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link != NULL);
  link_destroy(link);
}

void test2_link_create() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_id(link) == TEST_LINK_ID);
  link_destroy(link);
}

void test3_link_create() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_origin(link) == NO_ID);
  link_destroy(link);
}

void test1_link_get_id() { PRINT_TEST_RESULT(link_get_id(NULL) == NO_ID); }

void test2_link_get_id() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_id(link) == TEST_LINK_ID);
  link_destroy(link);
}

void test1_link_get_name() { PRINT_TEST_RESULT(link_get_name(NULL) == NULL); }

void test2_link_get_name() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT((strcmp(link_get_name(link), "") == 0));
  link_destroy(link);
}

void test1_link_get_origin() {
  PRINT_TEST_RESULT(link_get_origin(NULL) == NO_ID);
}

void test2_link_get_origin() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_origin(link) == NO_ID);
  link_destroy(link);
}

void test1_link_get_dest() { PRINT_TEST_RESULT(link_get_dest(NULL) == NO_ID); }

void test2_link_get_dest() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_dest(link) == NO_ID);
  link_destroy(link);
}

void test1_link_get_direction() {
  PRINT_TEST_RESULT(link_get_direction(NULL) == U);
}

void test2_link_get_direction() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_direction(link) == U);
  link_destroy(link);
}

void test1_link_get_status() {
  PRINT_TEST_RESULT(link_get_status(NULL) == ERROR);
}

void test2_link_get_status() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_status(link) == ERROR);
  link_destroy(link);
}

void test1_link_set_name() {
  PRINT_TEST_RESULT(link_set_name(NULL, TEST_LINK_NAME) == ERROR);
}

void test2_link_set_name() {
  Link *link = link_create(TEST_LINK_ID);

  if (!link_set_name(link, TEST_LINK_NAME))
    PRINT_TEST_RESULT(FALSE);

  PRINT_TEST_RESULT(strcmp(link_get_name(link), TEST_LINK_NAME) == 0);
  link_destroy(link);
}

void test1_link_set_origin() {
  PRINT_TEST_RESULT(link_set_origin(NULL, TEST_LINK_ID) == ERROR);
}

void test2_link_set_origin() {
  Link *link = link_create(TEST_LINK_ID);

  link_set_origin(link, TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_origin(link) == TEST_LINK_ID);
  link_destroy(link);
}

void test1_link_set_dest() {
  PRINT_TEST_RESULT(link_set_dest(NULL, TEST_LINK_ID) == ERROR);
}

void test2_link_set_dest() {
  Link *link = link_create(TEST_LINK_ID);

  link_set_dest(link, TEST_LINK_ID);

  PRINT_TEST_RESULT(link_get_dest(link) == TEST_LINK_ID);
  link_destroy(link);
}

void test1_link_set_direction() {
  PRINT_TEST_RESULT(link_set_direction(NULL, N) == ERROR);
}

void test2_link_set_direction() {
  Link *link = link_create(TEST_LINK_ID);

  link_set_direction(link, N);

  PRINT_TEST_RESULT(link_get_direction(link) == N);
  link_destroy(link);
}

void test1_link_set_status() {
  PRINT_TEST_RESULT(link_set_status(NULL, OK) == ERROR);
}

void test2_link_set_status() {
  Link *link = link_create(TEST_LINK_ID);

  link_set_status(link, OK);

  PRINT_TEST_RESULT(link_get_status(link) == OK);
  link_destroy(link);
}

void test1_link_print() { PRINT_TEST_RESULT(link_print(NULL) == ERROR); }

void test2_link_print() {
  Link *link = link_create(TEST_LINK_ID);

  PRINT_TEST_RESULT(link_print(link) == OK);
  link_destroy(link);
}
