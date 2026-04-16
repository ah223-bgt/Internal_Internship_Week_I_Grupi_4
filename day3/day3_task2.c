#include <stdio.h>

int main()
{
    int start, end;

    int countCift = 0, countTek = 0;
    int sumCift = 0, sumTek = 0;

    // Marrim intervalin nga përdoruesi
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
        if(i % 2 == 0)
        {
            countCift++;
            sumCift += i;
        }
        else
        {
            countTek++;
            sumTek += i;
        }
    }

    int total = (end - start) + 1;

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);
    printf("Totali i numrave: %d\n", total);

    printf("\nNumra cift: %d\n", countCift);
    printf("Shuma e numrave cift: %d\n", sumCift);

    printf("\nNumra tek: %d\n", countTek);
    printf("Shuma e numrave tek: %d\n", sumTek);

    // Krahasimi
    if(countCift > countTek)
    {
        printf("\nKa me shume numra cift.\n");
    }
    else if(countTek > countCift)
    {
        printf("\nKa me shume numra tek.\n");
    }
    else
    {
        printf("\nNumri i numrave cift dhe tek eshte i barabarte.\n");
    }

    return 0;
}
