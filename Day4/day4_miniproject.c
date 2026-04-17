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
        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
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
                    printf("Record added successfully!\n");
                } else {
                    printf("Error: Maximum limit reached (%d records).\n", MAX_RECORDS);
                }
                break;

            case 2:
                if (currentCount == 0) {
                    printf("No records found.\n");
                } else {
                    printf("\n--- Registered Students ---\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("ID: %d | Name: %s | Score: %d | Status: ", 
                               ids[i], names[i], scores[i]);
                        
                        switch (statuses[i]) {
                            case IN_PROGRESS: printf("In Progress\n"); break;
                            case COMPLETED: printf("Completed\n"); break;
                            case FAILED: printf("Failed\n"); break;
                        }
                    }
                }
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Option %d is invalid. Please try again.\n", choice);
        }
    }
    return 0;
}
