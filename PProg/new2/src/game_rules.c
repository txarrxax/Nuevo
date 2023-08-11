/**
 * @brief It implements the GameRules interface and the GameRules dialogues
 *
 * @file game_rules.c
 * @author Miguel Angel Sacristan
 * @version 1.0
 * @date 21-04-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <game_rules.h>
#include <graphic_engine.h>
#include <game.h>
#include <types.h>

/**
 * @brief This struct contains the Toxic rule information
 */
typedef struct {
  int    num_spaces;         /*!< Number of toxic spaces */
  Space *spaces[MAX_SPACES]; /*!< Array of all toxic spaces */
  int    count;              /*!< Number of actions allowed before loosing a health point */
  int    count_reset;        /*!< Constant number of actions allowed before loosing a health point*/
  Id     protection;         /*!< Id of the object that protects the player from toxic spaces*/
} Toxic;

/**
 * @brief This struct contains the Life rule information
 */
typedef struct {
  int power;  /*!< Number of health points to add or substract */
  Id  object; /*!< Id of the object that gives or takes health points */
} Life;

/**
 * @brief This struct contains the Light rule information
 */
typedef struct {
  Id  object;   /*!< Id of the illuminate object to turn off */
  Id  solution; /*!< Id of the space that stops the problem */
  Id  space;    /*!< Id of the space where the rule begins */
  int active;   /*!< Tells the problem status: 0 not active, 1 active, 2 fixed */
} Light;

/**
 * @brief This struct contains the Hack rule information
 */
typedef struct {
  int   count;       /*!< Number of actions allowed before loosing a health point */
  int   count_reset; /*!< Constant number of actions allowed before loosing a health point */
  Link *trap;        /*!< Pointer to the link that is going to be closed */
  Id    solution;    /*!< Id of the object that fixes the problem */
  Id    space;       /*!< Id of the space to drop the solution */
  int   active;      /*!< Tells the problem status: 0 not active, 1 active, 2 fixed */
} Hack;

/**
 * @brief This struct contains the Upgrade rule information
 */
typedef struct {
  int  stat;  /*!< Number of stats to upgrade the player */
  Id   space; /*!< Id of the space where the rule is called */
  BOOL done;  /*!< Tells if the player is already upgraded */
} Upgrade;

/**
 * @brief This struct contains the Escape rule information
 */
typedef struct {
  int  health;       /*!< Health points needed by the enemy to escape */
  int  reset_health; /*!< Health points given to the enemy after the escape */
  Id   link_1;       /*!< Id of a link to open after the escape */
  Id   link_2;       /*!< Id of a link to open after the escape */
  Id   destination;  /*!< Id of the space where the enemy goes after the escape */
  BOOL active;       /*!< Tells if the rule has been implemented or not */
} Escape;

/**
 * @brief This struct contains the BrokenLink rule information
 */
typedef struct {
  Id   link;   /*!< Id of the link to close */
  Id   fix;    /*!< Id of the object that solves the problem */
  BOOL active; /*!< Tells if the hack is active or not*/
} Broken_link;

/**
 * @brief This struct contains the GameRules information
 */
struct _Grules {
  Toxic       *toxic;                      /*!< Pointer to a Toxic rule */
  Life        *objects[MAX_OBJ];           /*!< Pointer to a Life rule */
  int          num_life;                   /*!< Number of objects that implement the Life rule */
  Light       *light;                      /*!< Pointer to a Light rule */
  Hack        *hack;                       /*!< Pointer to a Hack rule */
  Upgrade     *upgrade;                    /*!< Pointer to an Upgrade rule */
  Escape      *escape;                     /*!< Pointer to a Escape rule */
  Broken_link *broken;                     /*!< Pointer to a Broken_link rule */
  char         rule[MAX_RULES][WORD_SIZE]; /*!< Array with all the dialogues to display */
  int          num_rules;                  /*!< Number of dialogues to display*/
};

/**
 *  PRIVATE FUNCTIONS
 */

/**
 * @brief It implements the toxic rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_toxic_update(Game *game, Grules *grules);

/**
 * @brief It implements the life rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_life(Game *game, Grules *grules);

/**
 * @brief It implements the light rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_break_torch(Game *game, Grules *grules);

/**
 * @brief It implements the hack rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_hack(Game *game, Grules *grules);

/**
 * @brief It implements the upgrade rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_upgrade(Game *game, Grules *grules);

/**
 * @brief It implements the escape rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_runaway(Game *game, Grules *grules);

/**
 * @brief It implements the BrokenLink rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK if the rule has been implemented correctly, ERROR if there was an issue
 */
