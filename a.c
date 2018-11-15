// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

PERSON *a(PERSON **p_list, int *n_notes) {
    int left = *n_notes;
    char new_name[100];
    int aktual = 0, insert_pos = 0, inserted = 0;                                                                       //inserted = či už bolo vložené, aktual = pozícia v pôvodnom poli, insert_pos = pozícia v novom poli

    char new_name_max50_signs[51];
    int new_sex;
    char new_birth_year[5];
    char new_SPZ[8];
    int new_type;
    int new_money;
    char new_date[9];
    PERSON *new_list = (PERSON *) malloc((*n_notes + 1) * sizeof(PERSON));
    (*n_notes)++;

    fgets(new_name, 499, stdin);                                                                                        //do pomocnej premennej načítam celé meno
    if (strlen(new_name) <= MAX_STRING_LENGTH) {                                                                        //ak sa mi meno zmestí do štruktúry
        new_name[strlen(new_name) - 1] = '\0';                                                                          //odrežem \n na konci
    }
    else {
        new_name[MAX_STRING_LENGTH] = '\0';                                                                             //ak sa nezmestí, odrežem všetko, čo je dlhšie ako 50 znakov (51 = '\n')
    }
    strcpy(new_name_max50_signs, new_name);
    
    new_sex = getchar();
    scanf("%s", new_birth_year);
    scanf("%s", new_SPZ);
    scanf("%d", &new_type);
    scanf("%d", &new_money);
    scanf("%s", new_date);
    getchar();

    while (insert_pos <= left) {
        if ((!inserted && insert_pos == left) || (!inserted && strcmp(new_name_max50_signs, (*p_list)[aktual].name) <=0)) {   //som na poslednom prvku a ešte som pridávaný prvok nevložila, alebo som prvok ešte nevložila a abecedne môžem
            strcpy(new_list[insert_pos].name, new_name_max50_signs);
            new_list[insert_pos].sex = new_sex;
            strcpy(new_list[insert_pos].birth_year, new_birth_year);
            strcpy(new_list[insert_pos].SPZ, new_SPZ);
            new_list[insert_pos].type = new_type;
            new_list[insert_pos].money = new_money;
            strcpy(new_list[insert_pos].date, new_date);
            insert_pos++;
            inserted = 1;
        } else if (!inserted && strcmp(new_name_max50_signs, (*p_list)[aktual].name) == 0) {                            //ak vkladané údaje majú rovnaké meno ako nejaké meno, ktoré už v poli je, napíšem vkladaný záznam záznam pred existujúci záznam s rovnakým menom
            strcpy(new_list[insert_pos].name, new_name_max50_signs);
            new_list[insert_pos].sex = new_sex;
            strcpy(new_list[insert_pos].birth_year, new_birth_year);
            strcpy(new_list[insert_pos].SPZ, new_SPZ);
            new_list[insert_pos].type = new_type;
            new_list[insert_pos].money = new_money;
            strcpy(new_list[insert_pos].date, new_date);
            insert_pos++;
            inserted = 1;
        } else {                                                                                                        //v ostatných prípadoch iba kopírujem zo starého do nového poľa
            strcpy(new_list[insert_pos].name, (*p_list)[aktual].name);
            new_list[insert_pos].sex = (*p_list)[aktual].sex;
            strcpy(new_list[insert_pos].birth_year, (*p_list)[aktual].birth_year);
            strcpy(new_list[insert_pos].SPZ, (*p_list)[aktual].SPZ);
            new_list[insert_pos].type = (*p_list)[aktual].type;
            new_list[insert_pos].money = (*p_list)[aktual].money;
            strcpy(new_list[insert_pos].date, (*p_list)[aktual].date);
            aktual++;
            insert_pos++;
        }
    }

    if(p_list != NULL){                                                                                                 //pokiaľ už mám vytvorené pôvodné pole, uvoľní sa
        free(*p_list);                                                                                                  //ak funkcia o neprebehla a pole sa nenačítalo, nemusím uvoľňovať, lebo som nič nealokovala
    }

    return new_list;
}