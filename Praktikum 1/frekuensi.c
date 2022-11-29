# include <stdio.h>
# include <string.h>

int main() {
    char str[10];
    int array[10];
    int i,j,x;
    for ( i = 0; i < 10; i++) {
        array[i] = 0;
    }
    scanf("%s", &str);
    int len = strlen (str);
    for ( j = 0; j < len; j++) {
        if (str[j] == 48) {
            array[0] += 1;
        } else if (str[j] == 49) {
            array[1] += 1;
        } else if (str[j] == 50) {
            array[2] += 1;
        } else if (str[j] == 51) {
            array[3] += 1;
        } else if (str[j] == 52) {
            array[4] += 1;
        } else if (str[j] == 53) {
            array[5] += 1;
        } else if (str[j] == 54) {
            array[6] += 1;
        } else if (str[j] == 55) {
            array[7] += 1;
        } else if (str[j] == 56) {
            array[8] += 1;
        } else if (str[j] == 57) {
            array[9] += 1;
        }
    }

    for ( x = 0; x <10; x++) {
        printf("%d", array[x]);
    }
    printf("\n");
    return 0;
}