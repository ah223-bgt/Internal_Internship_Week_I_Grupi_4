#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

enum Status { IN_PROGRESS = 1, COMPLETED, FAILED };

void updateScore(int *scorePtr, int newScore) {
    *scorePtr = newScore;
}

int main() {
    int ids[MAX_RECORDS];
    char names[MAX_RECORDS][50];
    int scores[MAX_RECORDS];
    enum Status statuses[MAX_RECORDS];
    int currentCount = 0;
    int choice;

    while (1) {
        printf("\n--- Student Progress Tracker (Full Version) ---\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Analytical Report\n");
        printf("4. Update Score (Pointer)\n");
        printf("5. Search & Recommendations\n");
        printf("6. Exit\n");
        printf("Select option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: // Task 1 & 2: Shtimi me validim dhe enum
                if (currentCount < MAX_RECORDS) {
                    printf("ID: "); scanf("%d", &ids[currentCount]);
                    printf("Name: "); scanf("%s", names[currentCount]);
                    printf("Score (0-100): "); scanf("%d", &scores[currentCount]);
                    
                    int sChoice;
                    printf("Status (1-In Progress, 2-Completed, 3-Failed): ");
                    scanf("%d", &sChoice);
                    statuses[currentCount] = (enum Status)sChoice;
                    
                    currentCount++;
                    printf("Added successfully!\n");
                } else printf("Error: Limit reached! [cite: 32]\n");
                break;

            case 2: // Task 1: Shfaqja e listës
                if (currentCount == 0) printf("No records.\n");
                for (int i = 0; i < currentCount; i++)
                    printf("ID: %d | Name: %s | Score: %d | Status: %d\n", ids[i], names[i], scores[i], statuses[i]);
                break;

            case 3: // Task 3: Raporti Analitik
                if (currentCount > 0) {
                    float total = 0;
                    for (int i = 0; i < currentCount; i++) total += scores[i];
                    printf("\n--- Report ---\nTotal: %d | Average: %.2f\n", currentCount, total/currentCount);
                } else printf("No data for analysis.\n");
                break;

            case 4: // Task 4: Modifikimi me Pointer
                if (currentCount > 0) {
                    int sId, newS;
                    printf("Enter ID to update: "); scanf("%d", &sId);
                    for (int i = 0; i < currentCount; i++) {
                        if (ids[i] == sId) {
                            printf("New Score: "); scanf("%d", &newS);
                            updateScore(&scores[i], newS);
                            printf("Updated!\n");
                            break;
                        }
                    }
                }
                break;

            case 5: // Task 5: Kërkimi dhe Rekomandimet inteligjente
                if (currentCount == 0) {
                    printf("No records found to search. \n");
                } else {
                    int searchId, found = 0;
                    printf("Search by ID: "); scanf("%d", &searchId);
                    for (int i = 0; i < currentCount; i++) {
                        if (ids[i] == searchId) {
                            found = 1;
                            printf("\nResult: ID: %d | Name: %s | Score: %d\n", ids[i], names[i], scores[i]);
                            
                            // Logjikë rekomanduese e kombinuar 
                            if (scores[i] < 50 && statuses[i] != COMPLETED) {
                                printf("Recommendation: High Alert! Immediate tutoring required.\n");
                            } else if (scores[i] >= 50 && statuses[i] == IN_PROGRESS) {
                                printf("Recommendation: Good pace. Keep working to finish the course.\n");
                            } else if (statuses[i] == COMPLETED) {
                                printf("Recommendation: Excellent! Ready for the next level.\n");
                            }
                            break;
                        }
                    }
                    if (!found) printf("No student found with ID %d. \n", searchId);
                }
                break;

            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
