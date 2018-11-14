// Created by Susanka on 14. 11. 2018.

#include "functions.h"
#include <string.h>

void decode(PERSON **p_list, int n_notes, int value){
    int i, j, character;

    if (p_list == NULL){                                                                                                //ak list nebol naplnený, nič sa nestane
        return;
    }

    for (i = 0; i < n_notes; i++){
        for (j = 0; j < strlen((*p_list)[i].name); j++){
            character = ((*p_list)[i].name)[j];
            if (character >= 'a' && character <= 'z'){
                if (character - value < 'a'){
                    ((*p_list)[i].name)[j] = (char)(character + ('z' - 'a' + 1) - value);
                }
                else{
                    ((*p_list)[i].name)[j] = (char)(character -  value);
                }
            }
            else if(character >= 'A' && character <= 'Z'){
                if (character - value < 'A'){
                    ((*p_list)[i].name)[j] = (char)(character + ('Z' - 'A' + 1) - value);
                }
                else{
                    ((*p_list)[i].name)[j] = (char)(character -  value);
                }
            }
        }
    }
}