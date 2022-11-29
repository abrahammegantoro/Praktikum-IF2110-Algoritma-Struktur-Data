// Nama : Abraham Megantoro Samudra
// NIM : 18221123
// Tanggal : 31 Oktober 2022
// Topik : Set dan Map
// Deskripsi

# include "union_map.h"
Map UnionMap(Map m1, Map m2, boolean key_based ){
	Map m3;
	CreateEmpty(&m3);
	int i, j;
	for (i = 0; i<m1.Count ; i++){
		Insert(&m3, m1.Elements[i].Key, m1.Elements[i].Value);
	}
	
	for (i = 0 ; i<m2.Count ; i++){
		Insert(&m3, m2.Elements[i].Key, m2.Elements[i].Value);
	}
	
	infotype temp;
	
	if (key_based) {
		for (i = 0 ; i<m3.Count ; i++) {
			for(j = i; j<m3.Count; j++){
				if (m3.Elements[i].Key > m3.Elements[j].Key){
					temp = m3.Elements[i];
					m3.Elements[i] = m3.Elements[j];
					m3.Elements[j] = temp;
				}
			}
		}
	} else {	
		for (i = 0 ; i<m3.Count ; i++) {
			for(j = i; j<m3.Count; j++){
				if ((m3.Elements[i].Value > m3.Elements[j].Value) || (m3.Elements[i].Value == m3.Elements[j].Value && m3.Elements[i].Key > m3.Elements[j].Key)){
					temp = m3.Elements[i];
					m3.Elements[i] = m3.Elements[j];
					m3.Elements[j] = temp;
				}
			}
		}
	}
	return m3;
}
    /* Menggabungkan m1 dengan m2 pada sebuah map baru dengan urutan yang ditentukan berdasarkan key_based
    apabila key_based true maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan keynya
    apabila key_based false maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan valuenya*/

    /*I.S : Map m1 dan m2 terdefinisi. m1 dan m2 TIDAK kosong dan TIDAK penuh
    F.S : Map m3 yang merupakan gabungan isi dari m1 dan m2 yang diisi berdasarkan nilai key_based. Jumlah elemen m3 TIDAK mungkin melebihi MaxEl*/

    /*Notes: 
        1. Apabila terdapat nilai key yg sama pada m1 dan m2, value yang akan ditambah pada map baru adalah value dari m1 pada key tersebut
        2. Ingat yang unik adalah key, bukan value
    Hint: Lakukan penambahan semua elemen dari m1 dan m2 ke m3 terlebih dahulu kemudian urutkan isinya menggunakan algoritma sorting*/
    
    /*
    Contoh:
        1.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: true
          Output:
            m3: {<1,2>,<7,1>,<8,100>,<11,10>,<20,3>}
        2.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: false
          Output:
            m3: {<7,1>,<1,2>,<20,3>,<11,10>,<8,100>}
    */
