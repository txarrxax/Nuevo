/**
 * @brief It tests the game reader module
 * @file game_management_test.c
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */
#include <stdio.h>
#include <stdlib.h>
#include <game_management.h>
#include <game_management_test.h>
#include <game.h>
#include <space.h>
#include <object.h>
#include <set.h>
#include <player.h>
#include <enemy.h>
#include <link.h>
#include <test.h>

/**
 * @brief Max number of tests
 */
#define MAX_TESTS 20

/**
 * @brief Main function for GAME READER unit tests
 */
int main(int argc, char **argv) {
  int test = 0;
  int all  = 1;

  if (argc < 2)
    printf("Running all test for module Game Reader:\n");
  else {
    test = atoi(argv[1]);
    all  = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
    }
  }

  if (all || test == 1) test1_game_management_load_spaces();
  if (all || test == 2) test2_game_management_load_spaces();
  if (all || test == 3) test3_game_management_load_spaces();
  if (all || test == 4) test4_game_management_load_spaces();
  if (all || test == 5) test1_game_management_load_objects();
  if (all || test == 6) test2_game_management_load_objects();
  if (all || test == 7) test3_game_management_load_objects();
  if (all || test == 8) test4_game_management_load_objects();
  if (all || test == 9) test1_game_management_load_player();
  if (all || test == 10) test2_game_management_load_player();
  if (all || test == 11) test3_game_management_load_player();
  if (all || test == 12) test4_game_management_load_player();
  if (all || test == 13) test1_game_management_load_enemies();
  if (all || test == 14) test2_game_management_load_enemies();
  if (all || test == 15) test3_game_management_load_enemies();
  if (all || test == 16) test4_game_management_load_enemies();
  if (all || test == 17) test1_game_management_load_links();
  if (all || test == 18) test2_game_management_load_links();
  if (all || test == 19) test3_game_management_load_links();
  if (all || test == 20) test4_game_management_load_links();
  if (all || test == 21) test1_game_management_save_spaces();
  if (all || test == 22) test2_game_management_save_spaces();
  if (all || test == 23) test3_game_management_save_spaces();
  if (all || test == 24) test1_game_management_save_objects();
  if (all || test == 25) test2_game_management_save_objects();
  if (all || test == 26) test3_game_management_save_objects();
  if (all || test == 27) test1_game_management_save_player();
  if (all || test == 28) test2_game_management_save_player();
  if (all || test == 29) test3_game_management_save_player();
  if (all || test == 30) test1_game_management_save_enemies();
  if (all || test == 31) test2_game_management_save_enemies();
  if (all || test == 32) test3_game_management_save_enemies();
  if (all || test == 33) test1_game_management_save_links();
  if (all || test == 34) test2_game_management_save_links();
  if (all || test == 35) test3_game_management_save_links();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_management_load_spaces() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_spaces(game, TEST_FILENAME) == OK);

  game_destroy(game);
}

void test2_game_management_load_spaces() {
  PRINT_TEST_RESULT(game_management_load_spaces(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_management_load_spaces() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_spaces(game, NULL) == ERROR);

  game_destroy(game);
}

void test4_game_management_load_spaces() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_spaces(game, TEST_WRONG_FILENAME) == ERROR);

  game_destroy(game);
}

void test1_game_management_load_objects() {
  Game  *game;
  Space *space;

  game_create(&game);
  game_management_load_spaces(game, TEST_FILENAME);
  PRINT_TEST_RESULT(game_management_load_objects(game, TEST_FILENAME) == OK);

  game_destroy(game);
}

void test2_game_management_load_objects() {
  PRINT_TEST_RESULT(game_management_load_objects(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_management_load_objects() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_objects(game, NULL) == ERROR);

  game_destroy(game);
}

void test4_game_management_load_objects() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_objects(game, TEST_WRONG_FILENAME) == ERROR);

  game_destroy(game);
}

void test1_game_management_load_player() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_player(game, TEST_FILENAME) == OK);

  game_destroy(game);
}

