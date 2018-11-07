// Created by Susanka on 1. 11. 2018.

#ifndef PRPR1_ROZDELENE_FUNCTIONS_H                                                                                     //ak je definovaný, predefinuje sa
#define PRPR1_ROZDELENE_FUNCTIONS_H

#endif

#include <stdio.h>
#define MAX_STRING_LENGTH 50                                                                                            //nastavenie konštanty pre dĺžku mena = max 50 znakov

typedef struct {
    char name[51];                                                                                                      //pamäť sa alokuje pre 50 znakov + ukončujúci znak '\0'
    int sex;
    char birth_year[5];                                                                                                 //zle som si prečítala zadania a myslela som, že sa môže začínať 0. Preto som zvolila string
    char SPZ[8];
    int type;
    int money;
    char date[9];                                                                                                       //8 znakov + '\0'
} PERSON;

PERSON *o(PERSON *list, int *n_notes, FILE **fr);                                                                       //Hlavivčky funkcií, ktoré sú definované v .c súboroch
void v(PERSON **p_list, int n_notes);
void k(FILE **fr, PERSON **list);
void x(PERSON **p_list, int n_notes);
void r(PERSON **p_list, int n_notes);
void p(PERSON **p_list, int n_notes);
PERSON *a(PERSON **p_list, int *n_notes);