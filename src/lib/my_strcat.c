/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Concatenates two strings
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    if (!dest){
        dest = my_strdup(src);
        return dest;
    }
    while (dest[i] != '\0')
        i++;
    for (int k = 0; src[k] != '\0'; k++) {
        dest[i] = src[k];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
