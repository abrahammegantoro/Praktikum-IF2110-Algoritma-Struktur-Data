/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address P = First(L);
    int i = 0;
    while (i < r) {
        P = Next(P);
        i++;
    }
    return Info(P);
}

int main () {
  List L;
  int r;
  /* Tuliskan implementasi di sini */
  CreateEmpty(&L);

  int in;
  scanf("%d", &in);
  while (in != 0) {
      InsVLast(&L, in);
      scanf("%d", &in);
  }

  scanf("%d", &r);
  
  if(!IsEmpty(L)) {
      printf("%d\n", ElemenKeN(L, r));
  } else {
    printf("List Kosong\n");
  }
  return 0;
}