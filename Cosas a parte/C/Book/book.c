#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

struct _Book{
    char title[MAX_WORD];
    char author[MAX_WORD];
    char ISBN[ISBN_LEN];
    Bool borrow;
};

Book *book_create(char *title, char *author, char *ISBN){
    Book *b = NULL;

    if (!title || !author || !ISBN) return NULL;

    b = (Book*)malloc(sizeof(Book));

    if (!b) return NULL;

    strcpy(b->title, title);
    strcpy(b->author, author);
    strcpy(b->ISBN, ISBN);
    b->borrow = FALSE;

    return b;
}

Status book_delete(Book *b){
    free(b);
    
    return OK;
}

Status book_set_title(Book *b, char *title){
    if (!b || !title) return ERROR;

    strcpy(b->title, title);

    return OK;
}

Status book_set_author(Book *b, char *author){
    if (!b || !author) return ERROR;

    strcpy(b->author, author);

    return OK;
}

Status book_set_ISBN(Book *b, char *ISBN){
    if (!b || !ISBN) return ERROR;

    strcpy(b->ISBN, ISBN);

    return OK;
}

Status book_set_borrow(Book *b, Bool borrow){
    if (!b) return ERROR;

    b->borrow = borrow;

    return OK;
}

char *book_get_title(Book *b){
    if (!b) return NULL;

    return b->title;
}

char *book_get_author(Book *b){
    if (!b) return NULL;

    return b->author;
}

char *book_get_ISBN(Book *b){
    if (!b) return NULL;

    return b->ISBN;
}

Bool book_get_borrow(Book *b){
    if (!b) return NULL;

    return b->borrow;
}

