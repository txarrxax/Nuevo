#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define MAX_QUEUE 8

struct _Queue{
    void *data[MAX_QUEUE];
    int front;
    int rear;
};

/*<------------------ FUNCIONES PRIVADAS --------------------------->*/
Bool _queue_isFull(const Queue *pq);

Bool _queue_isFull(const Queue *pq){
    if (!pq) return TRUE;

    if (pq->front == (pq->rear +1)%MAX_QUEUE) return TRUE;

    return FALSE;
}
/*<----------------------------------------------------------------->*/

Queue *queue_new(){
    Queue *pq = NULL;
    int i;

    pq = (Queue *)malloc(sizeof(Queue));
    if (!pq) return NULL;

    for (i=0; i<MAX_QUEUE; i++)
        pq->data[i] = NULL;
    
    pq->front = 0;
    pq->rear = 0;

    return pq;
}

void queue_free(Queue *pq){
    free(pq);
}

Bool queue_isEmpty(const Queue *pq){
    if (!pq) return TRUE;

    if (pq->front == pq->rear)  return TRUE;

    return FALSE;
}

Status queue_push(Queue *pq, const void *e){
    if (!pq || !e || _queue_isFull(pq)) return ERROR;

    pq->data[pq->rear] = (void *)e;
    pq->rear = (pq->rear + 1)%MAX_QUEUE;

    return OK;
}

void *queue_pop(Queue *pq){
    void *e = NULL;

    if (!pq || queue_isEmpty(pq)) return NULL;
    
    e = pq->data[pq->front];
    pq->data[pq->front] = NULL;
    pq->front = (pq->front + 1)%MAX_QUEUE;

    return e;
}

void *queue_getFront(const Queue *pq){
    if (!pq || queue_isEmpty(pq)) return NULL;

    return pq->data[pq->front];
}

void *queue_getBack(const Queue *pq){
    int last_elem;

    if (!pq || queue_isEmpty(pq)) return NULL;

    last_elem = (MAX_QUEUE + pq->rear - 1)%MAX_QUEUE;
    return pq->data[last_elem];
}
