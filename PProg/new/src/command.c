/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Diego Fernández
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <command.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

/**
 * @brief Command list with both the complete and the shortened form of each
 * command
 */
char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"t", "Take"}, {"d", "Drop"}, {"a", "Attack"}, {"i", "Inspect"}, {"m", "Move"}, {"s", "Switch"}, {"o", "Open"}, {"sav", "Save"}, {"l", "Load"}};

/** command_get_user_input reads a command from the prompt
 * and returns it
 */

T_Command command_get_user_input(char *arg) {
  T_Command cmd = NO_CMD;
  char     *str_cmd, input[CMD_LENGTH] = "";
  int       i = UNKNOWN - NO_CMD + 1, cmd_len;

  if (!arg) return NO_CMD;

  /*Input is read*/
  if (fgets(input, CMD_LENGTH - 1, stdin) != NULL) {
    cmd_len            = strlen(input);
    input[cmd_len - 1] = ' ';
    /*We find the command*/
    if (!(str_cmd = strtok(input, " "))) return UNKNOWN;
    /*If the command is not in the list UNKNOWN is returned*/
    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD) {
      if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL])) {
        cmd = i + NO_CMD;
        /*If no arg was read "" is passed as arg*/
        str_cmd = strtok(NULL, " ");
        if (str_cmd != NULL) {
          strcpy(arg, str_cmd);
          while ((str_cmd = strtok(NULL, " ")) != NULL) {
            strcat(arg, " ");
            strcat(arg, str_cmd);
          }
        } else {
          arg[0] = '\0';
        }
      } else {
        i++;
      }
    }
  }

  return cmd;
}
