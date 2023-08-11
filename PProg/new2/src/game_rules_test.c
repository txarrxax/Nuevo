/**
 * @brief It tests the game rules module
 * @file game_rules_test.c
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 04-05-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <game_rules_test.h>
#include <game_rules.h>
#include <test.h>

/**
 * @brief Max number of tests
 */
#define MAX_TESTS 16

/**
 * @brief Main function for GAME RULES unit tests
 */
int main(int argc, char **argv) {
  int test = 0;
  int all  = 1;

  if (argc < 2)
    printf("Running all test for module Game Rules:\n");
  else {
    test = atoi(argv[1]);
    all  = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
    }
  }

  if (all || test == 1) test1_game_rules_init();
  if (all || test == 2) test2_game_rules_init();
  if (all || test == 3) test1_game_rules_init_from_file();
  if (all || test == 4) test2_game_rules_init_from_file();
  if (all || test == 5) test3_game_rules_init_from_file();
  if (all || test == 6) test1_game_rules_destroy();
  if (all || test == 7) test2_game_rules_destroy();
  if (all || test == 8) test1_game_rules_implement();
  if (all || test == 9) test2_game_rules_implement();
  if (all || test == 10) test3_game_rules_implement();
  if (all || test == 11) test1_game_rules_reset_rules();
  if (all || test == 12) test2_game_rules_reset_rules();
  if (all || test == 13) test1_game_rules_get_rule();
  if (all || test == 14) test2_game_rules_get_rule();
  if (all || test == 15) test1_game_rules_get_num_rules();
  if (all || test == 16) test2_game_rules_get_num_rules();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_rules_init() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init(game);

  PRINT_TEST_RESULT(grules != NULL);

  game_rules_destroy(grules);
  game_destroy(game);
}

void test2_game_rules_init() {
  PRINT_TEST_RESULT(game_rules_init(NULL) == NULL);
}

void test1_game_rules_init_from_file() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init_from_file(game, FILE_NAME);

  PRINT_TEST_RESULT(grules != NULL);

  game_rules_destroy(grules);
  game_destroy(game);
}

void test2_game_rules_init_from_file() {
  PRINT_TEST_RESULT(game_rules_init_from_file(NULL, FILE_NAME) == NULL);
}

void test3_game_rules_init_from_file() {
  Game *game = NULL;

  game_create_from_file(&game, FILE_NAME);

  PRINT_TEST_RESULT(game_rules_init_from_file(game, NULL) == NULL);

  game_destroy(game);
}

void test1_game_rules_destroy() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init_from_file(game, FILE_NAME);

  PRINT_TEST_RESULT(game_rules_destroy(grules) == OK);

  game_destroy(game);
}

void test2_game_rules_destroy() {
  PRINT_TEST_RESULT(game_rules_destroy(NULL) == ERROR);
}

void test1_game_rules_implement() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init(game);

  PRINT_TEST_RESULT(game_rules_implement(game, grules, NULL) == OK);

  game_rules_destroy(grules);
  game_destroy(game);
}

void test2_game_rules_implement() {
  Game *game = NULL;

  game_create_from_file(&game, FILE_NAME);

  PRINT_TEST_RESULT(game_rules_implement(game, NULL, NULL) == ERROR);

  game_destroy(game);
}

void test3_game_rules_implement() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init(game);

  PRINT_TEST_RESULT(game_rules_implement(NULL, grules, NULL) == ERROR);

  game_rules_destroy(grules);
  game_destroy(game);
}

void test1_game_rules_reset_rules() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init(game);

  PRINT_TEST_RESULT(game_rules_reset_rules(grules) == OK);

  game_rules_destroy(grules);
  game_destroy(game);
}

void test2_game_rules_reset_rules() {
  PRINT_TEST_RESULT(game_rules_reset_rules(NULL) == ERROR);
}

void test1_game_rules_get_rule() {
  Game   *game   = NULL;
  Grules *grules = NULL;

  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init(game);

  PRINT_TEST_RESULT(game_rules_get_rule(grules, -1) == NULL);

  game_rules_destroy(grules);
  game_destroy(game);
}

void test2_game_rules_get_rule() {
  PRINT_TEST_RESULT(game_rules_get_rule(NULL, INT) == NULL);
}

void test1_game_rules_get_num_rules() {
  Game   *game   = NULL;
  Grules *grules = NULL;
  game_create_from_file(&game, FILE_NAME);
  grules = game_rules_init(game);
  PRINT_TEST_RESULT(game_rules_get_num_rules(grules) >= 0);
  game_rules_destroy(grules);
  game_destroy(game);
}

void test2_game_rules_get_num_rules() {
  PRINT_TEST_RESULT(game_rules_get_num_rules(NULL) == -1);
}
