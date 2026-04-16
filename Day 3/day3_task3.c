#include <stdio.h>

int main() {
    int start, end;
    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    // Marrja e intervalit
    printf("Shkruani fillimin e intervalit: ");
    if (scanf("%d", &start) != 1) {
        printf("Input i pavlefshem.\n");
        return 1;
    }

    printf("Shkruani fundin e intervalit: ");
    if (scanf("%d", &end) != 1) {
        printf("Input i pavlefshem.\n");
        return 1;
    }

    // Kontroll intervali
    if (start > end) {
        printf("Fillimi nuk mund te jete me i madh se fundi.\n");
        return 1;
    }

    // For loop për intervalin
    for (int i = start; i <= end; i++) {

        // Pjesetohet me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }
        // Pjesetohet me 5 por jo me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            sum5 += i;
            count5++;
        }
    }

    printf("\nRezultatet:\n");

    printf("Numrat qe pjestohen me 3:\n");
    printf("Shuma = %d\n", sum3);
    printf("Numeruesi = %d\n\n", count3);

    printf("Numrat qe pjestohen me 5 por jo me 3:\n");
    printf("Shuma = %d\n", sum5);
    printf("Numeruesi = %d\n\n", count5);

    // Krahasimi i shumave
    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    }
    else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjestohen me 5 (jo me 3) eshte me e madhe.\n");
    }
    else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}
