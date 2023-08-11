/**
 * @brief Implementation of the GAME_LOOP module
 * @file game_loop.c
*/

#include "game.h"
#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief It initializes the game
 * 
 * @param game a pointer to a pointer to the game
 * @param gengine a pointer to a pointer to the graphic engine
 * @param filename the name of the file with the game's information
 * @return OK if everything goes well, ERROR if not
*/
Status game_loop_init(Game **game, Graphic_engine **gengine, char *filename);

/**
 * @brief It runs the game
 * 
 * @param game a pointer to a pointer to the game
 * @param gengine a pointer to the graphic engine
 * @return no return
*/
void game_loop_run(Game **game, Graphic_engine *gengine);

/**
 * @brief It destroys the game session and the graphic engine
 * 
 * @param game a pointer to the game
 * @param gengine a pointer to the graphic engine
 * @return no return
*/
void game_loop_cleanup(Game *game, Graphic_engine *gengine);


/**
 * @brief main function
*/
int main(int argc, char *argv[]){
    Game *game = NULL;
    Graphic_engine *gengine = NULL;
    FILE *f = NULL;

    if (game_loop_init(&game, &gengine, argv[1]) == OK){
        game_loop_run(&game, gengine);
        game_loop_cleanup(game, gengine);
    }

    return 0;
}

/**
 * game_loop_init initializes the game
*/
Status game_loop_init(Game **game, Graphic_engine **gengine, char *filename){
    if (game_create(game) == ERROR){
        fprintf(stderr, "Error while initializing the game.\n");
        return ERROR;
    }
    
    if ((*gengine = graphic_engine_create()) == NULL){
        fprintf(stderr, "Error while initializing the graphic engine.\n");
        game_destroy(game);
        return ERROR;
    }

    fprintf(stdout, "Welcome to Battleship. Press enter to continue.");
    fscanf(stdin, "%s");
    fprintf(stdout, "We are going to create the game. Please, complete the next fields.");
    

    return OK;
}

/**
 * game_loop_run runs the game
*/
void game_loop_run(Game **game, Graphic_engine *gengine){
    while (game_is_over(&game) == FALSE){
        graphic_engine_paint_game(gengine, &game);
        command = game_get_user_input();
        game_update(&game, command);
    }
}