/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string.h>
#define N_CMDT 2
#define N_CMD 10

/**
 * It assigns a value to each type of command
 */
typedef enum enum_CmdType {
  CMDS,
  CMDL} T_CmdType;

typedef enum enum_Command {
  NO_CMD = -1, /*!< It assigns to NO_CMD COMMAND the value -1*/
  UNKNOWN,     /*!< It assigns to UNKNOWN COMMAND the value 0*/
  EXIT,        /*!< It assigns to EXIT COMMAND the value 1*/
  NEXT,        /*!< It assigns to NEXT COMMAND the value 2*/
  BACK,        /*!< It assigns to BACK COMMAND the value 3*/
  LEFT,        /*!< It assigns to LEFT COMMAND the value 4*/
  RIGHT,       /*!< It assigns to RIGHT COMMAND the value 5*/
  TAKE,        /*!< It assigns to TAKE COMMAND the value 6*/
  DROP,        /*!< It assigns to DROP COMMAND the value 7*/
  ATTACK       /*!< It assigns to ATTACK COMMAND the value 8*/
  } T_Command;

/**
  * @brief It identifies which command has been introduced
  *
  * @return NO_CMD if no command has been introduced, UNKNOWN if the command was none of the expected, and EXIT, NEXT or BACK if they were introduced
  */
T_Command command_get_user_input();

#endif
