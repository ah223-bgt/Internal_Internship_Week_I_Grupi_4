#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int age;
    char initial;
    float height;
    double average;

    short score = 85;      // vlerë e vendosur në kod
    long population = 1800000; // vlerë e vendosur në kod

    // Marrja e input nga përdoruesi
    printf("Shkruaj moshen tende: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin e emrit: ");
    scanf(" %c", &initial); // hapësira para %c shmang probleme

    printf("Shkruaj gjatesine (p.sh 1.75): ");
    scanf("%f", &height);

    printf("Shkruaj mesataren (p.sh 4.5): ");
    scanf("%lf", &average);

    // Output i organizuar
    printf("\n--- PROFILI I PERDORUESIT ---\n");
    printf("Mosha: %d vjec\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %.2f m\n", height);
    printf("Mesatarja: %.2lf\n", average);
    printf("Piket (short): %d\n", score);
    printf("Popullsia (long): %ld\n", population);

    return 0;
}
