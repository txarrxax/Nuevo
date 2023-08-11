/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Diego Fernández
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <types.h>

/**
 * @brief Max length a command can take up
 */
#define CMD_LENGTH 50

/**
 * @brief Number of forms each command can take
 */
#define N_CMDT 2

/**
 * @brief Number of commands
 */
#define N_CMD 12

/**
 * @brief This enumeration defines the index of each command type from the
 * command list
 */
typedef enum enum_CmdType {
  CMDS, /*!< Index for the shortened form of the command */
  CMDL  /*!< Index for the longer form of the command */
} T_CmdType;

/**
 * @brief This enumeration defines all the available commands for internal
 * reference within the project
 */
typedef enum enum_Command {
  NO_CMD = -1, /*!< No command was typed or it is undefined */
  UNKNOWN,     /*!< The command entered by the user does not exist */
  EXIT,        /*!< Exit the game */
  TAKE,        /*!< Takes the object in the current room*/
  DROP,        /*!< Drops the object in the current room*/
  ATTACK,      /*!< Attacks an enemy in the current room */
  INSPECT,     /*!< Shows the description of an object */
  MOVE,        /*!< Moves in the direction specified by the user */
  SWITCH,      /*!< Turns on or off an object (only the ones that can illuminate) */
  OPEN,        /*!< Opens a link with an object */
  SAVE,        /*!< Saves the game to a file */
  LOAD         /*!< Loads the game from a file */
} T_Command;

/**
 * @brief It reads a command from the prompt
 * @author Profesores PPROG
 *
 * @return The read command, UNKNOWN if not recognized and NO_CMD if nothing was
 * typed
 */
T_Command command_get_user_input(char *arg);

#endif
