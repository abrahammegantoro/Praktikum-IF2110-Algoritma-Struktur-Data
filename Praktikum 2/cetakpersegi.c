// NIM : 18221123
// Nama : Abraham Megantoro Samudra
// Tanggal : 12 September 2022
// Topik praktikum : Praktikum 2
// Deskripsi : Mencetak persegi berpola OX
# include <stdio.h>

int main() {
    int a, sisi,i, j;
    scanf("%d", &a);
    sisi = 2*a-1;
    for (i=0; i<sisi; i++) {
        if (i%2 ==0) {
            for (j=0; j<sisi; j++) {
                if(j%2 ==0) {
                    printf("O");
                } else {
                    printf("X");
                }
            }
        } else {
            for (j=0; j<sisi; j++) {
                if(j%2 ==0) {
                    printf("X");
                } else {
                    printf("O");
                }
            }
        }
        printf("\n");
    }
    return 0;
}