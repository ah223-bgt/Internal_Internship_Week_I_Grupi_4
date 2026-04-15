#include <stdio.h>

int main() {

    int a;
    float b;
    double c;
    char d;
    short e;
    long f;

    printf("Shkruaj nje int: ");
    scanf("%d", &a);

    printf("Shkruaj nje float: ");
    scanf("%f", &b);

    printf("Shkruaj nje double: ");
    scanf("%lf", &c);

    printf("Shkruaj nje karakter: ");
    scanf(" %c", &d);

    printf("Shkruaj short: ");
    scanf("%hd", &e);

    printf("Shkruaj long: ");
    scanf("%ld", &f);

    printf("\n--- Rezultati ---\n");
    printf("int: %d\n", a);
    printf("float: %f\n", b);
    printf("double: %f\n", c);
    printf("char: %c\n", d);
    printf("short: %hd\n", e);
    printf("long: %ld\n", f);

    if(a > 0) {
        printf("int eshte pozitiv\n");
    }
    else if(a < 0) {
        printf("int eshte negativ\n");
    }
    else {
        printf("int eshte zero\n");
    }

    switch(d) {
        case 'a':
        case 'A':
            printf("Karakteri eshte zanore A\n");
            break;

        case 'e':
        case 'E':
            printf("Karakteri eshte zanore E\n");
            break;

        case 'i':
        case 'I':
            printf("Karakteri eshte zanore I\n");
            break;

        case 'o':
        case 'O':
            printf("Karakteri eshte zanore O\n");
            break;

        case 'u':
        case 'U':
            printf("Karakteri eshte zanore U\n");
            break;

        default:
            printf("Karakteri nuk eshte zanore\n");
    }

    return 0;
}
