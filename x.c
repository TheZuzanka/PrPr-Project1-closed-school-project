// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <string.h>
#include "functions.h"

void x(PERSON **p_list, int n_notes) {
    char a_year[5], l_year[5];                                                                                          //8 čísel + '\0'
    int i, j;

    if (*p_list == NULL) {                                                                                              //pri nenačítanom zozname sa nevykoná nič
        ;
    } else {
        fgets(a_year, 5, stdin);

        for (j = 0; j < n_notes; j++) {
            for (i = 0; i <= 3; i++) {
                l_year[i] = ((*p_list)[j].date)[i];
            }
            l_year[4] = '\0';

            if ((strcmp(a_year, l_year) == 0) && ((*p_list)[j].type == 0)) {
                printf("Meno a priezvisko: %s\n"
                       "SPZ: %s\n"
                       "Datum priestupku: %s\n\n", (*p_list)[j].name, (*p_list)[j].SPZ, (*p_list)[j].date);
            }                                                                                                           //vypíše sa len, keď sedí dátum a typ je 1 = odňatie
        }
    }
    getchar();                                                                                                          //keď sa vrátim do main, aby mi to vzalo ďalší príkaz
}