#include <stdio.h>

int main() {

    int mosha;          // variabel per moshen
    char iniciali;      // nje shkronje
    float gjatesia;     // numer me presje
    double mesatarja;   // numer me presje me i sakte
    short nr1 = 5;      // numer i vogel
    long nr2 = 100000;  // numer i madh

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine: ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    printf("\n--- PROFILI ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %f\n", gjatesia);
    printf("Mesatarja: %lf\n", mesatarja);
    printf("Short value: %d\n", nr1);
    printf("Long value: %ld\n", nr2);

    return 0;
}
