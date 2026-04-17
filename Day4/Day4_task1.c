#include <stdio.h>
#include <string.h>

#define MAX 5

enum Status {
    FAIL,
    PASS
};

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Array + count
struct Student students[MAX];
int count = 0;

// Shtim
void addStudent(struct Student *s) {
    printf("Enter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress: ");
    scanf("%f", &s->progress);

    if (s->progress >= 50) {
        s->status = PASS;
    } else {
        s->status = FAIL;
    }
}

// Shfaq të gjithë
void showStudents() {
    if (count == 0) {
        printf("No records.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        if (students[i].status == PASS) {
            printf("Status: PASS\n");
        } else {
            printf("Status: FAIL\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");
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

            case 3:
                printf("Exit...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
