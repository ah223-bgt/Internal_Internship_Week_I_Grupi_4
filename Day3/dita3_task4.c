#include <stdio.h>

int main() {
    int score = 75;
    double bonus = 5.5;
    
    int *pScore = &score;
    double *pBonus = &bonus;
    
    printf("Initial score: %d\n", score);
    printf("Address of score: %p\n", (void*)pScore);
    printf("Value via pointer: %d\n", *pScore);
    
    int originalScore = score;
    
    *pScore = 90;
    
    printf("\nUpdated score: %d\n", score);
    printf("Updated value via pointer: %d\n", *pScore);
    
    if (*pScore > originalScore) {
        printf("Status: Value has increased.\n");
    } else if (*pScore < originalScore) {
        printf("Status: Value has decreased.\n");
    } else {
        printf("Status: No change in value.\n");
    }
    
    return 0;
}
