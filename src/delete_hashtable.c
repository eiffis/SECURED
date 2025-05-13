/*
** EPITECH PROJECT, 2025
** secured
** File description:
** delete_hashtable
*/

#include "hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    for (int i = 0; i < ht->len; i++) {
        if (ht[i].storage != NULL) {
            free_list(ht[i].storage);
            free(ht[i].storage);
        }
    }
    free(ht);
}
