#include <stdio.h>

int main() {
    int age;
    char initial;
    double points;
    int workshopOption;

    printf("--- Workshop Registration ---\n");

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your first initial: ");
    scanf(" %c", &initial);

    printf("Enter your preliminary points (0.0 - 100.0): ");
    scanf("%lf", &points);

    printf("Choose workshop (1: C Basics, 2: Algorithms, 3: Hardware): ");
    scanf("%d", &workshopOption);

    printf("\n--- Final Summary ---\n");
    printf("Initial: %c\n", initial);
    printf("Age: %d\n", age);

    if (age >= 15 && age <= 30) {
        printf("Age status: Within participation limits.\n");
    } else {
        printf("Age status: Outside participation limits.\n");
    }

    printf("Points: %.2lf\n", points);
    if (points >= 85) {
        printf("Classification: Ready for Challenge\n");
    } else if (points >= 60) {
        printf("Classification: Ready to Continue\n");
    } else {
        printf("Classification: Needs More Practice\n");
    }

    printf("Workshop: ");
    switch (workshopOption) {
        case 1:
            printf("C Basics\n");
            break;
        case 2:
            printf("Algorithms\n");
            break;
        case 3:
            printf("Hardware\n");
            break;
        default:
            printf("Unknown Workshop Option\n");
    }

    return 0;
}
