// Created by Susanka on 14. 11. 2018.

#include "functions.h"
#include <string.h>
#include <stdlib.h>

void n(PERSON **p_list, int *n_note){
    int i,j, deleted = 0;

    if(*p_list == NULL){
        return;
    }

    int money;
    char z_SPZ[8], n1_SPZ[3], n2_SPZ[3];

    scanf("%d", &money);
    scanf("%s", z_SPZ);
    getchar();

    for (i = 0; i < 2; i++){
        n1_SPZ[i] = z_SPZ[i];
    }
    n1_SPZ[2] = '\0';
    if (strcmp(n1_SPZ, "BL") == 0){
        n1_SPZ[1] = 'A';
    }


    for (i = 0; i < (*n_note); i++){

        for (j = 0; j < 2; j++){
            n2_SPZ[j] = ((*p_list)[i].SPZ)[j];
        }
        n2_SPZ[2] = '\0';

        if (strcmp(n2_SPZ, "BL") == 0){
            n2_SPZ[1] = 'A';
        }
        //printf("%d %s\n", i, n2_SPZ);

        if ( strcmp(n1_SPZ, n2_SPZ) == 0  &&  (*p_list)[i].money < money ) {
            deleted++;
        }
            strcpy((*p_list)[i].name, (*p_list)[i+deleted].name);
            (*p_list)[i].sex = (*p_list)[i+deleted].sex;
            strcpy((*p_list)[i].birth_year, (*p_list)[i+deleted].birth_year);
            strcpy((*p_list)[i].SPZ, (*p_list)[i+deleted].SPZ);
            (*p_list)[i].type = (*p_list)[i+deleted].type;
            (*p_list)[i].money = (*p_list)[i+deleted].money;
            strcpy((*p_list)[i].date, (*p_list)[i+deleted].date);

        if (i == *n_note - deleted){
            break;
        }
    }

    if (deleted != 0){
        *n_note = *n_note - deleted;
        realloc(p_list, (size_t)(*n_note));
    }
    else{
        printf("Zaznamy neboli zistene\n");
    }
}

