/**
 * @brief It tests game module
 *
 * @file game_test.c
 * @author Álvaro Grande
 * @version 3.0
 * @date 07-03-2023
 * @copyright GNU Public License
 */

#include <game_test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Max number of tests
*/
#define MAX_TESTS 37

/**
 * @brief Length of the object descriptions
 */
#define ODESC_LEN 17

/**
 * @brief Sample id for space with testing purpose
*/
#define TEST_SPACE_ID 5

/**
 * @brief Main function for GAME unit tests
 */
int main(int argc, char **argv)
{
  int test = 0;
  int all = 1;

  if (argc < 2)
    printf("Running all test for module Game:\n");
  else
  {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS)
    {
      printf("Error: unknown test %d\t", test);
    }
  }

  if (all || test == 1)
    test1_game_create_from_file();
  if (all || test == 2)
    test2_game_create_from_file();
  if (all || test == 3)
    test1_game_destroy();
  if (all || test == 4)
    test1_game_add_space();
  if (all || test == 5)
    test2_game_add_space();
  if (all || test == 6)
    test1_game_get_space();
  if (all || test == 7)
    test2_game_get_space();
  if (all || test == 8)
    test1_game_update();
  if (all || test == 9)
    test2_game_update();
  if (all || test == 10)
    test1_game_is_over();
  if (all || test == 11)
    test2_game_is_over();
  if (all || test == 12)
    test1_game_get_last_command();
  if (all || test == 13)
    test2_game_get_last_command();
  if (all || test == 14)
    test1_print_data();
  if (all || test == 15)
    test2_print_data();
  if (all || test == 16)
    test1_game_get_object_location();
  if (all || test == 17)
    test2_game_get_object_location();
  if (all || test == 18)
    test1_game_add_object();
  if (all || test == 19)
    test2_game_add_object();
  if (all || test == 20)
    test1_game_get_player();
  if (all || test == 21)
    test2_game_get_player();
  if (all || test == 22)
    test1_game_get_enemy();
  if (all || test == 23)
    test2_game_get_enemy();
  if (all || test == 24)
    test1_game_get_number_of_objects();
  if (all || test == 25)
    test2_game_get_number_of_objects();
  if (all || test == 26)
    test1_game_get_object_from_position();
  if (all || test == 27)
    test2_game_get_object_from_position();
  if (all || test == 28)
    test1_game_get_last_command_exit();
  if (all || test == 29)
    test2_game_get_last_command_exit();
  if (all || test == 30)
    test1_game_get_connection_status();
  if (all || test == 31)
    test2_game_get_connection_status();
  if (all || test == 32)
    test1_game_get_connection();
  if (all || test == 33)
    test2_game_get_connection();
  if (all || test == 34)
    test1_game_add_link();
  if (all || test == 35)
    test2_game_add_link();
  if (all || test == 36)
    test1_game_get_space_obj_desc();
  if (all || test == 37)
    test2_game_get_space_obj_desc();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_create_from_file()
{
  PRINT_TEST_RESULT(game_create_from_file(NULL, TEST_FILENAME) == ERROR);
}

void test2_game_create_from_file()
{
  Game *game = NULL;

  PRINT_TEST_RESULT(game_create_from_file(&game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_destroy() { PRINT_TEST_RESULT(game_destroy(NULL) == ERROR); }

void test1_game_add_space()
{
  Space *space = space_create(TEST_ID);
  if (!space)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_space(NULL, space) == ERROR);
  space_destroy(space);
}

void test2_game_add_space()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_space(game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_get_space()
{
  PRINT_TEST_RESULT(game_get_space(NULL, TEST_ID) == ERROR);
}

void test2_game_get_space()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_space(game, NO_ID) == NULL);
  game_destroy(game);
}

void test1_game_update()
{
  T_Command cmd = TAKE;
  PRINT_TEST_RESULT(game_update(NULL, cmd, TEST_ARG) == ERROR);
}

void test2_game_update()
{
  T_Command cmd = TAKE;
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_update(game, cmd, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_is_over() { PRINT_TEST_RESULT(game_is_over(NULL) == TRUE); }

void test2_game_is_over()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (!player_set_health(game_get_player(game), TEST_PLAYER_HEALTH))
  {
    PRINT_TEST_RESULT(FALSE);
    game_destroy(game);
    return;
  }

  PRINT_TEST_RESULT(game_is_over(game) == FALSE);
  game_destroy(game);
}

void test1_game_get_last_command()
{
  PRINT_TEST_RESULT(game_get_last_command(NULL) == NO_CMD);
}

void test2_game_get_last_command()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_last_command(game) == NO_CMD);
  game_destroy(game);
}

