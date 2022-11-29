#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef int ElType;

typedef struct
	{
		ElType TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} TabInt;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    T -> Neff = 0;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    return T.Neff;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return IdxMax - IdxMin +1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return IdxMin;
}
IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return T.Neff;
}
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i){
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
    return T.TI[i];
}
/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
    int i;
    Tout -> Neff = Tin.Neff;
    for (i = IdxMin;i<=IdxMax;i++){
        Tout->TI[i] = Tin.TI[i];
    }
}
/* Assignment THsl -> Tin */
void SetEl (TabInt *T, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    T -> TI[i] = v;
    T->Neff = T->Neff +1;
}
void SetNeff (TabInt *T, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    T->Neff = N;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    if (i <=IdxMax && i>= IdxMin){
        return true;
    } else{
        return false;
    }
}
boolean IsIdxEff (TabInt T, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    if (i <=T.Neff && i>= IdxMin){
        return true;
    } else{
        return false;
    }
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    if (T.Neff == 0){
        return true;
    } else{
        return false;
    }
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    if (T.Neff == IdxMax){
        return true;
    } else{
        return false;
    }
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    else{
        int j = GetFirstIdx(T);
        for (j; j <= GetLastIdx(T); j++){
            printf("%d:%d\n", j, GetElmt(T, j));
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
    TabInt T3;
    int i;
    T3.Neff = T1.Neff;
    for(i = 1;i<=T3.Neff;i++){
        T3.TI[i] = T1.TI[i]+T2.TI[i];
    }
    return T3;
}

TabInt MinusTab (TabInt T1, TabInt T2){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
    TabInt T3;
    int i;
    T3.Neff = T1.Neff;
    for(i = 1;i<=T3.Neff;i++){
        T3.TI[i] = T1.TI[i]-T2.TI[i];
    }
    return T3;
    }


/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
    ElType max;
    int i;
    max = T.TI[IdxMin];
    for(i = 2;i<=T.Neff;i++){
        if (T.TI[i] > max){
            max = T.TI[i];
        }
    }
    return max;
}
ElType ValMin (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
    ElType min;
    int i;
    min = T.TI[IdxMin];
    for(i = 2;i<=T.Neff;i++){
        if (T.TI[i] < min){
            min = T.TI[i];
        }
    }
    return min;
}
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
    ElType max;
    int i,index;
    max = T.TI[IdxMin];
    index = IdxMin;
    for(i = 2;i<=T.Neff;i++){
        if (T.TI[i] > max){
            max = T.TI[i];
            index = i;
        }
    }
    return index;
}
IdxType IdxMinTab (TabInt T){
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
    ElType min;
    int i,index;
    min = T.TI[IdxMin];
    index = IdxMin;
    for(i = 2;i<=T.Neff;i++){
        if (T.TI[i] < min){
            min = T.TI[i];
            index = i;
        }
    }
    return index;
}
