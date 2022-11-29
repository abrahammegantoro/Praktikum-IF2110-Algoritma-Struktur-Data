# include <stdio.h>

int factorial(int x) { 
    int fact = 1;
    int i;
    if (x == 0) {
        return 1;
    } else {
        return (x * factorial(x-1));
    }
}

int split(int x) {
    if (x < 10) {
        return factorial(x);
    } else if (x >= 10) {
        return split(x / 10) + factorial(x%10);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    if (a == 0){
        printf("N\n");
    } else if (a == split(a)){ 
        printf("Y\n");
    } else {
        printf("N\n");
    }
}