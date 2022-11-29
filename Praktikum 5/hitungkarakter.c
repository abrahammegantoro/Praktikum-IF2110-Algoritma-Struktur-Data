# include "mesinkarakter.h"
# include <stdio.h>

int hitungkarakter(char karakter){
    int jumlah = 0;
    START();
    while(!IsEOP()){
        if(GetCC() == karakter){
            jumlah++;
        }
        ADV();
    }
    return jumlah;
}