#include <stdio.h>

int main() {
    int a;
    float b;

    // pointers
    int *pA;
    float *pB;

    // input
    printf("Shkruani nje numer integer: ");
    scanf("%d", &a);

    printf("Shkruani nje numer float: ");
    scanf("%f", &b);

    // ruajtja e adresave
    pA = &a;
    pB = &b;

    printf("\n--- Vlerat fillestare ---\n");

    printf("a = %d\n", a);
    printf("Adresa e a = %p\n", &a);
    printf("Vlera e a permes pointer = %d\n\n", *pA);

    printf("b = %.2f\n", b);
    printf("Adresa e b = %p\n", &b);
    printf("Vlera e b permes pointer = %.2f\n\n", *pB);

    // ruaj vleren e vjeter
    int oldA = a;

    // ndryshim permes pointer
    *pA = *pA + 10;

    printf("--- Pas ndryshimit me pointer ---\n");
    printf("Vlera e vjeter e a = %d\n", oldA);
    printf("Vlera e re e a = %d\n", a);

    // kontrolli me if/else
    printf("\n--- Kontrolli ---\n");

    if (a > oldA) {
        printf("Vlera eshte rritur\n");
    }
    else if (a < oldA) {
        printf("Vlera eshte zvogeluar\n");
    }
    else {
        printf("Vlera ka mbetur e njejte\n");
    }

    // kontroll intervali
    if (a >= 0 && a <= 100) {
        printf("Vlera eshte brenda intervalit 0 - 100\n");
    }
    else {
        printf("Vlera eshte jashte intervalit 0 - 100\n");
    }

    return 0;
}
