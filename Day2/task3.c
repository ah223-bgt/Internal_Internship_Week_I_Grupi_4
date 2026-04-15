#include <stdio.h>   // për përdorimin e printf dhe scanf

int main() {         // pika ku fillon programi

    int dita;        // variabël për të ruajtur numrin e ditës

    printf("Shkruaj nje numer (1-7): ");   // kërkon nga përdoruesi të japë një numër
    scanf("%d", &dita);                   // merr input dhe e ruan te variabla dita

    switch (dita) {   // kontrollon vlerën e variablës dita

        case 1:   // nëse dita është 1
            printf("E hene - Dite pune\n");   // printon ditën dhe që është ditë pune
            break;   // ndalon ekzekutimin që të mos vazhdojë në case tjetër

        case 2:   // nëse dita është 2
            printf("E marte - Dite pune\n");   // printon këtë
            break;

        case 3:   // nëse dita është 3
            printf("E merkure - Dite pune\n");   // printon këtë
            break;

        case 4:   // nëse dita është 4
            printf("E enjte - Dite pune\n");   // printon këtë
            break;

        case 5:   // nëse dita është 5
            printf("E premte - Dite pune\n");   // printon këtë
            break;

        case 6:   // nëse dita është 6
            printf("E shtune - Fundjave\n");   // printon që është fundjavë
            break;

        case 7:   // nëse dita është 7
            printf("E diele - Fundjave\n");   // printon që është fundjavë
            break;

        default:   // nëse numri nuk është 1-7
            printf("Input i pavlefshem\n");   // jep mesazh gabimi
    }

    return 0;   // përfundon programin me sukses

}
