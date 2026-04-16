#include <stdio.h>

int main()
{
    int n, zgjedhja;

    // Marrim input nga përdoruesi
    printf("Shkruaj nje numer (1 - 12): ");
    scanf("%d", &n);

    // Kontrollojmë validimin
    if(n < 1 || n > 12)
    {
        printf("Input i pavlefshem! Duhet te jete nga 1 deri ne 12.\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Zgjedh pattern:\n");
    printf("1 - Yje (*)\n");
    printf("2 - Numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &zgjedhja);

    printf("\nRezultati:\n");

    // Pattern me yje
    if(zgjedhja == 1)
    {
        for(int i = 1; i <= n; i++) // rreshtat
        {
            for(int j = 1; j <= i; j++) // elementet ne rresht
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if(zgjedhja == 2)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}
