#include <stdio.h>

int main() {
    int start, end, i;
    int evenCount = 0, oddCount = 0;
    long evenSum = 0, oddSum = 0;

    printf("Enter the starting value of the range: ");
    scanf("%d", &start);
    printf("Enter the ending value of the range: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval! The starting value must be less than or equal to the ending value.\n");
        return 0;
    }

    for (i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    printf("\n--- Range Analysis Results ---\n");
    printf("Interval: [%d, %d]\n", start, end);
    printf("Total numbers analyzed: %d\n", (end - start + 1));
    printf("Even numbers: %d (Sum: %ld)\n", evenCount, evenSum);
    printf("Odd numbers: %d (Sum: %ld)\n", oddCount, oddSum);

    if (evenCount > oddCount) {
        printf("Category with more numbers: Even\n");
    } else if (oddCount > evenCount) {
        printf("Category with more numbers: Odd\n");
    } else {
        printf("Both categories have the same amount of numbers.\n");
    }

    return 0;
}
