# include <stdio.h>
# include <stdlib.h>
# include "reverse.h"

void transferReverse(Queue* q1, Queue* q2){
    ElType * array;
    array = (ElType *)malloc(Length(*q1)*sizeof(ElType));
    int k = Length(*q1);
    for(int i=0;i<k;i++){
        if(q1->TAIL+i < q1->MaxEl){
            array[k-i-1] = Front(*q1);
            Pop(q1);
        } else{
            array[k-i-1] = Front(*q1);
            Pop(q1);
        }
    }
    for (int i = 0;i<k;i++){
        if(q1->TAIL+i<q1->MaxEl){
            Push(q2,array[i]);
        } else{
            Push(q2,array[i]);
        }
    }
}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik