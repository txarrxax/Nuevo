/**
 * @brief It tests the game reader module
 * @file game_reader_test.c
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
*/
#include <stdio.h>
#include <stdlib.h>
#include <game_reader.h>
#include <game_reader_test.h>
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
    int all = 1;

    if (argc < 2)
        printf("Running all test for module Game Reader:\n");
    else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 || test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
        }
    }

    if (all || test == 1)
        test1_game_reader_load_spaces();
    if (all || test == 2)
        test2_game_reader_load_spaces();
    if (all || test == 3)
        test3_game_reader_load_spaces();
    if (all || test == 4)
        test4_game_reader_load_spaces();
    if (all || test == 5)
        test1_game_reader_load_objects();
    if (all || test == 6)
        test2_game_reader_load_objects();
    if (all || test == 7)
        test3_game_reader_load_objects();
    if (all || test == 8)
        test4_game_reader_load_objects();
    if (all || test == 9)
        test1_game_reader_load_player();
    if (all || test == 10)
        test2_game_reader_load_player();
    if (all || test == 11)
        test3_game_reader_load_player();
    if (all || test == 12)
        test4_game_reader_load_player();
    if (all || test == 13)
        test1_game_reader_load_enemies();
    if (all || test == 14)
        test2_game_reader_load_enemies();
    if (all || test == 15)
        test3_game_reader_load_enemies();
    if (all || test == 16)
        test4_game_reader_load_enemies();
    if (all || test == 17)
        test1_game_reader_load_links();
    if (all || test == 18)
        test2_game_reader_load_links();
    if (all || test == 19)
        test3_game_reader_load_links();
    if (all || test == 20)
        test4_game_reader_load_links();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_game_reader_load_spaces(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_spaces(game, TEST_FILENAME) == OK);

    game_destroy(game);
}

void test2_game_reader_load_spaces(){
    PRINT_TEST_RESULT(game_reader_load_spaces(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_reader_load_spaces(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_spaces(game, NULL) == ERROR);

    game_destroy(game);
}

void test4_game_reader_load_spaces(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_spaces(game, TEST_WRONG_FILENAME) == ERROR);

    game_destroy(game);
}

void test1_game_reader_load_objects(){
    Game *game;
    Space *space;

    game_create(&game);
    space = space_create(11);
    game_add_space(game, space);
    PRINT_TEST_RESULT(game_reader_load_objects(game, TEST_FILENAME) == OK);

    game_destroy(game);
}

void test2_game_reader_load_objects(){
    PRINT_TEST_RESULT(game_reader_load_objects(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_reader_load_objects(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_objects(game, NULL) == ERROR);

    game_destroy(game);
}

void test4_game_reader_load_objects(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_objects(game, TEST_WRONG_FILENAME) == ERROR);

    game_destroy(game);
}

void test1_game_reader_load_player(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_player(game, TEST_FILENAME) == OK);

    game_destroy(game);
}

void test2_game_reader_load_player(){
    PRINT_TEST_RESULT(game_reader_load_player(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_reader_load_player(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_player(game, NULL) == ERROR);

    game_destroy(game);
}

void test4_game_reader_load_player(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_player(game, TEST_WRONG_FILENAME) == ERROR);

    game_destroy(game);
}

void test1_game_reader_load_enemies(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_enemies(game, TEST_FILENAME) == OK);

    game_destroy(game);
}

void test2_game_reader_load_enemies(){
    PRINT_TEST_RESULT(game_reader_load_enemies(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_reader_load_enemies(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_enemies(game, NULL) == ERROR);

    game_destroy(game);
}

void test4_game_reader_load_enemies(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_enemies(game, TEST_WRONG_FILENAME) == ERROR);

    game_destroy(game);
}

void test1_game_reader_load_links(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_links(game, TEST_FILENAME) == OK);

    game_destroy(game);
}

void test2_game_reader_load_links(){
    PRINT_TEST_RESULT(game_reader_load_links(NULL, TEST_FILENAME) == ERROR);
}

void test3_game_reader_load_links(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_links(game, NULL) == ERROR);

    game_destroy(game);
}

void test4_game_reader_load_links(){
    Game *game;

    game_create(&game);
    PRINT_TEST_RESULT(game_reader_load_links(game, TEST_WRONG_FILENAME) == ERROR);

    game_destroy(game);
}