#include "panjangstring.h"
#include <stdio.h>

int panjangString(char*pt){
    int count = 0;
    while (*pt != '\0'){
        count++;
        pt++;
    }
    return count;
}