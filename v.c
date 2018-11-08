// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include "functions.h"

void v(PERSON **p_list, int n_notes) {
    int i;

    if (*p_list != NULL) {
        for (i = 0; i < n_notes; i++) {
            printf("meno priezvisko: %s\n"
                           "pohlavie: %c\n"
                           "rok narodenia: %s\n"
                           "SPZ: %s\n"
                           "typ priestupku: %d\n"
                           "vyska pokuty: %d\n"
                           "datum priestupku: %s\n\n", (*p_list)[i].name, (*p_list)[i].sex, (*p_list)[i].birth_year,
                   (*p_list)[i].SPZ, (*p_list)[i].type, (*p_list)[i].money, (*p_list)[i].date);
        }
    }
}