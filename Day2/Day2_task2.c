#include <stdio.h>

int main()
{
    int rezultati;

    printf("Shkruaj rezultatin (0 - 100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100)
    {
        printf("Input i pavlefshem! Duhet te jete nga 0 deri ne 100.");
    }
    else if (rezultati >= 90)
    {
        printf("Vleresimi: Shkelqyeshem");
    }
    else if (rezultati >= 75)
    {
        printf("Vleresimi: Shume mire");
    }
    else if (rezultati >= 50)
    {
        printf("Vleresimi: Mire");
    }
    else
    {
        printf("Vleresimi: Ne permiresim");
    }

    return 0;
}
