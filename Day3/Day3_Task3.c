#include <stdio.h> // input/output

int main()
{
    int start, end;
    int count3 = 0, count5 = 0;
    int sum3 = 0, sum5 = 0;

    // marrja e intervalit
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    // kontrolli i input-it
    if (start > end)
    {
        printf("Interval i pavlefshem!");
        return 0; // ndalon programin
    }

    // loop per analizim
    for (int i = start; i <= end; i++)
    {
        if (i % 3 == 0) // numrat qe pjesetohen me 3
        {
            count3++;
            sum3 += i;
        }
        else if (i % 5 == 0) // pjesetohet me 5 por jo me 3
        {
            count5++;
            sum5 += i;
        }
    }

    // output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);

    printf("Numra qe pjesetohen me 3: %d\n", count3);
    printf("Shuma e tyre: %d\n", sum3);

    printf("Numra qe pjesetohen me 5 (jo me 3): %d\n", count5);
    printf("Shuma e tyre: %d\n", sum5);

    // krahasimi i shumave
    if (sum3 > sum5)
    {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    }
    else if (sum5 > sum3)
    {
        printf("Shuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    }
    else
    {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}
