#include <stdio.h>

// krijimi i enum me 4 vlera
enum Level
{
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main()
{
    int choice;
    int validCount = 0, invalidCount = 0;

    // loop per 3 raste
    for (int i = 1; i <= 3; i++)
    {
        printf("\nZgjedh nivelin per perdoruesin %d:\n", i);
        printf("1 - Beginner\n");
        printf("2 - Intermediate\n");
        printf("3 - Advanced\n");
        printf("4 - Expert\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        // kontroll me switch
        switch (choice)
        {
            case BEGINNER:
                printf("Nivel fillestar - fokus ne bazat.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Nivel mesatar - zhvillim i aftesive.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Nivel i avancuar - probleme me komplekse.\n");
                validCount++;
                break;

            case EXPERT:
                printf("Nivel ekspert - sfida te veshtira.\n");
                validCount++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
        }
    }

    // statistikat finale
    printf("\n--- STATISTIKA ---\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje te pavlefshme: %d\n", invalidCount);

    return 0;
}
