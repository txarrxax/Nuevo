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
void test_null_arg();

/**
 * @test test command_get_user_input with empty input
 * @pre "" input
 * @post NO_CMD
 */
void test_no_command();

/**
 * @test test command_get_user_input with wrong command
 * @pre wrong command ("hello")
 * @post UNKNOWN
 */
void test_unknown();

/**
 * @test test command_get_user_input with exit command
 * @pre "e" and "exit"
 * @post EXIT
 */
void test_exit();

/**
 * @test test command_get_user_input with next command
 * @pre "n" and "next"
 * @post NEXT
 */
void test_next();

/**
 * @test test command_get_user_input with back command
 * @pre "b" and "back"
 * @post BACK
 */
void test_back();

/**
 * @test test command_get_user_input with take command
 * @pre "t" and "take"
 * @post TAKE
 */
void test_take();

/**
 * @test test command_get_user_input with drop command
 * @pre "d" and "drop"
 * @post DROP
 */
void test_drop();

/**
 * @test test command_get_user_input with right command
 * @pre "r" and "right"
 * @post RIGHT
 */
void test_right();

/**
 * @test test command_get_user_input with left command
 * @pre "l" and "left"
 * @post LEFT
 */
void test_left();

/**
 * @test test command_get_user_input with attack command
 * @pre "a" and "attack"
 * @post ATTACK
 */
void test_attack();

/**
 * @test test command_get_user_input with inspect command
 * @pre "i" and "inspect"
 * @post INSPECT
 */
void test_inspect();

/**
 * @test test command_get_user_input with move command
 * @pre "m" and "move"
 * @post MOVE
 */
void test_move();

/**
 * @test test that arguments are being read correctly
 * @pre "inspect object --------"
 * @post "object"
 */
void test_arg();

/**
 * @test test that command_get_user_input can read longer than expected unknown commands without leaks
 * @pre gibberish longer than CMD_LENGHT, the MAX number of characters command_get_user_input can read
 * @post UNKNOWN
 */
void test_overflow1();

/**
 * @test test that command_get_user_input can read longer than expected correct commands without leaks
 * @pre valid command "next " followed by gibberish so that the input is longer than CMD_LENGTH
 * @post NEXT
 */
void test_overflow2();

#endif
