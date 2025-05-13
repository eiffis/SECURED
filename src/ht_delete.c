/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht_delete
*/

#include "hashtable.h"
#include "my.h"

int ht_delete_node(list_t *list, int hash)
{
    node_t *tmp = NULL;

    for (node_t *node = list->head; node != NULL; node = tmp) {
        tmp = node->next;
        if (hash == ((storage_t *)node->data)->key) {
            del_node(list, node);
            free_struct((storage_t *)node->data);
            free(node);
            return 1;
        }
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL || my_strlen(key) == 0)
        return 84;
    for (int i = 0; ht[i].storage != NULL; i++)
        if (ht_delete_node(ht[i].storage, ht->hash(key, ht->len)))
            return 0;
    return 84;
}
