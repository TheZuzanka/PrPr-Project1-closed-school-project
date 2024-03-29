// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <string.h>
#include "functions.h"

void r(PERSON **p_list, int n_notes) {
    double total_money = 0.0;
    char a_date[9], a_month[7], l_month[7];                                                                             //musím mať rovnaký rok aj mesiac = prvých 6 znakov
    int i, j;

    if(*p_list == NULL){                                                                                                //pri nenačítanom zozname sa načíta dátum ale nič sa nevykoná
        scanf("%s", a_date);
        return;
    }
    else {
        scanf("%s", a_date);
        for (i = 0; i < 6; i++) {
            a_month[i] = a_date[i];                                                                                     //prvých šesť znakov sa prekopíruje z načítaného do stringu = rok a mesiac
        }
        a_month[6] = '\0';                                                                                              //pridá sa ukončovací znak

        for (j = 0; j < n_notes; j++) {
            for (i = 0; i < 6; i++) {
                l_month[i] = ((*p_list)[j].date)[i];                                                                    //prvých šesť znakov sa prekopíruje zo štruktúry do stringu = rok a mesiac
            }
            l_month[6] = '\0';

            if (strcmp(a_month, l_month) == 0) {
                (*p_list)[j].type == 0 ? (total_money += ((*p_list)[j].money * 0.038)) : (total_money += (              //ak sa mesiac + rok rovnajú, podľa typu ppriestupku sa výška priestupku vynásobí príslušnou konštantou
                        (*p_list)[j].money * 0.052));                                                                   //a pripočíta sa do odmeny pre policajta
            }
        }
        printf("%.2lf\n", total_money);
    }
    getchar();
}