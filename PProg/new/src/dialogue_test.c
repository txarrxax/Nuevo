/**
 * @brief It tests the dialogue module
 *
 * @file dialogue_test.c
 * @author Álvaro Grande
 * @version 2.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dialogue.h>
#include <dialogue_test.h>
#include <test.h>
#include <game.h>

#include <game_management.h>
#include <space.h>
#include <player.h>
#include <object.h>
#include <enemy.h>
#include <link.h>
#include <set.h>
#include <inventory.h>

/**
 * @brief Max number of tests
 */
#define MAX_TESTS 2

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

  if (all || test == 1) test1_dialogue_message();
  if (all || test == 2) test2_dialogue_message();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_dialogue_message() {
  PRINT_TEST_RESULT(dialogue_message(NULL, REPEATED, NULL, NULL) == ERROR);
}
void test2_dialogue_message() {
  Game *g = NULL;
  game_create(&g);
  if (!g) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(dialogue_message(g, NO_DLG, NULL, NULL) == ERROR);
  game_destroy(g);
}