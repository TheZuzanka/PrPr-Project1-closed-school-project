// Created by Susanka on 1. 11. 2018.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

PERSON *o(PERSON *list, int *n_notes, FILE **fr) {
    int number, i;
    char string[500];

    if (list != NULL) {                                                                                                 //v main som nastavila list na NULL, ak nie je NULL, ostala hodnota z predtým
        free(list);                                                                                                     //dealokujem celé pole. Nie po prvkoch, dávam to isté, čo do malloc.
    }

    number = 1;
    *n_notes = 0;                                                                                                       //po dealokoácii nastavím hodnoty na počiatočné

    if ((*fr = fopen("priestupky.txt", "r")) == NULL) {
        exit(-1);
    }

    while (fgets(string, 500, *fr) != NULL) {                                                                           //spočítam si riadky súboru
        number++;
    }

    *n_notes = number / 8;                                                                                              //počet záznamov = počet riadkov / 8 pretože 1 záznam má 7 kategórií a jeden nový riadok za tým
    list = (PERSON *) malloc(number * sizeof(PERSON));                                                                  //alokujem pamäť pre dynamické pole štruktúr pre počet záznamov
    rewind(*fr);                                                                                                        //vrátim sa na začiatotk súboru, aby som z neho mohla čítať hodnoty konkrétnych záznammov

    for (i = 0; i < number; i++) {                                                                                      //potrebujem urobiť pre všetky riadky súboru
        if (i % 8 == 0) {
            fgets(string, 499, *fr);                                                                                    //do pomocnej premennej načítam celé meno
            if (strlen(string) <= MAX_STRING_LENGTH) {                                                                  //ak sa mi meno zmestí do štruktúry
                string[strlen(string) - 1] = '\0';                                                                      //odrežem \n na konci, ktoré sa tiež načítalo
            } else {
                string[MAX_STRING_LENGTH] = '\0';                                                                       //ak sa nezmestí, odrežem všetko, čo je dlhšie ako 50 znakov, na 51 pozíciu pridám ukončovací znak
            }
            strcpy(list[i / 8].name,
                   string);                                                                                             //meno, ktoré spĺňa max. veľkosť 50 znakov sa zapíšem do štruktúry
        } else if (i % 8 == 1) {
            (list[i / 8]).sex = fgetc(*fr);
        } else if (i % 8 == 2) {
            fscanf(*fr, "%s", (list[i / 8]).birth_year);                                                                //môžem dať fscanf() pretože mám statický string bez medzier, vždy 8 znakov + '\n'
            fgetc(*fr);
        } else if (i % 8 == 3) {
            fscanf(*fr, "%s", (list[i / 8]).SPZ);
        } else if (i % 8 == 4) {
            fscanf(*fr, "%d", &(list[i / 8]).type);
        } else if (i % 8 == 5) {
            fscanf(*fr, "%d", &(list[i / 8]).money);
        } else if (i % 8 == 6) {
            fscanf(*fr, "%s", (list[i / 8]).date);
            fgetc(*fr);
        } else if (i % 8 == 7) {                                                                                        //ak sa jedná o rozdeľovací prázdny riadok, načítam ho do pomocnej premennej ale keďže s ním nić nnnerobím, zahodím ho
            fgets(string, 50, *fr);
        }
    }

    return list;
}