#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

enum Status { IN_PROGRESS = 1, COMPLETED, FAILED };

int main() {
    int ids[MAX_RECORDS];
    char names[MAX_RECORDS][50];
    int scores[MAX_RECORDS];
    enum Status statuses[MAX_RECORDS];
    
    int currentCount = 0;
    int choice;

    while (1) {
        printf("\n--- Student Progress Tracker (v3) ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Generate Analytical Report\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                if (currentCount < MAX_RECORDS) {
                    printf("Enter ID: ");
                    scanf("%d", &ids[currentCount]);
                    printf("Enter Name: ");
                    scanf("%s", names[currentCount]);
                    printf("Enter Score (0-100): ");
                    scanf("%d", &scores[currentCount]);

                    int sChoice;
                    int validStatus = 0;
                    while (!validStatus) {
                        printf("Select Status (1-In Progress, 2-Completed, 3-Failed): ");
                        if (scanf("%d", &sChoice) == 1 && sChoice >= 1 && sChoice <= 3) {
                            statuses[currentCount] = (enum Status)sChoice;
                            validStatus = 1;
                        } else {
                            printf("Invalid status! Please choose 1, 2, or 3.\n");
                            while (getchar() != '\n');
                        }
                    }
                    currentCount++;
                } else {
                    printf("Error: Maximum limit reached!\n");
                }
                break;

            case 2:
                if (currentCount == 0) {
                    printf("No records found.\n");
                } else {
                    for (int i = 0; i < currentCount; i++) {
                        printf("ID: %d | Name: %s | Score: %d | Status: %d\n", 
                               ids[i], names[i], scores[i], statuses[i]);
                    }
                }
                break;

            case 3:
                if (currentCount == 0) {
                    printf("Report: No data available to analyze.\n");
                } else {
                    int completedCount = 0;
                    float totalScore = 0;
                    int highestScore = -1;

                    for (int i = 0; i < currentCount; i++) {
                        if (statuses[i] == COMPLETED) completedCount++;
                        totalScore += scores[i];
                        if (scores[i] > highestScore) highestScore = scores[i];
                    }

                    float average = totalScore / currentCount;

                    printf("\n--- Analytical Report ---\n");
                    printf("Total Students: %d\n", currentCount);
                    printf("Completed Tasks: %d\n", completedCount);
                    printf("Average Score: %.2f\n", average);
                    printf("Highest Score: %d\n", highestScore);

                    if (average >= 50) {
                        printf("Performance: Overall progress is Satisfactory.\n");
                    } else {
                        printf("Performance: Overall progress is Below Expectations.\n");
                    }
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}
