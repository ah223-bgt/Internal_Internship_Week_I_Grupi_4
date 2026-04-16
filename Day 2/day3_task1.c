#include <stdio.h>

int main() {
    int n, choice;

    printf("Shkruani madhesine e pattern-it (1 - 12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Input i pavlefshem! Ju lutem zgjidhni numer nga 1 deri 12.\n");
        return 0;
    }

    printf("Zgjidhni llojin e pattern-it:\n");
    printf("1 - Pattern me yje (*)\n");
    printf("2 - Pattern me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Pattern me yje
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } 
    else if (choice == 2) {
        // Pattern me numra
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } 
    else {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}
