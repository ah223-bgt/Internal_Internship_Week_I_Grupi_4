#include <stdio.h>

int main() {
    int score;

    // Marrja e input
    printf("Shkruaj rezultatin (0 - 100): ");
    scanf("%d", &score);

    // Kontrolli i intervalit (shume e rendesishme)
    if (score < 0 || score > 100) {
        printf("Input jo valid! Ju lutem shkruani nje vlere nga 0 deri ne 100.\n");
    }
    else if (score >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (score >= 50) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}
