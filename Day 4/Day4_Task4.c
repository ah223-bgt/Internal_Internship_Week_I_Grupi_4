#include <stdio.h>

#define MAX 100

typedef enum {
    USHTRIM = 1,
    VAZHDIM,
    SFIDE
} Status;

struct Regjistrim {
    int id;
    int mosha;
    char iniciali;
    double pike;
    Status status;
};

void printStatus(Status s) {
    switch(s) {
        case USHTRIM: printf("Nevojitet ushtrim"); break;
        case VAZHDIM: printf("Gati per vazhdim"); break;
        case SFIDE: printf("Gati per sfide"); break;
    }
}

int main() {

    struct Regjistrim lista[MAX];
    int count = 0;
    int nextID = 1;
    int zgjedhja;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha\n");
        printf("3. Raport analitik\n");
        printf("4. Kerko sipas ID\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {

        case 1:
            if(count >= MAX) {
                printf("Lista eshte plot!\n");
                break;
            }

            lista[count].id = nextID++;

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

            printf("Regjistrimi u shtua me ID: %d\n", nextID-1);
            break;

        case 2:
            if(count == 0) {
                printf("Nuk ka regjistrime.\n");
                break;
            }

            printf("\n--- LISTA ---\n");

            for(int i=0;i<count;i++) {
                printf("\nID: %d\n", lista[i].id);
                printf("Iniciali: %c\n", lista[i].iniciali);
                printf("Mosha: %d\n", lista[i].mosha);
                printf("Piket: %.2lf\n", lista[i].pike);
                printf("Statusi: ");
                printStatus(lista[i].status);
                printf("\n");
            }
            break;

        case 3:
            if(count == 0) {
                printf("Nuk ka te dhena.\n");
                break;
            }

            double shuma = 0;
            double max = lista[0].pike;
            double min = lista[0].pike;

            int nrSfide = 0;
            int nrUshtrim = 0;

            for(int i=0;i<count;i++) {

                shuma += lista[i].pike;

                if(lista[i].pike > max) max = lista[i].pike;
                if(lista[i].pike < min) min = lista[i].pike;

                if(lista[i].status == SFIDE) nrSfide++;
                if(lista[i].status == USHTRIM) nrUshtrim++;
            }

            double mesatarja = shuma / count;

            printf("\n===== RAPORT ANALITIK =====\n");
            printf("Total regjistrime: %d\n", count);
            printf("Mesatarja: %.2lf\n", mesatarja);
            printf("Max: %.2lf\n", max);
            printf("Min: %.2lf\n", min);
            printf("Nr Sfide: %d\n", nrSfide);
            printf("Nr Ushtrim: %d\n", nrUshtrim);

            printf("\nVleresim grupi: ");

            if(mesatarja < 50)
                printf("Grupi ka nevoje per ushtrim\n");
            else if(mesatarja < 80)
                printf("Grupi eshte gati per vazhdim\n");
            else
                printf("Grupi eshte gati per sfide\n");

            printf("\n");
            break;

        case 4:
            if(count == 0) {
                printf("Nuk ka regjistrime.\n");
                break;
            }

            int kerkoID;
            int found = 0;

            printf("Shkruaj ID: ");
            scanf("%d", &kerkoID);

            for(int i=0;i<count;i++) {

                if(lista[i].id == kerkoID) {

                    found = 1;

                    printf("\n--- REGJISTRIMI U GJET ---\n");
                    printf("ID: %d\n", lista[i].id);
                    printf("Iniciali: %c\n", lista[i].iniciali);
                    printf("Mosha: %d\n", lista[i].mosha);
                    printf("Piket: %.2lf\n", lista[i].pike);
                    printf("Statusi: ");
                    printStatus(lista[i].status);
                    printf("\n");

                    printf("\n--- VLERESIM ---\n");

                    if(lista[i].pike < 50 && lista[i].status == USHTRIM)
                        printf("Paralajmerim: Performanca e ulet.\n");

                    else if(lista[i].pike > 80 && lista[i].status == SFIDE)
                        printf("Shkelqyeshem: Kandidat per nivel avancuar.\n");

                    else if(lista[i].pike >=50 && lista[i].pike <=80 
                            && lista[i].status == VAZHDIM)
                        printf("Ne rruge te duhur.\n");

                    else if(lista[i].pike < 50 && lista[i].mosha < 18)
                        printf("Rekomandohet trajnim bazik.\n");

                    else
                        printf("Kerkon vleresim manual.\n");
                }
            }

            if(!found)
                printf("Asnje regjistrim nuk u gjet me kete ID.\n");

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
