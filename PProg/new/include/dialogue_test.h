/**
 * @brief It declares the tests for the dialogue module
 *
 * @file dialogue_test.h
 * @author Álvaro Grande
 * @version 2.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef DIALOGUE_TEST_H
#define DIALOGUE_TEST_H

/**
 * @test Test dialogue message function
 * @pre Game NULL
 * @post Output == ERROR
 */
void test1_dialogue_message();

/**
 * @test Test dialogue message function
 * @pre dlg NO_DLG
 * @post Output == ERROR
 */
void test2_dialogue_message();

#endif