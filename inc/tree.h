#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdlib.h>

typedef int key_t;
typedef int object_t;

typedef struct tr_n_t {
    key_t key;
    struct tr_n_t *left;
    struct tr_n_t *right;
    enum {
        red, black
    } color;
} tree_node_t;

tree_node_t* create_tree(void);

tree_node_t* get_node(void);

object_t* find(tree_node_t *tree, key_t query_key);

#endif // TREE_H
