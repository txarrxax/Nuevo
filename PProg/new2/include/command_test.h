/**
 * @brief It declares the tests for the command module
 *
 * @file command_test.h
 * @author Diego Fernández
 * @version 2.0
 * @date 10-04-2023
 * @copyright GNU Public License
 */

#ifndef COMMAND_TEST
#define COMMAND_TEST

/**
 * @test test command_get_user_input when arg is NULL
 * @pre NULL arg pointer
 * @post NO_CMD
 */
void test_null_arg_command_get_user_input();

/**
 * @test test command_get_user_input with empty input
 * @pre "" input
 * @post NO_CMD
 */
void test_no_command_command_get_user_input();

/**
 * @test test command_get_user_input with wrong command
 * @pre wrong command ("hello")
 * @post UNKNOWN
 */
void test_unknown_command_get_user_input();

/**
 * @test test command_get_user_input with exit command
 * @pre "e" and "exit"
 * @post EXIT
 */
void test_exit_command_get_user_input();

/**
 * @test test command_get_user_input with switch command
 * @pre "s" and "switch"
 * @post SWITCH
 */
void test_switch_command_get_user_input();

/**
 * @test test command_get_user_input with open command
 * @pre "o" and "open"
 * @post OPEN
 */
void test_open_command_get_user_input();

/**
 * @test test command_get_user_input with take command
 * @pre "t" and "take"
 * @post TAKE
 */
void test_take_command_get_user_input();

/**
 * @test test command_get_user_input with drop command
 * @pre "d" and "drop"
 * @post DROP
 */
void test_drop_command_get_user_input();

/**
 * @test test command_get_user_input with save command
 * @pre "s" and "save"
 * @post SAVE
 */
void test_save_command_get_user_input();

/**
 * @test test command_get_user_input with load command
 * @pre "l" and "load"
 * @post LOAD
 */
void test_load_command_get_user_input();

/**
 * @test test command_get_user_input with attack command
 * @pre "a" and "attack"
 * @post ATTACK
 */
void test_attack_command_get_user_input();

/**
 * @test test command_get_user_input with inspect command
 * @pre "i" and "inspect"
 * @post INSPECT
 */
void test_inspect_command_get_user_input();

/**
 * @test test command_get_user_input with move command
 * @pre "m" and "move"
 * @post MOVE
 */
void test_move_command_get_user_input();

/**
 * @test test that arguments are being read correctly
 * @pre "inspect object --------"
 * @post "object"
 */
void test_arg_command_get_user_input();

/**
 * @test test that command_get_user_input can read longer than expected unknown commands without leaks
 * @pre gibberish longer than CMD_LENGHT, the MAX number of characters command_get_user_input can read
 * @post UNKNOWN
 */
void test_overflow1_command_get_user_input();

/**
 * @test test that command_get_user_input can read longer than expected correct commands without leaks
 * @pre valid command "next " followed by gibberish so that the input is longer than CMD_LENGTH
 * @post NEXT
 */
void test_overflow2_command_get_user_input();

#endif
