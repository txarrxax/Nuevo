/**
 * @brief It tests space module
 *
 * @file space_test.c
 * @author Álvaro Grande
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <space_test.h>
#include <space.h>
#include <test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Total number of tests
 */
#define MAX_TESTS 38

/**
 * @brief Length of the object descriptions
 */
#define ODESC_LEN 17

/**
 * @brief Expected description for odesc tests
 */
#define DESC_SAMPLE "|               |"

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

  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_destroy();
  if (all || test == 4) test2_space_destroy();
  if (all || test == 5) test1_space_set_name();
  if (all || test == 6) test2_space_set_name();
  if (all || test == 7) test3_space_set_name();
  if (all || test == 8) test1_space_get_name();
  if (all || test == 9) test2_space_get_name();
  if (all || test == 10) test1_space_get_id();
  if (all || test == 11) test2_space_get_id();
  if (all || test == 12) test1_space_add_object();
  if (all || test == 13) test2_space_add_object();
  if (all || test == 14) test1_space_del_object();
  if (all || test == 15) test2_space_del_object();
  if (all || test == 16) test1_space_has_object();
  if (all || test == 17) test2_space_has_object();
  if (all || test == 18) test1_space_print();
  if (all || test == 19) test2_space_print();
  if (all || test == 20) test1_space_set_description();
  if (all || test == 21) test2_space_set_description();
  if (all || test == 22) test3_space_set_description();
  if (all || test == 23) test1_space_get_description();
  if (all || test == 24) test2_space_get_description();
  if (all || test == 25) test1_space_set_ldescription();
  if (all || test == 26) test2_space_set_ldescription();
  if (all || test == 27) test3_space_set_ldescription();
  if (all || test == 28) test1_space_get_ldescription();
  if (all || test == 29) test2_space_get_ldescription();
  if (all || test == 30) test1_space_set_light();
  if (all || test == 31) test2_space_set_light();
  if (all || test == 32) test3_space_set_light();
  if (all || test == 33) test1_space_get_light();
  if (all || test == 34) test2_space_get_light();
  if (all || test == 35) test1_space_set_gdesc();
  if (all || test == 36) test2_space_set_gdesc();
  if (all || test == 37) test1_space_get_gdesc();
  if (all || test == 38) test2_space_get_gdesc();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int    result;
  Space *s;
  s      = space_create(TEST_ID);
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(TEST_ID);
  PRINT_TEST_RESULT(space_get_id(s) == TEST_ID);
  space_destroy(s);
}

void test1_space_destroy() {
  Space *s = space_create(TEST_ID);

  PRINT_TEST_RESULT(space_destroy(s) == OK);
}

void test2_space_destroy() {
  PRINT_TEST_RESULT(space_destroy(NULL) == ERROR);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(TEST_ID);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(TEST_ID);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_add_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s, TEST_ID) == ERROR);
}

void test2_space_add_object() {
  Space *s;
  s = space_create(TEST_ID);
  if (!s) PRINT_TEST_RESULT(FALSE);

  PRINT_TEST_RESULT(space_add_object(s, TEST_ID) == OK);
  space_destroy(s);
}

void test1_space_del_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_del_object(s, TEST_ID) == ERROR);
}

void test2_space_del_object() {
  Space *s;
  s = space_create(TEST_ID);
  if (!s) PRINT_TEST_RESULT(FALSE);
  if (!space_add_object(s, TEST_ID)) PRINT_TEST_RESULT(FALSE);

  PRINT_TEST_RESULT(space_del_object(s, TEST_ID) == OK);
  space_destroy(s);
}

void test1_space_has_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_has_object(s, TEST_ID) == FALSE);
}

void test2_space_has_object() {
  Space *s;
  s = space_create(TEST_ID);
  if (!s) PRINT_TEST_RESULT(FALSE);

  if (space_add_object(s, TEST_ID) == ERROR) PRINT_TEST_RESULT(FALSE);

  PRINT_TEST_RESULT(space_has_object(s, TEST_ID) == TRUE);

  space_destroy(s);
}

