/**
 * @brief It declares the tests for the link module
 *
 * @file set_test.h
 * @author Álvaro Grande
 * @version 1.0
 * @date 20-03-2023
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre Link ID
 * @post Non NULL pointer to link
 */
void test1_link_create();

/**
 * @test Test link creation
 * @pre Link ID
 * @post Link_ID = Supplied Link id
 */
void test2_link_create();

/**
 * @test Test link creation
 * @pre Link ID
 * @post Link_id_origin == NO_ID
 */
void test3_link_create();

/**
 * @test Test link free
 * @pre Pointer to link
 * @post OK
 */
void test1_link_destroy();

/**
 * @test Test link free
 * @pre NULL
 * @post ERROR
 */
void test2_link_destroy();

/**
 * @test Test function link_get_id
 * @pre Link NULL
 * @post Output == NO_ID
 */
void test1_link_get_id();

/**
 * @test Test function link_get_id
 * @pre Link ID
 * @post Link_ID == Supplied Link Id
 */
void test2_link_get_id();

/**
 * @test Test function link_get_name
 * @pre Link NULL
 * @post Output == NULL
 */
void test1_link_get_name();

/**
 * @test Test function link_get_name
 * @pre Link
 * @post Output == OK
 */
void test2_link_get_name();

/**
 * @test Test function link_get_origin
 * @pre Link NULL
 * @post Output == NO_ID
 */
void test1_link_get_origin();

/**
 * @test Test function link_get_origin
 * @pre Link
 * @post Output == NO_ID
 */
void test2_link_get_origin();

/**
 * @test Test function link_get_dest
 * @pre Link NULL
 * @post Output == NO_ID
 */
void test1_link_get_dest();

/**
 * @test Test function link_get_dest
 * @pre Link
 * @post Output == NO_ID
 */
void test2_link_get_dest();

/**
 * @test Test function link_get_direction
 * @pre Link NULL
 * @post Output == U
 */
void test1_link_get_direction();

/**
 * @test Test function link_get_direction
 * @pre Link
 * @post Output == U
 */
void test2_link_get_direction();

/**
 * @test Test function link_get_status
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_get_status();

/**
 * @test Test function link_get_status
 * @pre Link
 * @post Output == ERROR
 */
void test2_link_get_status();

/**
 * @test Test function link_set_name
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_set_name();

/**
 * @test Test function link_set_name
 * @pre Link
 * @post Output == TEST_LINK_NAME
 */
void test2_link_set_name();

/**
 * @test Test function link_set_origin
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_set_origin();

/**
 * @test Test function link_set_origin
 * @pre Empty link
 * @post Output == TRUE
 */
void test2_link_set_origin();

/**
 * @test Test function link_set_dest
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_set_dest();

/**
 * @test Test function link_set_dest
 * @pre Empty link
 * @post Output == TRUE
 */
void test2_link_set_dest();

/**
 * @test Test function link_set_direction
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_set_direction();

/**
 * @test Test function link_set_direction
 * @pre Empty link
 * @post Output == TRUE
 */
void test2_link_set_direction();

/**
 * @test Test function link_set_status
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_set_status();

/**
 * @test Test function link_set_status
 * @pre Empty link
 * @post Output == TRUE
 */
void test2_link_set_status();

/**
 * @test Test function link_print
 * @pre Link NULL
 * @post Output == ERROR
 */
void test1_link_print();

/**
 * @test Test function link_print
 * @pre Empty link
 * @post Output == TRUE
 */
void test2_link_print();

#endif