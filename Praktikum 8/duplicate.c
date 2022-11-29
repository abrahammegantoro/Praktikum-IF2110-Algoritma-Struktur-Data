// Nama : Abraham Megantoro Samudra
// NIM : 18221123
// Tanggal : 31 Oktober 2022
// Topik : Set dan Map
// Deskripsi

# include "duplicate.h"
/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize){
	Set s;
	CreateEmpty(&s);
	int i = 0;
	for (i ; i<arrSize ; i++) {
		Insert(&s, arr[i]);
	}
	return s;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
	Set s;
	CreateEmpty(&s);
	int i = 0;
	for (i ; i < arrSize ; i++) {
		Insert(&s, arr[i]);
	}
	
	
	int j = 0;
	int l;
	for (j ; j < s.Count ; j++) {
		for (l = j+1 ; l <s.Count; l++){
			if (s.Elements[j] < s.Elements[l]) {
				int temp = s.Elements[j];
				s.Elements[j] = s.Elements[l];
				s.Elements[l] = temp;
			}
		}
	}
	
	int k = 0;
	for(k ; k <s.Count ; k++){
		arrRes[k] = s.Elements[k];
	}
	
	*arrResSize = s.Count;
	
}