STATUS game_rules_fix_link(Game *game, Grules *grules);

/**
 * @brief It creates the dialogues for the Life rule
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @param i position of the object in life objects
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_life_rule(Grules *grules, Game *game, int i);

/**
 * @brief It creates the dialogues to inform about the toxic protection object
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_prosuit_rule(Game *game, Grules *grules);

/**
 * @brief It creates the dialogues for the Toxic rule
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param grules a pointer to a Grules structure
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_toxic_space_rule(Game *game, Grules *grules);

/**
 * @brief It creates a dialogues for the Hack rule begining
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_hack_rule1(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Hack rule health substraction
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_hack_rule2(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Hack rule ending
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_hack_rule3(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Light rule begining
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_torch_rule1(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Light rule ending
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_torch_rule2(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Escape rule
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_escape_rule(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Broken_link rule
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_fix_link_rule(Grules *grules, Game *game);

/**
 * @brief It creates a dialogues for the Upgrade rule
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @return OK created correctly, ERROR if there was an issue
 */
STATUS game_rules_create_upgrade_rule(Grules *grules, Game *game);

/**
 * @brief Adjustment of game_management_parse_line to be used with rules
 * @author Miguel Angel Sacristan
 *
 * @param f input stream
 * @param arg_num pointer to which the function will write the number of
 * arguments read
 * @param args pointer to which the arguments read will be written
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_rules_parse_line1(FILE *f, int *arg_num, char args[MAX_RARG][MAX_TEXT]);

/**
 * @brief It saves the rules in a file
 * @author Miguel Angel Sacristan
 *
 * @param grules a pointer to a Grules structure
 * @param game a pointer to the game session
 * @param f a pointer to the file where the information is printed
 * @return OK saved correctly, ERROR if there was an issue
 */
STATUS game_rules_save_rules(Grules *grules, Game *game, FILE *f);

/**
  PUBLIC FUNCTIONS IMPLEMENTATION
*/
Grules *game_rules_init_from_file(Game *game, char *filename) {
  FILE   *file = NULL;
  char    args[MAX_RARG][MAX_TEXT];
  int     arg_num;
  Grules *grules;
  int     i;

  if (!game || !filename) return NULL;

  /*Error control*/
  if (!(file = fopen(filename, "r"))) return NULL;

  grules = (Grules *)malloc(sizeof(Grules));
  memset(grules, 0, sizeof(Grules));
  if (!grules) return NULL;

  strcpy(args[0], "\0");
  while (game_rules_parse_line1(file, &arg_num, args) == OK) {
    if (strcmp("rT", args[0]) == 0) {
      grules->toxic = (Toxic *)malloc(sizeof(Toxic));
      if (!grules->toxic) return NULL;
      grules->toxic->count = grules->toxic->count_reset = atoi(args[1]);
      if (grules->toxic->count < 0) return NULL;
      grules->toxic->protection = atoi(args[2]);
      if (grules->toxic->protection < 0) return NULL;
      grules->toxic->num_spaces = atoi(args[3]);
      if (grules->toxic->num_spaces < 0) return NULL;
      fprintf(stdout, "Leido Toxic: %d|%ld|%d|", grules->toxic->count, grules->toxic->protection, grules->toxic->num_spaces);
      for (i = 0; i < grules->toxic->num_spaces; i++) {
        grules->toxic->spaces[i] = game_get_space(game, atoi(args[4 + i]));
        fprintf(stdout, "%ld|", space_get_id(grules->toxic->spaces[i]));
        if (!grules->toxic->spaces[i]) return NULL;
      }
    }
    if (strcmp("rL", args[0]) == 0) {
      grules->num_life = atoi(args[1]);
      printf("\nLeido Life: %d|", grules->num_life);
      for (i = 0; i < grules->num_life; i++) {
        grules->objects[i]         = (Life *)malloc(sizeof(Life));
        grules->objects[i]->object = atoi(args[2 + (2 * i)]);
        grules->objects[i]->power  = atoi(args[3 + (2 * i)]);
        printf("%ld|%d|", grules->objects[i]->object, grules->objects[i]->power);
      }
    }

    if (strcmp("rA", args[0]) == 0) {
      /* hack rule */
      grules->hack = (Hack *)malloc(sizeof(Hack));
      if (!grules->hack) return NULL;
      grules->hack->count = grules->hack->count_reset = atoi(args[1]);
      grules->hack->solution                          = atoi(args[2]);
      grules->hack->active                            = atoi(args[3]);
      grules->hack->trap                              = game_get_link_from_id(game, atoi(args[4]));
      if (!grules->hack->trap) return NULL;
      grules->hack->space = atoi(args[5]);
      printf("\nLeido Hack: %d|%ld|%d|%s|%ld\n", grules->hack->count, grules->hack->solution, grules->hack->active, link_get_name(grules->hack->trap), grules->hack->space);

      /* light rule */
      grules->light = (Light *)malloc(sizeof(Light));
      if (!grules->light) return NULL;
      grules->light->object   = atoi(args[6]);
      grules->light->solution = atoi(args[7]);
      grules->light->space    = atoi(args[8]);
      grules->light->active   = atoi(args[9]);
      printf("Leido Light: %ld|%ld|%ld|%d\n", grules->light->object, grules->light->solution, grules->light->space, grules->light->active);

      /* upgrade rule */
      grules->upgrade = (Upgrade *)malloc(sizeof(Upgrade));
      if (!grules->upgrade) return NULL;
      grules->upgrade->space = atoi(args[10]);
      grules->upgrade->stat  = atoi(args[11]);
      grules->upgrade->done  = atoi(args[12]);
      printf("Leido Upgrade: %ld|%d|%d\n", grules->upgrade->space, grules->upgrade->stat, grules->upgrade->done);

      /* escape rule */
      grules->escape = (Escape *)malloc(sizeof(Escape));
      if (!grules->escape) return NULL;
      grules->escape->health       = atoi(args[13]);
      grules->escape->reset_health = atoi(args[14]);
      grules->escape->link_1       = atoi(args[15]);
      grules->escape->link_2       = atoi(args[16]);
      grules->escape->destination  = atoi(args[17]);
      grules->escape->active       = atoi(args[18]);
      printf("Leido Escape: %d|%d|%ld|%ld|%ld|%d\n", grules->escape->health, grules->escape->reset_health, grules->escape->link_1, grules->escape->link_2, grules->escape->destination, grules->escape->active);

      /* broken_link rule */
      grules->broken         = (Broken_link *)malloc(sizeof(Broken_link));
      grules->broken->link   = atoi(args[19]);
      grules->broken->fix    = atoi(args[20]);
      grules->broken->active = atoi(args[21]);
      printf("Leido Broken_link: %ld|%ld|%d", grules->broken->link, grules->broken->fix, grules->broken->active);
    }
  }
  /*Error control*/
  if (ferror(file)) return NULL;
  fclose(file);

  /* dialogue reset */
  for (i = 0; i < MAX_RULES; i++) {
    strcpy(grules->rule[i], "\0");
  }
  grules->num_rules = 0;

  return grules;
}

