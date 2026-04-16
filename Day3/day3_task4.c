#include <stdio.h>

int main() {
    int num;
    double value;

    // Pointer-at
    int *pNum;
    double *pValue;

    // Input
    printf("Shkruani nje numer (int): ");
    scanf("%d", &num);

    printf("Shkruani nje numer me presje (double): ");
    scanf("%lf", &value);

    // Caktimi i adresave
    pNum = &num;
    pValue = &value;

    // Shfaqja fillestare
    printf("\n=== VLERA FILLESTARE ===\n");
    printf("num = %d\n", num);
    printf("Adresa e num = %p\n", pNum);
    printf("Vlera permes pointer-it (*pNum) = %d\n", *pNum);

    printf("\nvalue = %.2lf\n", value);
    printf("Adresa e value = %p\n", pValue);
    printf("Vlera permes pointer-it (*pValue) = %.2lf\n", *pValue);

    // Ruajmë vlerën e vjetër
    int oldNum = num;

    // Ndryshimi përmes pointer-it
    *pNum = *pNum + 10;

    printf("\n=== PAS NDRYSHIMIT ===\n");
    printf("num i ri = %d\n", num);

    // Kontroll me if/else
    printf("\n=== ANALIZA ===\n");
    if (num > oldNum) {
        printf("Vlera eshte rritur.\n");
    } else if (num < oldNum) {
        printf("Vlera eshte zvogeluar.\n");
    } else {
        printf("Vlera ka mbetur e njejte.\n");
    }

    // Kontroll intervali
    if (num >= 0 && num <= 50) {
        printf("Vlera eshte ne intervalin [0 - 50].\n");
    } else {
        printf("Vlera eshte jashte intervalit [0 - 50].\n");
    }

    return 0;
}
