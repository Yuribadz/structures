#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

queue_t *free_list = NULL;

queue_t* create_queue(void) {
    queue_t *entrypoint;
    queue_t *placeholder;
    entrypoint = malloc(sizeof(queue_t));
    placeholder = malloc(sizeof(queue_t));
    entrypoint->next = placeholder;
    placeholder->next = placeholder;
    return entrypoint;
}

int queue_empty(queue_t *qu) {
    return qu->next == qu->next->next;
}

item_t front_element(queue_t *qu) {
    return qu->next->next->next->value;
}

static queue_t* get_node(void) {
    queue_t *tmp;
    if (free_list != NULL) {
        tmp = free_list;
        free_list = free_list->next;
    } else {
        tmp = malloc(sizeof(queue_t));
    }
    return tmp;
}

static void return_node(queue_t *node) {
    node->next = free_list;
    free_list = node;
}

void clean_free_nodes(void) {
    queue_t *head = free_list;
    while (head) {
        queue_t *next = head->next;
        free(head);
        head = next;
    }
    free_list = NULL;
}

void enqueue(item_t x, queue_t *qu) {
    queue_t *tmp;
    queue_t *new;
    new = get_node();
    new->value = x;
    tmp = qu->next;
    qu->next = new;
    new->next = tmp->next;
    tmp->next = new;
}

item_t dequeue(queue_t *qu) {
    queue_t *tmp;
    item_t tmp_item;
    tmp = qu->next->next->next;
    qu->next->next->next = tmp->next;
    if (tmp == qu->next)
        qu->next = tmp->next;
    tmp_item = tmp->value;
    return_node(tmp);
    return tmp_item;
}

queue_t* remove_queue(queue_t *qu) {
    queue_t *tmp;
    tmp = qu->next->next;
    while (tmp != qu->next) {
        qu->next->next = tmp->next;
        return_node(tmp);
        tmp = qu->next->next;
    }
    return_node(qu->next);
    return_node(qu);
    return NULL;
}
