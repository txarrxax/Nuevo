#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "book.h"

#define MAX_TITLE 128
#define MAX_AUTHOR 64
#define MAX_ISBN 32

struct _Book{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char isbn[MAX_ISBN];
    int num_copies;
};

/* book_createFromDescription creates a new book from a description */
Book *book_createFromDescription (char *desc){
    Book *b;
    char aux[64];

    /* error checks */
    if (!desc) return NULL;

    /* allocate memory for the book */
    b = (Book *)malloc(sizeof(Book));
    if (!b) return NULL;

    /* read the description and set the values */
    if (sscanf(desc, "%s %s %s %s", b->author, b->title, b->isbn, aux) != 4){
        free(b);
        return NULL;
    }

    /* convert an array into an integer */
    book_setNumCopies(b, atoi(aux));

    return b;
}

/* book_getAuthor gets the author of a book */
char *book_getAuthor (Book *b){
    /* error checks */
    if (!b) return NULL;

    return b->author;
}

/* book_getTitle gets the title of a book */
char *book_getTitle (Book *b){
    /* error checks */
    if (!b) return NULL;

    return b->title;
}

/* book_get_Isbn gets the ISBN of a book */
char *book_getIsbn (Book *b){
    /* error checks */
    if (!b) return NULL;

    return b->isbn;
}

/* book_getNumCopies gets the number of copies of a book */
int book_getNumCopies (Book *b){
    /* error checks */
    if (!b) return NULL;

    return b->num_copies;
}

/* book_compare compares two books*/
Bool book_compare (Book *b1, Book *b2){
    /* error checks */
    if (!b1 || !b2) return FALSE;

    /* compare the ISBNs */
    if (strcmp(b1, b2) == 0) return TRUE;

    return FALSE;
}

/* book_setNumCopies sets the number of copies of a book */
Status book_setNumCopies (Book *b, int n){
    /* error checks */
    if (!b || n < 0) return ERROR;

    b->num_copies = n;
    return OK;
}

/* book_destroy frees the memory allocated for a book*/
void book_destroy (Book *b){
    free (b);
}

/* book_print prints the information of a book */
Status book_print (FILE *f, Book *b){
    /* error checks */
    if (!b || !f) return ERROR;

    /* print the information */
    fprintf(f, "-------Book-------\n");
    fprintf(f, "Title: %s\n", book_getTitle(b));
    fprintf(f, "Author: %s\n", book_getAuthor(b));
    fprintf(f, "ISBN: %s\n", book_getIsbn(b));
    fprintf(f, "Number of copies: %d\n", book_getNumCopies(b));
    fprintf(f, "------------------\n");

    return OK;
}