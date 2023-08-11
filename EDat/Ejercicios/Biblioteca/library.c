#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"
#include "book.c"

#define MAX_BOOKS 1064

struct _Library{
    Book *catalog[MAX_BOOKS];
    int num_books;
};

/*<---------------------------- PRIVATE FUNCTIONS --------------------------->*/
/* _library_isFull checks if a library is full */
Bool _library_isFull (Library *lib){
    /* error checks */
    if (!lib) return TRUE;

    if (lib->num_books == MAX_BOOKS) return TRUE;

    return FALSE;
}
/*<-------------------------------------------------------------------------->*/

/* library_create creates a new empty library */
Library *library_create (){
    Library *lib;
    int i;

    /* allocate memory for the library */
    lib = (Library *)malloc(sizeof(Library));
    if (!lib) return NULL;

    /* set initial values */
    lib->num_books = 0;
    for (i=0; i<MAX_BOOKS; i++)
        lib->catalog[i] = NULL;

    return lib;
}

/* library_isEmpty checks if a library is empty */
Bool library_isEmpty (Library *lib){
    /* error checks */
    if (!lib) return TRUE;

    if (lib->num_books == 0) return TRUE;

    return FALSE;
}

/* library_bookInLib checks if a book is in a library */
Bool library_bookInLib (Library *lib, char *isbn){
    int i;
    /* error checks */
    if (!lib || !isbn) return FALSE;

    for (i=0; i<MAX_BOOKS; i++)
        if (strcmp(lib->catalog[i]->isbn, isbn) == 0) return TRUE;

    return FALSE;
}   

/* library_addBook adds a new book to a library */
Status library_addBook (Library *lib, char *desc){
    Book *b;

    /* error checks */
    if (!lib || !desc || _library_isFull(lib)) return ERROR;

    /* create the book */
    b = book_createFromDescription(desc);
    if (!b) return NULL;

    /* check if the book is in the library */
    if (library_bookInLib(lib, b->isbn)){
        book_destroy(b);
        return ERROR;
    }

    /* add the book to the library */
    lib->catalog[lib->num_books] = b;
    lib->num_books++;

    return OK;
}

/* library_removeBook removes a book from a library */
Status library_removeBook (Library *lib, char *isbn){
    int i;

    /* error checks */
    if (!lib || !isbn || library_isEmpty(lib)) return ERROR;

    /* check if the book is in the library */
    if (!library_bookInLib(lib, isbn)) return ERROR;

    /* remove the book */
    for (i=0; i<MAX_BOOKS; i++){
        if (strcmp(lib->catalog[i]->isbn, isbn) == 0)
            book_destroy(lib->catalog[i]);
    }

    lib->num_books--;

    return OK;
}

/* library_destroy frees the memory allocated for a library */
void library_destroy (Library *lib){
    int i;

    for (i=0; i<MAX_BOOKS; i++)
        book_destroy(lib->catalog[i]);

    free(lib);
}

/* library_print prints the information of a library */
Status library_print (FILE *f, Library *lib){
    int i;

    /* error checks */
    if (!lib) return ERROR;

    /* print the information */
    fprintf(f, "<----------LIBRARY---------->\n");
    fprintf(f, "Number of books: %d\n", lib->num_books);
    for (i=0; i<MAX_BOOKS; i++){
        if (lib->catalog[i])
            book_print(f, lib->catalog[i]);
    }
    fprintf(f, "<--------------------------->\n");

    return OK;
}