/** game_rules_init creates a new Grules structure and initializes its data
 */
Grules *game_rules_init(Game *game) {
  int     i;
  Grules *grules = NULL;

  if (!game) return NULL;

  grules = (Grules *)malloc(sizeof(Grules));

  /* we assign which spaces are toxic */
  grules->toxic             = (Toxic *)malloc(sizeof(Toxic));
  grules->toxic->spaces[0]  = game_get_space(game, TOXIC_1);
  grules->toxic->spaces[1]  = game_get_space(game, TOXIC_2);
  grules->toxic->spaces[2]  = game_get_space(game, TOXIC_3);
  grules->toxic->num_spaces = 3;
  for (i = 0; i < grules->toxic->num_spaces; i++) {
    if (!grules->toxic->spaces[i]) return NULL;
  }
  grules->toxic->count = grules->toxic->count_reset = TOXIC_COUNT;
  grules->toxic->protection                         = PRO_SUIT;

  /* we assingn the life management objects */
  grules->num_life = 2;
  for (i = 0; i < grules->num_life; i++) {
    grules->objects[i] = (Life *)malloc(sizeof(Life));
  }
  grules->objects[0]->object = POISON;
  grules->objects[1]->object = CURE;
  grules->objects[0]->power  = -1;
  grules->objects[1]->power  = 1;

  /* we set the hack information */
  grules->hack        = (Hack *)malloc(sizeof(Hack));
  grules->hack->count = grules->hack->count_reset = POWER;
  grules->hack->solution                          = WIRES;
  grules->hack->active                            = 0;
  grules->hack->trap                              = game_get_link_from_id(game, CLOSING_LINK);
  if (!grules->hack->trap) return NULL;
  grules->hack->space = HACK_FIXING;

  /* we store the objects that can illuminate */
  grules->light           = (Light *)malloc(sizeof(Light));
  grules->light->object   = LANTERN;
  grules->light->solution = CHARGER;
  grules->light->space    = TORCH_OFF;
  grules->light->active   = 0;

  /* we assign the upgrade values */
  grules->upgrade        = (Upgrade *)malloc(sizeof(Upgrade));
  grules->upgrade->space = UP_SPACE;
  grules->upgrade->stat  = UP_STAT;
  grules->upgrade->done  = FALSE;

  /* we assign the escape values */
  grules->escape               = (Escape *)malloc(sizeof(Escape));
  grules->escape->health       = RUNAWAY_HEALTH;
  grules->escape->reset_health = RESET_HEALTH;
  grules->escape->link_1       = RUNAWAY_LINK_1;
  grules->escape->link_2       = RUNAWAY_LINK_2;
  grules->escape->destination  = NEW_LOCATION;
  grules->escape->active       = FALSE;

  /* we assign the broken_link values */
  grules->broken         = (Broken_link *)malloc(sizeof(Broken_link));
  grules->broken->link   = ELEVATOR;
  grules->broken->fix    = FIX_ELEVATOR;
  grules->broken->active = TRUE;

  /* we reset all dialogues */
  for (i = 0; i < MAX_RULES; i++) {
    strcpy(grules->rule[i], "\0");
  }
  grules->num_rules = 0;

  return grules;
}

