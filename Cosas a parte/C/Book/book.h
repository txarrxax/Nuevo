#ifndef BOOK_H_
#define BOOK_H_

#include "types.h"

#define MAX_WORD 64
#define ISBN_LEN 17

typedef struct _Book Book;

Book book_create(char *title, char *author, char *ISBN);

Status book_delete(Book *b);

Status book_set_title(Book *b, char *title);

Status book_set_author(Book *b, char *author);

Status book_set_ISBN(Book *b, char *ISBN);

Status book_set_borrow(Book *b, Bool borrow);

char *book_get_title(Book *b);

char *book_get_author(Book *b);

char *book_get_ISBN(Book *b);

Bool book_get_borrow(Book *b);

#endif