#include <stdio.h>

int main() {
    int age, option;
    char initial;
    double points;

    // Marrja e input-it
    printf("Shkruani moshen: ");
    scanf("%d", &age);

    printf("Shkruani inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruani piket paraprake: ");
    scanf("%lf", &points);

    printf("Zgjidhni punetorine (1-3): ");
    scanf("%d", &option);

    // Kontrolli i moshes
    printf("\n=== KONTROLLI I MOSHES ===\n");
    if (age >= 15 && age <= 25) {
        printf("Mosha eshte e pranueshme.\n");
    } else {
        printf("Mosha jashte kufirit te lejuar.\n");
    }

    // Klasifikimi me if/else
    printf("\n=== VLERESIMI ===\n");
    if (points < 50) {
        printf("Nevojitet me shume ushtrim.\n");
    } else if (points < 75) {
        printf("Gati per vazhdim.\n");
    } else {
        printf("Gati per sfide.\n");
    }

    // Zgjedhja me switch
    printf("\n=== PUNETORIA ===\n");
    switch(option) {
        case 1:
            printf("Programim bazik\n");
            break;
        case 2:
            printf("Algoritme\n");
            break;
        case 3:
            printf("Zhvillim aplikacionesh\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    // Përmbledhja finale
    printf("\n=== PERMBLEDHJE ===\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Piket: %.2lf\n", points);
    printf("Opsioni: %d\n", option);

    return 0;
}
