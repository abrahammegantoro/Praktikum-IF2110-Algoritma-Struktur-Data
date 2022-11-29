# include "removeDuplicate.h"
# include "boolean.h"
# include <stdio.h>

List removeDuplicate(List l){
	address P1 = First(l);
	address P2 = Next(P1);
	while (P2 != Nil){
		if (Info(P1) == Info(P2)){
			DelAfter(&l, &P2, P1);
			P2 = Next(P1);
		} else {
			P1 = P2;
			P2 = Next(P1);
		}
	}
	return l;
}
