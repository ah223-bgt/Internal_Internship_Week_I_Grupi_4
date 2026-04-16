#include <stdio.h>

enum Level { BASIC = 1, INTERMEDIATE, ADVANCED, EXPERT };

int main() {
    enum Level userLevel;
    int choice, i;
    int valid = 0, invalid = 0;

    for (i = 0; i < 3; i++) {
        printf("\nIteration %d - Select Level (1-Basic, 2-Intermediate, 3-Advanced, 4-Expert): ", i + 1);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            userLevel = (enum Level)choice;
            valid++;

            switch (userLevel) {
                case BASIC:
                    printf("Response: Welcome! Let's start with the fundamentals.\n");
                    break;
                case INTERMEDIATE:
                    printf("Response: Great! You are ready for more complex tasks.\n");
                    break;
                case ADVANCED:
                    printf("Response: Impressive! You are handling professional levels.\n");
                    break;
                case EXPERT:
                    printf("Response: Mastery! You can now lead other students.\n");
                    break;
            }
        } else {
            printf("Response: Invalid selection! Please choose between 1 and 4.\n");
            invalid++;
        }
    }

    printf("\n--- Final Statistics ---\n");
    printf("Valid entries: %d\n", valid);
    printf("Invalid entries: %d\n", invalid);

    return 0;
}
