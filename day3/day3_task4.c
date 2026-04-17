#include <stdio.h>

int main()
{
    int a;
    double b;

    int *pA;
    double *pB;

    // Input
    printf("Shkruaj nje numer int: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer double: ");
    scanf("%lf", &b);

    // Lidhja e pointerave me adresat
    pA = &a;
    pB = &b;

    // Shfaqja e vlerave dhe adresave
    printf("\n--- Vlerat fillestare ---\n");
    printf("a (direkt) = %d\n", a);
    printf("Adresa e a = %p\n", &a);
    printf("Vlera e a permes pointer-it = %d\n", *pA);

    printf("\nb (direkt) = %.2lf\n", b);
    printf("Adresa e b = %p\n", &b);
    printf("Vlera e b permes pointer-it = %.2lf\n", *pB);

    // Ruajmë vlerat fillestare
    int oldA = a;
    double oldB = b;

    // Ndryshimi përmes pointer-it
    *pA = *pA + 10;     // rritje
    *pB = *pB - 5.5;    // zvogëlim

    // Shfaqja pas ndryshimit
    printf("\n--- Pas ndryshimit ---\n");
    printf("a (pas) = %d\n", a);
    printf("b (pas) = %.2lf\n", b);

    // Kontroll për a
    printf("\n--- Analiza per a ---\n");
    if(a > oldA)
    {
        printf("Vlera e a eshte rritur.\n");
    }
    else if(a < oldA)
    {
        printf("Vlera e a eshte zvogeluar.\n");
    }
    else
    {
        printf("Vlera e a ka mbetur e njejte.\n");
    }

    // Kontroll për b (me interval)
    printf("\n--- Analiza per b ---\n");
    if(b > oldB)
    {
        printf("Vlera e b eshte rritur.\n");
    }
    else if(b < oldB)
    {
        printf("Vlera e b eshte zvogeluar.\n");
    }
    else if(b >= -10 && b <= 10)
    {
        printf("Vlera e b eshte ne intervalin [-10, 10].\n");
    }
    else
    {
        printf("Vlera e b ka mbetur e njejte.\n");
    }

    return 0;
}
