// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include "functions.h"

void p(PERSON **p_list, int n_notes) {
    int i, j;

    if (*(p_list) != NULL) {                                                                                            //pri nenačítanom zozname sa nevykoná nič
        for (i = 0; i < n_notes; i++) {
            for (j = 0; j < 3; j++) {
                if (((*p_list)[i].SPZ)[j] != ((*p_list)[i].SPZ)[6 - j]) {
                    continue;
                }
                if (j == 2) {
                    printf("%s %s\n", (*p_list)[i].name, (*p_list)[i].SPZ);
                }
            }
        }
    }
}