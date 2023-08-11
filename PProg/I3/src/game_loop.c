/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Diego Fernández
 * @version 2.0
 * @date 8-2-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphic_engine.h>
#include <game.h>
#include <command.h>
#include <types.h>

/**
 * @brief It initializes a game and its graphic engine with the data from the given file
 * @author Diego Fernández
 *
 * @param game pointer to the game session that will be initialized
 * @param gengine pointer to the graphic engine that will be initialized
 * @param file_name path of the file with the data needed to initialize the game
 * @return OK if successful or ERROR if there was an issue
 */
STATUS game_loop_init(Game **game, Graphic_engine **gengine, char *file_name);

/**
 * @brief It runs the game loop
 * @author Profesores PPROG
 *
 * @param game the game session
 * @param gengine the graphic engine that will be printing the output
 * @param f a pointer to a file
 */
void game_loop_run(Game *game, Graphic_engine *gengine, FILE *f);

/**
 * @brief It destroys the game session and the game engine before leaving the application
 * @author Profesores PPROG
 *
 * @param game game session to be destroyed
 * @param gengine graphic engine to be destroyed
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/** main function
 */
int main(int argc, char *argv[]) {
  Game *game=NULL;
  Graphic_engine *gengine;
  FILE *f=NULL;

  /*It is made sure that the game data file has been passed through the arguments*/
  if (argc != 2 && argc != 4) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }else if (argc == 4){ 
    if (strcmp(argv[2], "-l") != 0){ 
      fprintf(stderr, "Incorrect arguments\n");
      return 1;
    }
    if (!(f = fopen(argv[3], "w"))){ 
      fprintf(stderr, "Error: could not create log file '%s'\n", argv[3]);
      return 1;
    }
  }
 
  /*We initialize and run the game loop and make the necessary cleanup afterwards*/
  if (game_loop_init(&game, &gengine, argv[1]) == OK) {
    game_loop_run(game, gengine, f);
    game_loop_cleanup(game, gengine);
  }

  if (f != NULL)
    fclose(f);

  return 0;
}

/** game_loop_init initializes a game session and its graphic engine
 */
STATUS game_loop_init(Game **game, Graphic_engine **gengine, char *file_name) {
  /*The game is initialized from the given file*/
  if (game_create_from_file(game, file_name) == ERROR) {
    /*Error control*/
    game_destroy(*game);
    fprintf(stderr, "Error while initializing game.\n");
    return ERROR;
  }

  /*The graphic engine is initialized*/
  if (!(*gengine = graphic_engine_create())) {
    /*Error control*/
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(*game);
    return ERROR;
  }

  return OK;
}

/** game_loop_run runs the game loop
 */
void game_loop_run(Game *game, Graphic_engine *gengine, FILE *f) {
  extern char *cmd_to_str[N_CMD][N_CMDT];
  T_Command command = NO_CMD;
  char arg[CMD_LENGTH]="";
  STATUS update_exit;

  /*Error control*/
  if (!gengine)
    return;

  /*The game loops as long as gameover conditions are not met and the last command is not EXIT*/
  while ((command != EXIT) && !game_is_over(game)) {
    /*Each iteration of the loop the output is refreshed, a command is read from the user and the game state is updated accordingly*/
    graphic_engine_paint_game(gengine, game);
    command = command_get_user_input(arg);
    update_exit = game_update(game, command, arg);
    if (f != NULL)
      fprintf(f, "%s (%s) %s\n%s\n", cmd_to_str[command - NO_CMD][CMDL], cmd_to_str[command - NO_CMD][CMDS], arg, update_exit == OK? "OK" : "ERROR");
  }
}

/** game_loop_cleanup destroys the game session and the graphic engine
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine) {
  game_destroy(game);
  if (gengine != NULL)
    graphic_engine_destroy(gengine);
}
