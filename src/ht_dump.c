/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht_dump
*/

#include "hashtable.h"
#include "my.h"

void dump_list(list_t *list)
{
    for (node_t *node = list->tail; node != NULL; node = node->prev)
        my_printf("> %d - %s\n", KEY, ((storage_t *)node->data)->value);
}

void ht_dump(hashtable_t *ht)
{
    for (int i = 0; i < ht->len; i++) {
        my_printf("[%d]:\n", i);
        dump_list(ht[i].storage);
    }
}
