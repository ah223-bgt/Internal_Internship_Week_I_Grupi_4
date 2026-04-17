#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status { FAIL = 0, PASS = 1 };

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

struct Student students[MAX];
int count = 0;

// Add
void addStudent(struct Student *s) {
    printf("\nEnter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress: ");
    scanf("%f", &s->progress);

    if (s->progress >= 50)
        s->status = PASS;
    else
        s->status = FAIL;
}

// Show
void showStudents() {
    if (count == 0) {
        printf("\nNo records available.\n");
        return;
    }

    printf("\n===== STUDENTS =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | ID:%d | %.2f | %s\n",
               i + 1,
               students[i].name,
               students[i].id,
               students[i].progress,
               students[i].status == PASS ? "PASS" : "FAIL");
    }
}

// Update (Pointer)
void updateStudent(struct Student *s) {
    printf("\nCurrent Progress: %.2f\n", s->progress);
    printf("Enter new progress: ");
    scanf("%f", &s->progress);

    s->status = (s->progress >= 50) ? PASS : FAIL;
    printf("Updated successfully!\n");
}

// Search + logic
void searchStudent() {
    if (count == 0) {
        printf("\nNo records.\n");
        return;
    }

    int id, found = 0;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;

            printf("\nFOUND: %s | %.2f\n",
                   students[i].name,
                   students[i].progress);

            if (students[i].progress < 50)
                printf("WARNING: At risk!\n");
            else if (students[i].progress >= 85)
                printf("EXCELLENT!\n");
            else
                printf("GOOD.\n");
        }
    }

    if (!found)
        printf("Not found.\n");
}

// 🔥 TASK 6 – SORTING (Ranking)
void sortStudents() {
    if (count == 0) {
        printf("\nNo data to sort.\n");
        return;
    }

    // Bubble sort (descending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].progress < students[j + 1].progress) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n=== RANKING (Highest to Lowest) ===\n");
    showStudents();
}

// Report
void showReport() {
    if (count == 0) {
        printf("\nNo data.\n");
        return;
    }

    float total = 0, max = students[0].progress, min = students[0].progress;
    int pass = 0;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].status == PASS) pass++;

        if (students[i].progress > max) max = students[i].progress;
        if (students[i].progress < min) min = students[i].progress;
    }

    float avg = total / count;

    printf("\n===== REPORT =====\n");
    printf("Total: %d\n", count);
    printf("Passed: %d\n", pass);
    printf("Average: %.2f\n", avg);
    printf("Max: %.2f | Min: %.2f\n", max, min);
}

// MAIN
int main() {
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Add\n");
        printf("2. Show\n");
        printf("3. Update\n");
        printf("4. Search\n");
        printf("5. Report\n");
        printf("6. Ranking\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count < MAX) {
                    addStudent(&students[count]);
                    count++;
                } else {
                    printf("Limit reached!\n");
                }
                break;

            case 2:
                showStudents();
                break;

            case 3: {
                int id, found = 0;
                printf("Enter ID: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (students[i].id == id) {
                        updateStudent(&students[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) printf("Not found.\n");
                break;
            }

            case 4:
                searchStudent();
                break;

            case 5:
                showReport();
                break;

            case 6:
                sortStudents();
                break;

            case 7:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
