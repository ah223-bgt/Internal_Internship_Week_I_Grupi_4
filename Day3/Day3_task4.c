#include <stdio.h>

int main() {
    int num;
    float value;

    // Pointers
    int *pNum;
    float *pValue;

    // Input
    printf("Shkruaj nje numer int: ");
    scanf("%d", &num);

    printf("Shkruaj nje numer float: ");
    scanf("%f", &value);

    // Marrja e adresave
    pNum = &num;
    pValue = &value;

    // Shfaqja e vlerave dhe adresave
    printf("\n--- VLERA FILLESTARE ---\n");
    printf("num = %d\n", num);
    printf("Adresa e num: %p\n", &num);
    printf("Vlera nga pointer pNum: %d\n", *pNum);

    printf("\nvalue = %.2f\n", value);
    printf("Adresa e value: %p\n", &value);
    printf("Vlera nga pointer pValue: %.2f\n", *pValue);

    // Ruajmë vlerën para ndryshimit
    int oldNum = num;

    // Ndryshimi përmes pointer-it
    *pNum = *pNum + 10;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("Vlera e re e num: %d\n", num);

    // Kontrolli me if/else
    if (num > oldNum) {
        printf("Numri eshte rritur.\n");
    } else if (num < oldNum) {
        printf("Numri eshte zvogeluar.\n");
    } else {
        printf("Numri ka mbetur i njejte.\n");
    }

    // Kontroll shtese intervali
    if (num >= 0 && num <= 50) {
        printf("Numri eshte ne intervalin [0, 50].\n");
    } else {
        printf("Numri eshte jashte intervalit [0, 50].\n");
    }

    return 0;
}