/** game_rules_destroy deletes a Grules structure and frees its memory
 */
STATUS game_rules_destroy(Grules *grules) {
  int i;

  if (!grules) return ERROR;

  free(grules->hack);
  free(grules->toxic);
  for (i = 0; i < grules->num_life; i++) {
    free(grules->objects[i]);
  }
  free(grules->upgrade);
  free(grules->light);
  free(grules->escape);
  free(grules->broken);
  free(grules);

  return OK;
}

/** game_rules_implement calls each rule and dialogues
 */
STATUS game_rules_implement(Game *game, Grules *grules, char *arg) {
  STATUS st = OK;
  FILE  *f;

  if (!game || !grules) return ERROR;

  if (game_get_last_command(game) == EXIT) return OK;

  if (game_get_last_command(game) == SAVE && arg != NULL && arg[0] != '\0') {
    f = fopen(arg, "a");
    if (!f) {
      return ERROR;
    }
    game_rules_save_rules(grules, game, f);
    fclose(f);
    return OK;
  }

  if (game_rules_toxic_update(game, grules) == ERROR) st = ERROR;
  if (game_rules_life(game, grules) == ERROR) st = ERROR;
  if (game_rules_hack(game, grules) == ERROR) st = ERROR;
  if (game_rules_runaway(game, grules) == ERROR) st = ERROR;
  if (game_rules_fix_link(game, grules) == ERROR) st = ERROR;
  if (game_rules_break_torch(game, grules) == ERROR) st = ERROR;
  if (game_rules_upgrade(game, grules) == ERROR) st = ERROR;
  if (st == ERROR) return ERROR;
  return OK;
}

/** game_rules_get_rule gets a dialogue from its position
 */
char *game_rules_get_rule(Grules *grules, int i) {
  if (!grules) return NULL;
  if (i > grules->num_rules || i < 0) return NULL;
  return grules->rule[i];
}

/** game_rules_get_num_rules gets the number of dialogues generated in each game_rule implementation
 */
int game_rules_get_num_rules(Grules *grules) {
  if (!grules) return -1;
  return grules->num_rules;
}

/** game_rules_reset_rules sets the number of dialogues to 0
 */
STATUS game_rules_reset_rules(Grules *grules) {
  int i;
  if (!grules) return ERROR;
  for (i = 0; i < grules->num_rules; i++) {
    strcpy(grules->rule[i], "\0");
  }
  grules->num_rules = 0;
  return OK;
}

