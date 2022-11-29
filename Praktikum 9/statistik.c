# include "listlinier.h"
# include <stdio.h>

int main(){
    List L;
    CreateEmpty(&L);

    infotype X;
    scanf("%d", &X);
    while (X >= 0 && X <= 100){
        InsVFirst(&L, X);
        scanf("%d", &X);
    }

    if (!IsEmpty(L)){
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));
        InversList(&L);
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    } else {
        printf("Daftar nilai kosong\n");
    }
    return 0;
}