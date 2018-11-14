// Created by Susanka on 14. 11. 2018.

#include "functions.h"
#include <stdio.h>

void h(PERSON **p_list, int *n_note){
    char character;
    char abcd['Z'-'A'+1];
    int i, j;

    if(p_list == NULL){
        return;
    }

    for (i = 0; i < 'Z'-'A'+ 1; i++){
        abcd[i] = 0;
        //printf("%c: %d\n", 'A'+ i, abcd[i]);
    }

    for (i = 0; i < (*n_note); i++) {

        for (j = 0; j < 2; j++) {
            character = ((*p_list)[i].SPZ)[j];
            //printf("char: %c\n", character);
            abcd[character - 'A']++;
        }
    }

    for (i = 0; i < 'Z'-'A'+ 1; i++){
        if (abcd[i] != 0){
            printf("%c: %d\n", 'A'+ i, abcd[i]);
        }
    }
}