void test1_space_print() {
  PRINT_TEST_RESULT(space_print(NULL) == ERROR);
}

void test2_space_print() {
  Space *s = space_create(TEST_ID);
  if (!s) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(space_print(s) == OK);
  space_destroy(s);
}

void test1_space_set_description() {
  int    result;
  char   desc[ODESC_LEN + 1];
  Space *s;
  strcpy(desc, DESC_SAMPLE);
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = space_set_description(s, desc);
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_set_description() {
  int    result;
  char  *desc = NULL;
  Space *s;
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = space_set_description(s, desc) == ERROR;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test3_space_set_description() {
  int    result;
  char   desc[ODESC_LEN + 1];
  Space *s = NULL;
  strcpy(desc, DESC_SAMPLE);
  result = space_set_description(s, desc) == ERROR;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test1_space_get_description() {
  int    result;
  Space *s;
  char   desc[ODESC_LEN + 1];
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  strcpy(desc, DESC_SAMPLE);
  if (space_set_description(s, desc) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    space_destroy(s);
    return;
  }
  result = strcmp(desc, space_get_description(s)) == 0;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_get_description() {
  int    result;
  Space *s = NULL;
  result   = space_get_description(s) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test1_space_set_ldescription() {
  int    result;
  char   desc[ODESC_LEN + 1];
  Space *s;
  strcpy(desc, DESC_SAMPLE);
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = space_set_ldescription(s, desc);
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_set_ldescription() {
  int    result;
  char  *desc = NULL;
  Space *s;
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = space_set_ldescription(s, desc) == ERROR;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test3_space_set_ldescription() {
  int    result;
  char   desc[ODESC_LEN + 1];
  Space *s = NULL;
  strcpy(desc, DESC_SAMPLE);
  result = space_set_ldescription(s, desc) == ERROR;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test1_space_get_ldescription() {
  int    result;
  Space *s;
  char   desc[ODESC_LEN + 1];
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  strcpy(desc, DESC_SAMPLE);
  if (space_set_ldescription(s, desc) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    space_destroy(s);
    return;
  }
  result = strcmp(desc, space_get_ldescription(s)) == 0;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_get_ldescription() {
  int    result;
  Space *s = NULL;
  result   = space_get_ldescription(s) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test1_space_set_light() {
  int    result;
  Space *s = NULL;
  BOOL   b = TRUE;
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = space_set_light(s, b) == OK;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_set_light() {
  int    result;
  Space *s = NULL;
  BOOL   b = TRUE;
  result   = space_set_light(s, b) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test3_space_set_light() {
  int    result;
  Space *s = NULL;
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = space_set_light(s, -1) == ERROR;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test1_space_get_light() {
  int    result;
  Space *s = NULL;
  BOOL   b = TRUE;
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (space_set_light(s, b) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = b == space_get_light(s);
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_get_light() {
  int    result;
  Space *s = NULL;
  result   = space_get_light(s) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test1_space_set_gdesc() {
  Space *s            = NULL;
  char   str[5][1000] = {" |_EXIT_|", "|  ||  |", "|  || o|", " |  ||  |", " |._._._|"};
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  PRINT_TEST_RESULT(space_set_gdesc(s, str) == OK);
  space_destroy(s);
}

void test2_space_set_gdesc() {
  Space *s            = NULL;
  char   str[5][1000] = {" |_EXIT_|", "|  ||  |", "|  || o|", " |  ||  |", " |._._._|"};
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(space_set_gdesc(s, str) == OK);
  space_destroy(s);
}

void test1_space_get_gdesc() {
  Space *s = NULL;
  int    i, result = 0;
  char   str[5][1000] = {" |_EXIT_|", "|  ||  |", "|  || o|", " |  ||  |", " |._._._|"};
  if (!(s = space_create(TEST_ID))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (space_set_gdesc(s, str) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    space_destroy(s);
  }
  for (i = 0; i < 5; i++) {
    result += strcmp(space_get_gdesc(s)[i], str[i]);
  }
  PRINT_TEST_RESULT(result == 0);
  space_destroy(s);
}

void test2_space_get_gdesc() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_gdesc(s) == NULL);
}