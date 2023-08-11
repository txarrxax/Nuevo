/**
 * @brief It tests the player module
 *
 * @file player_test.c
 * @author Álvaro Grande
 * @version 2.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inventory.h>
#include <player.h>
#include <player_test.h>
#include <set.h>
#include <test.h>

/**
 * @brief Max number of tests
 */
#define MAX_TESTS 38

/**
 * @brief Sample id for testing purpose
 */
#define TEST_PLAYER_ID 5

/**
 * @brief sample location for testing purpose
 */
#define TEST_PLAYER_LOC 2

/**
 * @brief Sample name for testing purpose
 */
#define TEST_PLAYER_NAME "PLAYER"

/**
 * @brief Sample item for testing purpose
 */
#define TEST_PLAYER_ITEM 4

/**
 * @brief Sample health for testing purpose
 */
#define TEST_PLAYER_HEALTH 5

/**
 * @brief Sample capacity for testing purpose
 */
#define TEST_PLAYER_INV_CAP 4

/**
 * @brief Sample stat for testing purpose
 */
#define TEST_PLAYER_STAT 3

/**
 * @brief Sample stat for testing purpose
 */
#define TEST_PLAYER_STAT_NEG -3

/**
 * @brief Main function for PLAYER unit tests
 */
int main(int argc, char **argv) {
  int test = 0;
  int all  = 1;

  if (argc < 2) {
    printf("Running all test for the module Link:\n");
  } else {
    test = atoi(argv[1]);
    all  = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_player_create();
  if (all || test == 2) test2_player_create();
  if (all || test == 3) test1_player_destroy();
  if (all || test == 4) test2_player_destroy();
  if (all || test == 5) test1_player_get_id();
  if (all || test == 6) test2_player_get_id();
  if (all || test == 7) test1_player_set_id();
  if (all || test == 8) test2_player_set_id();
  if (all || test == 9) test1_player_get_inventory();
  if (all || test == 10) test2_player_get_inventory();
  if (all || test == 11) test1_player_add_item();
  if (all || test == 12) test2_player_add_item();
  if (all || test == 13) test1_player_del_item();
  if (all || test == 14) test2_player_del_item();
  if (all || test == 15) test1_player_get_location();
  if (all || test == 16) test2_player_get_location();
  if (all || test == 17) test1_player_set_location();
  if (all || test == 18) test2_player_set_location();
  if (all || test == 19) test1_player_get_name();
  if (all || test == 20) test2_player_get_name();
  if (all || test == 21) test1_player_set_name();
  if (all || test == 22) test2_player_set_name();
  if (all || test == 23) test1_player_get_health();
  if (all || test == 24) test2_player_get_health();
  if (all || test == 25) test1_player_set_health();
  if (all || test == 26) test2_player_set_health();
  if (all || test == 27) test1_player_print();
  if (all || test == 28) test2_player_print();
  if (all || test == 29) test1_player_set_inv_cap();
  if (all || test == 30) test2_player_set_inv_cap();
  if (all || test == 31) test1_player_add_stat();
  if (all || test == 32) test2_player_add_stat();
  if (all || test == 33) test1_player_subs_stat();
  if (all || test == 34) test2_player_subs_stat();
  if (all || test == 35) test1_player_get_atk();
  if (all || test == 36) test2_player_get_atk();
  if (all || test == 37) test1_player_get_def();
  if (all || test == 38) test2_player_get_def();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_player_create() {
  Player *p = player_create();
  PRINT_TEST_RESULT(p != NULL);
  player_destroy(p);
}

void test2_player_create() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
  player_destroy(p);
}

void test1_player_destroy() {
  Player *p = player_create();

  PRINT_TEST_RESULT(player_destroy(p) == OK);
}

void test2_player_destroy() {
  PRINT_TEST_RESULT(player_destroy(NULL) == ERROR);
}

void test1_player_get_id() {
  PRINT_TEST_RESULT(player_get_id(NULL) == NO_ID);
}

void test2_player_get_id() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
  player_destroy(p);
}

void test1_player_set_id() {
  PRINT_TEST_RESULT(player_set_id(NULL, TEST_PLAYER_ID) == ERROR);
}

void test2_player_set_id() {
  Player *p = player_create();
  player_set_id(p, TEST_PLAYER_ID);
  PRINT_TEST_RESULT(player_get_id(p) == TEST_PLAYER_ID);
  player_destroy(p);
}

void test1_player_get_inventory() {
  PRINT_TEST_RESULT(player_get_inventory(NULL) == NULL);
}

void test2_player_get_inventory() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_get_inventory(p) != NULL);
  player_destroy(p);
}

void test1_player_add_item() {
  PRINT_TEST_RESULT(player_add_item(NULL, TEST_PLAYER_ITEM) == ERROR);
}

void test2_player_add_item() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_add_item(p, TEST_PLAYER_ITEM) == OK);
  player_destroy(p);
}

