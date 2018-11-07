// Created by Susanka on 1. 11. 2018.

#ifndef PRPR1_ROZDELENE_FUNCTIONS_H
#define PRPR1_ROZDELENE_FUNCTIONS_H

#endif

#include <stdio.h>
#define MAX_STRING_LENGTH 50

typedef struct {
    char name[51];
    int sex;
    char birth_year[5];                                                                                                 //ak by som začínala nulou,robilo by to šarapatu, v stringu, to čo napíšem, to mám + je statický jeeej
    char SPZ[8];
    int type;
    int money;
    char date[9];                                                                                                       //8 znakov + '\0'
} PERSON;

PERSON *o(PERSON *list, int *n_notes, FILE **fr);                                                                       //Použité funkcie
void v(PERSON **p_list, int n_notes);
void k(FILE **fr, PERSON **list);
void x(PERSON **p_list, int n_notes);
void r(PERSON **p_list, int n_notes);
void p(PERSON **p_list, int n_notes);
PERSON *a(PERSON **p_list, int *n_notes);