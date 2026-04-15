#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int age, workshop;
    char initial;
    double points;

    // Marrja e input-it
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj pikat paraprake: ");
    scanf("%lf", &points);

    printf("Zgjedh punetorine (1, 2, 3): ");
    scanf("%d", &workshop);

    // Kontrolli i moshes
    if (age < 15 || age > 25) {
        printf("\nNuk ploteson kushtin e moshes per pjesemarrje!\n");
    }

    // Klasifikimi sipas pikeve
    char status[50];

    if (points < 50) {
        sprintf(status, "Nevojitet me shume ushtrim");
    }
    else if (points < 75) {
        sprintf(status, "Gati per vazhdim");
    }
    else {
        sprintf(status, "Gati per sfide");
    }

    // Switch per punetorine
    char workshopName[50];

    switch(workshop) {
        case 1:
            sprintf(workshopName, "Programim Bazik");
            break;
        case 2:
            sprintf(workshopName, "Web Development");
            break;
        case 3:
            sprintf(workshopName, "Data & Security");
            break;
        default:
            sprintf(workshopName, "Opsion jo valid");
    }

    // Output final
    printf("\n----- PERMBLEDHJA -----\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Piket: %.2lf\n", points);
    printf("Statusi: %s\n", status);
    printf("Punetoria: %s\n", workshopName);

    return 0;
}
