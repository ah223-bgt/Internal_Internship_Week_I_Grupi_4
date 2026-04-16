#include <stdio.h>

int main() {
    int mosha, opsioni;
    char iniciali;
    double piket;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    int lejohet = 0;
    if (mosha >= 12 && mosha <= 18) {
        lejohet = 1;
    }

    // Klasifikimi sipas pikëve
    char* rezultati;

    if (piket < 50) {
        rezultati = "Nevojitet me shume ushtrim";
    } else if (piket >= 50 && piket < 80) {
        rezultati = "Gati per vazhdim";
    } else {
        rezultati = "Gati per sfide";
    }

    // Zgjedhja e punëtorisë
    char* punetoria;

    switch (opsioni) {
        case 1:
            punetoria = "Programim Bazik";
            break;
        case 2:
            punetoria = "Web Development";
            break;
        case 3:
            punetoria = "Data Analysis";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
    }

    // Output përfundimtar
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", piket);
    printf("Punetoria: %s\n", punetoria);

    if (lejohet) {
        printf("Statusi i moshes: Lejohet per pjesemarrje\n");
    } else {
        printf("Statusi i moshes: Nuk lejohet per pjesemarrje\n");
    }

    printf("Rezultati: %s\n", rezultati);

    return 0;
}
