/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <command.h>
#include <graphic_engine.h>
#include <inventory.h>
#include <libscreen.h>
#include <player.h>
#include <space.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>
#include <game.h>
#include <game_rules.h>

/**
 * @brief Number of rows on the display
 */
#define ROWS 40

/**
 * @brief Number of columns on the display
 */
#define COLUMNS 150

/**
 * @brief Blank area length
 */
#define BLANK_LEN 10

/**
 * @brief Length of the object descriptions
 */
#define OBJ_LEN 18

/**
 * @brief Numbre of newlines for the death screen
 */
#define NEWLINE_COUNT 70

/**
 * @brief This struct stores all the information of the graphic engine
 */
struct _Graphic_engine {
  Area *map;      /*!< The image of the virtual world */
  Area *descript; /*!< Description area */
  Area *banner;   /*!< Banner area */
  Area *help;     /*!< Help area */
  Area *feedback; /*!< Prompt area */
};

/** graphic_engine_create creates a new graphic engine
 */
Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  /*Error control*/
  if (ge) return ge;

  /*Intergace is initialized*/
  screen_init(ROWS, COLUMNS);
  /*Dynamic memory for the graphic engine is allocated*/
  /*Error control*/
  if (!(ge = malloc(sizeof(Graphic_engine)))) return NULL;

  /*The space that each section takes on the screen is defined*/
  ge->map      = screen_area_init(1, 1, 69, 29);
  ge->descript = screen_area_init(75, 1, 74, 38);
  ge->banner   = screen_area_init(26, 31, 23, 1);
  ge->help     = screen_area_init(1, 32, 73, 2);
  ge->feedback = screen_area_init(1, 34, 73, 5);
  /*Return the new graphic engine*/
  return ge;
}

/** graphic_engine_destroy destroys the given graphic engine
 */
void graphic_engine_destroy(Graphic_engine *ge) {
  /*Error control*/
  if (!ge) return;

  /*Each graphic area is destroyed individually*/
  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  /*The interface is deactivated and the memory is freed*/
  screen_destroy();
  free(ge);
}

