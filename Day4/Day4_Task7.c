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

// ADD (për testim)
void addStudent(struct Student *s) {
    printf("\nEnter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress: ");
    scanf("%f", &s->progress);

    s->status = (s->progress >= 50) ? PASS : FAIL;
}

// SHOW
void showStudents() {
    if (count == 0) {
        printf("\nNo records.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n%d. ID:%d | %s | %.2f | %s\n",
               i + 1,
               students[i].id,
               students[i].name,
               students[i].progress,
               students[i].status == PASS ? "PASS" : "FAIL");
    }
}

// 🔥 EDIT (ndryshon 2 fusha)
void editStudent(struct Student *s) {
    printf("\n--- EDIT STUDENT ---\n");

    printf("Current Name: %s\n", s->name);
    printf("Enter new name: ");
    scanf("%s", s->name);

    printf("Current Progress: %.2f\n", s->progress);
    printf("Enter new progress: ");
    scanf("%f", &s->progress);

    // update status
    if (s->progress >= 50)
        s->status = PASS;
    else
        s->status = FAIL;

    printf("Student updated successfully!\n");
}

// 🔥 DELETE (zhvendosje në array)
void deleteStudent() {
    if (count == 0) {
        printf("\nNo records to delete.\n");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    int index = -1;

    // gjej studentin
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    // 🔥 zhvendos elementet majtas
    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--; // shumë e rëndësishme

    printf("Student deleted successfully!\n");
}

// MAIN (testim)
int main() {
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
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
                printf("Enter ID to edit: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (students[i].id == id) {
                        editStudent(&students[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("Exit...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