void test1_print_data() { PRINT_TEST_RESULT(game_print_data(NULL) == ERROR); }

void test2_print_data()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_print_data(game) == OK);
  game_destroy(game);
}

void test1_game_get_object_location()
{
  Object *object = object_create();
  if (!object)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_object_location(NULL, object) == NO_ID);
  object_destroy(object);
}

void test2_game_get_object_location()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_object_location(game, NULL) == NO_ID);
  game_destroy(game);
}

void test1_game_add_object()
{
  Object *object = object_create();
  if (!object)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_object(NULL, object) == ERROR);
  object_destroy(object);
}

void test2_game_add_object()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_object(game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_get_player()
{
  PRINT_TEST_RESULT(game_get_player(NULL) == NULL);
}

void test2_game_get_player()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_player(game) != NULL);
  game_destroy(game);
}

void test1_game_get_enemy() { PRINT_TEST_RESULT(game_get_enemy(NULL) == NULL); }

void test2_game_get_enemy()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_enemy(game) != NULL);
  game_destroy(game);
}

void test1_game_get_number_of_objects()
{
  PRINT_TEST_RESULT(game_get_number_of_objects(NULL) == -1);
}

void test2_game_get_number_of_objects()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_number_of_objects(game) == 0);
  game_destroy(game);
}

void test1_game_get_object_from_position()
{
  PRINT_TEST_RESULT(game_get_object_from_position(NULL, 0) == NULL);
}

void test2_game_get_object_from_position()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_object_from_position(game, TEST_POSITION) ==
                    ERROR);
  game_destroy(game);
}

void test1_game_get_last_command_exit()
{
  PRINT_TEST_RESULT(game_get_last_command_exit(NULL) == ERROR);
}

void test2_game_get_last_command_exit()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_last_command_exit(game) == OK);
  game_destroy(game);
}

void test1_game_get_connection_status()
{
  PRINT_TEST_RESULT(game_get_connection_status(NULL, TEST_ID, N) == ERROR);
}

void test2_game_get_connection_status()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_connection_status(game, TEST_ID, -1) == ERROR);
  game_destroy(game);
}

void test1_game_get_connection()
{
  PRINT_TEST_RESULT(game_get_connection(NULL, TEST_ID, N) == NO_ID);
}

void test2_game_get_connection()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_connection(game, NO_ID, N) == NO_ID);
  game_destroy(game);
}

void test1_game_add_link()
{
  Link *link = link_create(TEST_ID);
  if (!link)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_link(NULL, link) == ERROR);
  link_destroy(link);
}

void test2_game_add_link()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_link(game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_create() { PRINT_TEST_RESULT(game_create(NULL) == ERROR); }

void test2_game_create()
{
  Game *game = NULL;
  if (game_create(&game) == ERROR)
    PRINT_TEST_RESULT(FALSE);

  PRINT_TEST_RESULT(game_get_last_command(game) == NO_CMD);
  game_destroy(game);
}

void test1_game_get_space_obj_desc()
{
  char desc[ODESC_LEN];
  Space *space = space_create(TEST_SPACE_ID);
  if (!space)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_space_obj_desc(NULL, space, desc) == ERROR);
  space_destroy(space);
}

void test2_game_get_space_obj_desc()
{
  char desc[ODESC_LEN];
  Game *game = NULL;
  game_create(&game);
  if (!game)
  {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_space_obj_desc(game, NULL, desc) == ERROR);
  game_destroy(game);
}
