// Created by Susanka on 14. 11. 2018.

#include "functions.h"
#include <string.h>
#include <stdlib.h>

void del(PERSON **p_list, int *n_note, int position){
    int i;

    if(*p_list == NULL){
        return;
    }
    for (i = 0; i < (*n_note)-1; i++){
        if (i >= position){
            strcpy((*p_list)[i].name, (*p_list)[i+1].name);
            (*p_list)[i].sex = (*p_list)[i+1].sex;
            strcpy((*p_list)[i].birth_year, (*p_list)[i+1].birth_year);
            strcpy((*p_list)[i].SPZ, (*p_list)[i+1].SPZ);
            (*p_list)[i].type = (*p_list)[i+1].type;
            (*p_list)[i].money = (*p_list)[i+1].money;
            strcpy((*p_list)[i].date, (*p_list)[i+1].date);
        }
    }

    (*n_note)--;
    realloc(p_list, (size_t)(*n_note));
}

