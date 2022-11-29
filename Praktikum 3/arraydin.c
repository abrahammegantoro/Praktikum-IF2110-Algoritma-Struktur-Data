# include "arraydin.h"
# include <stdio.h>
# include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin array;
    array.A = (ElType*)malloc(InitialSize * sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free((*array).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    if ((*array).Neff == (*array).Capacity){
        (*array).A = (ElType*)realloc((*array).A, 2 * (*array).Capacity * sizeof(ElType));
        (*array).Capacity *= 2;
    }
    for (int j = (*array).Neff; j > i; j--){
        (*array).A[j] = (*array).A[j-1];
    }
    (*array).A[i] = el;
    (*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el){
    if ((*array).Neff == (*array).Capacity){
        (*array).A = (ElType*)realloc((*array).A, 2 * (*array).Capacity * sizeof(ElType));
        (*array).Capacity *= 2;
    }
    (*array).A[(*array).Neff] = el;
    (*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
    if ((*array).Neff == (*array).Capacity){
        (*array).A = (ElType*)realloc((*array).A, 2 * (*array).Capacity * sizeof(ElType));
        (*array).Capacity *= 2;
    }
    for (int j = (*array).Neff; j > 0; j--){
        (*array).A[j] = (*array).A[j-1];
    }
    (*array).A[0] = el;
    (*array).Neff++;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    int j;
    for(j=i;j<Length(*array)-1;j++){
        (*array).A[j] = (*array).A[j+1];
    }
    (*array).Neff -= 1;
    if (Length(*array)<=GetCapacity(*array)/4){
        int caps;
        if (InitialSize < GetCapacity(*array)/2){
            caps = GetCapacity(*array)/2;
        } else {
            caps = InitialSize;
        }
        (*array).A = (ElType*)realloc((*array).A, caps*sizeof(ElType));
        (*array).Capacity = caps;
    }
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array){
    (*array).Neff -= 1;
    if (Length(*array)<=GetCapacity(*array)/4){
        int caps;
        if (InitialSize < GetCapacity(*array)/2){
            caps = GetCapacity(*array)/2;
        } else {
            caps = InitialSize;
        }
        (*array).A = (ElType*)realloc((*array).A, caps*sizeof(ElType));
        (*array).Capacity = caps;
    }
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    int j;
    for(j=0;j<Length(*array)-1;j++){
        (*array).A[j] = (*array).A[j+1];
    }
    (*array).Neff -= 1;
    if (Length(*array)<=GetCapacity(*array)/4){
        int caps;
        if (InitialSize < GetCapacity(*array)/2){
            caps = GetCapacity(*array)/2;
        } else {
            caps = InitialSize;
        }
        (*array).A = (ElType*)realloc((*array).A, caps*sizeof(ElType));
        (*array).Capacity = caps;
    }
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
    printf("[");
    for (int i = 0; i < Length(array); i++){
        printf("%d", Get(array, i));
        if (i != Length(array) - 1){
            printf(", ");
        }
    }
    printf("]\n");
}
/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
    int i = 0;
    int j = Length(*array) - 1;
    while (i < j){
        ElType temp = Get(*array, i);
        (*array).A[i] = (*array).A[j];
        (*array).A[j] = temp;
        i++;
        j--;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
    ArrayDin copy = MakeArrayDin();
    for (int i = 0; i < Length(array); i++){
        InsertLast(&copy, Get(array, i));
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
    for (int i = 0; i < Length(array); i++){
        if (Get(array, i) == el){
            return i;
        }
    }
    return -1;
}
