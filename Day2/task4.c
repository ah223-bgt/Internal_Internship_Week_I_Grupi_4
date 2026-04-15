#include <stdio.h>   // për përdorimin e printf dhe scanf

int main() {         // pika ku fillon programi

    int mosha, opsioni;   // variabla për moshën dhe zgjedhjen e punëtorisë
    char iniciali;        // variabël për një shkronjë (iniciali)
    double pike;          // variabël për pikët (numër me presje)

    printf("Shkruaj moshen: ");   // kërkon nga përdoruesi të japë moshën
    scanf("%d", &mosha);          // merr moshën dhe e ruan te mosha

    printf("Shkruaj inicialin: ");   // kërkon inicialin
    scanf(" %c", &iniciali);         // merr shkronjën dhe e ruan te iniciali

    printf("Shkruaj piket: ");   // kërkon pikët
    scanf("%lf", &pike);         // merr pikët dhe i ruan te pike

    printf("Zgjidh punetorine (1-3): ");   // kërkon opsionin e punëtorisë
    scanf("%d", &opsioni);               // merr numrin dhe e ruan te opsioni

    // kontrollon nëse mosha është e lejuar
    if (mosha < 10) {   // nëse mosha është më e vogël se 10
        printf("Nuk lejohet pjesemarrja\n");   // nuk lejohet
    } else {   // nëse mosha është 10 ose më shumë
        printf("Lejohet pjesemarrja\n");   // lejohet
    }

    // vendim sipas pikëve
    if (pike < 50) {   // nëse pikët janë më pak se 50
        printf("Nevojitet me shume ushtrim\n");   // kategori e ulët
    } else if (pike < 80) {   // nëse janë më pak se 80
        printf("Gati per vazhdim\n");   // kategori mesatare
    } else {   // nëse janë 80 ose më shumë
        printf("Gati per sfide\n");   // kategori e lartë
    }

    // zgjedhja e punëtorisë me switch
    switch (opsioni) {   // kontrollon vlerën e opsioni

        case 1:   // nëse është 1
            printf("Punetoria 1\n");   // printon këtë
            break;   // ndalon që të mos kalojë në rast tjetër

        case 2:   // nëse është 2
            printf("Punetoria 2\n");   // printon këtë
            break;

        case 3:   // nëse është 3
            printf("Punetoria 3\n");   // printon këtë
            break;

        default:   // nëse nuk është 1, 2 ose 3
            printf("Opsion i pavlefshem\n");   // mesazh gabimi
    }

    // përmbledhja finale
    printf("\n--- PERMBLEDHJE ---\n");   // titulli
    printf("Mosha: %d\n", mosha);       // printon moshën
    printf("Iniciali: %c\n", iniciali); // printon inicialin
    printf("Piket: %lf\n", pike);       // printon pikët

    return 0;   // përfundon programin me sukses

}
