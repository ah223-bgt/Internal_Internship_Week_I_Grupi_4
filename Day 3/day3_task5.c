#include <stdio.h>

// krijimi i enum me 4 vlera
enum Niveli {
    FILLESTAR = 1,
    MESATAR,
    AVANCUAR,
    EKSPERT
};

int main() {
    int zgjedhja;
    int valide = 0, pavlefshme = 0;

    printf("Zgjedh nivelin e nxenesit:\n");
    printf("1 - Fillestar\n");
    printf("2 - Mesatar\n");
    printf("3 - Avancuar\n");
    printf("4 - Ekspert\n");

    // loop për 3 testime
    for (int i = 1; i <= 3; i++) {
        printf("\nRasti %d - Jep zgjedhjen: ", i);
        scanf("%d", &zgjedhja);

        // lidhja me enum
        enum Niveli niveli = zgjedhja;

        switch (niveli) {
            case FILLESTAR:
                printf("Nxenesi eshte Fillestar. Duhet me fillu nga bazat.\n");
                valide++;
                break;

            case MESATAR:
                printf("Nxenesi eshte Mesatar. Ka njohuri solide.\n");
                valide++;
                break;

            case AVANCUAR:
                printf("Nxenesi eshte i Avancuar. Mund te zgjidhe probleme te veshtira.\n");
                valide++;
                break;

            case EKSPERT:
                printf("Nxenesi eshte Ekspert. Ka nivel shume te larte.\n");
                valide++;
                break;

            default:
                printf("Zgjedhje e pavlefshme! Provo perseri.\n");
                pavlefshme++;
        }
    }

    // statistikat finale
    printf("\n--- STATISTIKAT ---\n");
    printf("Zgjedhje valide: %d\n", valide);
    printf("Zgjedhje te pavlefshme: %d\n", pavlefshme);

    return 0;
}
