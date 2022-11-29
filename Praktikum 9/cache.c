#include <stdio.h>
#include "listlinier.h"
# include "boolean.h"

int indexOf(List l, infotype val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    int cnt = 0;
    address p = First(l);
    boolean found = false;
    while(p != NULL && !found){
        if(Info(p) == val){
            found=true;
        }
        else{
            cnt++;
            p = p->next;
        }
    }
    if(found){
        return cnt;
    }
    else{
        return -1;
    }
}

void deleteAt(List *l, int idx, infotype *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    if(idx == 0){
        DelVFirst(l, val);
    }
    else{
        int cnt = 0;
        address p, loc;
        loc = First(*l);
        while(cnt<idx-1){
            cnt++;
            loc = Next(loc);
        }
        p = Next(loc);
        *val = Info(p);
        Next(loc) = Next(p);
        Dealokasi(&p);
    }
}

int main(){
    int n;
    scanf("%i", &n);
    int i, temp, val;
    List l;
    CreateEmpty(&l);
    for(i = 0; i < n; i++){
        InsVLast(&l, i+1);
    }
    int q;
    scanf("%i", &q);
    for(i=1; i <= q; i++){
        boolean hit = false;
        scanf("%i", &temp);
        address P = Search(l,temp);    
        int idx = indexOf(l, temp); 
        if(P != Nil){
            hit = true;
        }
        if(hit){
			deleteAt(&l, idx, &val);
            InsVFirst(&l, temp);
            printf("hit ");
            PrintInfo(l);
        }
        else{
            DelVLast(&l, &val);
            InsVFirst(&l, temp);
            printf("miss ");
            PrintInfo(l);
        }
        printf("\n");
    }


}
