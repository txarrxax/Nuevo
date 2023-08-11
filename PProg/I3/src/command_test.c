/**
 * @brief It tests command module
 *
 * @file command_test.c
 * @author Diego Fernández
 * @version 3.0
 * @date 10-04-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <command_test.h>
#include <command.h>
#include <test.h>

/**
 * @brief file used to emulate user input
 */
#define FILE_PATH ".command_test.txt"

/**
 * @brief max number of tests for the command module
 */
#define MAX_TESTS 16

/*Private prototypes*/

/**
 * @brief It emulates the input of a user in order to run a test on the command module
 * @author Diego Fernández
 *
 * @param filename file from which the input will be read
 * @param test test input
 * @param arg variable on which the read argument will be stored
 * @param output test output from the command module
 * @return OK if successful, ERROR if there was an issue
 */
STATUS run_test(char *filename, char *test, char *arg, T_Command *output);

/**
 * @brief It runs an automated test of a specific correct command
 * @author Diego Fernández
 *
 * @param s short version of the command
 * @param l long version of the command
 * @param cmd expected T_Command output
 * @return TRUE if the test was passed, FALSE otherwise
 */
BOOL test_command(char *s, char *l, T_Command cmd);

/**
 * @brief Main function for COMMAND unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv){ 
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all tests for module Command:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1)
    test_null_arg();
  if (all || test == 2)
    test_no_command();
  if (all || test == 3)
    test_unknown();
  if (all || test == 4)
    test_exit();
  if (all || test == 5)
    test_next();
  if (all || test == 6)
    test_back();
  if (all || test == 7)
    test_take();
  if (all || test == 8)
    test_drop();
  if (all || test == 9)
    test_right();
  if (all || test == 10)
    test_left();
  if (all || test == 11)
    test_attack();
  if (all || test == 12)
    test_inspect();
  if (all || test == 13)
    test_move();
  if (all || test == 14)
    test_arg();
  if (all || test == 15)
    test_overflow1();
  if (all || test == 16)
    test_overflow2();

  PRINT_PASSED_PERCENTAGE;

  remove(FILE_PATH);

  return 1;
}

/*Public functions*/

void test_null_arg(){ 
  int result;
  T_Command output;
  
  if (run_test(FILE_PATH, "m n", NULL, &output) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  
  result = output == NO_CMD;
  PRINT_TEST_RESULT(result);

  fclose(stdin);
}

void test_no_command(){ 
  int result;
  char arg[0];
  T_Command output;

  if (run_test(FILE_PATH, "", arg, &output) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  result = output == NO_CMD;
  PRINT_TEST_RESULT(result);
}

void test_unknown(){ 
  int result;
  char arg[0];
  T_Command output;

  if (run_test(FILE_PATH, "hello\n", arg, &output) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  result = output == UNKNOWN;
  PRINT_TEST_RESULT(result);
}

void test_exit(){ 
  PRINT_TEST_RESULT(test_command("e", "exit", EXIT));
}

void test_next(){ 
  PRINT_TEST_RESULT(test_command("n", "next", NEXT));
}

void test_back(){ 
  PRINT_TEST_RESULT(test_command("b", "back", BACK));  
}

void test_take(){ 
  PRINT_TEST_RESULT(test_command("t", "take", TAKE));
}

void test_drop(){ 
  PRINT_TEST_RESULT(test_command("d", "drop", DROP));
}

void test_right(){ 
  PRINT_TEST_RESULT(test_command("r", "right", RIGHT));
}

void test_left(){ 
  PRINT_TEST_RESULT(test_command("l", "left", LEFT));
}

void test_attack(){ 
  PRINT_TEST_RESULT(test_command("a", "attack", ATTACK));
}

void test_inspect(){ 
  PRINT_TEST_RESULT(test_command("i", "inspect", INSPECT));
}

void test_move(){ 
  PRINT_TEST_RESULT(test_command("m", "move", MOVE));
}

void test_arg(){ 
  char arg[CMD_LENGTH];
  T_Command output;

  if (run_test(FILE_PATH, "inspect object ----", arg, &output) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(strcmp(arg, "object") == 0);
}

void test_overflow1(){ 
  char arg[0], test[CMD_LENGTH + 3];
  T_Command output;
  int i;

  for (i=0; i<CMD_LENGTH+1; i++){ 
    test[i] = 'a';
  }
  test[CMD_LENGTH + 1] = '\n';
  test[CMD_LENGTH + 2] = '\0';

  if (run_test(FILE_PATH, test, arg, &output) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(output == UNKNOWN);
}

void test_overflow2(){ 
  char arg[CMD_LENGTH], test[CMD_LENGTH + 3]="next ";
  T_Command output;
  int i;

  for (i=5; i<CMD_LENGTH+1; i++){ 
    test[i] = 'a';
  }
  test[CMD_LENGTH + 1] = '\n';
  test[CMD_LENGTH + 2] = '\0';

  if (run_test(FILE_PATH, test, arg, &output) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }

  PRINT_TEST_RESULT(output == NEXT);
}

/*Private functions*/
/** run test emulates the input of a user in order to run a test on the command module
 */
STATUS run_test(char *filename, char *test, char *arg, T_Command *output){ 
  FILE *f;

  if (!filename || ! test || !output)
    return ERROR;

  if (!(f = fopen(filename, "w")))
    return ERROR;

  fprintf(f, "%s", test);
  fclose(f);

  if (!freopen(filename, "r", stdin))
    return ERROR;

  *output = command_get_user_input(arg);

  fclose(stdin);

  return OK;
}

/** test_command runs an automated test of a specific correct command
 */
BOOL test_command(char *s, char *l, T_Command cmd){ 
  char arg[0], cmd_s[CMD_LENGTH], cmd_l[CMD_LENGTH];
  T_Command output;

  if (!s || !l)
    return FALSE;

  strcat(strcpy(cmd_s, s), "\n");
  strcat(strcpy(cmd_l, l), "\n");

  if (run_test(FILE_PATH, cmd_s, arg, &output) == ERROR)
    return FALSE;
  
  if (output != cmd)
    return FALSE;

  if (run_test(FILE_PATH, cmd_l, arg, &output) == ERROR)
    return FALSE;
  
  return output == cmd;
}