STATUS game_rules_save_rules(Grules *grules, Game *game, FILE *f) {
  int i;
  if (!grules || !f) return ERROR;

  /* create toxic rule */
  if (!grules->toxic || grules->toxic->count < 0) return ERROR;

  fprintf(f, "#rT:%d;%ld;%d", grules->toxic->count, grules->toxic->protection, grules->toxic->num_spaces);
  for (i = 0; i < grules->toxic->num_spaces; i++) {
    printf("\n%d %d", i, grules->toxic->num_spaces);
    fprintf(f, ";%ld", space_get_id(grules->toxic->spaces[i]));
  }
  fprintf(f, "\n");

  /* create life rule */
  fprintf(f, "#rL:%d", grules->num_life);
  for (i = 0; i < grules->num_life; i++) {
    fprintf(f, ";%ld;%d", grules->objects[i]->object, grules->objects[i]->power);
  }
  fprintf(f, "\n");

  /* create ALL rule */
  fprintf(f, "#rA:");
  fprintf(f, "%d;%ld;%d;%ld;%ld;", grules->hack->count, grules->hack->solution, grules->hack->active, link_get_id(grules->hack->trap), grules->hack->space);
  fprintf(f, "%ld;%ld;%ld;%d;", grules->light->object, grules->light->solution, grules->light->space, grules->light->active);
  fprintf(f, "%ld;%d;%d;", grules->upgrade->space, grules->upgrade->stat, grules->upgrade->done);
  fprintf(f, "%d;%d;%ld;%ld;%ld;%d;", grules->escape->health, grules->escape->reset_health, grules->escape->link_1, grules->escape->link_2, grules->escape->destination, grules->escape->active);
  fprintf(f, "%ld;%ld;%d", grules->broken->link, grules->broken->fix, grules->broken->active);
  fprintf(f, "\n");
  return OK;
}
/**
  PRIVATE FUNCTIONS IMPLEMENTATION
*/

/** game_rules_toxic_update implements the Toxic rule
 */
STATUS game_rules_toxic_update(Game *game, Grules *grules) {
  Id         player_loc = NO_ID;
  Player    *player     = NULL;
  Space     *space      = NULL;
  Inventory *inventory  = NULL;
  int        i, health;

  if (!game || !grules) return ERROR;

  player = game_get_player(game);
  if (!player) return ERROR;

  player_loc = player_get_location(player);
  if (player_loc == NO_ID) return ERROR;

  space = game_get_space(game, player_loc);
  if (!space) return ERROR;

  inventory = (Inventory *)player_get_inventory(player);
  if (!inventory) return ERROR;
  if (inventory_has_object(inventory, grules->toxic->protection) == FALSE) {
    for (i = 0; i < grules->toxic->num_spaces; i++) {
      if (player_loc == space_get_id(grules->toxic->spaces[i])) {
        grules->num_rules++;
        game_rules_create_toxic_space_rule(game, grules);
        grules->num_rules++;
        game_rules_create_prosuit_rule(game, grules);
        grules->toxic->count--;
        if (grules->toxic->count < 0) {
          grules->toxic->count = grules->toxic->count_reset;
          health               = player_get_health(player);
          if (health < 0) return ERROR;
          health--;
          if (player_set_health(player, health) == ERROR) return ERROR;
        }
      }
    }
  }
  return OK;
}

/** game_rules_life implements the Life rule
 */
STATUS game_rules_life(Game *game, Grules *grules) {
  Player    *player    = NULL;
  Inventory *inventory = NULL;
  int        i, health = -1;

  if (!game || !grules) return ERROR;

  player = game_get_player(game);
  if (!player) return ERROR;
  inventory = (Inventory *)player_get_inventory(player);
  if (!inventory) return ERROR;
  for (i = 0; i < grules->num_life; i++) {
    if (inventory_has_object(inventory, grules->objects[i]->object)) {
      grules->num_rules++;
      game_rules_create_life_rule(grules, game, i);
      if (inventory_del_object(inventory, grules->objects[i]->object) == ERROR) return ERROR;
      health = player_get_health(player);
      if (health < 0) return ERROR;
      health += grules->objects[i]->power;
      if (player_set_health(player, health) == ERROR) return ERROR;
    }
  }
  return OK;
}

/** game_rules_hack implements the Hack rule
 */
STATUS game_rules_hack(Game *game, Grules *grules) {
  Id      player_loc = NO_ID;
  Player *player     = NULL;
  Space  *space      = NULL;
  int     health;

  if (!game || !grules) return ERROR;

  player = game_get_player(game);
  if (!player) return ERROR;

  player_loc = player_get_location(player);
  if (player_loc == NO_ID) return ERROR;

  space = game_get_space(game, player_loc);
  if (!space) return ERROR;

  if (!grules->hack) return ERROR;

  /* if player is in the given space and the hack has not been activated, hack is activated */
  if (player_loc == link_get_origin(grules->hack->trap) && grules->hack->active == 0) {
    grules->hack->active = 1;
  }

  /* implementation of the hack */
  if (grules->hack->active == 1) {
    grules->num_rules++;
    game_rules_create_hack_rule1(grules, game);
    if (link_set_status(grules->hack->trap, ERROR) == ERROR) {
      return ERROR;
    }
    grules->hack->count--;
    if (grules->hack->count < 0) {
      health = player_get_health(player);
      health--;
      if (player_set_health(player, health) == ERROR) {
        return ERROR;
      }
      grules->num_rules++;
      game_rules_create_hack_rule2(grules, game);
      grules->hack->count = grules->hack->count_reset;
    }
    /* fixing the hack */
    if (player_loc == grules->hack->space && space_has_object(space, grules->hack->solution) == TRUE) {
      grules->num_rules++;
      game_rules_create_hack_rule3(grules, game);
      if (space_del_object(space, grules->hack->solution) == ERROR) return ERROR;
      if (link_set_status(grules->hack->trap, OK) == ERROR) return ERROR;
      grules->hack->active = 2;
    }
  }
  return OK;
}

