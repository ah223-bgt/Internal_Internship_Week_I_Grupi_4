#include <stdio.h>

int main() {
    int n, choice;

    // Marrja e input-it
    printf("Shkruani nje numer (1 - 12): ");
    scanf("%d", &n);

    // Kontrolli i input-it
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem!\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Zgjidhni pattern-in:\n");
    printf("1 - Me yje (*)\n");
    printf("2 - Me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    printf("\n=== PATTERN ===\n");

    // Pattern me yje
    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    // Input i pavlefshëm për zgjedhje
    else {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}
