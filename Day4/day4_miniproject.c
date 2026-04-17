#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

int main() {
    int ids[MAX_RECORDS];
    char names[MAX_RECORDS][50];
    int scores[MAX_RECORDS];
    int currentCount = 0;
    int choice;

    while (1) {
        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentCount < MAX_RECORDS) {
                    printf("Enter ID: ");
                    scanf("%d", &ids[currentCount]);
                    printf("Enter Name: ");
                    scanf("%s", names[currentCount]);
                    printf("Enter Score: ");
                    scanf("%d", &scores[currentCount]);

                    currentCount++;
                    printf("Record added successfully!\n");
                } else {
                    printf("Error: Maximum limit of %d records reached!\n", MAX_RECORDS);
                }
                break;

            case 2:
                if (currentCount == 0) {
                    printf("No records found.\n");
                } else {
                    printf("\n--- Registered Records ---\n");
                    for (int i = 0; i < currentCount; i++) {
                        printf("Record %d - ID: %d | Name: %s | Score: %d\n", i + 1, ids[i], names[i], scores[i]);
                    }
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


