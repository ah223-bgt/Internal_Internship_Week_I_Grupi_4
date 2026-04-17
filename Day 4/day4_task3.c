#include <stdio.h>

#define MAX 5

typedef enum {
    USHTRIM = 1,
    VAZHDIM,
    SFIDE
} Status;

struct Regjistrim {
    int mosha;
    char iniciali;
    double pike;
    Status status;
};

int main() {

    struct Regjistrim lista[MAX];
    int count = 0;
    int zgjedhja;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha\n");
        printf("3. Raport analitik\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {

        case 1:
            if(count >= MAX) {
                printf("Keni arritur maksimumin!\n");
                break;
            }

            printf("Mosha: ");
            scanf("%d", &lista[count].mosha);

            printf("Iniciali: ");
            scanf(" %c", &lista[count].iniciali);

            printf("Piket: ");
            scanf("%lf", &lista[count].pike);

            int s;
            printf("Statusi:\n");
            printf("1. Nevojitet ushtrim\n");
            printf("2. Gati per vazhdim\n");
            printf("3. Gati per sfide\n");
            printf("Zgjedhja: ");
            scanf("%d", &s);

            if(s < 1 || s > 3) {
                printf("Status i pavlefshem!\n");
                break;
            }

            lista[count].status = s;
            count++;

            printf("Regjistrimi u shtua!\n");
            break;

        case 2:
            if(count == 0) {
                printf("Lista eshte bosh.\n");
                break;
            }

            for(int i=0;i<count;i++) {
                printf("\nRegjistrimi #%d\n", i+1);
                printf("Iniciali: %c\n", lista[i].iniciali);
                printf("Mosha: %d\n", lista[i].mosha);
                printf("Piket: %.2lf\n", lista[i].pike);

                printf("Statusi: ");
                switch(lista[i].status) {
                    case USHTRIM: printf("Nevojitet ushtrim\n"); break;
                    case VAZHDIM: printf("Gati per vazhdim\n"); break;
                    case SFIDE: printf("Gati per sfide\n"); break;
                }
            }
            break;

        case 3:
            if(count == 0) {
                printf("Nuk ka te dhena per raport.\n");
                break;
            }

            int nrSfide = 0;
            int nrUshtrim = 0;
            double shuma = 0;
            double max = lista[0].pike;
            double min = lista[0].pike;

            for(int i=0;i<count;i++) {

                shuma += lista[i].pike;

                if(lista[i].pike > max)
                    max = lista[i].pike;

                if(lista[i].pike < min)
                    min = lista[i].pike;

                if(lista[i].status == SFIDE)
                    nrSfide++;

                if(lista[i].status == USHTRIM)
                    nrUshtrim++;
            }

            double mesatarja = shuma / count;

            printf("\n------ RAPORT ANALITIK ------\n");
            printf("Total regjistrime: %d\n", count);
            printf("Mesatarja e pikeve: %.2lf\n", mesatarja);
            printf("Piket max: %.2lf\n", max);
            printf("Piket min: %.2lf\n", min);
            printf("Nr. per sfide: %d\n", nrSfide);
            printf("Nr. nevojitet ushtrim: %d\n", nrUshtrim);

            printf("\nKlasifikimi i grupit: ");

            if(mesatarja < 50)
                printf("Grupi ka nevoje per me shume ushtrime\n");
            else if(mesatarja < 80)
                printf("Grupi eshte gati per vazhdim\n");
            else
                printf("Grupi eshte gati per sfida\n");

            break;

        case 0:
            printf("Programi u mbyll.\n");
            break;

        default:
            printf("Zgjedhje e pavlefshme!\n");
        }

    } while(zgjedhja != 0);

    return 0;
}
