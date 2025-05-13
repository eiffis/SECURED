/*
** EPITECH PROJECT, 2025
** secured
** File description:
** new_hashtable
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"

storage_t *create_storage(int key, char *value)
{
    storage_t *storage = malloc(sizeof(storage_t));

    storage->key = key;
    if (value == NULL)
        storage->value = NULL;
    else
        storage->value = strdup(value);
    return storage;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_htable = malloc(sizeof(hashtable_t) * (len + 1));

    if (new_htable == NULL || len <= 0)
        return NULL;
    for (int i = 0; i < len; i++)
        new_htable[i].storage = create_list();
    new_htable->len = len;
    new_htable->hash = hash;
    new_htable[len].storage = NULL;
    return new_htable;
}
