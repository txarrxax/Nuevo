/**
 * @brief It implements the dialogue module
 *
 * @file dialogue.c
 * @author Alberto Tarrasa
 * @version 2.0
 * @date 20-04-2023
 * @copyright GNU Public License
 */

#include <dialogue.h>
#include <game.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * PRIVATE FUNCTIONS
 */
/**
 * @brief It shows the result of the UNKNOWN command
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_unknown(Game *game);

/**
 * @brief It shows the result of the EXIT command
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_exit(Game *game);

/**
 * @brief It shows the result of the TAKE command when the object is not in the room
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the TAKE command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_not_in_room(Game *game, const char *obj);

/**
 * @brief It shows the result of the TAKE command when the object is not movable
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the TAKE command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_not_movable(Game *game, const char *obj);

/**
 * @brief It shows the result of the TAKE command when the inventory is full
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the TAKE command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_full_inventory(Game *game, const char *obj);

/**
 * @brief It shows the result of the TAKE command when the object depends on another one
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the TAKE command
 * @param dep the name of the object on which obj depends
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_depends_on(Game *game, const char *obj, const char *dep);

/**
 * @brief It shows the result of the TAKE command when the object is taken
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the TAKE command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_taken(Game *game, const char *obj);

/**
 * @brief It shows the result of the DROP command when the object is not in the inventory
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the DROP command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_not_in_inventory(Game *game, const char *obj);

/**
 * @brief It shows the result of the DROP command when the object can't be dropped
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the DROP command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_full_space(Game *game, const char *obj);

/**
 * @brief It shows the result of the DROP command when the object is dropped
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the DROP command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_dropped(Game *game, const char *obj);

/**
 * @brief It shows the result of the SWITCH command when the object can't illuminate
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the SWITCH command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_cant_illuminate(Game *game, const char *obj);

/**
 * @brief It shows the result of the SWITCH command when the object is turned ON or OFF
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object called in the SWITCH command
 * @param turned TRUE if the object is turned ON, FALSE if it is OFF
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_switched(Game *game, const char *obj, const char *turned);

/**
 * @brief It shows the result of the MOVE command when the player has moved to a new space
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param dir the name of the direction called in the MOVE command
 * @param space the name of the new space
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_moved(Game *game, const char *dir, const char *space);

/**
 * @brief It shows the result of the MOVE command when the link is closed
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param dir the name of the direction called in the MOVE command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_link(Game *game, const char *dir);

/**
 * @brief It shows the result of the MOVE command when the direction is wrong
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param dir the name of the direction called in the MOVE command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_wrong_dir(Game *game, const char *dir);

/**
 * @brief It shows the result of the MOVE command when no direction is read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_dir(Game *game);

/**
 * @brief It shows the result of the ATTACK command when there is no enemy in the room
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_enemy(Game *game);

/**
 * @brief It shows the result of the ATTACK command when the player is hurt
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_player_hurt(Game *game);

/**
 * @brief It shows the result of the ATTACK command when the enemy is hurt
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param enemy the name of the enemy
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_enemy_hurt(Game *game, const char *enemy);

/**
 * @brief It shows the result of the ATTACK command when the enemy is destroyed
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param enemy the name of the enemy
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_enemy_destroyed(Game *game, const char *enemy);

/**
 * @brief It shows the result of the INSPECT command when a space is inspected
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param space the name of the space
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_space(Game *game, const char *space);

/**
 * @brief It shows the result of the INSPECT command when a space has no light
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param space the name of the space
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_light(Game *game, const char *space);

/**
 * @brief It shows the result of the INSPECT command when an object in the inventory is inspected
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_object_inventory(Game *game, const char *obj);

/**
 * @brief It shows the result of the INSPECT command when an object in the actual space is inspected
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_object_space(Game *game, const char *obj);

/**
 * @brief It shows the result of the INSPECT command when an object can't be inspected
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param obj the name of the object
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_cant_inspect(Game *game, const char *obj);

/**
 * @brief It shows the result of the OPEN command when a link is opened
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param link the name of the link
 * @param obj the name of the object
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_opened(Game *game, const char *link, const char *obj);

/**
 * @brief It shows the result of the OPEN command when a link cant be opened
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param link the name of the link
 * @param obj the name of the object
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_not_opened(Game *game, const char *link, const char *obj);

/**
 * @brief It shows the result of the OPEN command when no link name is read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_link_name(Game *game);

/**
 * @brief It shows the result of the OPEN command when a not valid structure is read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_wrong_structure(Game *game);

/**
 * @brief It shows the result of the OPEN command when no object name is read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_object_name(Game *game);

/**
 * @brief It shows the result of the SAVE/LOAD command when a wrong filename is read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param filename the name of the file
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_wrong_file(Game *game, const char *filename);

/**
 * @brief It shows the result of the SAVE command when the game is saved
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param filename the name of the file
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_saved(Game *game, const char *filename);

/**
 * @brief It shows the result of the LOAD command when the game is loaded
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param filename the name of the file
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_loaded(Game *game, const char *filename);

/**
 * @brief It shows the result of a command that needs an object when it is not read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param cmd the name of the command
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_no_object(Game *game, const char *cmd);

/**
 * @brief It shows the result of executing twice the same wrong command
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if everything goes well, ERROR if not
 */
