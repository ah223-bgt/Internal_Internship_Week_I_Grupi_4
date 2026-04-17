#include <stdio.h>   // perdoret per printf dhe scanf

int main() {         // pika ku fillon programi

    int a;           // variabel numerike e tipit int
    double b;        // variabel numerike e tipit double

    int *pA;         // pointer per variablen a
    double *pB;      // pointer per variablen b

    int oldA;        // ruan vleren e vjeter te a
    double oldB;     // ruan vleren e vjeter te b

    printf("Shkruaj nje numer int: ");   // kerkon input per a
    scanf("%d", &a);                     // lexon a

    printf("Shkruaj nje numer double: "); // kerkon input per b
    scanf("%lf", &b);                     // lexon b

    pA = &a;         // pointer pA ruan adresen e a
    pB = &b;         // pointer pB ruan adresen e b

    oldA = a;        // ruajme vleren fillestare te a
    oldB = b;        // ruajme vleren fillestare te b

    printf("\n--- PARA NDRYSHIMIT ---\n");          // titull
    printf("Vlera direkte e a: %d\n", a);           // printon a
    printf("Adresa e a: %p\n", &a);                 // printon adresen e a
    printf("Vlera e a permes pointer-it: %d\n", *pA); // printon a me pointer

    printf("Vlera direkte e b: %.2lf\n", b);        // printon b
    printf("Adresa e b: %p\n", &b);                 // printon adresen e b
    printf("Vlera e b permes pointer-it: %.2lf\n", *pB); // printon b me pointer

    *pA = *pA + 5;   // ndryshon a permes pointer-it
    *pB = *pB * 2;   // ndryshon b permes pointer-it

    printf("\n--- PAS NDRYSHIMIT ---\n");   // titull
    printf("Vlera e re e a: %d\n", a);      // printon a pas ndryshimit
    printf("Vlera e re e b: %.2lf\n", b);   // printon b pas ndryshimit

    if (a > oldA) {   // kontrollon nese a eshte rritur
        printf("Vlera perfundimtare e a eshte rritur.\n");
    } else if (a < oldA) {   // kontrollon nese a eshte zvogeluar
        printf("Vlera perfundimtare e a eshte zvogeluar.\n");
    } else {   // nese eshte e njejte
        printf("Vlera perfundimtare e a ka mbetur e njejte.\n");
    }

    if (b > oldB) {   // kontrollon nese b eshte rritur
        printf("Vlera perfundimtare e b eshte rritur.\n");
    } else if (b < oldB) {   // kontrollon nese b eshte zvogeluar
        printf("Vlera perfundimtare e b eshte zvogeluar.\n");
    } else {   // nese eshte e njejte
        printf("Vlera perfundimtare e b ka mbetur e njejte.\n");
    }

    if (a >= 0 && a <= 20) {   // kontroll intervali per a
        printf("Vlera perfundimtare e a hyn ne intervalin 0 deri 20.\n");
    } else {
        printf("Vlera perfundimtare e a eshte jashte intervalit 0 deri 20.\n");
    }

    return 0;   // perfundon programin
}
