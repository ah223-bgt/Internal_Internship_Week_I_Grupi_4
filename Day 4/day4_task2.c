#include <stdio.h>

#define MAX 5

// ENUM per statusin
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
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {

        case 1:
            if(count >= MAX) {
                printf("Keni arritur maksimumin e regjistrimeve!\n");
                break;
            }

            printf("Mosha: ");
            scanf("%d", &lista[count].mosha);

            printf("Iniciali: ");
            scanf(" %c", &lista[count].iniciali);

            printf("Piket: ");
            scanf("%lf", &lista[count].pike);

            int zgjedhStatus;

            printf("Zgjidh statusin:\n");
            printf("1. Nevojitet ushtrim\n");
            printf("2. Gati per vazhdim\n");
            printf("3. Gati per sfide\n");
            printf("Zgjedhja: ");
            scanf("%d", &zgjedhStatus);

            // validim i statusit
            switch(zgjedhStatus) {
                case 1:
                    lista[count].status = USHTRIM;
                    break;
                case 2:
                    lista[count].status = VAZHDIM;
                    break;
                case 3:
                    lista[count].status = SFIDE;
                    break;
                default:
                    printf("Status i pavlefshem! Regjistrimi u anulua.\n");
                    break;
            }

            if(zgjedhStatus >= 1 && zgjedhStatus <= 3) {
                count++;
                printf("Regjistrimi u shtua!\n");
            }

            break;

        case 2:
            if(count == 0) {
                printf("Nuk ka regjistrime!\n");
                break;
            }

            printf("\n--- LISTA ---\n");

            for(int i=0;i<count;i++) {
                printf("\nRegjistrimi #%d\n", i+1);
                printf("Iniciali: %c\n", lista[i].iniciali);
                printf("Mosha: %d\n", lista[i].mosha);
                printf("Piket: %.2lf\n", lista[i].pike);

                printf("Statusi: ");
                switch(lista[i].status) {
                    case USHTRIM:
                        printf("Nevojitet ushtrim\n");
                        break;
                    case VAZHDIM:
                        printf("Gati per vazhdim\n");
                        break;
                    case SFIDE:
                        printf("Gati per sfide\n");
                        break;
                }
            }
            break;

        case 0:
            printf("Programi u mbyll.\n");
            break;

        default:
            printf("Zgjedhje e pavlefshme! Provoni perseri.\n");
        }

    } while(zgjedhja != 0);

    return 0;
}
