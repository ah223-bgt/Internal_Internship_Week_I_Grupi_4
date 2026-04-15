#include <stdio.h>

int main() {
    int score;

    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Invalid input! Please enter a score between 0 and 100.\n");
    } 
    else if (score >= 90) {
        printf("Excellent (Shkelqyeshem)\n");
    } 
    else if (score >= 80) {
        printf("Very Good (Shume mire)\n");
    } 
    else if (score >= 70) {
        printf("Good (Mire)\n");
    } 
    else {
        printf("Needs Improvement (Nevojitet permiresim)\n");
    }

    return 0;
}