/** graphic_engine_paint_game paints the contents of the graphic engine to the
 * interface
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game, Grules *grules) {
  /*Ids of adjacent rooms and object location*/
  Id     id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID, id_right = NO_ID, id_left = NO_ID, id_enemy = NO_ID;
  Space *space_act = NULL, *space_v = NULL, *space_right = NULL, *space_left = NULL;

  /* Auxiliar status for loops */
  STATUS st;

  /* Auxiliar variables for rules */
  int  num_rules, printed;
  char rule[MAX_RULES][WORD_SIZE];

  /*Container of information to be painted*/
  char         str[257], obj_desc[OBJ_LEN], obj_desc_l[OBJ_LEN], obj_desc_r[OBJ_LEN], last_des[255];
  const char  *tmp;
  const char **gdesc, **gdesc_left, **gdesc_right;

  /*19 for empty spaces*/
  const char blanks[21] = "                    ";
  /*Enemy asset*/
  const char enemy[7] = "/\\oo/\\";
  int        health_output, i;
  const Id  *obj_ids;
  char       g_link_status, g_link_stat_b;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = player_get_location(game_get_player(game))) != NO_ID) {
    space_act = game_get_space(game, id_act);

    id_back  = game_get_connection(game, space_get_id(space_act), N);
    id_next  = game_get_connection(game, space_get_id(space_act), S);
    id_right = game_get_connection(game, space_get_id(space_act), E);
    id_left  = game_get_connection(game, space_get_id(space_act), W);
    id_enemy = enemy_get_location(game_get_enemy(game));

    if (id_back != NO_ID) {
      gdesc         = space_get_gdesc((space_v = game_get_space(game, id_back)));
      g_link_status = game_get_connection_status(game, id_act, N) == OK ? '^' : 'x';
      if (gdesc == NULL) return;

      sprintf(str, "%s+---------------+", blanks);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|     %s %3d|", blanks, id_enemy == id_back ? enemy : "      ", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[4]);
      screen_area_puts(ge->map, str);
      game_get_space_obj_desc(game, space_v, obj_desc);
      sprintf(str, "%s%s", blanks, obj_desc);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s+---------------+", blanks);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s        %c        ", blanks, g_link_status);
      screen_area_puts(ge->map, str);
    } else {
      for (i = 0; i < BLANK_LEN; i++) {
        sprintf(str, "%s%s", blanks, blanks);
        screen_area_puts(ge->map, str);
      }
    }

    if (id_act != NO_ID) {
      if (id_left == NO_ID && id_right == NO_ID) {
        gdesc = space_get_gdesc(space_act);
        if (gdesc == NULL) return;

        sprintf(str, "%s+---------------+", blanks);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s| %s %s %3d|", blanks, "mo^", id_enemy == id_act ? enemy : "      ", (int)id_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |", blanks, gdesc[0]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |", blanks, gdesc[1]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |", blanks, gdesc[2]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |", blanks, gdesc[3]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |", blanks, gdesc[4]);
        screen_area_puts(ge->map, str);
        game_get_space_obj_desc(game, space_act, obj_desc);
        sprintf(str, "%s%s", blanks, obj_desc);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s+---------------+", blanks);
        screen_area_puts(ge->map, str);
      } else if (id_left != NO_ID && id_right == NO_ID) {
        gdesc         = space_get_gdesc(space_act);
        g_link_status = game_get_connection_status(game, id_act, W) == OK ? '<' : 'x';
        if (gdesc == NULL) return;

        gdesc_left = space_get_gdesc((space_left = game_get_space(game, id_left)));
        if (gdesc_left == NULL) return;

        sprintf(str, "  +---------------+ +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %s %3d| | %s %s %3d|", id_enemy == id_left ? enemy : "      ", (int)id_left, "mo^", id_enemy == id_act ? enemy : "      ", (int)id_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      | |%s      |", gdesc_left[0], gdesc[0]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      |%c|%s      |", gdesc_left[1], g_link_status, gdesc[1]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      |%c|%s      |", gdesc_left[2], g_link_status, gdesc[2]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      |%c|%s      |", gdesc_left[3], g_link_status, gdesc[3]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      | |%s      |", gdesc_left[4], gdesc[4]);
        screen_area_puts(ge->map, str);
        game_get_space_obj_desc(game, space_left, obj_desc_l);
        game_get_space_obj_desc(game, space_act, obj_desc);
        sprintf(str, "  %s %s", obj_desc_l, obj_desc);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +---------------+ +---------------+");
        screen_area_puts(ge->map, str);
      } else if (id_left == NO_ID && id_right != NO_ID) {
        gdesc         = space_get_gdesc(space_act);
        g_link_status = game_get_connection_status(game, id_act, E) == OK ? '>' : 'x';
        if (gdesc == NULL) return;

        gdesc_right = space_get_gdesc((space_right = game_get_space(game, id_right)));
        if (gdesc_right == NULL) return;

        sprintf(str, "%s+---------------+ +---------------+", blanks);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s| %s %s %3d| |     %s %3d|", blanks, "mo^", id_enemy == id_act ? enemy : "      ", (int)id_act, id_enemy == id_right ? enemy : "      ", (int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      | |%s      |", blanks, gdesc[0], gdesc_right[0]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |%c|%s      |", blanks, gdesc[1], g_link_status, gdesc_right[1]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |%c|%s      |", blanks, gdesc[2], g_link_status, gdesc_right[2]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      |%c|%s      |", blanks, gdesc[3], g_link_status, gdesc_right[3]);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s|%s      | |%s      |", blanks, gdesc[4], gdesc_right[4]);
        screen_area_puts(ge->map, str);
        game_get_space_obj_desc(game, space_act, obj_desc);
        game_get_space_obj_desc(game, space_right, obj_desc_r);
        sprintf(str, "%s%s %s", blanks, obj_desc, obj_desc_r);
        screen_area_puts(ge->map, str);
        sprintf(str, "%s+---------------+ +---------------+", blanks);
        screen_area_puts(ge->map, str);
      } else {
        gdesc         = space_get_gdesc(space_act);
        g_link_status = game_get_connection_status(game, id_act, W) == OK ? '<' : 'x';
        g_link_stat_b = game_get_connection_status(game, id_act, E) == OK ? '>' : 'x';
        if (gdesc == NULL) return;

        gdesc_left = space_get_gdesc((space_left = game_get_space(game, id_left)));
        if (gdesc_left == NULL) return;

        gdesc_right = space_get_gdesc((space_right = game_get_space(game, id_right)));
        if (gdesc_right == NULL) return;

        sprintf(str, "  +---------------+ +---------------+ +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  |     %s %3d| | %s %s %3d| |     %s %3d|", id_enemy == id_left ? enemy : "      ", (int)id_left, "mo^", id_enemy == id_act ? enemy : "      ", (int)id_act, id_enemy == id_right ? enemy : "      ", (int)id_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      | |%s      | |%s      |", gdesc_left[0], gdesc[0], gdesc_right[0]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      |%c|%s      |%c|%s      |", gdesc_left[1], g_link_status, gdesc[1], g_link_stat_b, gdesc_right[1]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      |%c|%s      |%c|%s      |", gdesc_left[2], g_link_status, gdesc[2], g_link_stat_b, gdesc_right[2]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      |%c|%s      |%c|%s      |", gdesc_left[3], g_link_status, gdesc[3], g_link_stat_b, gdesc_right[3]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s      | |%s      | |%s      |", gdesc_left[4], gdesc[4], gdesc_right[4]);
        screen_area_puts(ge->map, str);
        game_get_space_obj_desc(game, space_left, obj_desc_l);
        game_get_space_obj_desc(game, space_act, obj_desc);
        game_get_space_obj_desc(game, space_right, obj_desc_r);
        sprintf(str, "  %s %s %s", obj_desc_l, obj_desc, obj_desc_r);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +---------------+ +---------------+ +---------------+");
        screen_area_puts(ge->map, str);
      }
    }

    if (id_next != NO_ID) {
      gdesc         = space_get_gdesc((space_v = game_get_space(game, id_next)));
      g_link_status = game_get_connection_status(game, id_act, S) == OK ? 'v' : 'x';
      if (gdesc == NULL) return;

      sprintf(str, "%s        %c        ", blanks, g_link_status);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s+---------------+", blanks);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|     %s %3d|", blanks, id_enemy == id_next ? enemy : "      ", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s      |", blanks, gdesc[4]);
      screen_area_puts(ge->map, str);
      game_get_space_obj_desc(game, space_v, obj_desc);
      sprintf(str, "%s%s", blanks, obj_desc);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s+---------------+", blanks);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  screen_area_puts(ge->descript, " ");
  screen_area_puts(ge->descript, "  Objects location:");
  /*Object info is printed*/
  for (i = 0; i < game_get_number_of_objects(game); i++) {
    if (((obj_loc = game_get_object_location(game, game_get_object_from_position(game, i))) != NO_ID) && object_get_hidden(game_get_object_from_position(game, i)) == FALSE && (player_get_location(game_get_player(game)) / 100) == (obj_loc / 100)) {
      sprintf(str, "  %s:%ld", object_get_name(game_get_object_from_position(game, i)), obj_loc);
      screen_area_puts(ge->descript, str);
    }
  }
  screen_area_puts(ge->descript, " ");

  /*The name of the room where the player is located is printed*/
  if ((tmp = space_get_name(space_act)) != NULL) {
    sprintf(str, "  Player location: %s", tmp);
    screen_area_puts(ge->descript, str);
    screen_area_puts(ge->descript, " ");
  }

  /*Player health is displayed*/
  if ((health_output = player_get_health(game_get_player(game))) != -1) {
    sprintf(str, "  Player health: %d", health_output);
    screen_area_puts(ge->descript, str);
    screen_area_puts(ge->descript, " ");
  }

  /*Player objects are displayed*/
  screen_area_puts(ge->descript, "  Inventory:");
  obj_ids = set_get_ids(inventory_get_objs(player_get_inventory(game_get_player(game))));
  for (i = 0; i < inventory_get_max_objs(player_get_inventory(game_get_player(game))); i++) {
    if (obj_ids[i] != NO_ID) {
      sprintf(str, "  %s", object_get_name(game_get_object_from_id(game, obj_ids[i])));
      screen_area_puts(ge->descript, str);
    }
  }
  screen_area_puts(ge->descript, " ");

  /*Enemy location*/
  if (id_enemy != NO_ID) {
    sprintf(str, "  Enemy location: %ld", id_enemy);
    screen_area_puts(ge->descript, str);
    screen_area_puts(ge->descript, " ");
  }

  /*Enemy health is displayed*/
  if ((health_output = enemy_get_health(game_get_enemy(game))) != -1) {
    sprintf(str, "  Enemy health: %d", health_output);
    screen_area_puts(ge->descript, str);
    screen_area_puts(ge->descript, " ");
  }

  /* Descriptions are displayed*/
  sprintf(str, "  Space descriptions: ");
  screen_area_puts(ge->descript, str);
  st = OK;
  for (i = 0; st == OK; i++) {
    if ((id_act = game_get_space_id_at(game, i)) == NO_ID) {
      st = ERROR;
      break;
    }
    if ((space_act = game_get_space(game, id_act)) == NULL) {
      st = ERROR;
      break;
    }
    if ((player_get_location(game_get_player(game))) / 100 == (id_act / 100)) {
      sprintf(str, "  %s: %s", space_get_name(space_act), space_get_description(space_act));
      screen_area_puts(ge->descript, str);
    }
  }
  screen_area_puts(ge->descript, " ");
  strcpy(last_des, game_get_last_description(game));
  if (last_des[0] != '\0') {
    sprintf(str, "  Descriptions: ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  %s", last_des);
    screen_area_puts(ge->descript, str);
  }

  screen_area_puts(ge->descript, " ");
  num_rules = game_rules_get_num_rules(grules);
  i         = 0;
  if (num_rules > 0) {
    screen_area_puts(ge->descript, "  Rules: ");
    for (printed = 0; printed < num_rules; printed++) {
      printf("Imprimir: %d", printed);
      strcpy(rule[printed], game_rules_get_rule(grules, printed + 1));
      if (rule[printed][0] != '\0') {
        screen_area_puts(ge->descript, rule[printed]);
        printf("\n %d", printed);
      }
    }
  }
  game_rules_reset_rules(grules);

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);

  sprintf(str, " The commands you can use are: move or m, take or t, drop or d, attack or a, inspect or i, switch or s, open or o, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  screen_area_puts(ge->feedback, game_get_last_dialogue(game));

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}

