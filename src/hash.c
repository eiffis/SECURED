/*
** EPITECH PROJECT, 2025
** secured
** File description:
** hash
*/

#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <string.h>

char *copy_to_hash(char *hashed, char *valuetab)
{
    hashed = malloc(sizeof(char) * (my_strlen(valuetab) + 1));
    hashed = my_strcpy(hashed, valuetab);
    return hashed;
}

char *secure_valuetab(char *valuetab, int len)
{
    int special_value = 0;
    int joker;
    char *newnbr;

    joker = (my_strlen(valuetab) - len) * my_getnbr(valuetab);
    if (joker < 0)
        joker *= -1;
    for (size_t i = 0; valuetab[i] != '\0'; i++){
        if (valuetab[i] == '0'){
            special_value = (((my_strlen(valuetab) * len)) + ((joker - i)));
            newnbr = my_int_to_str(special_value);
            valuetab[i] = newnbr[0];
            free(newnbr);
        }
    }
    return valuetab;
}

char *set_valuetab(char *valuetab, char *key, int len)
{
    for (int i = 0; i < my_strlen(key); i++)
        valuetab = my_strcat(valuetab, my_int_to_str(key[i]));
    valuetab = secure_valuetab(valuetab, len);
    return valuetab;
}

char *value_pow(char *valuetab, int *value, size_t i, int len)
{
    if (i > 0){
        (*value) *= (*value);
        valuetab = my_strcpy(valuetab, my_int_to_str((*value)));
        if (my_strlen(valuetab) < 4){
            (*value) = my_getnbr(valuetab);
            (*value) *= (*value);
            valuetab = my_strcpy(valuetab, my_int_to_str((*value)));
        }
    }
    valuetab = secure_valuetab(valuetab, len);
    return valuetab;
}

int hash(char *key, int len)
{
    int value = 0;
    char *valuetab;
    int sizeval = 0;
    char *hashed;
    int start = 0;

    for (int i = 0; i < my_strlen(key); i++)
        sizeval += my_len_int(key[i]);
    valuetab = malloc(sizeof(char) * (sizeval + 1));
    valuetab[0] = '\0';
    valuetab = set_valuetab(valuetab, key, len);
    for (int i = 0; i < (my_strlen(key) + len); i++){
        valuetab = value_pow(valuetab, &value, i, len);
        hashed = copy_to_hash(hashed, valuetab);
        start = ((my_strlen(hashed) / 2) - 2);
        hashed[start + 6] = '\0';
        value = (my_getnbr(hashed + start) * ((key[0] / 10) + (key[len])));
    }
    return value;
}