/** game_rules_runaway implements the Escape rule
 */
STATUS game_rules_runaway(Game *game, Grules *grules) {
  Link  *link       = NULL;
  Enemy *enemy      = NULL;
  Id     player_loc = NO_ID;
  int    enemy_health;

  if (!game || !grules) return ERROR;

  player_loc = player_get_location(game_get_player(game));
  if (player_loc == NO_ID) return ERROR;

  enemy = game_get_enemy(game);
  if (!enemy) return ERROR;
  link = game_get_link_from_id(game, grules->escape->link_1);
  if (!link) return ERROR;
  enemy_health = enemy_get_health(enemy);

  if (enemy_health == grules->escape->health && enemy_get_location(enemy) == link_get_origin(link)) {
    grules->escape->active = TRUE;
    if (link_set_status(link, OK) == ERROR) return ERROR;
    if (enemy_set_location(enemy, grules->escape->destination) == ERROR) return ERROR;
    if (enemy_set_health(enemy, grules->escape->reset_health) == ERROR) {
      return ERROR;
    }
    link = game_get_link_from_id(game, grules->escape->link_2);
    if (!link) return ERROR;
    if (link_set_status(link, OK) == ERROR) return ERROR;
    /* we close a link, it is reopened by game_rules_fix_link */
    link = game_get_link_from_id(game, grules->broken->link);
    if (!link) return ERROR;
    if (link_set_status(link, ERROR) == ERROR) return ERROR;
  }
  if (grules->escape->active == TRUE && player_loc != grules->escape->destination) {
    grules->num_rules++;
    game_rules_create_escape_rule(grules, game);
  }
  return OK;
}

/** game_rules_fix_link implements the Broken_link rule
 */
STATUS game_rules_fix_link(Game *game, Grules *grules) {
  Link   *link       = NULL;
  Enemy  *enemy      = NULL;
  Space  *space      = NULL;
  Player *player     = NULL;
  Id      player_loc = NO_ID;

  if (!game || !grules) return ERROR;

  player = game_get_player(game);
  if (!player) return ERROR;

  player_loc = player_get_location(player);
  if (player_loc == NO_ID) return ERROR;

  space = game_get_space(game, player_loc);
  if (!space) return ERROR;

  enemy = game_get_enemy(game);
  if (!enemy) return ERROR;

  if (grules->escape->active == FALSE) return OK;

  link = game_get_link_from_id(game, grules->broken->link);
  if (!link) return ERROR;
  if (grules->broken->active == TRUE) {
    if (link_set_status(link, ERROR) == ERROR) return ERROR;
    if (enemy_get_location(enemy) == grules->escape->destination && player_loc == link_get_origin(link)) {
      grules->num_rules++;
      game_rules_fix_link_rule(grules, game);
      if (space_has_object(space, grules->broken->fix) == TRUE) {
        if (space_del_object(space, grules->broken->fix) == ERROR) return ERROR;
        if (link_set_status(link, OK) == ERROR) return ERROR;
        grules->broken->active = FALSE;
      }
    }
  }
  return OK;
}

/** game_rules_break_torch implements the Light rule
 */
STATUS game_rules_break_torch(Game *game, Grules *grules) {
  Player    *player     = NULL;
  Inventory *inventory  = NULL;
  Space     *space      = NULL;
  Id         player_loc = NO_ID;

  if (!game || !grules) return ERROR;

  player = game_get_player(game);
  if (!player) return ERROR;

  player_loc = player_get_location(player);
  if (player_loc == NO_ID) return ERROR;

  space = game_get_space(game, player_loc);
  if (!space) return ERROR;

  inventory = (Inventory *)player_get_inventory(player);
  if (!inventory) return ERROR;

  if (player_loc == grules->light->space && grules->light->active == 0 && grules->hack->active == 2) {
    grules->light->active = 1;
    if (object_set_turnedon(game_get_object_from_id(game, grules->light->object), FALSE) == ERROR) {
      grules->light->active = 0;
      return ERROR;
    }
    if (object_set_illuminate(game_get_object_from_id(game, grules->light->object), FALSE) == ERROR) {
      object_set_turnedon(game_get_object_from_id(game, grules->light->object), TRUE);
      grules->light->active = 0;
      return ERROR;
    }
  }

  if (grules->light->active == 1) {
    grules->num_rules++;
    game_rules_create_torch_rule1(grules, game);
    if (player_loc == grules->light->solution) {
      grules->num_rules++;
      game_rules_create_torch_rule2(grules, game);
      grules->light->active = 2;
      if (object_set_illuminate(game_get_object_from_id(game, grules->light->object), TRUE) == ERROR) return ERROR;
    }
  }
  return OK;
}

