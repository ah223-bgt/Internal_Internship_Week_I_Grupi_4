#include <stdio.h>   // për përdorimin e printf dhe scanf

int main() {         // pika ku fillon programi

    int mosha;          // variabël për moshën (numër i plotë)
    char iniciali;      // variabël për një shkronjë (char)
    float gjatesia;     // variabël për numër me presje (float)
    double mesatarja;   // variabël për numër me presje më të saktë (double)
    short nr1 = 5;      // variabël short me vlerë të vogël
    long nr2 = 100000;  // variabël long me vlerë të madhe

    printf("Shkruaj moshen: ");   // kërkon nga përdoruesi të shkruajë moshën
    scanf("%d", &mosha);          // merr numrin dhe e ruan në variablën mosha

    printf("Shkruaj inicialin: ");   // kërkon një shkronjë nga përdoruesi
    scanf(" %c", &iniciali);         // merr shkronjën dhe e ruan te iniciali

    printf("Shkruaj gjatesine: ");   // kërkon gjatësinë
    scanf("%f", &gjatesia);          // merr numër me presje dhe e ruan te gjatesia

    printf("Shkruaj mesataren: ");   // kërkon mesataren
    scanf("%lf", &mesatarja);        // merr numër double dhe e ruan te mesatarja

    printf("\n--- PROFILI ---\n");   // printon titullin e profilit (rresht i ri)

    printf("Mosha: %d\n", mosha);         // printon moshën
    printf("Iniciali: %c\n", iniciali);   // printon inicialin
    printf("Gjatesia: %f\n", gjatesia);   // printon gjatësinë
    printf("Mesatarja: %lf\n", mesatarja); // printon mesataren
    printf("Short value: %d\n", nr1);     // printon variablën short
    printf("Long value: %ld\n", nr2);     // printon variablën long

    return 0;   // përfundon programin me sukses

}
