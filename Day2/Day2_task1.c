#include <stdio.h>

int main() {
    // Deklarimi dhe inicializimi i variablave
    int mosha = 21;
    char iniciali = 'A';
    float gjatesia = 1.75f;
    double mesatarja = 8.65;
    short vleraShort = 30;
    long vleraLong = 1234567890;

    // Shfaqja e të dhënave
    printf("----- PROFILI I PERDORUESIT -----\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia (m): %.2f\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vlera short: %hd\n", vleraShort);
    printf("Vlera long: %ld\n", vleraLong);

    return 0;
}