void test1_player_del_item() {
  PRINT_TEST_RESULT(player_del_item(NULL, TEST_PLAYER_ITEM) == ERROR);
}

void test2_player_del_item() {
  Player *p = player_create();
  player_add_item(p, TEST_PLAYER_ITEM);
  PRINT_TEST_RESULT(player_del_item(p, TEST_PLAYER_ITEM) == OK);
  player_destroy(p);
}

void test1_player_get_location() {
  PRINT_TEST_RESULT(player_get_location(NULL) == NO_ID);
}

void test2_player_get_location() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_get_location(p) == NO_ID);
  player_destroy(p);
}

void test1_player_set_location() {
  PRINT_TEST_RESULT(player_set_location(NULL, TEST_PLAYER_LOC) == ERROR);
}

void test2_player_set_location() {
  Player *p = player_create();
  player_set_location(p, TEST_PLAYER_LOC);
  PRINT_TEST_RESULT(player_get_location(p) == TEST_PLAYER_LOC);
  player_destroy(p);
}

void test1_player_get_name() {
  PRINT_TEST_RESULT(player_get_name(NULL) == NULL);
}

void test2_player_get_name() {
  Player *p = player_create();
  player_set_name(p, TEST_PLAYER_NAME);
  PRINT_TEST_RESULT(strcmp(player_get_name(p), TEST_PLAYER_NAME) == 0);
  player_destroy(p);
}

void test1_player_set_name() {
  PRINT_TEST_RESULT(player_set_name(NULL, TEST_PLAYER_NAME) == ERROR);
}

void test2_player_set_name() {
  Player *p = player_create();
  player_set_name(p, TEST_PLAYER_NAME);
  PRINT_TEST_RESULT(strcmp(player_get_name(p), TEST_PLAYER_NAME) == 0);
  player_destroy(p);
}

void test1_player_get_health() {
  PRINT_TEST_RESULT(player_get_health(NULL) == -1);
}

void test2_player_get_health() {
  Player *p = player_create();
  player_set_health(p, TEST_PLAYER_HEALTH);
  PRINT_TEST_RESULT(player_get_health(p) == TEST_PLAYER_HEALTH);
  player_destroy(p);
}

void test1_player_set_health() {
  PRINT_TEST_RESULT(player_set_health(NULL, TEST_PLAYER_HEALTH) == ERROR);
}

void test2_player_set_health() {
  Player *p = player_create();
  player_set_health(p, TEST_PLAYER_HEALTH);
  PRINT_TEST_RESULT(player_get_health(p) == TEST_PLAYER_HEALTH);
  player_destroy(p);
}

void test1_player_print() {
  PRINT_TEST_RESULT(player_print(NULL) == ERROR);
}

void test2_player_print() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_print(p) == OK);
  player_destroy(p);
}

void test1_player_set_inv_cap() {
  PRINT_TEST_RESULT(player_set_inv_cap(NULL, TEST_PLAYER_INV_CAP) == ERROR);
}

void test2_player_set_inv_cap() {
  Player *p = player_create();
  PRINT_TEST_RESULT(player_set_inv_cap(p, TEST_PLAYER_INV_CAP) == OK);
  player_destroy(p);
}

void test1_player_add_stat() {
  PRINT_TEST_RESULT(player_add_stat(NULL, TEST_PLAYER_STAT) == ERROR);
}

void test2_player_add_stat() {
  Player *p = player_create();
  if (!p) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (player_add_stat(p, TEST_PLAYER_STAT) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    player_destroy(p);
    return;
  }

  PRINT_TEST_RESULT(player_get_atk(p) == TEST_PLAYER_STAT);
  player_destroy(p);
}

void test1_player_subs_stat() {
  PRINT_TEST_RESULT(player_subs_stat(NULL, TEST_PLAYER_STAT) == ERROR);
}

void test2_player_subs_stat() {
  Player *p = player_create();
  if (!p) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (player_subs_stat(p, TEST_PLAYER_STAT_NEG) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    player_destroy(p);
    return;
  }

  PRINT_TEST_RESULT(player_get_def(p) == TEST_PLAYER_STAT_NEG);
  player_destroy(p);
}

void test1_player_get_atk() {
  PRINT_TEST_RESULT(player_get_atk(NULL) == 0);
}

void test2_player_get_atk() {
  Player *p = player_create();
  if (!p) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (player_add_stat(p, TEST_PLAYER_STAT) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    player_destroy(p);
    return;
  }

  PRINT_TEST_RESULT(player_get_atk(p) == TEST_PLAYER_STAT);
  player_destroy(p);
}

void test1_player_get_def() {
  PRINT_TEST_RESULT(player_get_def(NULL) == 0);
}

void test2_player_get_def() {
  Player *p = player_create();
  if (!p) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (player_subs_stat(p, TEST_PLAYER_STAT_NEG) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    player_destroy(p);
    return;
  }

  PRINT_TEST_RESULT(player_get_def(p) == TEST_PLAYER_STAT_NEG);
  player_destroy(p);
}