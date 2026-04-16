#include <stdio.h>

int main()
{
    int numri, paraNdryshimit;
    double nota;
    int *pNumri;
    double *pNota;

    printf("Shkruaj nje numer te plote: ");
    scanf("%d", &numri);

    printf("Shkruaj nje numer me presje: ");
    scanf("%lf", &nota);

    pNumri = &numri;
    pNota = &nota;

    printf("\n--- VLERA FILLESTARE ---\n");
    printf("Numri direkt: %d\n", numri);
    printf("Adresa e numrit: %p\n", (void*)pNumri);
    printf("Numri permes pointer-it: %d\n", *pNumri);

    printf("\nNota direkt: %.2lf\n", nota);
    printf("Adresa e notes: %p\n", (void*)pNota);
    printf("Nota permes pointer-it: %.2lf\n", *pNota);

    paraNdryshimit = *pNumri;

    *pNumri = *pNumri + 10;

    printf("\n--- PAS NDRYSHIMIT ME POINTER ---\n");
    printf("Numri para ndryshimit: %d\n", paraNdryshimit);
    printf("Numri pas ndryshimit: %d\n", *pNumri);

    if (*pNumri > paraNdryshimit)
    {
        printf("Rezultati: Vlera eshte rritur.\n");
    }
    else if (*pNumri < paraNdryshimit)
    {
        printf("Rezultati: Vlera eshte zvogeluar.\n");
    }
    else
    {
        printf("Rezultati: Vlera ka mbetur e njejte.\n");
    }

    if (*pNumri >= 0 && *pNumri <= 50)
    {
        printf("Vlera perfundimtare eshte ne intervalin 0 - 50.\n");
    }
    else
    {
        printf("Vlera perfundimtare eshte jashte intervalit 0 - 50.\n");
    }

    return 0;
}
