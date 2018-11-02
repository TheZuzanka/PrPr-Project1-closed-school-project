// Created by Susanka on 1. 11. 2018.

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void k(FILE **fr, PERSON **list) {
    if (fclose(*fr) == EOF) {
        exit(-1);
    }

    free(*list);
    exit(0);
}