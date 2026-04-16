#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA;
    double *pB;

    // Input
    printf("Shkruaj nje vlere int: ");
    scanf("%d", &a);

    printf("Shkruaj nje vlere double: ");
    scanf("%lf", &b);

    // Lidhja e pointerave me adresat
    pA = &a;
    pB = &b;

    // Shfaqja e vlerave dhe adresave
    printf("\n--- VLERAT FILLESTARE ---\n");
    printf("a (direkt): %d\n", a);
    printf("Adresa e a: %p\n", (void*)&a);
    printf("a permes pointer-it: %d\n", *pA);

    printf("\nb (direkt): %.2lf\n", b);
    printf("Adresa e b: %p\n", (void*)&b);
    printf("b permes pointer-it: %.2lf\n", *pB);

    // Ruajmë vlerat fillestare për krahasim
    int oldA = a;
    double oldB = b;

    // Ndryshimi përmes pointer-it
    *pA = *pA + 10;
    *pB = *pB * 2;

    // Output pas ndryshimit
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a i ri: %d\n", a);
    printf("b i ri: %.2lf\n", b);

    // Kontroll me if/else për a
    printf("\n--- ANALIZA ---\n");

    if (a > oldA) {
        printf("Vlera e a eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera e a eshte zvogeluar.\n");
    } else {
        printf("Vlera e a ka mbetur e njejte.\n");
    }

    // Kontroll për interval për b
    if (b >= 0 && b <= 100) {
        printf("Vlera e b eshte brenda intervalit 0 - 100.\n");
    } else {
        printf("Vlera e b eshte jashte intervalit 0 - 100.\n");
    }

    return 0;
}
