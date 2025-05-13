/*
** EPITECH PROJECT, 2024
** organised
** File description:
** list
*/

#ifndef INCLUDED_LIST_H
    #define INCLUDED_LIST_H

    #include <stdlib.h>

typedef struct node_s {
    void *data;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list(void);
void add_end(list_t *list, void *data);
void add_front(list_t *list, void *data);
void del_front(list_t *list);
void del_end(list_t *list);
void del_node(list_t *list, node_t *node);
void swap_node(node_t *n1, node_t *n2);
void cut_list(list_t *list, node_t *start, node_t *end);
void cat_list(list_t *l1, list_t *l2);
node_t *find_node(list_t *list, node_t *to_find);
void rev_list(list_t *list);

#endif
