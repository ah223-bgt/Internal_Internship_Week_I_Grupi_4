#include <stdio.h>

int main() {

    int rezultati;

    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100) {
        printf("Inputi nuk eshte valid!\n");
    }
    else if (rezultati >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (rezultati >= 80) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (rezultati >= 70) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}
