/*
** EPITECH PROJECT, 2024
** organized
** File description:
** cat_list
*/

#include "list.h"

void cat_list(list_t *l1, list_t *l2)
{
    if (l1->head == NULL && l2->head != NULL) {
        l1 = l2;
        l1->size = l2->size;
        return;
    }
    if (l1->head != NULL && l2->head == NULL) {
        return;
    }
    if (l1->head != NULL && l2->head != NULL) {
        l2->head->prev = l1->tail;
        l1->tail->next = l2->head;
        l1->tail = l2->tail;
        l1->size += l2->size;
        return;
    }
    return;
}
