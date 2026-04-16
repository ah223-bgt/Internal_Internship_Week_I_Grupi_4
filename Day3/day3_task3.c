#include <stdio.h>

int main() {
    int start, end, i;
    int count3 = 0, count5 = 0;
    long sum3 = 0, sum5 = 0;

    printf("Enter the starting value: ");
    scanf("%d", &start);
    printf("Enter the ending value: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid input! Starting value must be less than or equal to ending value.\n");
        return 0;
    }

    for (i = start; i <= end; i++) {
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        } else if (i % 5 == 0) {
            count5++;
            sum5 += i;
        }
    }

    printf("\n--- Comparison Results ---\n");
    printf("Numbers divisible by 3: Count = %d, Sum = %ld\n", count3, sum3);
    printf("Numbers divisible by 5 (but not 3): Count = %d, Sum = %ld\n", count5, sum5);

    if (sum3 > sum5) {
        printf("The sum of numbers divisible by 3 is larger.\n");
    } else if (sum5 > sum3) {
        printf("The sum of numbers divisible by 5 is larger.\n");
    } else {
        printf("Both sums are equal.\n");
    }

    return 0;
}
