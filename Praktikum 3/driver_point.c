#include "point.h"
#include <stdio.h>

int main()
{
    POINT P, P1, P2;
    printf("Input koordinat titik P\n");
    BacaPOINT(&P);

    printf("Titik P mempunyai koordinat: \n");
    TulisPOINT(P);

    printf("Input koordinat titik P1\n");
    BacaPOINT(&P1);

    printf("Titik P1 mempunyai koordinat: \n");
    TulisPOINT(P1);

    printf("Input koordinat titik P2\n");
    BacaPOINT(&P2);

    printf("Titik P2 mempunyai koordinat: \n");
    TulisPOINT(P2);

    printf("Apakah P1 = P2?\n");
    printf("%d\n", EQ(P1, P2));

    printf("Apakah P1 != P2?\n");
    printf("%d\n", NEQ(P1, P2));

    printf("Apakah P titik origin?\n");
    printf("%d\n", IsOrigin(P));

    printf("Apakah P berada di sumbu x?\n");
    printf("%d\n", IsOnSbX(P));

    printf("Apakah P berada di sumbu y?\n");
    printf("%d\n", IsOnSbY(P));

    printf("P berada di kuadran = %d\n", Kuadran(P));

    float deltax, deltay;
    printf("Input deltax dan deltay\n");
    scanf("%f %f", &deltax, &deltay);
    printf("Titik delta P adalah = ");
    TulisPOINT(PlusDelta(P, deltax, deltay));
    printf("\n");
    printf("Titik setelah digeser P adalah = ");
    Geser(&P, deltax, deltay);
    printf("\n");



    printf("Jarak P ke titik origin = %f\n", Jarak0(P));
    printf("Jarak antara P dan P2 = %f\n", Panjang(P1, P2));
    return 0;
}