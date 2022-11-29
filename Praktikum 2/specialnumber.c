# include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d",&n);
    int m;
    while (n>0) {
        scanf("%d\n",&m);
        while (m>0) {
            if (m / 10 == 7 || (m % 10) == 7 || m%7 ==0) {
                count += m;
            }
            m -= 1;
        }  
        printf("%d\n",count);
        n-= 1; 
        count = 0;
    }
    return 0;
}