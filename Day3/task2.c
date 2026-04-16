#include <stdio.h>   // for printf and scanf

int main() {         // start of the program

    int fillimi, fundi;   // variables for the start and end of the interval
    int countCift = 0;    // counter for even numbers
    int countTek = 0;     // counter for odd numbers
    int shumaCift = 0;    // sum of even numbers
    int shumaTek = 0;     // sum of odd numbers
    int total;            // total amount of values in the interval

    printf("Shkruaj vleren fillestare: ");   // asks for the starting value
    scanf("%d", &fillimi);                   // reads the starting value

    printf("Shkruaj vleren perfundimtare: "); // asks for the ending value
    scanf("%d", &fundi);                      // reads the ending value

    // checks if the interval is valid
    if (fillimi > fundi) {
        printf("Interval i pavlefshem\n");   // prints error message
        return 0;                            // stops the program
    }

    // loop through the interval
    for (int i = fillimi; i <= fundi; i++) {

        if (i % 2 == 0) {        // if the number is even
            countCift++;         // increases the even counter
            shumaCift += i;      // adds the number to the even sum
        } else {                 // if the number is odd
            countTek++;          // increases the odd counter
            shumaTek += i;       // adds the number to the odd sum
        }
    }

    total = fundi - fillimi + 1;   // calculates total numbers in the interval

    printf("\n--- REZULTATI ---\n");                 // title
    printf("Intervali: %d deri %d\n", fillimi, fundi); // prints the interval
    printf("Totali i vlerave: %d\n", total);        // prints total values
    printf("Numra cift: %d\n", countCift);          // prints count of even numbers
    printf("Numra tek: %d\n", countTek);            // prints count of odd numbers
    printf("Shuma e numrave cift: %d\n", shumaCift); // prints sum of even numbers
    printf("Shuma e numrave tek: %d\n", shumaTek);   // prints sum of odd numbers

    // checks which category has more numbers
    if (countCift > countTek) {
        printf("Ka me shume numra cift\n");
    } else if (countTek > countCift) {
        printf("Ka me shume numra tek\n");
    } else {
        printf("Numri i numrave cift dhe tek eshte i barabarte\n");
    }

    return 0;   // ends the program successfully
}
