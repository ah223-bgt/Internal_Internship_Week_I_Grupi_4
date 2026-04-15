#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double pike;
    int opsioni;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjedh punetorine (1-3): ");
    scanf("%d", &opsioni);

    printf("\n--- Klasifikimi ---\n");

    if(pike < 50) {
        printf("Nevojitet me shume ushtrim\n");
    }
    else if(pike >= 50 && pike < 80) {
        printf("Gati per vazhdim\n");
    }
    else {
        printf("Gati per sfide\n");
    }

    printf("\n--- Punetoria ---\n");

    switch(opsioni) {
        case 1:
            printf("Programim Bazik\n");
            break;

        case 2:
            printf("Struktura te Dhenash\n");
            break;

        case 3:
            printf("Algoritme\n");
            break;

        default:
            printf("Opsion i pavlefshem\n");
    }

    printf("\n--- Kontrolli i Moshes ---\n");

    if(mosha >= 15 && mosha <= 25) {
        printf("Lejohet pjesemarrja\n");
    } else {
        printf("Mosha jashte kufirit per pjesemarrje\n");
    }

    printf("\n--- Permbledhja ---\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %f\n", pike);
    printf("Opsioni: %d\n", opsioni);

    return 0;
}
