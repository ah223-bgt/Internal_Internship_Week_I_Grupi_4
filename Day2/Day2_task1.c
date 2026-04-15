#include <stdio.h>

int main() {

    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vite;
    long id;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine: ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    vite = 2;
    id = 123456789;

    printf("\n--- PROFILI ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vite eksperience: %d\n", vite);
    printf("ID: %ld\n", id);

    return 0;
}
