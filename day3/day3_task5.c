#include <stdio.h>

// Krijojmë enum me 4 vlera
enum Level {Beginner = 1, Intermediate, Advanced, Expert};

int main()
{
    int zgjedhja;
    int valid = 0, invalid = 0;

    // Loop për 3 raste testimi
    for(int i = 1; i <= 3; i++)
    {
        printf("\nZgjedh nivelin per perdoruesin %d:\n", i);
        printf("1 - Beginner\n");
        printf("2 - Intermediate\n");
        printf("3 - Advanced\n");
        printf("4 - Expert\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        // Kontroll dhe lidhje me enum
        switch(zgjedhja)
        {
            case Beginner:
                printf("Niveli Beginner: Duhet te fillosh me bazat.\n");
                valid++;
                break;

            case Intermediate:
                printf("Niveli Intermediate: Ke njohuri mesatare.\n");
                valid++;
                break;

            case Advanced:
                printf("Niveli Advanced: Je shume i avancuar.\n");
                valid++;
                break;

            case Expert:
                printf("Niveli Expert: Ke njohuri te thella.\n");
                valid++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalid++;
                break;
        }
    }

    // Statistikat
    printf("\n--- Statistikat ---\n");
    printf("Zgjedhje valide: %d\n", valid);
    printf("Zgjedhje te pavlefshme: %d\n", invalid);

    return 0;
}