/** graphic_engine_death prints the death screen
 */
void graphic_engine_death() {
  int i;

  for (i = 0; i < NEWLINE_COUNT; i++) {
    printf("\n");
  }

  printf(" \n");
  printf("                      :::!-!!!!!:.\n");
  printf("                  .xUHWH!! !!?M88WHX:.\n");
  printf("                .X*#M@$!!  !X!M$$$$$$WWx:.\n");
  printf("               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n");
  printf("              !!-  -:-!! :-!$!#$$$$$$$$$$8X:\n");
  printf("             :!-::!H!<   -.U$X!?R$$$$$$$$MM!\n");
  printf("             -!-!!!!-- .:XW$$$U!!?$$$$$$RMM!\n");
  printf("               !:--- .:!M\"T#$$$$WX??#MRRMMM!\n");
  printf("               -?WuxiW*`   `\"#$$$$8!!!!!?!!!\n");
  printf("             :X- M$$$$       `\"T#$T-!8$WUXU-\n");
  printf("            :%%`  -#$$$m:        -!- ?$$$$$$\n");
  printf("          :!`.-   -T$$$$8xx.  .xWW- -\"\"##*\"\n");
  printf(".....   ---:<` !    -?T#$$@@W@*?$$      /`\n");
  printf("W$@@M!!! .!-- !!     .:XUW$W!- `\"-:    :\n");
  printf("#\"--`.:x%%`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n");
  printf(":::-:!!`:X- .: ?H.!u \"$$$B$$$!W:U!T$$M-\n");
  printf(".--   :X@!.--   ?@WTWo(\"*$$$W$TH$! `\n");
  printf("Wi.-!X$?!--    : ?$$$B$Wu(\"**$RM!\n");
  printf("$R@i.-- !     :   -$$$$$B$$en:``\n");
  printf("?MXT@Wx.-    :     -\"##*$$$$M-\n\n\n\033[31;1mMORTIS\n\033[0m");
}

void graphic_engine_win() {
  int i;

  for (i = 0; i < NEWLINE_COUNT; i++) {
    printf("\n");
  }

  printf(" \n");
  printf("   ***********      ********      **********          ***************          *********        *****\n");
  printf("    ***********     ********     **********           ***************          **********       *****\n");
  printf("     ***********    ********    **********            ***************          ***********      *****\n");
  printf("      ***********   ********   **********                *********             ************     *****\n");
  printf("       ***********  ********  **********                 *********             ****** ******    *****\n");
  printf("        *********** ******** **********                  *********             ******  ******   *****\n");
  printf("         *****************************                   *********             ******   ******  *****\n");
  printf("          ***************************                    *********             ******    ****** *****\n");
  printf("           ************ ************                  ***************          ******     ***********\n");
  printf("            **********   **********                   ***************          ******      **********\n");
  printf("             ********     ********                    ***************          ******       *********\n");
  printf("\n");
  printf("\n");
}
