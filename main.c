#include <stdio.h>
#include "functions.h"

int main() {
    PERSON *list = NULL, *new_list;                                                                                     //prvy prvok nastavím explicinte na NULL. Ak nebude alokované pole, ostane NULL
    PERSON **p_list = &list;                                                                                             //keď si "pridám" do poľa, vytvorím nové a potrebujem potom vypisovať nové pole
    FILE *fr = NULL;
    int num_notes = 0;
    int function;
    int position, value = 0;


    while ((function = getchar())) {                                                                                    //nekonečný cyklus, ukončuje sa vo funkcii k
        getchar();                                                                                                      //prečíta '\n'
        switch (function) {
            case 'o':
                list = o(list, &num_notes, &fr);
                if (list == NULL) {                                                                                     //malloc mi vracia NULL ak sa pamäť nealokuje alebo NULL z explicitnej definície, ak sa funkcia o vôbec nespustí
                    printf("Pole nie je naplnené.\n");
                }
                p_list = &list;                                                                                         //keď budem chcieť vypísať pole, budem vypisovať
                break;

            case 'v':
                v(p_list, num_notes);                                                                                   //ak num_notes nie je inicializované, nevadí to, lebo ako prvé sa vykoná porovnanie p_list na nulu, ak je p_list 0, tým pádom num_notes nie je inicializované ale funkcia sa skončí predtým ako by sa s neinicializovanou premennou malo niečo robiť
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
            case 'd':
                scanf("%d", &position);
                getchar();
                del(p_list, &num_notes, position);
                break;
            case 'c':
                scanf("%d", &value);
                getchar();
                ces(p_list, num_notes, value);
                break;
            default:
            case 'b':
                scanf("%d", &value);
                getchar();
                decode(p_list, num_notes, value);
                break;
        }
    }


    return 0;
}
