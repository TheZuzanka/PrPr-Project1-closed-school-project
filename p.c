// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include "functions.h"

void p(PERSON **p_list, int n_notes) {
    int i, j;

    if (*(p_list) != NULL) {                                                                                            //pri nenačítanom zozname sa nevykoná nič
        for (i = 0; i < n_notes; i++) {                                                                                 //robím pre počet záznamov
            for (j = 0; j < 3; j++) {                                                                                   //porovnávam znaky nultý, posledný, prvý, druhý od konca. Prostredný nemusím = vždy je rovnaký z oboch strán.
                if (((*p_list)[i].SPZ)[j] != ((*p_list)[i].SPZ)[6 - j]) {                                               //ak sa znaky nezhodujú, vylúčim palindróm
                    break;
                }
                if (j == 2) {                                                                                           //ak sa cyklus dostane do bodu j==2, porovnala som všetky znaky a sú rovnaké lebo cyklus sa neprerušil = palindróm
                    printf("%s %s\n", (*p_list)[i].name, (*p_list)[i].SPZ);
                }
            }
        }
    }
}