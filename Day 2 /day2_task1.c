#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int age;
    char initial;
    float height;
    double average;
    short year = 11;       // e vendosur direkt
    long population = 1800000; // shembull vlerë

    // Marrja e input-it nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial); // hapsirë para %c për me shmang bug

    printf("Shkruaj gjatesine (p.sh. 1.75): ");
    scanf("%f", &height);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &average);

    // Output i organizuar
    printf("\n----- PROFILI I PERDORUESIT -----\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %.2f m\n", height);
    printf("Mesatarja: %.2lf\n", average);
    printf("Klasa (short): %hd\n", year);
    printf("Popullsia (long): %ld\n", population);

    return 0;
}