STATUS dialogue_repeated_wrong_command(Game *game);

/** dialogue_message shows the result of the last command read
 */
STATUS dialogue_message(Game *game, T_Dialogue dlg, const char *arg1, const char *arg2) {
  /*check arguments*/
  if (!game || dlg == NO_DLG) return ERROR;

  switch (dlg) {
    case UNKNOWN_C:
      return dialogue_unknown(game);

    case EXIT_C:
      return dialogue_exit(game);

    case NOT_IN_ROOM:
      return dialogue_not_in_room(game, arg1);

    case NOT_MOVABLE:
      return dialogue_not_movable(game, arg1);

    case FULL_INVENTORY:
      return dialogue_full_inventory(game, arg1);

    case DEPENDS_ON:
      return dialogue_depends_on(game, arg1, arg2);

    case TAKEN:
      return dialogue_taken(game, arg1);

    case NOT_IN_INVENTORY:
      return dialogue_not_in_inventory(game, arg1);

    case FULL_SPACE:
      return dialogue_full_space(game, arg1);

    case DROPPED:
      return dialogue_dropped(game, arg1);

    case CANT_ILLUMINATE:
      return dialogue_cant_illuminate(game, arg1);

    case SWITCHED:
      return dialogue_switched(game, arg1, arg2);

    case MOVED:
      return dialogue_moved(game, arg1, arg2);

    case NO_LINK:
      return dialogue_no_link(game, arg1);

    case WRONG_DIR:
      return dialogue_wrong_dir(game, arg1);

    case NO_DIR:
      return dialogue_no_dir(game);

    case NO_ENEMY:
      return dialogue_no_enemy(game);

    case PLAYER_HURT:
      return dialogue_player_hurt(game);

    case ENEMY_HURT:
      return dialogue_enemy_hurt(game, arg1);

    case ENEMY_DESTROYED:
      return dialogue_enemy_destroyed(game, arg1);

    case SPACE:
      return dialogue_space(game, arg1);

    case NO_LIGHT:
      return dialogue_no_light(game, arg1);

    case OBJECT_INVENTORY:
      return dialogue_object_inventory(game, arg1);

    case OBJECT_SPACE:
      return dialogue_object_space(game, arg1);

    case CANT_INSPECT:
      return dialogue_cant_inspect(game, arg1);

    case OPENED:
      return dialogue_opened(game, arg1, arg2);

    case NOT_OPENED:
      return dialogue_not_opened(game, arg1, arg2);

    case LINK_NAME:
      return dialogue_no_link_name(game);

    case STRUCTURE:
      return dialogue_wrong_structure(game);

    case OBJ_NAME:
      return dialogue_no_object_name(game);

    case WRONG_FILE:
      return dialogue_wrong_file(game, arg1);

    case SAVED:
      return dialogue_saved(game, arg1);

    case LOADED:
      return dialogue_loaded(game, arg1);

    case NO_OBJ:
      return dialogue_no_object(game, arg1);

    case REPEATED:
      return dialogue_repeated_wrong_command(game);

    default:
      return ERROR;
  }
}

/**
 * PRIVATE FUNCTIONS IMPLEMENTATION
 */

/** dialogue_unknown shows the result of the UNKNOWN command
 */
