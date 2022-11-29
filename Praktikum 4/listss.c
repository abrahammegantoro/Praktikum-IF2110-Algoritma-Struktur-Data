/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
# include "list.h"
# include "boolean.h"
# include <stdio.h>
# include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
    List L;
    int i = 0;
    for(i=0;i<MaxEl;i++){
        L.A[i] = Mark;
    }
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    return (L.A[0] == Mark);
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
    return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
    L->A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    if (IsEmpty(L)){
        return 0;
    }
    else{
        int i = 0;
        while (Get(L, i) != Mark){
            i++;
        }
        return i;
    }
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return 0;
}

IdxType LastIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return Length(L)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
    return ((i >= FirstIdx(L)) && (i < MaxEl));
}
boolean IsIdxEff (List L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    return ((i >= FirstIdx(L)) && (i <= LastIdx(L)));
}
/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    int i = FirstIdx(L);
    boolean found = false;
    while (!found && i <= LastIdx(L))
    {
        if (Get(L, i) == X)
        {
            found = true;
        }
        i++;
    }
    return found;
}


void InsertFirst(List *L, ElType X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
    if (IsEmpty(*L)){
        Set(L, 0, X);
    }
    else{
        int i = LastIdx(*L);
        // Geser Elemen ke Kanan
        for (i; i >= FirstIdx(*L); i--)
        {
            Set(L, i + 1, Get(*L, i));
        }
        // Insert Elemen
        Set(L, 0, X);
    }
}
void InsertAt(List *L, ElType X, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    int j = LastIdx(*L);
    // Geser Elemen ke Kanan
    for (j; j >= i; j--){
        Set(L, j + 1, Get(*L, j));
    }
    // Insert Elemen
    Set(L, i, X);
}
void InsertLast(List *L, ElType X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */ 
    if (IsEmpty(*L)){
        Set(L, 0, X);
    }
    else{
        Set(L, LastIdx(*L) + 1, Get(*L, LastIdx(*L)));
        Set(L, LastIdx(*L), X);
    }
}
void DeleteFirst(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
    int i = FirstIdx(*L);
    for (i; i <= LastIdx(*L); i++)
    {
        Set(L, i, Get(*L, i + 1));
    }
    Set(L, LastIdx(*L) + 1, Mark);
}
void DeleteAt(List *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
    for (i; i <= LastIdx(*L); i++)
    {
        Set(L, i, Get(*L, i + 1));
    }
    Set(L, LastIdx(*L) + 1, Mark);
}

void DeleteLast(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
    Set(L, LastIdx(*L), Mark);
}

List Concat(List L1, List L2){
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
    List L3 = MakeList();
    int i = 0;
    for (i; i < Length(L1); i++)
    {
        Set(&L3, i, Get(L1, i));
    }
    for (i = Length(L1); i < Length(L1) + Length(L2); i++)
    {
        Set(&L3, i, Get(L2, i - Length(L1)));
    }
    Set(&L3, LastIdx(L3) + 1, Mark);
    return (L3);
}

