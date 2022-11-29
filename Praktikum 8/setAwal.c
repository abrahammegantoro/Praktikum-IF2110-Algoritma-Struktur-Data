# include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
    if (!IsMember(*S, Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
    if (IsMember(*S, Elmt)){
        address i = 0;
        while (i < (*S).Count && (*S).Elements[i] != Elmt){ // selama i lebih kecil dari s.count dan nilai element indeks i bukan elmt
            i++;
        }
        
        // element dari i yang memang isinya elmt diganti dengan element terakhir, lalu element terakhir dihapus, jadi tetep ada
        (*S).Elements[i] = (*S).Elements[(*S).Count - 1]; 
        (*S).Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
    address i = 0;
    while (i < S.Count && S.Elements[i] != Elmt){
        i++;
    }
    return i < S.Count;
}
/* Mengembalikan true jika Elmt adalah member dari S */
