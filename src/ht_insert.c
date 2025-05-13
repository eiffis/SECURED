/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht_insert
*/

#include "hashtable.h"
#include "my.h"

int search_key(hashtable_t *ht, char *key, int i, char *value)
{
    for (node_t *node = ht[i].storage->head; node != NULL; node = node->next) {
        if (((storage_t *)node->data)->key == ht->hash(key, ht->len)) {
            ((storage_t *)node->data)->value = my_strdup(value);
            return 1;
        }
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    if (key == NULL || value == NULL || ht == NULL)
        return 84;
    for (int i = 0; ht[i].storage != NULL; i++) {
        if (search_key(ht, key, i, value))
            return 0;
        if (ht->hash(key, ht->len) % ht->len == i)
            add_end(ht[i].storage,
            create_storage(ht->hash(key, ht->len), value));
    }
    return 0;
}
