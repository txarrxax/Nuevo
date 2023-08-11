/**
 * @brief It defines all the information needed by GameRules
 *
 * @file game_rules.h
 * @author Miguel Angel Sacristan
 * @version 1.0
 * @date 21-04-2023
 * @copyright GNU Public License
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include <game.h>
#include <types.h>

/**
 * @brief Struct that stores the Grules information
 */
typedef struct _Grules Grules;

/**
 * @brief Max number of elements read in a single rule
 */
#define MAX_RARG 22

/**
 * @brief Max number of dialogues that can be printed in a single implementation
 */
#define MAX_RULES 100

/**
 * @brief Max number of characters that can be stored in a dialogue
 */
#define MAX_TEXT 10000

/**
 * @brief Id number of the Toxic protection object
 */
#define PRO_SUIT 21

/**
 * @brief Id number of a Toxic space
 */
#define TOXIC_1 211

/**
 * @brief Id number of a Toxic space
 */
#define TOXIC_2 224

/**
 * @brief Id number of a Toxic space
 */
#define TOXIC_3 313

/**
 * @brief Id number of a Toxic space
 */
#define TOXIC_4 314

/**
 * @brief Number of actions allowed in a toxic space before reducing life
 */
#define TOXIC_COUNT 2

/**
 * @brief Id number of a Life rule object
 */
#define POISON 34

/**
 * @brief Id number of a Life rule object
 */
#define CURE 31

/**
 * @brief Id number of the Hack dropping space
 */
#define HACK_FIXING 333

/**
 * @brief Id number of the Hack closing link
 */
#define CLOSING_LINK 77

/**
 * @brief Id number of the Hack fixing object
 */
#define WIRES 33

/**
 * @brief Number of actions allowed before loosing a health point when Hack is active
 */
#define POWER 4

/**
 * @brief Enemy health when running away
 */
#define RUNAWAY_HEALTH 2

/**
 * @brief Health points given to the enemy when running away
 */
#define RESET_HEALTH 5

/**
 * @brief Id number of the Link to open during Escape rule
 */
#define RUNAWAY_LINK_1 91

/**
 * @brief Id number of the Link to open during Escape rule
 */
#define RUNAWAY_LINK_2 92

/**
 * @brief Id number of the space where the enemy escapes
 */
#define NEW_LOCATION 122

/**
 * @brief Id number of the Link to close during Broken_link rule
 */
#define ELEVATOR 51

/**
 * @brief Id number of the object that solves Broken_link rule
 */
#define FIX_ELEVATOR 26

/**
 * @brief Id number of the space where Light rule begins
 */
#define TORCH_OFF 322

/**
 * @brief Id number of the object to cancel during Light rule
 */
#define LANTERN 11

/**
 * @brief Id number of the object that solves Light rule
 */
#define CHARGER 35

/**
 * @brief Id number of the Upgrade space
 */
#define UP_SPACE 414

/**
 * @brief Stats that will be added to the player in Upgrade rule
 */
#define UP_STAT 2

/**
 * @brief It creates a new Grules structure and initializes its data
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @return a pointer to a Grules structure, NULL if there was an issue
 */
Grules *game_rules_init(Game *game);

/**
 * @brief It initializes a Grule structure from a file
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param filename a pointer to the file name
 * @return a pointer to the new Grule structure, NULL if there was an issue
 */
Grules *game_rules_init_from_file(Game *game, char *filename);

/**
 * @brief It destroys a Grules structures and frees its memory
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 */
STATUS game_rules_destroy(Grules *grules);

/**
 * @brief It implements the game_rules module
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @param arg game last command argument
 * @return OK if the rules have been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_implement(Game *game, Grules *grules, char *arg);

/**
 * @brief It resets all the dialogues to empty
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @return OK if the rule have been reseted correctly, ERROR if there was an issue
 */
STATUS game_rules_reset_rules(Grules *grules);

/**
 * @brief It gets a dialogue from its position
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param i the position of the dialogue
 * @return the dialogue, NULL if there was an issue
 */
char *game_rules_get_rule(Grules *grules, int i);

/**
 * @brief It gets the number of dialogues to print in an implementation
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @return the number of rules, -1 if there was an issue
 */
int game_rules_get_num_rules(Grules *grules);

#endif
