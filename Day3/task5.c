#include <stdio.h>

// enum me 4 nivele
enum Niveli {DOBET = 1, MESATAR, MIRE, SHKELQYESHEM};

int main() {

    int zgjedhja;
    int valid = 0;
    int invalid = 0;

    // loop për 3 raste
    for (int i = 1; i <= 3; i++) {

        printf("\nZgjedh nivelin per nxenesin %d:\n", i);
        printf("1 - Dobet\n");
        printf("2 - Mesatar\n");
        printf("3 - Mire\n");
        printf("4 - Shkelqyeshem\n");

        scanf("%d", &zgjedhja);

        // switch për enum
        switch (zgjedhja) {

            case DOBET:
                printf("Nxenesi ka nivel te dobet.\n");
                valid++;
                break;

            case MESATAR:
                printf("Nxenesi ka nivel mesatar.\n");
                valid++;
                break;

            case MIRE:
                printf("Nxenesi ka nivel te mire.\n");
                valid++;
                break;

            case SHKELQYESHEM:
                printf("Nxenesi eshte shkelqyeshem.\n");
                valid++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalid++;
        }
    }

    printf("\n--- STATISTIKA ---\n");
    printf("Zgjedhje valide: %d\n", valid);
    printf("Zgjedhje te pavlefshme: %d\n", invalid);

    return 0;
}
