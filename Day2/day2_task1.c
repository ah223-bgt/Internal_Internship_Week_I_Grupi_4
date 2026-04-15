
#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;

    short vitet_shkolle = 12;   // e vendosur direkt
    long popullsia = 1800000;   // e vendosur direkt

    // Marrja e input-it nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin (nje karakter): ");
    scanf(" %c", &iniciali);  // hapësira para %c është e rëndësishme

    printf("Shkruaj gjatesine (p.sh. 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Shfaqja e rezultateve
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vitet e shkolles (short): %d\n", vitet_shkolle);
    printf("Popullsia (long): %ld\n", popullsia);

    return 0;
}