/** game_rules_upgrade implements the Upgrade rule
 */
STATUS game_rules_upgrade(Game *game, Grules *grules) {
  Player *player = NULL;
  Id      player_loc;

  if (!game || !grules) return ERROR;

  if (grules->upgrade->done == TRUE) return OK;

  player = game_get_player(game);
  if (!player) return ERROR;

  player_loc = player_get_location(player);
  if (player_loc == NO_ID) return ERROR;

  if (player_loc == grules->upgrade->space) {
    grules->upgrade->done = TRUE;
    player_add_stat(player, grules->upgrade->stat);
    player_add_stat(player, 100);
    grules->num_rules++;
    game_rules_create_upgrade_rule(grules, game);
  }
  return OK;
}

/** game_rules_create_toxic_space_rule generates dialogues for Toxic rule
 */
STATUS game_rules_create_toxic_space_rule(Game *game, Grules *grules) {
  Player *player;
  Space  *space;
  if (!game) return ERROR;
  player = game_get_player(game);
  if (!player) return ERROR;
  space = game_get_space(game, player_get_location(player));
  strcpy(grules->rule[grules->num_rules], "  ");
  strcat(grules->rule[grules->num_rules], space_get_name(space));
  strcat(grules->rule[grules->num_rules], " is toxic. You will loose life");

  return OK;
}

/** game_rules_create_prosuit_rule generates dialogues to inform about the Toxic protection object
 */
STATUS game_rules_create_prosuit_rule(Game *game, Grules *grules) {
  Object *object = NULL;
  if (!game || !grules) return ERROR;
  object = game_get_object_from_id(game, grules->toxic->protection);
  if (!object) return ERROR;
  sprintf(grules->rule[grules->num_rules], " Take %s from %s to protect you.", object_get_name(object), space_get_name(game_get_space(game, game_get_object_location(game, object))));
  return OK;
}

/** game_rules_create_life_rule generates dialogues for Life rule
 */
STATUS game_rules_create_life_rule(Grules *grules, Game *game, int i) {
  Object *object = NULL;
  if (!grules || !game) return ERROR;
  if (i < 0 || i > grules->num_life) return ERROR;
  object = game_get_object_from_id(game, grules->objects[i]->object);
  if (!object) return ERROR;
  strcpy(grules->rule[grules->num_rules], "\0");
  sprintf(grules->rule[grules->num_rules], "  %d", grules->objects[i]->power);
  strcat(grules->rule[grules->num_rules], " health point from ");
  strcat(grules->rule[grules->num_rules], object_get_name(object));
  return OK;
}

/** game_rules_create_hack_rule1 generates dialogues for the Hack rule begining
 */
STATUS game_rules_create_hack_rule1(Grules *grules, Game *game) {
  Object *obj   = NULL;
  Space  *space = NULL;

  if (!grules || !game) return ERROR;

  strcpy(grules->rule[grules->num_rules], "  The enemy trapped you! There's no air!");
  grules->num_rules++;
  obj = game_get_object_from_id(game, grules->hack->solution);
  if (!obj) return ERROR;
  space = game_get_space(game, grules->hack->space);
  if (!space) return ERROR;
  sprintf(grules->rule[grules->num_rules], "  Search and take %s and drop it in %s to survive.", object_get_name(obj), space_get_name(space));
  return OK;
}

/** game_rules_create_hack_rule2 generates dialogues for the Hack rule loosing life
 */
STATUS game_rules_create_hack_rule2(Grules *grules, Game *game) {
  if (!grules || !game) return ERROR;
  strcpy(grules->rule[grules->num_rules], "  Hurry! You lost another health point");
  return OK;
}

/** game_rules_create_hack_rule1 generates dialogues for the Hack rule ending
 */
