#include <stdio.h>
#include <stdlib.h>
#include "arraydin1.h"

ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (ElType*)malloc(InitialSize * sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateArrayDin(ArrayDin *array) {
    free((*array).A);
}

boolean IsEmpty(ArrayDin array){
    return (array.Neff == 0);
}

int Length(ArrayDin array) {
    return array.Neff;
}

ElType Get(ArrayDin array, IdxType i){
    return array.A[i];
}

int GetCapacity(ArrayDin array){
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i){
    ElType j;
    if (Length(*array)>=GetCapacity(*array)){
        (*array).A = (ElType*)realloc((*array).A, ((*array).Capacity)*2*sizeof(ElType));
        (*array).Capacity *= 2;
    }
    for(j=(*array).Neff;j>i;j--){
        (*array).A[j] = (*array).A[j-1];
        }
    (*array).A[i] = el;
    (*array).Neff += 1;
}


void DeleteAt(ArrayDin (*array), IdxType i) {
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