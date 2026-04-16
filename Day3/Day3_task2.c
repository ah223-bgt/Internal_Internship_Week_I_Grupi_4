#include <stdio.h> // input/output

int main()
{
    int start, end;
    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    // marrja e intervalit
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // kontrolli i intervalit
    if (start > end)
    {
        printf("Interval i pavlefshem!");
        return 0; // ndalon programin
    }

    // loop per analizim
    for (int i = start; i <= end; i++)
    {
        if (i % 2 == 0) // kontroll nese eshte çift
        {
            countEven++;
            sumEven += i;
        }
        else // ndryshe eshte tek
        {
            countOdd++;
            sumOdd += i;
        }
    }

    int totalNumbers = end - start + 1;

    // output final
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);
    printf("Total numra: %d\n", totalNumbers);

    printf("Numra çift: %d\n", countEven);
    printf("Shuma e numrave çift: %d\n", sumEven);

    printf("Numra tek: %d\n", countOdd);
    printf("Shuma e numrave tek: %d\n", sumOdd);

    // krahasimi
    if (countEven > countOdd)
    {
        printf("Ka me shume numra çift.\n");
    }
    else if (countOdd > countEven)
    {
        printf("Ka me shume numra tek.\n");
    }
    else
    {
        printf("Numrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}
