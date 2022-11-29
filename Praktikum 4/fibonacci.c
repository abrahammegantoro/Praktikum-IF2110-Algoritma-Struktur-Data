#include<stdio.h>
#include<stdlib.h>
// Deret bilangan fibonacci adalah deret angka yang susunan angkanya
// merupakan penjumlahan dari dua angka sebelumnya.
// Contoh:
// Fib 0: 1
// Fib 1: 1
// Fib 2: 1 + 1 = 2
// Fib 3: 2 + 1 = 3
// Fib 4: 3 + 2 = 5
// Fib 5: 5 + 3 = 8

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result){
    long long int temp1,temp2,temp3,i;
    temp1 =1;
    temp2 = 1;
    if (n == 0 || n==1){
        *result = 1;
    } else {
        for(i = 2; i <= n; i++){
            temp3 = temp1+temp2;
            temp1 = temp2;
            temp2 = temp3;
        }
        *result = temp3;
    }
}
// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
    long long int temp1,temp2,temp3,i;
    temp1 =1;
    temp2 = 1;
    temp3 = 2;
    if (n == 0 || n==1){
        return 1;
    } else {
        for(i = 2; i <= n; i++){
            temp3 = temp1+temp2;
            temp1 = temp2;
            temp2 = temp3;
        }
        return temp3;
    }
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result){
    long long int temp1,temp2,temp3,i;
    temp1 = 1;
    temp2 = 1;
    if (n == 0){
        result[0] = 1;
    } else if (n == 1){
        result[0] = 1;
        result[1] = 1;    
    } else {
        result[0] = 1;
        result[1] = 1;
        for(i = 2; i <= n; i++){
            temp3 = temp1+temp2;
            temp1 = temp2;
            temp2 = temp3;
            result[i] = temp3;
        }
    }
}

