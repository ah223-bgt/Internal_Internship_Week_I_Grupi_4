#include <stdio.h>

int main()
{
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;

    short vitiLindjes = 2008;
    long popullsia = 1800000;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine (ne metra): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    printf("\n--- PROFILI I PERDORUESIT ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Viti i lindjes: %d\n", vitiLindjes);
    printf("Popullsia e vendit: %ld\n", popullsia);

    return 0;
}
