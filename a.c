// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

PERSON *a(PERSON **p_list, int *n_notes) {
    int i, left = *n_notes;
    char string_n[100];
    int aktual = 0, insert_pos = 0, inserted = 0;                                                                       //inserted = či už bolo vložené, aktual = pozícia v pôvodnom poli, insert_pos = pozícia v novom poli

    char name_n[51];
    int sex_n;
    char birth_year_n[5];
    char SPZ_n[8];
    int type_n;
    int money_n;
    char date_n[9];
    PERSON *new_list = (PERSON *) malloc((*n_notes + 1) * sizeof(PERSON));
    (*n_notes)++;

    fgets(string_n, 499, stdin);                                                                                        //do pomocnej premennej načítam celé meno
    if (strlen(string_n) <= MAX_STRING_LENGTH) {                                                                        //ak sa mi meno zmestí do štruktúry
        string_n[strlen(string_n) - 1] = '\0';                                                                          //odrežem \n na konci
    } else {
        string_n[MAX_STRING_LENGTH] = '\0';                                                                             //ak sa nezmestí, odrežem všetko, čo je dlhšie ako 50 znakov (51 = '\n')
    }
    strcpy(name_n, string_n);
    sex_n = getchar();
    scanf("%s", birth_year_n);
    scanf("%s", SPZ_n);
    scanf("%d", &type_n);
    scanf("%d", &money_n);
    scanf("%s", date_n);
    getchar();

    while (insert_pos <= left) {
        if ((!inserted && insert_pos == left) || (!inserted && strcmp(name_n, (*p_list)[aktual].name) <=0)) {           //som na poslednom prvku a ešte som pridávaný prvok nevložila alebo som ešte prvok ešte nevložila a abecedne môžemm
            strcpy(new_list[insert_pos].name, name_n);
            new_list[insert_pos].sex = sex_n;
            strcpy(new_list[insert_pos].birth_year, birth_year_n);
            strcpy(new_list[insert_pos].SPZ, SPZ_n);
            new_list[insert_pos].type = type_n;
            new_list[insert_pos].money = money_n;
            strcpy(new_list[insert_pos].date, date_n);
            insert_pos++;
            inserted = 1;
        } else if (!inserted && strcmp(name_n, (*p_list)[aktual].name) == 0) {                                          //ak vkladané údaje majú rovnaké meno ako nejaké mmeno, ktoré už v poli je, hodím to pred to, ak by sme chceli, môžme za to
            strcpy(new_list[insert_pos].name, name_n);
            new_list[insert_pos].sex = sex_n;
            strcpy(new_list[insert_pos].birth_year, birth_year_n);
            strcpy(new_list[insert_pos].SPZ, SPZ_n);
            new_list[insert_pos].type = type_n;
            new_list[insert_pos].money = money_n;
            strcpy(new_list[insert_pos].date, date_n);
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

    free(*p_list);

    return new_list;
}