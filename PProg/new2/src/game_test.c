/**
 * @brief It tests game module
 *
 * @file game_test.c
 * @author Álvaro Grande
 * @author Diego Fernández
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
#define MAX_TESTS 68

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
int main(int argc, char **argv) {
  int test = 0;
  int all  = 1;

  if (argc < 2)
    printf("Running all test for module Game:\n");
  else {
    test = atoi(argv[1]);
    all  = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
    }
  }

  if (all || test == 1) test1_game_create_from_file();
  if (all || test == 2) test2_game_create_from_file();
  if (all || test == 3) test1_game_destroy();
  if (all || test == 4) test1_game_add_space();
  if (all || test == 5) test2_game_add_space();
  if (all || test == 6) test1_game_get_space();
  if (all || test == 7) test2_game_get_space();
  if (all || test == 8) test1_game_update();
  if (all || test == 9) test2_game_update();
  if (all || test == 10) test1_game_is_over();
  if (all || test == 11) test2_game_is_over();
  if (all || test == 12) test1_game_get_last_command();
  if (all || test == 13) test2_game_get_last_command();
  if (all || test == 14) test1_game_print_data();
  if (all || test == 15) test2_game_print_data();
  if (all || test == 16) test1_game_get_object_location();
  if (all || test == 17) test2_game_get_object_location();
  if (all || test == 18) test1_game_add_object();
  if (all || test == 19) test2_game_add_object();
  if (all || test == 20) test1_game_get_player();
  if (all || test == 21) test2_game_get_player();
  if (all || test == 22) test1_game_get_enemy();
  if (all || test == 23) test2_game_get_enemy();
  if (all || test == 24) test1_game_get_number_of_objects();
  if (all || test == 25) test2_game_get_number_of_objects();
  if (all || test == 26) test1_game_get_object_from_position();
  if (all || test == 27) test2_game_get_object_from_position();
  if (all || test == 28) test1_game_get_last_command_exit();
  if (all || test == 29) test2_game_get_last_command_exit();
  if (all || test == 30) test1_game_get_connection_status();
  if (all || test == 31) test2_game_get_connection_status();
  if (all || test == 32) test1_game_get_connection();
  if (all || test == 33) test2_game_get_connection();
  if (all || test == 34) test1_game_add_link();
  if (all || test == 35) test2_game_add_link();
  if (all || test == 36) test1_game_get_space_obj_desc();
  if (all || test == 37) test2_game_get_space_obj_desc();
  if (all || test == 38) test2_game_destroy();
  if (all || test == 39) test1_game_set_last_description();
  if (all || test == 40) test2_game_set_last_description();
  if (all || test == 41) test3_game_set_last_description();
  if (all || test == 42) test1_game_get_last_description();
  if (all || test == 43) test2_game_get_last_description();
  if (all || test == 44) test1_game_set_last_dialogue();
  if (all || test == 45) test2_game_set_last_dialogue();
  if (all || test == 46) test3_game_set_last_dialogue();
  if (all || test == 47) test1_game_get_last_dialogue();
  if (all || test == 48) test2_game_get_last_dialogue();
  if (all || test == 49) test1_game_get_object_from_id();
  if (all || test == 50) test2_game_get_object_from_id();
  if (all || test == 51) test1_game_get_object_from_name();
  if (all || test == 52) test2_game_get_object_from_name();
  if (all || test == 53) test1_game_get_space_id_at();
  if (all || test == 54) test2_game_get_space_id_at();
  if (all || test == 55) test1_game_get_all_spaces();
  if (all || test == 56) test2_game_get_all_spaces();
  if (all || test == 57) test1_game_get_all_objects();
  if (all || test == 58) test2_game_get_all_objects();
  if (all || test == 59) test1_game_get_num_links();
  if (all || test == 60) test2_game_get_num_links();
  if (all || test == 61) test1_game_get_all_links();
  if (all || test == 62) test2_game_get_all_links();
  if (all || test == 63) test1_game_no_enemy();
  if (all || test == 64) test2_game_no_enemy();
  if (all || test == 65) test1_game_get_link_from_id();
  if (all || test == 66) test2_game_get_link_from_id();
  if (all || test == 67) test1_game_create();
  if (all || test == 68) test2_game_create();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_create_from_file() {
  PRINT_TEST_RESULT(game_create_from_file(NULL, TEST_FILENAME) == ERROR);
}

void test2_game_create_from_file() {
  Game *game = NULL;

  PRINT_TEST_RESULT(game_create_from_file(&game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_destroy() {
  PRINT_TEST_RESULT(game_destroy(NULL) == ERROR);
}

void test2_game_destroy() {
  Game *game;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_destroy(game) == OK);
}

void test1_game_add_space() {
  Space *space = space_create(TEST_ID);
  if (!space) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_space(NULL, space) == ERROR);
  space_destroy(space);
}

void test2_game_add_space() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_space(game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_get_space() {
  PRINT_TEST_RESULT(game_get_space(NULL, TEST_ID) == ERROR);
}

void test2_game_get_space() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_space(game, NO_ID) == NULL);
  game_destroy(game);
}

void test1_game_update() {
  T_Command cmd = TAKE;
  PRINT_TEST_RESULT(game_update(NULL, cmd, TEST_ARG) == ERROR);
}

void test2_game_update() {
  T_Command cmd  = TAKE;
  Game     *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_update(&game, cmd, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_is_over() {
  PRINT_TEST_RESULT(game_is_over(NULL) == TRUE);
}

void test2_game_is_over() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  if (player_set_health(game_get_player(game), TEST_PLAYER_HEALTH) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    game_destroy(game);
    return;
  }

  if (enemy_set_health(game_get_enemy(game), TEST_PLAYER_HEALTH) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    game_destroy(game);
    return;
  }

  PRINT_TEST_RESULT(game_is_over(game) == FALSE);
  game_destroy(game);
}

void test1_game_get_last_command() {
  PRINT_TEST_RESULT(game_get_last_command(NULL) == NO_CMD);
}

void test2_game_get_last_command() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_last_command(game) == NO_CMD);
  game_destroy(game);
}

void test1_game_print_data() {
  PRINT_TEST_RESULT(game_print_data(NULL) == ERROR);
}

void test2_game_print_data() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_print_data(game) == OK);
  game_destroy(game);
}

void test1_game_get_object_location() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_object_location(NULL, object) == NO_ID);
  object_destroy(object);
}

void test2_game_get_object_location() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_object_location(game, NULL) == NO_ID);
  game_destroy(game);
}

void test1_game_add_object() {
  Object *object = object_create();
  if (!object) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_object(NULL, object) == ERROR);
  object_destroy(object);
}

void test2_game_add_object() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_object(game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_get_player() {
  PRINT_TEST_RESULT(game_get_player(NULL) == NULL);
}

void test2_game_get_player() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_player(game) != NULL);
  game_destroy(game);
}

void test1_game_get_enemy() {
  PRINT_TEST_RESULT(game_get_enemy(NULL) == NULL);
}

void test2_game_get_enemy() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_enemy(game) != NULL);
  game_destroy(game);
}

void test1_game_get_number_of_objects() {
  PRINT_TEST_RESULT(game_get_number_of_objects(NULL) == -1);
}

void test2_game_get_number_of_objects() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_number_of_objects(game) == 0);
  game_destroy(game);
}

void test1_game_get_object_from_position() {
  PRINT_TEST_RESULT(game_get_object_from_position(NULL, 0) == NULL);
}

void test2_game_get_object_from_position() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_object_from_position(game, TEST_POSITION) == ERROR);
  game_destroy(game);
}

void test1_game_get_last_command_exit() {
  PRINT_TEST_RESULT(game_get_last_command_exit(NULL) == ERROR);
}

void test2_game_get_last_command_exit() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_last_command_exit(game) == OK);
  game_destroy(game);
}

void test1_game_get_connection_status() {
  PRINT_TEST_RESULT(game_get_connection_status(NULL, TEST_ID, N) == ERROR);
}

void test2_game_get_connection_status() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_connection_status(game, TEST_ID, -1) == ERROR);
  game_destroy(game);
}

void test1_game_get_connection() {
  PRINT_TEST_RESULT(game_get_connection(NULL, TEST_ID, N) == NO_ID);
}

void test2_game_get_connection() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_connection(game, NO_ID, N) == NO_ID);
  game_destroy(game);
}

void test1_game_add_link() {
  Link *link = link_create(TEST_ID);
  if (!link) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_link(NULL, link) == ERROR);
  link_destroy(link);
}

void test2_game_add_link() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_add_link(game, NULL) == ERROR);
  game_destroy(game);
}

void test1_game_create() {
  PRINT_TEST_RESULT(game_create(NULL) == ERROR);
}

void test2_game_create() {
  Game *game = NULL;
  if (game_create(&game) == ERROR) PRINT_TEST_RESULT(FALSE);

  PRINT_TEST_RESULT(game_get_last_command(game) == NO_CMD);
  game_destroy(game);
}

void test1_game_get_space_obj_desc() {
  char   desc[ODESC_LEN];
  Space *space = space_create(TEST_SPACE_ID);
  if (!space) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_space_obj_desc(NULL, space, desc) == ERROR);
  space_destroy(space);
}

void test2_game_get_space_obj_desc() {
  char  desc[ODESC_LEN];
  Game *game = NULL;
  game_create(&game);
  if (!game) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_space_obj_desc(game, NULL, desc) == ERROR);
  game_destroy(game);
}

void test1_game_set_last_description() {
  char *tmp = "test";

  PRINT_TEST_RESULT(game_set_last_description(NULL, tmp) == ERROR);
}

void test2_game_set_last_description() {
  Game *game;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_set_last_description(game, NULL) == ERROR);

  game_destroy(game);
}

void test3_game_set_last_description() {
  Game *game;
  char  desc[WORD_SIZE + 1];
  int   i;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < WORD_SIZE; i++) {
    desc[i] = 'a';
  }
  desc[WORD_SIZE] = '\0';

  PRINT_TEST_RESULT(game_set_last_description(game, desc) == ERROR);

  game_destroy(game);
}

void test1_game_get_last_description() {
  Game *game;
  char *desc = "test";

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  game_set_last_description(game, desc);

  PRINT_TEST_RESULT(strcmp(desc, game_get_last_description(game)) == 0);

  game_destroy(game);
}

void test2_game_get_last_description() {
  PRINT_TEST_RESULT(!game_get_last_description(NULL));
}

void test1_game_set_last_dialogue() {
  char *tmp = "test";

  PRINT_TEST_RESULT(game_set_last_dialogue(NULL, tmp) == ERROR);
}

void test2_game_set_last_dialogue() {
  Game *game;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_set_last_dialogue(game, NULL) == ERROR);

  game_destroy(game);
}

void test3_game_set_last_dialogue() {
  Game *game;
  char  desc[WORD_SIZE + 1];
  int   i;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < WORD_SIZE; i++) {
    desc[i] = 'a';
  }
  desc[WORD_SIZE] = '\0';

  PRINT_TEST_RESULT(game_set_last_dialogue(game, desc) == ERROR);

  game_destroy(game);
}

void test1_game_get_last_dialogue() {
  Game *game;
  char *desc = "test";

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  game_set_last_dialogue(game, desc);

  PRINT_TEST_RESULT(strcmp(desc, game_get_last_dialogue(game)) == 0);

  game_destroy(game);
}

void test2_game_get_last_dialogue() {
  PRINT_TEST_RESULT(!game_get_last_dialogue(NULL));
}

void test1_game_get_object_from_id() {
  PRINT_TEST_RESULT(!game_get_object_from_id(NULL, TEST_ID));
}

void test2_game_get_object_from_id() {
  Game   *game;
  int     i, target = TEST_SIZE / 2;
  Object *objs, *answer;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (!(objs = object_create())) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    if (i == target) {
      answer = objs;
      object_set_id(objs, TEST_ID);
    } else {
      object_set_id(objs, TEST_ID + i + 1);
    }
    game_add_object(game, objs);
  }

  PRINT_TEST_RESULT(game_get_object_from_id(game, TEST_ID) == answer);

  game_destroy(game);
}

void test1_game_get_object_from_name() {
  PRINT_TEST_RESULT(!game_get_object_from_name(NULL, "a"));
}

void test2_game_get_object_from_name() {
  Game   *game;
  int     i, target = TEST_SIZE / 2;
  Object *objs, *answer;
  char    name[TEST_SIZE] = "";

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (!(objs = object_create())) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    if (i == target) {
      answer = objs;
      object_set_name(objs, "b");
    } else {
      object_set_name(objs, name);
    }
    game_add_object(game, objs);
    strcat(name, "a");
  }

  PRINT_TEST_RESULT(game_get_object_from_name(game, "b") == answer);

  game_destroy(game);
}

void test1_game_get_space_id_at() {
  PRINT_TEST_RESULT(game_get_space_id_at(NULL, 0) == NO_ID);
}

void test2_game_get_space_id_at() {
  Game  *game;
  int    i;
  Space *s;
  BOOL   result = TRUE;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (!(s = space_create(i))) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    game_add_space(game, s);
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (game_get_space_id_at(game, i) != i) {
      result = FALSE;
      break;
    }
  }

  PRINT_TEST_RESULT(result);

  game_destroy(game);
}

void test1_game_get_all_spaces() {
  PRINT_TEST_RESULT(!game_get_all_spaces(NULL));
}

void test2_game_get_all_spaces() {
  Game         *game;
  int           i;
  Space        *s;
  const Space **array;
  BOOL          result = TRUE;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (!(s = space_create(i))) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    game_add_space(game, s);
  }

  if (!(array = game_get_all_spaces(game))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (space_get_id(array[i]) != i) {
      result = FALSE;
      break;
    }
  }

  PRINT_TEST_RESULT(result);

  game_destroy(game);
}

void test1_game_get_all_objects() {
  PRINT_TEST_RESULT(!game_get_all_objects(NULL));
}

void test2_game_get_all_objects() {
  Game          *game;
  int            i;
  Object        *obj;
  const Object **array;
  BOOL           result = TRUE;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (!(obj = object_create())) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    object_set_id(obj, i);
    game_add_object(game, obj);
  }

  if (!(array = game_get_all_objects(game))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (object_get_id(array[i]) != i) {
      result = FALSE;
      break;
    }
  }

  PRINT_TEST_RESULT(result);

  game_destroy(game);
}

void test1_game_get_num_links() {
  PRINT_TEST_RESULT(game_get_num_links(NULL) == -1);
}

void test2_game_get_num_links() {
  Game *game;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(game_get_num_links(game) == 0);

  game_destroy(game);
}

void test1_game_get_all_links() {
  PRINT_TEST_RESULT(!game_get_all_links(NULL));
}

void test2_game_get_all_links() {
  Game        *game;
  int          i;
  Link        *lnk;
  const Link **array;
  BOOL         result = TRUE;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (!(lnk = link_create(i))) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    game_add_link(game, lnk);
  }

  if (!(array = game_get_all_links(game))) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (link_get_id(array[i]) != i) {
      result = FALSE;
      break;
    }
  }

  PRINT_TEST_RESULT(result);

  game_destroy(game);
}

void test1_game_no_enemy() {
  PRINT_TEST_RESULT(game_no_enemy(NULL) == ERROR);
}

void test2_game_no_enemy() {
  Game *game;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  game_no_enemy(game);

  PRINT_TEST_RESULT(!game_get_enemy(game));

  game_destroy(game);
}

void test1_game_get_link_from_id() {
  PRINT_TEST_RESULT(!game_get_link_from_id(NULL, TEST_ID));
}

void test2_game_get_link_from_id() {
  Game *game;
  int   i, target = TEST_SIZE / 2;
  Link *lnk, *answer;

  if (game_create(&game) == ERROR) {
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  for (i = 0; i < TEST_SIZE; i++) {
    if (i == target) {
      lnk    = link_create(TEST_ID);
      answer = lnk;
    } else {
      lnk = link_create(TEST_ID + i + 1);
    }
    if (!lnk) {
      game_destroy(game);
      PRINT_TEST_RESULT(FALSE);
      return;
    }
    game_add_link(game, lnk);
  }

  PRINT_TEST_RESULT(game_get_link_from_id(game, TEST_ID) == answer);

  game_destroy(game);
}
