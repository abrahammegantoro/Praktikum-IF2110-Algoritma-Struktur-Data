// NIM : 18221123
// Nama : Abraham Megantoro Samudra
// Tanggal : 12 September 2022
// Topik praktikum : Praktikum 2
// Deskripsi : Menjumlahkan semua digit bilangan
# include <stdio.h>

int jumlah(int a) {
    if (a<10) {
        return a;
    } else {
        return jumlah(a/10) + (a%10);
    }
}

int main() {
    int x;
    scanf("%d",&x);
    printf("%d\n",jumlah(x));
    return 0;
}