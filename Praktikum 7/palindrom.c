# include "stack.h"
# include <stdio.h>

int main(){
    Stack S1, temp;
    Stack S2;
    infotype X;
    CreateEmpty(&S1);
    CreateEmpty(&temp);
    CreateEmpty(&S2);
    
    scanf("%d",&X);
    Push(&S1,X);
    Push(&temp,X);

    while (X != 0){
        scanf("%d",&X);
        Push(&S1,X);
        Push(&temp,X);
    }

    Pop(&S1, &X);
    Pop(&temp, &X);
    
    while (!IsEmpty(temp)){
        Pop(&temp,&X);
        Push(&S2,X);
    }
   
    // while(!IsEmpty(S1)){
    //    Pop(&S1,&X);
    //    printf("%d ",X);
    // } // bener susunannya 1 2 3 4, kalau di print jadi terbalik
    // printf("\n");

    // while (!IsEmpty(S2)){
    //     Pop(&S2,&X);
    //     printf("%d ",X);
    // }

    if(IsEmpty(S1)){
        printf("Stack kosong\n");
    } else {
        boolean found = false;
        while (!IsEmpty(S1) && !found){
            if (InfoTop(S1) != InfoTop(S2)){
                found = true;
            }
            Pop(&S1,&X);
            Pop(&S2,&X);
        }
        
        if (found){
            printf("Bukan Palindrom\n");
        } else {
            printf("Palindrom\n");
        }
    }

    return 0;
}
