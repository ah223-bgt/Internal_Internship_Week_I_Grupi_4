#include <stdio.h>   // library for printf and scanf

int main() {         // start of the program
    int a;           // integer variable
    float b;         // float variable

    int *p1;         // pointer for integer
    float *p2;       // pointer for float

    int oldA;        // variable to store old integer value
    float oldB;      // variable to store old float value

    printf("Enter an integer value: ");   // asks user for integer
    scanf("%d", &a);                      // reads integer value

    printf("Enter a float value: ");      // asks user for float
    scanf("%f", &b);                      // reads float value

    p1 = &a;   // assigns address of a to pointer p1
    p2 = &b;   // assigns address of b to pointer p2

    oldA = a;  // saves original a
    oldB = b;  // saves original b

    printf("\n--- BEFORE CHANGE ---\n");   // title before change

    printf("Value of a: %d\n", a);                 // direct value of a
    printf("Address of a: %p\n", &a);              // memory address of a
    printf("Value of a using pointer: %d\n", *p1); // value through pointer

    printf("Value of b: %.2f\n", b);                 // direct value of b
    printf("Address of b: %p\n", &b);                // memory address of b
    printf("Value of b using pointer: %.2f\n", *p2); // value through pointer

    *p1 = *p1 + 5;    // changes integer value through pointer
    *p2 = *p2 + 2.5f; // changes float value through pointer

    printf("\n--- AFTER CHANGE ---\n");   // title after change
    printf("New value of a: %d\n", a);    // prints changed a
    printf("New value of b: %.2f\n", b);  // prints changed b

    if (a > oldA) {   // checks if integer increased
        printf("The integer value increased.\n");
    } else if (a < oldA) {   // checks if integer decreased
        printf("The integer value decreased.\n");
    } else {   // if unchanged
        printf("The integer value stayed the same.\n");
    }

    if (b > oldB) {   // checks if float increased
        printf("The float value increased.\n");
    } else if (b < oldB) {   // checks if float decreased
        printf("The float value decreased.\n");
    } else {   // if unchanged
        printf("The float value stayed the same.\n");
    }

    if (a >= 0 && a <= 20) {   // checks if final integer is inside range
        printf("Final integer value is inside the range 0 to 20.\n");
    } else {   // if outside range
        printf("Final integer value is outside the range 0 to 20.\n");
    }

    return 0;   // ends program successfully
}
