#include "tree.h"

tree_node_t* create_tree(void) {
    tree_node_t *tmp_node;
    tmp_node = get_t_node();
    tmp_node->left = NULL;
    tmp_node->right = NULL;
    tmp_node->color = black;
    return tmp_node;
}

tree_node_t* get_t_node(void) {
    tree_node_t *tmp = malloc(sizeof(tree_node_t));
    return tmp;
}

void left_rotation(tree_node_t *n) {
    tree_node_t *tmp_node;
    key_t tmp_key;
    tmp_node = n->left;
    tmp_key = n->key;
    n->left = n->right;
    n->key = n->right->key;
    n->right = n->left->right;
    n->left->right = n->left->left;
    n->left->left = tmp_node;
    n->left->key = tmp_key;
}

void right_rotation(tree_node_t *n) {
    tree_node_t *tmp_node;
    key_t tmp_key;
    tmp_node = n->right;
    tmp_key = n->key;
    n->right = n->left;
    n->key = n->left->key;
    n->left = n->right->left;
    n->right->left = n->right->right;
    n->right->right = tmp_node;
    n->right->right->key = tmp_key;
}

object_t* find(tree_node_t *tree, key_t query_key) {
    tree_node_t *tmp_node;

    if (tree->left == NULL) {
        return NULL;
    } else {

        tmp_node = tree;

        while (tmp_node->right != NULL) {
            if (query_key < tmp_node->key) {
                tmp_node = tmp_node->left;
            } else {
                tmp_node = tmp_node->right;
            }
        }
        if (tmp_node->key == query_key) {
            return (object_t*) tmp_node->left;
        }
        return NULL;
    }
    return NULL;
}

void insert_rebalance(tree_node_t *current, tree_node_t *next_node,
        tree_node_t *upper, key_t new_key) {

    while (current->right != NULL) {
        if (new_key < current->key) {
            next_node = current->left;
        } else {
            next_node = current->right;
        }
        if (current->color == black) {
            if (current->left->color == black
                    || current->right->color == black) {
                upper = current;
                current = next_node;
            } else {
                if (upper == NULL) {
                    current->left->color = black;
                    current->right->color = black;
                    upper = current;
                } else if (current->key < upper->key) {
                    if (current == upper->left) {
                        current->left->color = black;
                        current->right->color = black;
                        current->color = red;
                    } else if (current == upper->left->left) {
                        right_rotation(upper);
                        upper->left->color = red;
                        upper->right->color = red;
                        upper->left->left->color = black;
                        upper->left->left->color = black;
                    } else {
                        left_rotation(upper->left);
                        right_rotation(upper);
                        upper->left->color = red;
                        upper->right->color = red;
                        upper->right->left->color = black;
                        upper->left->right->color = black;
                    }
                } else {
                    if (current == upper->right) {
                        current->left->color = black;
                        current->right->color = black;
                        current->color = red;
                    } else if (current == upper->right->right) {
                        left_rotation(upper);
                        upper->left->color = red;
                        upper->right->color = red;
                        upper->right->left->color = black;
                        upper->right->right->color = black;
                    } else {
                        right_rotation(upper->right);
                        left_rotation(upper);
                        upper->left->color = red;
                        upper->right->color = red;
                        upper->right->left->color = black;
                        upper->left->right->color = black;
                    }
                }
                current = next_node;
                upper = current;
            }
        } else {
            current = next_node;
        }
    }
}
static void _insert(tree_node_t *current, key_t new_key, object_t *new_object) {
    tree_node_t *old_leaf;
    tree_node_t *new_leaf;
    old_leaf = get_t_node();
    old_leaf->left = current->left;
    old_leaf->key = current->key;
    old_leaf->right = NULL;
    old_leaf->color = red;
    new_leaf = get_t_node();
    new_leaf = new_leaf->left = (tree_node_t*) new_object;
    new_leaf->key = new_key;
    new_leaf->right = NULL;
    new_leaf->color = red;
    if (current->key < new_key) {
        current->left = old_leaf;
        current->right = old_leaf;
        current->key = new_key;
    } else {
        current->left = new_leaf;
        current->right = old_leaf;
    }
}
int insert(tree_node_t *tree, key_t new_key, object_t *new_object) {
    if (tree->left == NULL) {

        tree->left = (tree_node_t*) new_object;
        tree->key = new_key;
        tree->color = black;
        tree->right = NULL;

    } else {

        tree_node_t *current = NULL;
        tree_node_t *next_node = NULL;
        tree_node_t *upper = NULL;
        current = tree;
        insert_rebalance(current, next_node, upper, new_key);
        if (current->key == new_key) {
            return -1;
        }
        _insert(current, new_key, new_object);
    }
    return 0;
}

//int delete(tree_node_t *tree, key_t remove) {
//    tree_node_t *current;
//    tree_node_t *next_node;
//    tree_node_t *upper;
//    current = tree;
//    while (current->right != NULL) {
//        if (remove < current->key) {
//            current = current->left;
//        } else {
//            current = current->right;
//        }
//    }
//    return 0;
//}
