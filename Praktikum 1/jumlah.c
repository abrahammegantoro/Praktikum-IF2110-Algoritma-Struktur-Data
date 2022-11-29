// NIM : 18221123
// Nama : Abraham Megantoro Samudra
// Tanggal : 2 September 2022
// Topik praktikum : penjumlahan 2 buah integer
// Deskripsi : Menjumlahkan 2 buah integer yang dimasukkan

#include <stdio.h>

long long jumlah(long long a, long long b) {
    return(a+b);
}

int main() {
    long long x,y;
    scanf("%lld %lld", &x, &y);

    printf("%lld\n",jumlah(x,y));
    return 0;
}
