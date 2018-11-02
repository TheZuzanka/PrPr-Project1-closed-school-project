#include <stdio.h>
#include "functions.h"

int main() {
    PERSON *list = NULL, *new_list;                                                                                     //prvy prvok nastavím explicinte na NULL. Ak nebude alokované pole, ostane NULL
    PERSON **p_list = NULL;                                                                                             //keď si "pridám" do poˇôa, vytvorím nové a potrebujem ppotom vypisovať nové pole
    FILE *fr = NULL;
    int num_notes;
    int function;


    while ((function = getchar())) {                                                                                    //nekonečný cyklus, ukončuje sa vo funkcii k
        getchar();
        switch (function) {
            case 'o':
                list = o(list, &num_notes, &fr);
                if (list ==
                    NULL) {                                                                                             //malloc mi vracia NULL ak sa pamäť nealokuje alebo NULL z explicitnej definície, ak sa funkcia o vôbec nespustí
                    printf("Pole nie je naplnené.\n");
                }
                p_list = &list;
                break;

            case 'v':
                v(p_list,
                  num_notes);                                                                                           //ak num_notes nie je inicializované, nevadí to, lebo ako prvé sa vykoná porovnanie p_list na nulu, ak je p_list 0,, num_notes nie je inicializované a funkcia skončí
                break;
            case 'k':
                k(&fr, &list);
                break;
            case 'x':
                x(p_list, num_notes);
                break;
            case 'r':
                r(p_list, num_notes);
                break;
            case 'p':
                p(p_list, num_notes);
                break;
            case 'a':
                new_list = a(p_list, &num_notes);
                p_list = &new_list;
                break;
            default:
                break;
        }
    }


    return 0;
}
