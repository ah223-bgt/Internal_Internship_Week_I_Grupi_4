#include <stdio.h>

int main()
{
    int start, end;
    int i;

    int count = 0;
    int sum = 0;

    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi i intervalit
    if(start > end)
    {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    printf("\nNumrat qe pjestohen me 2 ne intervalin [%d - %d]:\n", start, end);

    for(i = start; i <= end; i++)
    {
        if(i % 2 == 0)
        {
            printf("%d\n", i);
            count++;
            sum += i;
        }
    }

    printf("\nTotali i numrave cift: %d\n", count);
    printf("Shuma e numrave cift: %d\n", sum);

    return 0;
}
