/*
** EPITECH PROJECT, 2025
** secured
** File description:
** free_all
*/

#include "hashtable.h"

void free_struct(storage_t *storage)
{
    free(storage->value);
    free(storage);
}

void free_list(list_t *list)
{
    node_t *tmp = NULL;

    for (node_t *node = list->head; node != NULL; node = tmp) {
        tmp = node->next;
        free_struct((storage_t *)node->data);
        free(node);
    }
}
