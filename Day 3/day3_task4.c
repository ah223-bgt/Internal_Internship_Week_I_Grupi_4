#include <stdio.h>

int main() {
    int num1, originalNum1;
    float num2;
    int *pNum1;
    float *pNum2;

    // Marrja e input-it
    printf("Shkruani nje vlere int: ");
    scanf("%d", &num1);

    printf("Shkruani nje vlere float: ");
    scanf("%f", &num2);

    // Ruajme vleren origjinale te int per krahasim
    originalNum1 = num1;

    // Pointerat marrin adresat e variablave
    pNum1 = &num1;
    pNum2 = &num2;

    // Shfaqja e vlerave fillestare
    printf("\n--- VLERAT FILLESTARE ---\n");
    printf("num1 (direkt) = %d\n", num1);
    printf("Adresa e num1 = %p\n", (void*)pNum1);
    printf("Vlera e num1 permes pointer-it = %d\n", *pNum1);

    printf("\nnum2 (direkt) = %.2f\n", num2);
    printf("Adresa e num2 = %p\n", (void*)pNum2);
    printf("Vlera e num2 permes pointer-it = %.2f\n", *pNum2);

    // Ndryshimi i vleres se int permes pointer-it
    printf("\n--- NDRYSHIMI I VLERES ---\n");
    printf("Vlera e num1 para ndryshimit = %d\n", *pNum1);

    *pNum1 = *pNum1 + 10;

    printf("Vlera e num1 pas ndryshimit = %d\n", *pNum1);

    // Kontrolli me if/else
    printf("\n--- ANALIZA PERFUNDIMTARE ---\n");
    if (*pNum1 > originalNum1) {
        printf("Vlera perfundimtare eshte rritur.\n");
    } else if (*pNum1 < originalNum1) {
        printf("Vlera perfundimtare eshte zvogeluar.\n");
    } else {
        printf("Vlera perfundimtare ka mbetur e njejte.\n");
    }

    // Kontroll shtese per interval
    if (*pNum1 >= 0 && *pNum1 <= 100) {
        printf("Vlera perfundimtare hyn ne intervalin [0, 100].\n");
    } else {
        printf("Vlera perfundimtare nuk hyn ne intervalin [0, 100].\n");
    }

    return 0;
}
