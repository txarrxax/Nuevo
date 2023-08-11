/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"
#include "set.h"

#define ROWS 30
#define COLUMNS 110

/*
 * Structure that holds the five areas of the graphic engine
 */
struct _Graphic_engine {
  Area *map, *descript, *banner, *help, *feedback;
};

/*
 * graphic_engine_create allocates memory for a new graphic engine and its areas, only if the graphic engine did not exist
 */
Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (!ge)
    return NULL;

  ge->map = screen_area_init(1, 1, 72, 20);
  ge->descript = screen_area_init(74, 1, 35, 13);
  ge->banner = screen_area_init(40, 22, 25, 1);
  ge->help = screen_area_init(1, 23, 106, 2);
  ge->feedback = screen_area_init(1, 26, 106, 3);

  return ge;
}

/*
 * graphic_engine_destroy frees the areas and the screen of an existing graphic engine
 */
void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/*
 * graphic_engine_paint_game paints or writes on the different areas of the graphic engine
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_right = NO_ID, id_left = NO_ID;
  Id enm_loc = NO_ID, ply_loc = NO_ID, obj_id = NO_ID;
  Space *space_act = NULL;
  char enm[8], enm_left[8], enm_right[8];
  char str[500];
  char **gd, **gd_left, **gd_right;
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i, num;
  Set *objects, *objects_left, *objects_right;
  char obj_str[128] = "\0", obj_left_str[128] = "\0", obj_right_str[128] = "\0", aux[128] = "\0";
  STATUS status;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_right = space_get_east(space_act);
    id_left = space_get_west(space_act);

    if (id_left != NO_ID){
      
      if(game_get_enemy_location(game) == id_back && enemy_get_health(game->enemy) > 0)
        strcpy(enm, "/\\oo/\\");
      else
        strcpy(enm, "      ");

      if (id_back != NO_ID){
        gd = space_get_gDesc(game_get_space(game, id_back));
        sprintf(str, "                 |     %6s %2d|", (char*)enm, (int)id_back);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "                 | %9s     |", gd[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
        }
        objects = space_get_objects(game_get_space(game, id_back));
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(space_act); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        sprintf(str, "  |%15s|", obj_str);
        screen_area_puts(ge->map, str);
        sprintf(str, "                 +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                       ^");
        screen_area_puts(ge->map, str);
        free(gd);
      }
      
      else if (id_next == NO_ID){
      	sprintf(str, " ");
      	screen_area_puts(ge->map, str);
      	screen_area_puts(ge->map, str);
      	screen_area_puts(ge->map, str);
      	screen_area_puts(ge->map, str);
      }

      if(game_get_enemy_location(game) == id_act && enemy_get_health(game->enemy) > 0)
        strcpy(enm, "/\\oo/\\");
      else
        strcpy(enm, "      ");
      
      if(game_get_enemy_location(game) == id_left && enemy_get_health(game->enemy) > 0)
        strcpy(enm_left, "/\\oo/\\");
      else
        strcpy(enm_left, "      ");
      
      if(game_get_enemy_location(game) == id_right && enemy_get_health(game->enemy) > 0)
        strcpy(enm_right, "/\\oo/\\");
      else
        strcpy(enm_right, "      ");

      if (id_act != NO_ID && id_right != NO_ID){
        gd = space_get_gDesc(space_act);
        gd_left = space_get_gDesc(game_get_space(game, id_left));
        gd_right = space_get_gDesc(game_get_space(game, id_right));
        sprintf(str, "  ---------------+   +---------------+   +---------------");
        screen_area_puts(ge->map, str);
        sprintf(str, "        %6s %2d| < | m0^  %6s %2d| > |      %6s %2d", (char*)enm_left, (int)id_left, (char*)enm, (int)id_act, (char*)enm_right, (int)id_right);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "   %9s     |   | %9s     |   | %9s      ", gd_left[i], gd[i], gd_right[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
          free(gd_left[i]);
          free(gd_right[i]);
        }
        objects = space_get_objects(space_act);
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(space_act); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        objects_left = space_get_objects(game_get_space(game, id_left));
        strcpy(obj_left_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(game_get_space(game, id_left)); i++){
          num += sprintf(aux, "O%ld ", objects_left->ids[i]);
          strcat(obj_left_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_left_str, " ");
        objects_right = space_get_objects(game_get_space(game, id_right));
        strcpy(obj_right_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(game_get_space(game, id_right)); i++){
          num += sprintf(aux, "O%ld ", objects_right->ids[i]);
          strcat(obj_right_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_right_str, " ");
        sprintf(str, "  %15s|   |%15s|   |%15s", obj_left_str, obj_str, obj_right_str);
        screen_area_puts(ge->map, str);
        sprintf(str, "  ---------------+   +---------------+   +---------------");
        screen_area_puts(ge->map, str);
        free(gd);
        free(gd_left);
        free(gd_right);
      }

      else if (id_act != NO_ID){
        gd = space_get_gDesc(space_act);
        gd_left = space_get_gDesc(game_get_space(game, id_left));
        sprintf(str, "  ---------------+   +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "        %6s %2d| < | m0^  %6s %2d|", (char*)enm_left, (int)id_left, (char*)enm, (int)id_act);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "   %9s     |   | %9s     |", gd_left[i], gd[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
          free(gd_left[i]);
        }
        objects = space_get_objects(space_act);
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(space_act); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        objects_left = space_get_objects(game_get_space(game, id_left));
        strcpy(obj_left_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(game_get_space(game, id_left)); i++){
          num += sprintf(aux, "O%ld ", objects_left->ids[i]);
          strcat(obj_left_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_left_str, " ");
        sprintf(str, "  %15s|   |%15s|", obj_left_str, obj_str);
        screen_area_puts(ge->map, str);
        sprintf(str, "  ---------------+   +---------------+");
        screen_area_puts(ge->map, str);
        free(gd);
        free(gd_left);
      }

      
      if(game_get_enemy_location(game) == id_next && enemy_get_health(game->enemy) > 0)
        strcpy(enm, "/\\oo/\\");
      else
        strcpy(enm, "      ");

      if (id_next != NO_ID){
        gd = space_get_gDesc(game_get_space(game, id_next));
        sprintf(str, "                       v");
        screen_area_puts(ge->map, str);
        sprintf(str, "                     +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                     |     %6s %2d|", (char*)enm, (int)id_next);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "                 | %9s     |", gd[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
        }
        objects = space_get_objects(game_get_space(game, id_next));
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(space_act); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        sprintf(str, "                    |%15s|", obj_str);
        free(gd);
      }
    }

    else{
      
      if(game_get_enemy_location(game) == id_back && enemy_get_health(game->enemy) > 0)
        strcpy(enm, "/\\oo/\\");
      else
        strcpy(enm, "      ");

      if (id_back != NO_ID) {
        gd = space_get_gDesc(game_get_space(game, id_back));
        sprintf(str, "  |      %6s %2d|", (char*)enm, (int)id_back);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "  | %9s     |", gd[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
        }
        objects = space_get_objects(game_get_space(game, id_back));
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(game_get_space(game, id_back)); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        sprintf(str, "  |%15s|", obj_str);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "        ^");
        screen_area_puts(ge->map, str);
        free(gd);
      }
      
      if(game_get_enemy_location(game) == id_act && enemy_get_health(game->enemy) > 0)
        strcpy(enm, "/\\oo/\\");
      else
        strcpy(enm, "      ");
      
      if(game_get_enemy_location(game) == id_right && enemy_get_health(game->enemy) > 0)
        strcpy(enm_right, "/\\oo/\\");
      else
        strcpy(enm_right, "      ");

      if (id_act != NO_ID && id_right != NO_ID){
        gd = space_get_gDesc(space_act);
        gd_right = space_get_gDesc(game_get_space(game, id_right));
        sprintf(str, "  +---------------+   +---------------");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | m0^  %6s %2d| > |      %6s %2d", (char*)enm, (int)id_act, (char*)enm_right, (int)id_right);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "  | %9s     |   | %9s     ", gd[i], gd_right[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
          free(gd_right[i]);
        }
        objects = space_get_objects(space_act);
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(space_act) && num<15; i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        objects_right = space_get_objects(game_get_space(game, id_right));
        strcpy(obj_right_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(game_get_space(game, id_right)); i++){
          num += sprintf(aux, "O%ld ", (long)objects_right->ids[i]);
          strcat(obj_right_str, aux);
        }
        for (; num<14; num++)
          strcat(obj_right_str, " ");
        sprintf(str, "  |%15s|   |%15s", obj_str, obj_right_str);
        printf("%d\n", num);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +---------------+   +---------------");
        screen_area_puts(ge->map, str);
        free(gd);
        free(gd_right);
      }

      else if (id_act != NO_ID){
        gd = space_get_gDesc(space_act);
        sprintf(str, "  +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | m0^  %6s %2d|", (char*)enm, (int)id_act);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "  | %9s     |", gd[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
        }
        objects = space_get_objects(space_act);
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(space_act); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        sprintf(str, "  |%15s|", obj_str);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +---------------+");
        screen_area_puts(ge->map, str);

        free(gd);

      }

      
      if(game_get_enemy_location(game) == id_next && enemy_get_health(game->enemy) > 0)
        strcpy(enm, "/\\oo/\\");
      else
        strcpy(enm, "      ");

      if (id_next != NO_ID){
        gd = space_get_gDesc(game_get_space(game, id_next));
        sprintf(str, "        v");
        screen_area_puts(ge->map, str);
        sprintf(str, "  +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  |      %6s %2d|", (char*)enm, (int)id_next);
        screen_area_puts(ge->map, str);
        for (i=0; i<HEIGHT; i++){
          sprintf(str, "  | %9s     |", gd[i]);
          screen_area_puts(ge->map, str);
          free(gd[i]);
        }
        objects = space_get_objects(game_get_space(game, id_next));
        strcpy(obj_str, "\0");
        for (i=0, num=0; i<space_get_numberOfObjects(game_get_space(game, id_next)); i++){
          num += sprintf(aux, "O%ld ", objects->ids[i]);
          strcat(obj_str, aux);
        }
        for (; num<15; num++)
          strcat(obj_str, " ");
        sprintf(str, "  |%15s|", obj_str);
        screen_area_puts(ge->map, str);
        free(gd);
      }
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  if (game->objects[0] != NULL){
    sprintf(str, "  Objects location:");
    screen_area_puts(ge->descript, str);
    strcpy(obj_str, "  ");
    for (i=0; i<MAX_OBJECTS && game->objects[i]!=NULL; i++){
      obj_id = object_get_id(game->objects[i]);
      sprintf(str, "%ld:%ld", obj_id, game_get_object_location(game, obj_id));
      strcat(obj_str, str);
      if (game->objects[i+1] != NULL)
        strcat(obj_str, ", ");
    }
    screen_area_puts(ge->descript, obj_str);
  }

  


  if ((ply_loc = game_get_player_location(game)) != NO_ID){
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  Player location: %d", (int)ply_loc);
    screen_area_puts(ge->descript, str);
  }
  if ((obj_id = object_get_id(player_get_object(game->player))) != NO_ID){
    sprintf(str, "  Player object: %d", (int)obj_id);
    screen_area_puts(ge->descript, str);
  }
  if (player_get_health(game->player) != -1){
    sprintf(str, "  Player health: %2d", player_get_health(game->player));
    screen_area_puts(ge->descript, str);
  }

  if ((enm_loc = game_get_enemy_location(game)) != NO_ID){
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  Enemy location: %d", (int)enm_loc);
    screen_area_puts(ge->descript, str);
  }

  if (enemy_get_health(game->enemy) != -1){
    sprintf(str, "  Enemy health: %2d", enemy_get_health(game->enemy));
    screen_area_puts(ge->descript, str);
  }
  
  /*if ((enm_loc = game_get_enemy_location(game)) != NO_ID){
    sprintf(str, "  Enemy location:%d", (int)enm_loc);
    screen_area_puts(ge->descript, str);
  }*/
  

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, left or l, right or r, take or t, drop or d, attack or a, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  status = game_get_last_commandSt(game);
  if (status == OK || last_cmd == EXIT)
    sprintf(str, " %s (%s): OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  else if (last_cmd == UNKNOWN)
    sprintf(str, " %s command", cmd_to_str[last_cmd - NO_CMD][CMDL]);
  else if (last_cmd == NO_CMD)
    sprintf(str, " %s", cmd_to_str[last_cmd - NO_CMD][CMDL]);
  else
    sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);

  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}