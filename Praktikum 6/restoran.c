# include "queue.h"
# include <stdio.h>

int main(){
    Queue q;
	CreateQueue(&q);
	int inp, count = 0, t, tMin = 0, tMax = 0;
	scanf("%d", &inp);
	while (inp != 0)
	{
		if (inp == 1) {
			scanf("%d", &t);
			if (!isFull(q) && t > 0){
                enqueue(&q, t);
            }
		}
		else if (inp == 2) {
			if (!isEmpty(q)) {
				dequeue(&q, &t);
				count++;
				if (tMin == 0 || tMin > t) {
                    tMin = t;
                }
				if (tMax == 0 || tMax < t) {
                    tMax = t;
                }
			}
		}
		scanf("%d", &inp);
	}
	printf("%d\n%d\n%d\n", count, tMin, tMax);
}