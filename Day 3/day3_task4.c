#include <stdio.h>

int main() {
    int num;
    double num2;

    int *p1;
    double *p2;

    printf("Shkruaj nje vlere int: ");
    scanf("%d", &num);

    printf("Shkruaj nje vlere double: ");
    scanf("%lf", &num2);

    // lidhja e pointerave me adresat
    p1 = &num;
    p2 = &num2;

    // shfaqja e vlerave dhe adresave
    printf("\n--- Vlerat Fillestare ---\n");
    printf("num (direkt): %d\n", num);
    printf("Adresa e num: %p\n", &num);
    printf("Vlera permes pointer p1: %d\n", *p1);

    printf("\nnum2 (direkt): %.2lf\n", num2);
    printf("Adresa e num2: %p\n", &num2);
    printf("Vlera permes pointer p2: %.2lf\n", *p2);

    // ruaj vlerat fillestare
    int old_num = num;
    double old_num2 = num2;

    // ndryshimi permes pointer-it
    *p1 = *p1 + 10;     // rritje
    *p2 = *p2 - 5.5;    // zvogelim

    // rezultatet pas ndryshimit
    printf("\n--- Pas Ndryshimit ---\n");
    printf("num para: %d, num pas: %d\n", old_num, num);
    printf("num2 para: %.2lf, num2 pas: %.2lf\n", old_num2, num2);

    // kontroll me if/else
    printf("\n--- Kontrolli ---\n");

    if (num > old_num) {
        printf("num eshte rritur.\n");
    } else if (num < old_num) {
        printf("num eshte zvogeluar.\n");
    } else {
        printf("num ka mbetur i njejte.\n");
    }

    if (num2 >= 0 && num2 <= 50) {
        printf("num2 eshte ne intervalin [0, 50].\n");
    } else {
        printf("num2 eshte jashte intervalit [0, 50].\n");
    }

    return 0;
}