void test2_game_management_load_player() {
  PRINT_TEST_RESULT(game_management_load_player(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_management_load_player() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_player(game, NULL) == ERROR);

  game_destroy(game);
}

void test4_game_management_load_player() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_player(game, TEST_WRONG_FILENAME) == ERROR);

  game_destroy(game);
}

void test1_game_management_load_enemies() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_enemies(game, TEST_FILENAME) == OK);

  game_destroy(game);
}

void test2_game_management_load_enemies() {
  PRINT_TEST_RESULT(game_management_load_enemies(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_management_load_enemies() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_enemies(game, NULL) == ERROR);

  game_destroy(game);
}

void test4_game_management_load_enemies() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_enemies(game, TEST_WRONG_FILENAME) == ERROR);

  game_destroy(game);
}

void test1_game_management_load_links() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_links(game, TEST_FILENAME) == OK);

  game_destroy(game);
}

void test2_game_management_load_links() {
  PRINT_TEST_RESULT(game_management_load_links(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_management_load_links() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_links(game, NULL) == ERROR);

  game_destroy(game);
}

void test4_game_management_load_links() {
  Game *game;

  game_create(&game);
  PRINT_TEST_RESULT(game_management_load_links(game, TEST_WRONG_FILENAME) == ERROR);

  game_destroy(game);
}

void test1_game_management_save_spaces() {
  Game *game;
  FILE *f;
  game_create(&game);
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_spaces(game, f) == OK);
  fclose(f);
  game_destroy(game);
}

void test2_game_management_save_spaces() {
  Game *game;
  FILE *f = NULL;
  game_create(&game);
  PRINT_TEST_RESULT(game_management_save_spaces(game, f) == ERROR);
  game_destroy(game);
}

void test3_game_management_save_spaces() {
  Game *game = NULL;
  FILE *f;
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_spaces(game, f) == ERROR);
  fclose(f);
}

void test1_game_management_save_objects() {
  Game *game;
  FILE *f;
  game_create(&game);
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_objects(game, f) == OK);
  fclose(f);
  game_destroy(game);
}

void test2_game_management_save_objects() {
  Game *game;
  FILE *f = NULL;
  game_create(&game);
  PRINT_TEST_RESULT(game_management_save_objects(game, f) == ERROR);
  game_destroy(game);
}

void test3_game_management_save_objects() {
  Game *game = NULL;
  FILE *f;
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_objects(game, f) == ERROR);
  fclose(f);
}

void test1_game_management_save_player() {
  Game *game;
  FILE *f;
  game_create(&game);
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_player(game, f) == OK);
  fclose(f);
  game_destroy(game);
}

void test2_game_management_save_player() {
  Game *game;
  FILE *f = NULL;
  game_create(&game);
  PRINT_TEST_RESULT(game_management_save_player(game, f) == ERROR);
  game_destroy(game);
}

void test3_game_management_save_player() {
  Game *game = NULL;
  FILE *f;
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_player(game, f) == ERROR);
  fclose(f);
}

void test1_game_management_save_enemies() {
  Game *game;
  FILE *f;
  game_create(&game);
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_enemies(game, f) == OK);
  fclose(f);
  game_destroy(game);
}

void test2_game_management_save_enemies() {
  Game *game;
  FILE *f = NULL;
  game_create(&game);
  PRINT_TEST_RESULT(game_management_save_enemies(game, f) == ERROR);
  game_destroy(game);
}

void test3_game_management_save_enemies() {
  Game *game = NULL;
  FILE *f;
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_enemies(game, f) == ERROR);
  fclose(f);
}

void test1_game_management_save_links() {
  Game *game;
  FILE *f;
  game_create(&game);
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_links(game, f) == OK);
  fclose(f);
  game_destroy(game);
}

void test2_game_management_save_links() {
  Game *game;
  FILE *f = NULL;
  game_create(&game);
  PRINT_TEST_RESULT(game_management_save_links(game, f) == ERROR);
  game_destroy(game);
}

void test3_game_management_save_links() {
  Game *game = NULL;
  FILE *f;
  f = fopen(SAVE_FILE, "w");
  PRINT_TEST_RESULT(game_management_save_links(game, f) == ERROR);
  fclose(f);
}