#include <stdio.h> // input/output

int main()
{
    int n, zgjedhja;

    // marrja e madhesise
    printf("Shkruaj nje numer (1 - 12): ");
    scanf("%d", &n);

    // kontrolli i input-it
    if (n < 1 || n > 12)
    {
        printf("Input i pavlefshem! Jep numer nga 1 deri ne 12.");
        return 0; // ndalon programin
    }

    // zgjedhja e pattern-it
    printf("Zgjidh pattern:\n");
    printf("1 - Yje (*)\n");
    printf("2 - Numra\n");
    printf("Zgjedhja: ");
    scanf("%d", &zgjedhja);

    printf("\n--- PATTERN ---\n");

    // pattern me yje
    if (zgjedhja == 1)
    {
        for (int i = 1; i <= n; i++) // rreshtat
        {
            for (int j = 1; j <= i; j++) // elementet ne rresht
            {
                printf("* ");
            }
            printf("\n"); // rresht i ri
        }
    }
    // pattern me numra
    else if (zgjedhja == 2)
    {
        for (int i = 1; i <= n; i++) // rreshtat
        {
            for (int j = 1; j <= i; j++) // elementet
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Zgjedhje e pavlefshme!");
    }

    return 0; // fundi
}
