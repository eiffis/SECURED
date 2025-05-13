/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht_search
*/

#include "hashtable.h"

char *ht_search_node(list_t *list, int hash)
{
    for (node_t *node = list->head; node != NULL; node = node->next) {
        if (hash == ((storage_t *)node->data)->key) {
            return ((storage_t *)node->data)->value;
        }
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL)
        return NULL;
    for (int i = 0; ht[i].storage != NULL; i++) {
        if (ht_search_node(ht[i].storage, ht->hash(key, ht->len)) != NULL)
            return ht_search_node(ht[i].storage, ht->hash(key, ht->len));
    }
    return NULL;
}
