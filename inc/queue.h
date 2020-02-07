#ifndef QUEUE_H
#define QUEUE_H

#include "stdlib.h"

#define BLOCK_SIZE 256

typedef union item {
    void *v;
    int i;
    unsigned int u;
    char *s;
    long l;
    float f;
    double d;

} item_t;

typedef struct queue {
    item_t value;
    struct queue *next;
} queue_t;

queue_t *free_list;

queue_t* create_queue(void);

int queue_empty(queue_t *qu);

item_t front_element(queue_t *qu);

void enqueue(item_t x, queue_t *qu);

item_t dequeue(queue_t *qu);

queue_t* remove_queue(queue_t *qu);

void clean_free_nodes(void);

#endif
