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
        printf("\n--- Professional Student Management System (vFinal) ---\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Analytical Report\n");
        printf("4. Update Score (Pointer)\n");
        printf("5. Search & Recommendations\n");
        printf("6. Sort Students by Score (Ranking)\n");
        printf("7. Edit or Delete Record\n");
        printf("8. Exit\n");
        printf("Select option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                if (currentCount < MAX_RECORDS) {
                    printf("ID: "); scanf("%d", &ids[currentCount]);
                    printf("Name: "); scanf("%s", names[currentCount]);
                    printf("Score (0-100): "); scanf("%d", &scores[currentCount]);
                    printf("Status (1-In Progress, 2-Completed, 3-Failed): ");
                    int s; scanf("%d", &s);
                    statuses[currentCount] = (enum Status)s;
                    currentCount++;
                } else printf("Limit reached!\n");
                break;

            case 2:
                for (int i = 0; i < currentCount; i++)
                    printf("ID: %d | Name: %s | Score: %d | Status: %d\n", ids[i], names[i], scores[i], statuses[i]);
                break;

            case 3:
                if (currentCount > 0) {
                    float total = 0;
                    for (int i = 0; i < currentCount; i++) total += scores[i];
                    printf("Total: %d | Average: %.2f\n", currentCount, total/currentCount);
                }
                break;

            case 4:
                if (currentCount > 0) {
                    int sId, newS;
                    printf("Enter ID to update: "); scanf("%d", &sId);
                    for (int i = 0; i < currentCount; i++) {
                        if (ids[i] == sId) {
                            printf("New Score: "); scanf("%d", &newS);
                            updateScore(&scores[i], newS);
                            break;
                        }
                    }
                }
                break;

            case 5:
                
                break;

            case 6: 
                if (currentCount > 1) {
                    for (int i = 0; i < currentCount - 1; i++) {
                        for (int j = 0; j < currentCount - i - 1; j++) {
                            if (scores[j] < scores[j + 1]) {
                              
                                int tempId = ids[j]; ids[j] = ids[j+1]; ids[j+1] = tempId;
                                int tempScore = scores[j]; scores[j] = scores[j+1]; scores[j+1] = tempScore;
                                char tempName[50]; strcpy(tempName, names[j]); strcpy(names[j], names[j+1]); strcpy(names[j+1], tempName);
                                enum Status tempStatus = statuses[j]; statuses[j] = statuses[j+1]; statuses[j+1] = tempStatus;
                            }
                        }
                    }
                    printf("Students ranked by score successfully!\n");
                }
                break;

            case 7: 
                if (currentCount > 0) {
                    int subChoice, sId, foundIndex = -1;
                    printf("1. Edit Record | 2. Delete Record: "); scanf("%d", &subChoice);
                    printf("Enter Student ID: "); scanf("%d", &sId);
                    for(int i=0; i<currentCount; i++) if(ids[i] == sId) foundIndex = i;

                    if (foundIndex != -1) {
                        if (subChoice == 1) { 
                            printf("New Name: "); scanf("%s", names[foundIndex]);
                            printf("New Score: "); scanf("%d", &scores[foundIndex]);
                        } else if (subChoice == 2) { 
                            for (int i = foundIndex; i < currentCount - 1; i++) {
                                ids[i] = ids[i + 1];
                                scores[i] = scores[i + 1];
                                statuses[i] = statuses[i + 1];
                                strcpy(names[i], names[i + 1]);
                            }
                            currentCount--;
                            printf("Record deleted.\n");
                        }
                    } else printf("Student not found.\n");
                }
                break;

            case 8: return 0;
        }
    }
}
