#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double pike;
    int opsioni;

    // Input
    printf("Shkruani moshen: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruani piket paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjidhni punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    int lejohet = 0;
    if (mosha >= 15 && mosha <= 25) {
        lejohet = 1;
    }

    // Klasifikimi sipas pikeve
    char rezultat[30];

    if (pike < 50) {
        sprintf(rezultat, "Nevojitet me shume ushtrim");
    }
    else if (pike >= 50 && pike < 80) {
        sprintf(rezultat, "Gati per vazhdim");
    }
    else {
        sprintf(rezultat, "Gati per sfide");
    }

    // Switch per punetorine
    char punetoria[30];

    switch (opsioni) {
        case 1:
            sprintf(punetoria, "Programim Bazik");
            break;
        case 2:
            sprintf(punetoria, "Algoritme");
            break;
        case 3:
            sprintf(punetoria, "Struktura te dhenash");
            break;
        default:
            sprintf(punetoria, "Opsion i pavlefshem");
    }

    // Output i formatuar
    printf("\n----- PERMBLEDHJE -----\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2lf\n", pike);
    printf("Punetoria: %s\n", punetoria);
    printf("Rezultati: %s\n", rezultat);

    if (lejohet) {
        printf("Statusi i moshes: Lejohet pjesemarrja\n");
    } else {
        printf("Statusi i moshes: Nuk lejohet pjesemarrja\n");
    }

    return 0;
}
