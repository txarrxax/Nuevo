#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "book.h"

/**
 * @brief ADT Library
*/
typedef struct _Library Library;

/**
 * @brief It creates a new empty library
 * @author Alberto Tarrasa
 * 
 * @return a pointer to a new library
*/
Library *library_create ();

/**
 * @brief It checks if a library is empty
 * @author Alberto Tarrasa
 * 
 * @param lib a pointer to a library
 * @return TRUE if the library is empty, FALSE if not
*/
Bool library_isEmpty (Library *lib);

/**
 * @brief It checks if a book is in a library
 * @author Alberto Tarrasa
 * 
 * @param lib a pointer to a library
 * @param isbn an array with the ISBN of a book
 * @return TRUE if the book is in the library, FALSE if not
*/
Bool library_bookInLib (Library *lib, char *isbn);

/**
 * @brief It adds a new book to a library
 * @author Alberto Tarrasa
 * 
 * @param lib a pointer to a library
 * @param desc an array with a description of a book
 * @return OK if everything goes well, ERROR if not
*/
Status library_addBook (Library *lib, char *desc);

/**
 * @brief It removes a book from a library
 * @author Alberto Tarrasa
 * 
 * @param lib a pointer to a library
 * @param isbn an array with the ISBN of a book
 * @return OK if everything goes well, ERROR if not
*/
Status library_removeBook (Library *lib, char *isbn);

/**
 * @brief It frees the memory allocated for a library
 * @author Alberto Tarrasa
 * 
 * @param lib a pointer to a library
 * @return no return
*/
void library_destroy (Library *lib);

/**
 * @brief It prints the information of a library
 * @author Alberto Tarrasa
 * 
 * @param f a pointer to a file
 * @param lib a pointer to a library
 * @return OK if everything goes well, ERROR if not
*/
Status library_print (FILE *f, Library *lib);


#endif