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

/* ------------------ UTIL ------------------ */

void printStatus(Status s) {
    switch(s) {
        case USHTRIM: printf("Nevojitet ushtrim"); break;
        case VAZHDIM: printf("Gati per vazhdim"); break;
        case SFIDE: printf("Gati per sfide"); break;
    }
}

void printHeader() {
    printf("\n====================================\n");
    printf("        MINI PROJEKT - DITA 4       \n");
    printf("====================================\n");
}

void printRegjistrim(struct Regjistrim r) {
    printf("ID: %d\n", r.id);
    printf("Iniciali: %c\n", r.iniciali);
    printf("Mosha: %d\n", r.mosha);
    printf("Piket: %.2lf\n", r.pike);
    printf("Statusi: ");
    printStatus(r.status);
    printf("\n-----------------------------\n");
}

/* ------------------ ADD ------------------ */

void shtoRegjistrim(struct Regjistrim lista[], int *count, int *nextID) {

    if(*count >= MAX) {
        printf("Lista eshte plot.\n");
        return;
    }

    lista[*count].id = (*nextID)++;

    printf("Mosha: ");
    scanf("%d", &lista[*count].mosha);

    printf("Iniciali: ");
    scanf(" %c", &lista[*count].iniciali);

    printf("Piket: ");
    scanf("%lf", &lista[*count].pike);

    int s;
    printf("Statusi (1-3): ");
    scanf("%d", &s);

    if(s < 1 || s > 3) {
        printf("Status i pavlefshem.\n");
        return;
    }

    lista[*count].status = s;
    (*count)++;

    printf("Regjistrimi u shtua.\n");
}

/* ------------------ SHOW ------------------ */

void shfaqTeGjitha(struct Regjistrim lista[], int count) {

    if(count == 0) {
        printf("Lista bosh.\n");
        return;
    }

    for(int i=0;i<count;i++)
        printRegjistrim(lista[i]);
}

/* ------------------ RAPORT ------------------ */

void raport(struct Regjistrim lista[], int count) {

    if(count == 0) {
        printf("Nuk ka te dhena.\n");
        return;
    }

    double sum = 0;
    double max = lista[0].pike;
    double min = lista[0].pike;

    for(int i=0;i<count;i++) {

        sum += lista[i].pike;

        if(lista[i].pike > max) max = lista[i].pike;
        if(lista[i].pike < min) min = lista[i].pike;
    }

    printf("\n===== RAPORT =====\n");
    printf("Total: %d\n", count);
    printf("Mesatarja: %.2lf\n", sum/count);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);
}

/* ------------------ SEARCH ------------------ */

void kerko(struct Regjistrim lista[], int count) {

    int id;
    int found = 0;

    printf("ID: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++) {

        if(lista[i].id == id) {

            found = 1;
            printRegjistrim(lista[i]);

            if(lista[i].pike < 50 && lista[i].status == USHTRIM)
                printf("Paralajmerim: Performanca e ulet\n");

            else if(lista[i].pike > 80 && lista[i].status == SFIDE)
                printf("Shkelqyeshem\n");

            else
                printf("Ne progres normal\n");
        }
    }

    if(!found)
        printf("Nuk u gjet.\n");
}

/* ------------------ EDIT ------------------ */

void editRegjistrim(struct Regjistrim *r) {

    printf("Piket e reja: ");
    scanf("%lf",&r->pike);

    int s;
    printf("Statusi i ri (1-3): ");
    scanf("%d",&s);

    if(s>=1 && s<=3)
        r->status = s;
    else
        printf("Status i pavlefshem.\n");
}

/* ------------------ DELETE ------------------ */

void fshi(struct Regjistrim lista[], int *count) {

    int id;
    printf("ID per fshirje: ");
    scanf("%d",&id);

    int index = -1;

    for(int i=0;i<*count;i++) {
        if(lista[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Nuk u gjet.\n");
        return;
    }

    for(int i=index;i<*count-1;i++)
        lista[i] = lista[i+1];

    (*count)--;

    printf("U fshi me sukses.\n");
}

/* ------------------ SORT ------------------ */

void rendit(struct Regjistrim lista[], int count) {

    for(int i=0;i<count-1;i++)
    for(int j=0;j<count-i-1;j++)
    if(lista[j].pike < lista[j+1].pike) {

        struct Regjistrim t = lista[j];
        lista[j] = lista[j+1];
        lista[j+1] = t;
    }

    printf("\n--- RANKING ---\n");

    for(int i=0;i<count;i++) {
        printf("Rank #%d\n",i+1);
        printRegjistrim(lista[i]);
    }
}

/* ------------------ MAIN ------------------ */

int main() {

    struct Regjistrim lista[MAX];

    int count = 0;
    int nextID = 1;
    int z;

    do {

        printHeader();

        printf("1. Shto\n");
        printf("2. Shfaq\n");
        printf("3. Raport\n");
        printf("4. Kerko\n");
        printf("5. Edit\n");
        printf("6. Fshi\n");
        printf("7. Rendit\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");

        scanf("%d",&z);

        switch(z) {

            case 1: shtoRegjistrim(lista,&count,&nextID); break;
            case 2: shfaqTeGjitha(lista,count); break;
            case 3: raport(lista,count); break;
            case 4: kerko(lista,count); break;

            case 5: {
                int id, found = 0;

                printf("ID: ");
                scanf("%d",&id);

                for(int i=0;i<count;i++) {
                    if(lista[i].id==id) {
                        editRegjistrim(&lista[i]);
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("Regjistrimi nuk u gjet.\n");

                break;
            }

            case 6: fshi(lista,&count); break;
            case 7: rendit(lista,count); break;

            case 0: printf("Programi u mbyll.\n"); break;

            default: printf("Zgjedhje e pavlefshme.\n");
        }

    } while(z!=0);

    return 0;
}
