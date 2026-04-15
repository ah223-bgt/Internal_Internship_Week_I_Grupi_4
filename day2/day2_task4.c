#include <stdio.h>

int main() {

    int age;
    char initial;
    double points;
    int option;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj pike paraprake: ");
    scanf("%lf", &points);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &option);

    // Kontrolli i moshes
    if (age < 15 || age > 25) {
        printf("\nNuk ploteson kushtin e moshes per pjesemarrje.\n");
    }

    // Vleresimi me if/else
    char* level;

    if (points < 50) {
        level = "Nevojitet me shume ushtrim";
    }
    else if (points < 75) {
        level = "Gati per vazhdim";
    }
    else {
        level = "Gati per sfide";
    }

    // Zgjedhja e punetorise me switch
    char* workshop;

    switch(option) {
        case 1:
            workshop = "Programim Bazik";
            break;
        case 2:
            workshop = "Web Development";
            break;
        case 3:
            workshop = "Data Analysis";
            break;
        default:
            workshop = "Opsion i pavlefshem";
            break;
    }

    // Output final
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Iniciali: %c\n", initial);
    printf("Mosha: %d\n", age);
    printf("Piket: %.2lf\n", points);
    printf("Niveli: %s\n", level);
    printf("Punetoria: %s\n", workshop);

    return 0;
}
