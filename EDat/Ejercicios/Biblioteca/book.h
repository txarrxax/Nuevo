#ifndef BOOK_H_
#define BOOK_H_

#include "types.h"

/**
 * @brief ADT Book
*/
typedef struct _Book Book;

/**
 * @brief It creates a new book from a description
 * @author Alberto Tarrasa
 * 
 * @param desc an array with a description of a book
 * @return a pointer to a new book
*/
Book *book_createFromDescription (char *desc);

/**
 * @brief It gets the author of a book
 * @author Alberto Tarrasa
 * 
 * @param b a pointer to a book
 * @return a string with the author of the book
*/
char *book_getAuthor (Book *b);

/**
 * @brief It gets the title of a book
 * @author Alberto Tarrasa
 * 
 * @param b a pointer to a book
 * @return a string with the title of the book
*/
char *book_getTitle (Book *b);

/**
 * @brief It gets the ISBN of a book
 * @author Alberto Tarrasa
 * 
 * @param b a pointer to a book
 * @return a string with the ISBN of the book
*/
char *book_getIsbn (Book *b);

/**
 * @brief It gets the number of copies of a book
 * @author Alberto Tarrasa
 * 
 * @param b a pointer to a book
 * @return an integer with the number of copies of the book
*/
int book_getNumCopies (Book *b);

/**
 * @brief It sets the number of copies of a book
 * @author Alberto Tarrasa
 * 
 * @param b a pointer to a book
 * @param n an integer with the number of copies
 * @return OK if everything goes well, ERROR if not
*/
Status book_setNumCopies (Book *b, int n);

/**
 * @brief It compares two books
 * @author Alberto Tarrasa
 * 
 * @param b1 a pointer to a book
 * @param b2 a pointer to a book
 * @return TRUE if both books have the same ISBN, FALSE if not
*/
Bool book_compare (Book *b1, Book *b2);

/**
 * @brief It frees the memory allocated for a book
 * @author Alberto Tarrasa
 * 
 * @param b a pointer to a book
 * @return no return
*/
void book_destroy (Book *b);

/**
 * @brief It prints the information of a book
 * @author Alberto Tarrasa
 * 
 * @param f a pointer to a file
 * @param b a pointer to a book
 * @return OK if everything goes well, ERROR if not
*/
Status book_print (FILE *f, Book *b);

#endif