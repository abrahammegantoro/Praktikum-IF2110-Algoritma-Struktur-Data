# include "boolean.h"
# include "mesinkarakterv2.h"
# include "mesinkata.h"
# include <stdio.h>

int main(){
    STARTWORD();
    int jumlahShift = currentWord.Length % 26;
    int i;
    while (!isEndWord()){
        for (i = 0; i < currentWord.Length; i++){
            currentWord.TabWord[i] += jumlahShift;

            if (currentWord.TabWord[i] > 90){
                currentWord.TabWord[i] -= 26;
            }
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        if (!isEndWord()){
            printf(" ");
        }
    }
    printf(".\n");
    return 0;
}