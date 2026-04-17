#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status {
    FAIL = 0,
    PASS = 1
};

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

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        if (students[i].status == PASS)
            printf("Status: PASS\n");
        else
            printf("Status: FAIL\n");
    }
}

// Update (Task 4)
void updateStudent(struct Student *s) {
    printf("\nCurrent Progress: %.2f\n", s->progress);

    printf("Enter new progress: ");
    scanf("%f", &s->progress);

    if (s->progress >= 50)
        s->status = PASS;
    else
        s->status = FAIL;

    printf("Student updated!\n");
}

// 🔍 TASK 5 – SEARCH + WARNING
void searchStudent() {
    if (count == 0) {
        printf("\nNo records to search.\n");
        return;
    }

    int option;
    printf("\nSearch by:\n1. ID\n2. Name\nChoice: ");
    scanf("%d", &option);

    int found = 0;

    if (option == 1) {
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                found = 1;

                printf("\n--- FOUND ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);

                // LOGJIKË E ZGJUAR
                if (students[i].progress < 50 && students[i].status == FAIL) {
                    printf("WARNING: At risk of failing!\n");
                }
                else if (students[i].progress >= 85 && students[i].status == PASS) {
                    printf("EXCELLENT: Outstanding performance!\n");
                }
                else if (students[i].progress >= 50 && students[i].progress < 85) {
                    printf("INFO: Stable performance.\n");
                }
                else {
                    printf("NOTE: Check student data.\n");
                }
            }
        }
    }

    else if (option == 2) {
        char name[50];
        printf("Enter Name: ");
        scanf("%s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                found = 1;

                printf("\n--- FOUND ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);

                // LOGJIKË E ZGJUAR
                if (students[i].progress < 40) {
                    printf("CRITICAL: Immediate improvement needed!\n");
                }
                else if (students[i].progress >= 80) {
                    printf("GREAT: Strong performance!\n");
                }
                else {
                    printf("AVERAGE: Keep working.\n");
                }
            }
        }
    }

    else {
        printf("Invalid search option!\n");
        return;
    }

    if (!found) {
        printf("\nNo matching student found.\n");
    }
}

// MAIN
int main() {
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count < MAX) {
                    addStudent(&students[count]);
                    count++;
                } else {
                    printf("Maximum limit reached!\n");
                }
                break;

            case 2:
                showStudents();
                break;

            case 3: {
                if (count == 0) {
                    printf("No students to update.\n");
                    break;
                }

                int id, found = 0;
                printf("Enter ID to update: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (students[i].id == id) {
                        updateStudent(&students[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4:
                searchStudent();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
