#include <stdio.h>

// Krijimi i enum
enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    // For loop për 3 raste
    for (int i = 1; i <= 3; i++) {
        printf("\nZgjedhja %d:\n", i);
        printf("Zgjidh nivelin:\n");
        printf("1 - Beginner\n");
        printf("2 - Intermediate\n");
        printf("3 - Advanced\n");
        printf("4 - Expert\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &choice);

        // Kontrolli me switch
        switch (choice) {
            case BEGINNER:
                printf("Ti je fillestar. Vazhdo te mesosh bazat.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Ti ke njohuri mesatare. Mund te provosh projekte me te avancuara.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Ti je ne nivel te avancuar. Po ben pune shume te mire!\n");
                validCount++;
                break;

            case EXPERT:
                printf("Ti je ekspert! Mund te ndihmosh edhe te tjeret.\n");
                validCount++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
                break;
        }
    }

    // Statistikat
    printf("\n--- STATISTIKAT ---\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje te pavlefshme: %d\n", invalidCount);

    return 0;
}
