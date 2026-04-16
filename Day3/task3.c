#include <stdio.h>   // për përdorimin e printf dhe scanf

int main() {         // pika ku fillon programi

    int fillimi, fundi;   // variabla për fillimin dhe fundin e intervalit
    int count3 = 0, count5 = 0;   // numërues për numrat që pjesëtohen me 3 dhe 5
    int shuma3 = 0, shuma5 = 0;   // shuma për secilën kategori

    printf("Shkruaj fillimin: ");   // kërkon nga përdoruesi fillimin
    scanf("%d", &fillimi);          // merr input dhe e ruan te fillimi

    printf("Shkruaj fundin: ");     // kërkon fundin
    scanf("%d", &fundi);            // merr input dhe e ruan te fundi

    // kontrollon nëse intervali është valid
    if (fillimi > fundi) {          // nëse fillimi është më i madh se fundi
        printf("Interval i pavlefshem\n");   // mesazh gabimi
        return 0;                   // ndalon programin
    }

    // loop për të kaluar nëpër çdo numër të intervalit
    for (int i = fillimi; i <= fundi; i++) {   // fillon nga fillimi deri te fundi

        // kontrollon nëse numri pjesëtohet me 3
        if (i % 3 == 0) {          // nëse mbetja e pjesëtimit me 3 është 0
            count3++;              // rrit numëruesin për këtë kategori
            shuma3 += i;           // shton numrin në shumën totale
        }

        // kontrollon nëse numri pjesëtohet me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {   // dy kushte bashkë
            count5++;              // rrit numëruesin për këtë kategori
            shuma5 += i;           // shton numrin në shumën totale
        }
    }

    // printon rezultatet
    printf("\n--- REZULTATI ---\n");   // titull për output
    printf("Intervali: %d deri %d\n", fillimi, fundi);   // tregon intervalin

    printf("Numra qe pjesetohen me 3: %d\n", count3);   // numri i tyre
    printf("Shuma e tyre: %d\n", shuma3);               // shuma e tyre

    printf("Numra qe pjesetohen me 5 (jo me 3): %d\n", count5);   // numri
    printf("Shuma e tyre: %d\n", shuma5);                         // shuma

    // krahasimi i dy shumave
    if (shuma3 > shuma5) {   // nëse shuma e parë është më e madhe
        printf("Shuma e numrave me 3 eshte me e madhe\n");
    } else if (shuma5 > shuma3) {   // nëse e dyta është më e madhe
        printf("Shuma e numrave me 5 eshte me e madhe\n");
    } else {   // nëse janë të barabarta
        printf("Shumat jane te barabarta\n");
    }

    return 0;   // përfundon programin me sukses
}
