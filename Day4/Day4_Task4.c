#include <stdio.h>
#include <string.h>

#define MAX 5

// Enum për statusin
enum Status {
    FAIL = 0,
    PASS = 1
};

// Struktura e studentit
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Array + counter
struct Student students[MAX];
int count = 0;

// Shtimi i studentit
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

// Shfaqje
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

// 🔥 TASK 4 – POINTER FUNCTION (REAL UPDATE)
void updateStudent(struct Student *s) {
    printf("\n--- UPDATE STUDENT ---\n");

    printf("Current Progress: %.2f\n", s->progress);

    printf("Enter new progress: ");
    scanf("%f", &s->progress);

    // ndryshim real përmes pointer-it
    if (s->progress >= 50)
        s->status = PASS;
    else
        s->status = FAIL;

    printf("Student updated successfully!\n");
}

// Menu
int main() {
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Update Student (Pointer)\n");
        printf("4. Exit\n");
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
                        updateStudent(&students[i]); // 🔥 POINTER REAL USE
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found!\n");
                }

                break;
            }

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
