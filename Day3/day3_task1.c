#include <stdio.h>

int main() {
    int size, choice, i, j;

    printf("Enter the size of the pattern (1-12): ");
    scanf("%d", &size);

    if (size < 1 || size > 12) {
        printf("Invalid input! Please enter a number between 1 and 12.\n");
        return 0;
    }

    printf("Choose pattern type (1 for Stars, 2 for Numbers): ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else if (choice == 2) {
        for (i = 1; i <= size; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
