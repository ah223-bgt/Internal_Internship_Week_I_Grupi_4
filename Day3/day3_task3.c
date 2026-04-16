#include <stdio.h>

int main() {
    int fillimi, fundi;

    int count3 = 0, count5 = 0;
    int shuma3 = 0, shuma5 = 0;

    // Input
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &fillimi);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &fundi);

    // Kontrolli i intervalit
    if (fillimi > fundi) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    // Loop për analizë
    for (int i = fillimi; i <= fundi; i++) {

        // Numrat qe pjestohen me 3
        if (i % 3 == 0) {
            count3++;
            shuma3 += i;
        }
        // Numrat qe pjestohen me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            count5++;
            shuma5 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d deri %d\n", fillimi, fundi);

    printf("Pjestohen me 3 -> Numerues: %d | Shuma: %d\n", count3, shuma3);
    printf("Pjestohen me 5 (jo me 3) -> Numerues: %d | Shuma: %d\n", count5, shuma5);

    // Krahasimi i shumave
    if (shuma3 > shuma5) {
        printf("Shuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } else if (shuma5 > shuma3) {
        printf("Shuma e numrave qe pjestohen me 5 (jo me 3) eshte me e madhe.\n");
    } else {
        printf("Te dyja shumat jane te barabarta.\n");
    }

    return 0;
}
