#include <stdio.h>

int main() {
    int start, end;
    int count3 = 0, count5 = 0;
    int sum3 = 0, sum5 = 0;

    // Marrja e input-it
    printf("Shkruani fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruani fundin e intervalit: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    // Loop për analizë
    for (int i = start; i <= end; i++) {

        // Kategoria 1: pjesëtohet me 3
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }
        // Kategoria 2: pjesëtohet me 5 por JO me 3
        else if (i % 5 == 0) {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\n=== REZULTATI ===\n");
    printf("Intervali: [%d - %d]\n", start, end);

    printf("\nNumra qe pjesetohen me 3: %d\n", count3);
    printf("Shuma e tyre: %d\n", sum3);

    printf("\nNumra qe pjesetohen me 5 (jo me 3): %d\n", count5);
    printf("Shuma e tyre: %d\n", sum5);

    // Krahasimi i shumave
    printf("\n=== KRAHASIMI ===\n");
    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    } else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}
