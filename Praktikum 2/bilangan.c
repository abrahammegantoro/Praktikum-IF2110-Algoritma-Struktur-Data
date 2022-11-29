# include <stdio.h>

int main(){
    int count, num, i, total = 0;
    scanf("%d",&count);

    while(count > 0){
        scanf("%d",&num);
        for(i = num; i >= 1; i--){
            if (i % 7 == 0){
                total += i;
            } else {
                int temp = i;
                while (temp > 0){
                    if (temp % 10 == 7){
                        total += i;
                        break;
                    }
                    temp /= 10;
                }
            }
        }
        printf("%d\n", total);
        total = 0;
        count--;
    }
}