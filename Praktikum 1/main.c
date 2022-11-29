// NIM : 18221123
// Nama : Abraham Megantoro Samudra
// Tanggal : 2 September 2022
// Topik praktikum : penjumlahan 2 buah integer
// Deskripsi : Menjumlahkan 2 buah integer yang dimasukkan
#include <stdio.h>
int main() {
    int detik;
    scanf("%d", &detik);

    int jam, menit, sisa;
    jam = detik/3600;
    menit = (detik - (jam * 3600)) / 60;
    sisa = (detik - (jam * 3600) - (menit * 60));
    printf("%d detik = %d jam %d menit %d detik\n", detik, jam, menit, sisa);
    return 0;
}