STATUS dialogue_unknown(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> This is not a valid action. Try again.");

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_exit shows the result of the EXIT command
 */
STATUS dialogue_exit(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> Bye! Have a nice day!");

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_not_in_room shows the result of the TAKE command when the object is not in the room
 */
STATUS dialogue_not_in_room(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> %s is not in this room.", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_not_movable shows the result of the TAKE command when the object is not movable
 */
STATUS dialogue_not_movable(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> %s is not movable, you can't take it.", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_depends_on shows the result of the TAKE command when the object depends on another
 */
STATUS dialogue_depends_on(Game *game, const char *obj, const char *dep) {
  char dialogue[WORD_SIZE];

  if (!game || !obj || !dep) return ERROR;

  sprintf(dialogue, " >> You can't take %s without having %s in your inventory.", (char *)obj, (char *)dep);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_taken shows the result of the TAKE command when the object is taken
 */
STATUS dialogue_taken(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> You've taken a/an %s. Now it's in your inventory.", (char *)obj);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_full_inventory shows the result of the TAKE command when the inventory is full
 */
STATUS dialogue_full_inventory(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> Your inventory is full, you can't take %s.", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_not_in_inventory  shows the result of the DROP command when the object is not in the inventory
 */
STATUS dialogue_not_in_inventory(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> %s isn't in your inventory.", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_full_space shows the result of the DROP command when the object can't be dropped
 */
STATUS dialogue_full_space(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> %s can't be dropped in this room. Try in another one.", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_dropped shows the result of the DROP command when the object is dropped
 */
STATUS dialogue_dropped(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> You've dropped %s. Now it isn't in your inventory.", (char *)obj);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_cant_illuminate shows the result of the SWITCH command when the object can't illuminate
 */
STATUS dialogue_cant_illuminate(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> %s can't be turned ON", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_switched shows the result of the SWITCH command when the object is turned ON or OFF
 */
STATUS dialogue_switched(Game *game, const char *obj, const char *turned) {
  char dialogue[WORD_SIZE];

  if (!game || !obj || !turned) return ERROR;

  sprintf(dialogue, " >> %s has been turned %s.", (char *)obj, (char *)turned);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_moved shows the result of the MOVE command when the player has moved to a new space
 */
STATUS dialogue_moved(Game *game, const char *dir, const char *space) {
  char dialogue[WORD_SIZE];

  if (!game || !dir || !space) return ERROR;

  sprintf(dialogue, " >> You've moved %s. Now you're in %s.", (char *)dir, (char *)space);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_no_link shows the result of the MOVE command when the link is closed
 */
STATUS dialogue_no_link(Game *game, const char *dir) {
  char dialogue[WORD_SIZE];

  if (!game || !dir) return ERROR;

  sprintf(dialogue, " >> You can't move %s.", (char *)dir);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_wrong_dir shows the result of the MOVE command when the direction is wrong
 */
STATUS dialogue_wrong_dir(Game *game, const char *dir) {
  char dialogue[WORD_SIZE];

  if (!game || !dir) return ERROR;

  sprintf(dialogue, " >> %s doesn't exist. Try with a valid direction.", (char *)dir);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_no_dir shows the result of the MOVE command when no direction is read
 */
STATUS dialogue_no_dir(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> Please, specify a direction to move.");

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_no_enemy shows the result of the ATTACK command when there is no enemy in the room
 */
STATUS dialogue_no_enemy(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> There's no enemy in this room.");

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_player_hurt shows the result of the ATTACK command when the player is hurt
 */
STATUS dialogue_player_hurt(Game *game) {
  char dialogue[WORD_SIZE];

  sprintf(dialogue, " >> Ouch! It must have hurt. You've taken damage.");
  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_enemy_hurt shows the result of the ATTACK command when the enemy is hurt
 */
STATUS dialogue_enemy_hurt(Game *game, const char *enemy) {
  char dialogue[WORD_SIZE];

  if (!game || !enemy) return ERROR;

  sprintf(dialogue, " >> Wow! %s has lost a health point.", (char *)enemy);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_enemy_destroyed shows the result of the ATTACK command when the enemy is destroyed
 */
STATUS dialogue_enemy_destroyed(Game *game, const char *enemy) {
  char dialogue[WORD_SIZE];

  if (!game || !enemy) return ERROR;

  sprintf(dialogue, " >> Amazing! You've killed %s.", (char *)enemy);

  return game_set_last_dialogue(game, dialogue);
}
/** dialogue_space shows the result of the INSPECT command when a space is inspected
 */
STATUS dialogue_space(Game *game, const char *space) {
  char dialogue[WORD_SIZE];

  if (!game || !space) return ERROR;

  sprintf(dialogue, " >> You've inspected %s.", (char *)space);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_no_light shows the result of the INSPECT command when a space has no light
 */

STATUS dialogue_no_light(Game *game, const char *space) {
  char dialogue[WORD_SIZE];

  if (!game || !space) return ERROR;

  sprintf(dialogue, " >> You can't inspect %s. It has no light.", (char *)space);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}
/** dialogue_object_inventory shows the result of the INSPECT command when an object in the inventory is inspected
 */
STATUS dialogue_object_inventory(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> You've inspected %s from your inventory.", (char *)obj);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_object_space shows the result of the INSPECT command when an object in the space is inspected
 */
STATUS dialogue_object_space(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> You've inspected %s from the current room.", (char *)obj);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_cant_inspect shows the result of the INSPECT command when an object can't be inspected
 */
STATUS dialogue_cant_inspect(Game *game, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !obj) return ERROR;

  sprintf(dialogue, " >> You can't inspect %s. It's neither in your inventory or the current room.", (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_opened shows the result of the OPEN command when a link is opened
 */
STATUS dialogue_opened(Game *game, const char *link, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !link || !obj) return ERROR;

  sprintf(dialogue, " >> You've opened %s with %s.", (char *)link, (char *)obj);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_not_opened shows the result of the OPEN command when a link cant be opened
 */
STATUS dialogue_not_opened(Game *game, const char *link, const char *obj) {
  char dialogue[WORD_SIZE];

  if (!game || !link || !obj) return ERROR;

  sprintf(dialogue, " >> You can't open %s with %s.", (char *)link, (char *)obj);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}
/** dialogue_no_link_name shows the result of the OPEN command when no link name is read
 */
STATUS dialogue_no_link_name(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> Remember to write a link name.");

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_wrong_structure shows the result of the OPEN command when a not valid structure is read
 */
STATUS dialogue_wrong_structure(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> Remember the OPEN command structure is 'o <link> with <obj>'.");

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_no_object_name shows the result of the OPEN command when no object name is read
 */
STATUS dialogue_no_object_name(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> Remember to write an object name.");

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_wrong_file shows the result of the SAVE/LOAD command when a wrong filename is read
 */
STATUS dialogue_wrong_file(Game *game, const char *filename) {
  char dialogue[WORD_SIZE];

  if (!game || !filename) return ERROR;

  sprintf(dialogue, " >> %s can't be used as a file name. Try another one.", (char *)filename);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_saved shows the result of the SAVE command when the game is saved
 */
STATUS dialogue_saved(Game *game, const char *filename) {
  char dialogue[WORD_SIZE];

  if (!game || !filename) return ERROR;

  sprintf(dialogue, " >> The current game has been saved in %s.", (char *)filename);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_loaded shows the result of the LOAD command when the game is loaded
 */
STATUS dialogue_loaded(Game *game, const char *filename) {
  char dialogue[WORD_SIZE];

  if (!game || !filename) return ERROR;

  sprintf(dialogue, " >> The game has been successfully loaded from %s.", (char *)filename);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_no_object shows the result of the INSPECT command when no argument is read
 */
STATUS dialogue_no_object(Game *game, const char *cmd) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> Please, specify what object you want to %s.", (char *)cmd);

  if (strcmp(game_get_last_dialogue(game), dialogue) == 0) return dialogue_repeated_wrong_command(game);

  return game_set_last_dialogue(game, dialogue);
}

/** dialogue_repeated_wrong_command shows the result of executing twice the same wrong command
 */
STATUS dialogue_repeated_wrong_command(Game *game) {
  char dialogue[WORD_SIZE];

  if (!game) return ERROR;

  sprintf(dialogue, " >> You've already tried this without success. Try another action.");

  return game_set_last_dialogue(game, dialogue);
}
