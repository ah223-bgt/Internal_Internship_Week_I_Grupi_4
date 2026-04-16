#include <stdio.h>

int main()
{
    int start, end;

    int count3 = 0, sum3 = 0;
    int count5 = 0, sum5 = 0;

    // Marrim input nga përdoruesi
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Kontroll validimi
    if(start > end)
    {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 0;
    }

    // Loop per intervalin
    for(int i = start; i <= end; i++)
    {
        // Numrat qe pjestohen me 3
        if(i % 3 == 0)
        {
            count3++;
            sum3 += i;
        }
        // Numrat qe pjestohen me 5 por jo me 3
        else if(i % 5 == 0)
        {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);

    printf("\nNumra qe pjestohen me 3: %d\n", count3);
    printf("Shuma e tyre: %d\n", sum3);

    printf("\nNumra qe pjestohen me 5 (jo me 3): %d\n", count5);
    printf("Shuma e tyre: %d\n", sum5);

    // Krahasimi i shumave
    if(sum3 > sum5)
    {
        printf("\nShuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    }
    else if(sum5 > sum3)
    {
        printf("\nShuma e numrave qe pjestohen me 5 eshte me e madhe.\n");
    }
    else
    {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}
