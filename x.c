// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <string.h>
#include "functions.h"

void x(PERSON **p_list, int n_notes) {
    char a_year[9], l_year[9];                                                                                          //8 čísel + '\0'
    int i, j;

    if (*p_list == NULL) {                                                                                              //pri nenačítanom zozname sa načíta dátum ale nič sa nevykoná
        fgets(a_year, 9, stdin);
    }
    else {
        fgets(a_year, 9, stdin);
        a_year[4] = '\0';                                                                                               //načíta sa aktuálny dátum a odreže sa z neho iba rok

        for (j = 0; j < n_notes; j++) {
            for (i = 0; i <= 3; i++) {
                l_year[i] = ((*p_list)[j].date)[i];                                                                     //zo štruktúry sa vezme dátum priestupku, prvé štyri znaky (rok) sa prekopírujú
            }
            l_year[4] = '\0';                                                                                           //pridá sa ukončovací znak

            if ((strcmp(a_year, l_year) == 0) && ((*p_list)[j].type == 0)) {                                            //ak sa roky zhodujú a typ priestupku je 0 = odňatie preukazu, vypíše sa
                printf("meno priezvisko: %s\n"
                       "SPZ: %s\n"
                       "datum priestupku: %s\n\n", (*p_list)[j].name, (*p_list)[j].SPZ, (*p_list)[j].date);
            }
        }
    }
    getchar();                                                                                                          //keď sa vrátim do main, aby mi to vzalo ďalší príkaz
}