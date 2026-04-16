#include <stdio.h>   // për printf dhe scanf

int main() {

    int n, zgjedhja;   // n = madhësia e pattern, zgjedhja = tipi (yje apo numra)

    printf("Shkruaj nje numer (1-12): ");   // kërkon madhësinë
    scanf("%d", &n);                       // merr input

    // kontroll nëse input-i është valid
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem\n");   // mesazh gabimi
        return 0;                         // ndalon programin
    }

    printf("Zgjidh pattern:\n");   // menu për përdoruesin
    printf("1 - Yje\n");
    printf("2 - Numra\n");
    scanf("%d", &zgjedhja);        // merr zgjedhjen

    // pattern me yje
    if (zgjedhja == 1) {

        for (int i = 1; i <= n; i++) {   // loop për rreshtat

            for (int j = 1; j <= i; j++) {   // loop për elementet brenda rreshtit
                printf("* ");   // printon yje
            }

            printf("\n");   // kalon në rresht tjetër
        }
    }

    // pattern me numra
    else if (zgjedhja == 2) {

        for (int i = 1; i <= n; i++) {   // loop për rreshtat

            for (int j = 1; j <= i; j++) {   // loop për numrat
                printf("%d ", j);   // printon numra
            }

            printf("\n");   // rresht i ri
        }
    }

    // nëse zgjedhja nuk është 1 ose 2
    else {
        printf("Zgjedhje e pavlefshme\n");
    }

    return 0;   // fundi i programit
}
