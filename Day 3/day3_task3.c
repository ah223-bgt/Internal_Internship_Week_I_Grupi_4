#include <stdio.h>

int main() {
    int start, end;

    int count3 = 0, sum3 = 0;
    int count5 = 0, sum5 = 0;

    // Marrja e input-it
    printf("Shkruani fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruani fundin e intervalit: ");
    scanf("%d", &end);

    // Validimi
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 1;
    }

    // Loop
    for (int i = start; i <= end; i++) {

        // Numrat qe pjesetohen me 3
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }

        // Numrat qe pjesetohen me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d, %d]\n", start, end);

    printf("\nPjesetohen me 3:\n");
    printf("Numeruesi: %d\n", count3);
    printf("Shuma: %d\n", sum3);

    printf("\nPjesetohen me 5 (jo me 3):\n");
    printf("Numeruesi: %d\n", count5);
    printf("Shuma: %d\n", sum5);

    // Krahasimi i shumave
    if (sum3 > sum5) {
        printf("\nShuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("\nShuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}
