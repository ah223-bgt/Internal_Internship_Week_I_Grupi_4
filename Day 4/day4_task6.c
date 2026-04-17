void renditSipasPikeve(struct Regjistrim lista[], int count) {

    for(int i=0;i<count-1;i++) {
        for(int j=0;j<count-i-1;j++) {

            if(lista[j].pike < lista[j+1].pike) {

                struct Regjistrim temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    printf("\n--- RENDITJA SIPAS PIKEVE ---\n");

    for(int i=0;i<count;i++) {

        printf("\nRank #%d\n", i+1);
        printf("ID: %d\n", lista[i].id);
        printf("Iniciali: %c\n", lista[i].iniciali);
        printf("Mosha: %d\n", lista[i].mosha);
        printf("Piket: %.2lf\n", lista[i].pike);

        printf("Statusi: ");
        printStatus(lista[i].status);
        printf("\n");
    }
}
