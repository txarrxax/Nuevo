/**
 * @brief It tests enemy module
 *
 * @file enemy_test.c
 * @author Diego Fernández
 * @version 3.0
 * @date 07-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include <enemy_test.h>

/**
 * @brief Main function for ENEMY unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv){ 
  test1_enemy_create();
  test2_enemy_create();
  test1_enemy_destroy();
  test2_enemy_destroy();
  test1_enemy_get_id();
  test2_enemy_get_id();
  test1_enemy_set_id();
  test2_enemy_set_id();
  test1_enemy_get_location();
  test2_enemy_get_location();
  test1_enemy_set_location();
  test2_enemy_set_location();
  test1_enemy_get_name();
  test2_enemy_get_name();
  test1_enemy_set_name();
  test2_enemy_set_name();
  test1_enemy_get_health();
  test2_enemy_get_health();
  test1_enemy_set_health();
  test2_enemy_set_health();
  test1_enemy_print();
  test2_enemy_print();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_enemy_create(){
  int result;
  Enemy *e;

  e = enemy_create();
  result = e != NULL;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test2_enemy_create(){ 
  int result;
  Enemy *e;

  e = enemy_create();
  result = e != NULL && enemy_get_id(e) == NO_ID && enemy_get_location(e) == NO_ID && enemy_get_name(e)[0] == '\0' && enemy_get_health(e) == 0;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_destroy(){ 
  int result;

  result = enemy_destroy(NULL) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_destroy(){ 
  int result;
  Enemy *e;

  e = enemy_create();
  if (!e)
    result = enemy_destroy(e) == ERROR;
  else
    result = enemy_destroy(e) != ERROR;
  PRINT_TEST_RESULT(result);
}

void test1_enemy_get_id(){ 
  int result;

  result = enemy_get_id(NULL) == NO_ID;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_get_id(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  enemy_set_id(e, TEST_ID);
  result = enemy_get_id(e) == TEST_ID;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_set_id(){ 
  int result;

  result = enemy_set_id(NULL, TEST_ID) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_set_id(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = enemy_set_id(e, NO_ID) == ERROR;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_get_location(){ 
  int result;

  result = enemy_get_location(NULL) == NO_ID;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_get_location(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (enemy_set_location(e, TEST_ID) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    enemy_destroy(e);
    return;
  }
  result = enemy_get_location(e) == TEST_ID;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_set_location(){ 
  int result;

  result = enemy_set_location(NULL, TEST_ID) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_set_location(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = enemy_set_location(e, NO_ID) == ERROR;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_get_name(){ 
  int result;

  result = !enemy_get_name(NULL);
  PRINT_TEST_RESULT(result);
}

void test2_enemy_get_name(){ 
  int result;
  Enemy *e;
  const char *name;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (enemy_set_name(e, TEST_NAME) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    enemy_destroy(e);
    return;
  }
  result = (name = enemy_get_name(e)) && strcmp(name, TEST_NAME) == 0;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_set_name(){ 
  int result;

  result = enemy_set_name(NULL, TEST_NAME) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_set_name(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = enemy_set_name(e, NULL) == ERROR;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_get_health(){ 
  int result;

  result = enemy_get_health(NULL) == -1;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_get_health(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  if (enemy_set_health(e, TEST_HEALTH) == ERROR){ 
    PRINT_TEST_RESULT(FALSE);
    enemy_destroy(e);
    return;
  }
  result = enemy_get_health(e) == TEST_HEALTH;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_set_health(){ 
  int result;

  result = enemy_set_health(NULL, TEST_HEALTH) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_set_health(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = enemy_set_health(e, TEST_HEALTH) == OK;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}

void test1_enemy_print(){ 
  int result;

  result = enemy_print(NULL) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test2_enemy_print(){ 
  int result;
  Enemy *e;

  if (!(e = enemy_create())){ 
    PRINT_TEST_RESULT(FALSE);
    return;
  }
  result = enemy_print(e) == OK;
  PRINT_TEST_RESULT(result);

  enemy_destroy(e);
}
