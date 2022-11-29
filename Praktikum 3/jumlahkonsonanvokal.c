# include "jumlahkonsonanvokal.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void jumlahKonsonanVokal(char* kalimat, int* konsonan, int* vokal){
    while (*kalimat != '\0'){
        if((*kalimat >= 'a' && *kalimat <= 'z') || (*kalimat >= 'A' && *kalimat <= 'Z')){
            if(*kalimat == 'a' || *kalimat == 'i' || *kalimat == 'u' || *kalimat == 'e' || *kalimat == 'o' || *kalimat == 'A' || *kalimat == 'I' || *kalimat == 'U' || *kalimat == 'E' || *kalimat == 'O'){
                (*vokal)++;
            } else {
                (*konsonan)++;
            }
        }
        *kalimat++;
    }
}