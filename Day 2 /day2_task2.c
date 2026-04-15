#include <stdio.h>

int main() {
    int score;

    // Marrja e input-it
    printf("Shkruaj rezultatin (0 - 100): ");
    scanf("%d", &score);

    // Kontrolli i intervalit + klasifikimi
    if (score < 0 || score > 100) {
        printf("Input jo valid!\n");
    }
    else if (score >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (score >= 60) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}
