// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void k(FILE **fr, PERSON **p_list) {
    if (fclose(*fr) == EOF) {                                                                                           //zavriem súbor
        exit(-1);
    }

    if(p_list != NULL){                                                                                                 //pokiaľ už mám vytvorené pôvodné pole, uvoľní sa
        free(*p_list);                                                                                                  //ak funkcia o neprebehla a pole sa nenačítalo, nemusím uvoľňovať, lebo som nič nealokovala
    }
    exit(0);
}