STATUS game_rules_create_hack_rule3(Grules *grules, Game *game) {
  if (!game || !grules) return ERROR;
  strcpy(grules->rule[grules->num_rules], "  Wow! You solved the issue.");
  return OK;
}

/** game_rules_create_torch_rule1 generates dialogues for the Light rule begining
 */
STATUS game_rules_create_torch_rule1(Grules *grules, Game *game) {
  Object *object   = NULL;
  Space  *solution = NULL;
  if (!game || !grules) return ERROR;
  object   = game_get_object_from_id(game, grules->light->object);
  solution = game_get_space(game, grules->light->solution);
  if (!object || !solution) return ERROR;
  strcpy(grules->rule[grules->num_rules], "\0");
  sprintf(grules->rule[grules->num_rules], "  %s has stopped working, go to %s to fix it", object_get_name(object), space_get_name(solution));
  return OK;
}

/** game_rules_create_torch_rule2 generates dialogues for the Light rule ending
 */
STATUS game_rules_create_torch_rule2(Grules *grules, Game *game) {
  Object *object = NULL;
  if (!game || !grules) return ERROR;
  object = game_get_object_from_id(game, grules->light->object);
  if (!object) return ERROR;
  strcpy(grules->rule[grules->num_rules], "\0");
  sprintf(grules->rule[grules->num_rules], "  Great! You can switch %s again!", object_get_name(object));
  return OK;
}

/** game_rules_create_escape_rule generates dialogues for the Escape rule
 */
STATUS game_rules_create_escape_rule(Grules *grules, Game *game) {
  Space *space = NULL;
  if (!game || !grules) return ERROR;
  space = game_get_space(game, grules->escape->destination);
  if (!space) return ERROR;
  sprintf(grules->rule[grules->num_rules], "  The enemy has run away to %s", space_get_name(space));

  if (grules->upgrade->done == FALSE) {
    grules->num_rules++;
    space = NULL;
    space = game_get_space(game, link_get_dest(game_get_link_from_id(game, grules->escape->link_2)));
    if (!space) return ERROR;
    strcpy(grules->rule[grules->num_rules], "\0");
    sprintf(grules->rule[grules->num_rules], "  Upgrade your skills in %s and search him.", space_get_name(space));
  }
  return OK;
}

/** game_rules_create_fix_link_rule generates dialogues for the Broken_link rule
 */
STATUS game_rules_fix_link_rule(Grules *grules, Game *game) {
  Object *object = NULL;
  if (!game || !grules) return ERROR;
  object = game_get_object_from_id(game, grules->broken->fix);
  if (!object) return ERROR;

  strcpy(grules->rule[grules->num_rules], "\0");
  sprintf(grules->rule[grules->num_rules], "  Oh no! %s is broken. Drop %s here to fix it!", link_get_name(game_get_link_from_id(game, grules->broken->link)), object_get_name(object));
  if (grules->broken->active == FALSE) {
    grules->num_rules++;
    sprintf(grules->rule[grules->num_rules], "Wow! That worked! You can use it again!");
  }
  return OK;
}

/** game_rules_create_upgrade_rule generates dialogues for the Upgrade rule
 */
STATUS game_rules_create_upgrade_rule(Grules *grules, Game *game) {
  if (!game || !grules) return ERROR;
  sprintf(grules->rule[grules->num_rules], "  Your attack has been upgraded");
  return OK;
}

/** game_rules_parse_line1 parses the input from a .dat file so that it can be
 * processed in other functions with ease. It is an adjustment of game_management_parse_line
 */
STATUS game_rules_parse_line1(FILE *f, int *arg_num, char args[MAX_RARG][MAX_TEXT]) {
  char  raw_input[MAX_TEXT];
  char *toks;
  int   i, len;

  if (!f || !arg_num) return ERROR;

  if (!fgets(raw_input, MAX_TEXT, f)) return ERROR;

  if (raw_input[0] != '#' || raw_input[3] != ':') return OK;

  *arg_num   = 1;
  args[0][0] = raw_input[1];
  args[0][1] = raw_input[2];
  args[0][2] = '\0';

  for (toks = strtok(raw_input + 4, ";"); toks != NULL && (*arg_num) < MAX_TEXT; toks = strtok(NULL, ";"), (*arg_num)++) {
    strcpy(args[(*arg_num)], toks);
  }
  len = strlen(args[(*arg_num) - 1]);
  for (i = 0; i < len; i++) {
    if (args[(*arg_num) - 1][i] == '\n' || args[(*arg_num) - 1][i] == '\r') args[(*arg_num) - 1][i] = '\0';
  }
  return OK;
}
