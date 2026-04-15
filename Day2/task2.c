#include <stdio.h>   // për përdorimin e printf dhe scanf

int main() {         // pika ku fillon programi

    int nota;        // variabël për të ruajtur rezultatin e përdoruesit

    printf("Shkruaj rezultatin (0-100): ");   // kërkon nga përdoruesi të japë një numër
    scanf("%d", &nota);                      // merr input dhe e ruan te variabla nota

    // kontrollon nëse numri është jashtë intervalit 0-100
    if (nota < 0 || nota > 100) {
        printf("Input i pavlefshem\n");   // nëse është jashtë intervalit, jep këtë mesazh
    }

    // nëse është 90 ose më shumë
    else if (nota >= 90) {
        printf("Shkelqyeshem\n");   // printon këtë kategori
    }

    // nëse është 80 ose më shumë
    else if (nota >= 80) {
        printf("Shume mire\n");   // printon këtë kategori
    }

    // nëse është 70 ose më shumë
    else if (nota >= 70) {
        printf("Mire\n");   // printon këtë kategori
    }

    // për të gjitha rastet tjera (më pak se 70)
    else {
        printf("Ne permiresim\n");   // printon këtë kategori
    }

    return 0;   // përfundon programin me sukses

}
