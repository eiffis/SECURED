/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #define KEY ((storage_t *)node->data)->key
    #define KEY_HEAD ((storage_t *)list->head->data)->key
    #define VALUE_HEAD ((storage_t *)list->head->data)->value

    #include "list.h"

typedef struct storage_s {
    int key;
    char *value;
} storage_t;

typedef struct hashtable_s {
    list_t *storage;
    int (*hash)(char *, int);
    int len;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

// Free
void free_list(list_t *list);
void free_struct(storage_t *storage);

// Create structure
storage_t *create_storage(int key, char *value);

#endif /* HASHTABLE_H */
