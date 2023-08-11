/**
 * @brief It implements the dialogue module
 *
 * @file dialogue.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 17-4-2023
 * @copyright GNU Public License
 */

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <command.h>
#include <game.h>
#include <types.h>

/**
 * @brief This enumeration defines the index of each dialogue type
 */
typedef enum enum_Dialogue {
  NO_DLG = -1,      /*<! No dialogue was specified */
  UNKNOWN_C,        /*<! Dialogue for UNKNOWN command */
  EXIT_C,           /*<! Dialogue for EXIT command*/
  NOT_IN_ROOM,      /*<! Dialogue for TAKE command when the object is not in the room */
  NOT_MOVABLE,      /*<! Dialogue for TAKE command when the object is not movable */
  FULL_INVENTORY,   /*<! Dialogue for TAKE command when the inventory is full */
  DEPENDS_ON,       /*<! Dialogue for TAKE command when the object depends on another one */
  TAKEN,            /*<! Dialogue for TAKE command when the object is taken */
  NOT_IN_INVENTORY, /*<! Dialogue for DROP/OPEN command when the object is not in the inventory */
  FULL_SPACE,       /*<! Dialogue for DROP command when the space is full */
  DROPPED,          /*<! Dialogue for DROP command when the object is dropped */
  CANT_ILLUMINATE,  /*<! Dialogue for SWITCH command when the object can not illuminate */
  SWITCHED,         /*<! Dialogue for SWITCH command when the object is switched */
  MOVED,            /*<! Dialogue for MOVE command when the player has moved */
  NO_LINK,          /*<! Dialogue for MOVE command when there is no link */
  WRONG_DIR,        /*<! Dialogue for MOVE command when the direction is no recognised */
  NO_DIR,           /*<! Dialogue for MOVE command when no direction is read */
  NO_ENEMY,         /*<! Dialogue for ATTACK command when there is no enemy in the room */
  PLAYER_HURT,      /*<! Dialogue for ATTACK command when the player is hurt */
  ENEMY_HURT,       /*<! Dialogue for ATTACK command when the enemy is hurt */
  ENEMY_DESTROYED,  /*<! Dialogue for ATTACK command when the enemy is destroyed */
  SPACE,            /*<! Dialogue for INSPECT command when a space is inspected */
  NO_LIGHT,         /*<! Dialogue for INSPECT command when a space has no light */
  OBJECT_INVENTORY, /*<! Dialogue for INSPECT command when an object in the inventory is inspected */
  OBJECT_SPACE,     /*<! Dialogue for INSPECT command when an object in the room is inspected */
  CANT_INSPECT,     /*<! Dialogue for INSPECT command when an object can not be inspected */
  OPENED,           /*<! Dialogue for OPEN command when a link is opened */
  NOT_OPENED,       /*<! Dialogue for OPEN command when a link cant be opened */
  LINK_NAME,        /*<! Dialogue for OPEN command when no link name is read */
  STRUCTURE,        /*<! Dialogue for OPEN command when the structure of the command is wrong */
  OBJ_NAME,         /*<! Dialogue for OPEN command when no object name is read */
  WRONG_FILE,       /*<! Dialogue for SAVE/LOAD command when a wrong filename is read */
  SAVED,            /*<! Dialogue for SAVE command when the game is saved */
  LOADED,           /*<! Dialogue for LOAD command when the game is loaded */
  NO_OBJ,           /*<! Dialogue for a command that needs an object when it is not read */
  REPEATED          /*<! Dialogue for a wrong repeated command */
} T_Dialogue;

/**
 * @brief It shows the result of the last command read
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param dlg the dialogue type
 * @param arg1 the first argument for the message
 * @param arg2 the second argument fot the message
 * @return OK if everything goes well, ERROR if there was some mistake
 */
STATUS dialogue_message(Game *game, T_Dialogue dlg, const char *arg1, const char *arg2);

#endif
