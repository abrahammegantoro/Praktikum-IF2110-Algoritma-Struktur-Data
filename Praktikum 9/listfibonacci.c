/*
NIM : 18221123
Nama : Abraham Megantoro Samudra
Tanggal : 7 November 2022
Topik : List Linier
Deskripsi
*/

#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);
    
    infotype num;

    // Masukkan kode program disini

    if (el == 0) {
        // Masukkan kode program disini
        printf("[]");
        return 0;
    } else if (el == 1) {
        // Masukkan kode program disini
		scanf("%d",&num);
		InsVFirst(&fibonacci, num);
        PrintInfo(fibonacci);
        // printf("\n");
        return 0;
    } else {
        // Masukkan kode program disini
        scanf("%d",&num);
		InsVLast(&fibonacci, num);
		scanf("%d",&num);
		InsVLast(&fibonacci, num);
        address P = First(fibonacci);
        address Q = Next(P);
        while (NbElmt(fibonacci) < el){
			num = Info(P) + Info(Q);
			InsVLast(&fibonacci, num);
			P = Q;
			Q = Next(Q);
			num = 0;
		}
        PrintInfo(fibonacci);
        // printf("\n");
    }

    return 0;
}
