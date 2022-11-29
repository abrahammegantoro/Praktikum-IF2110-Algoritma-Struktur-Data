#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    scanf("%s", &str1);
    scanf("%s", &str2);

    int i,j;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (i = 0; i < len1; i++) {
        if (str1[i] >= 65 && str1[i] <= 90)
            str1[i] += 32; 
    }
    for (j = 0; j < len2; j++) {
        if (str2[j] >= 65 && str2[j] <= 90)
            str2[j] += 32; 
    }

    if (len1 == len2 && *str1==*str2) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    return 0;
}