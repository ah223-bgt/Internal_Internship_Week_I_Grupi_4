#include <stdio.h>
#include <string.h>

#define MAX 5

// Enum për statusin
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

// Funksion për zgjedhjen e statusit (me validim + switch)
enum Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nChoose Status:\n");
        printf("0. FAIL\n");
        printf("1. PASS\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                return FAIL;
            case 1:
                return PASS;
            default:
                printf("Invalid status! Try again.\n");
        }
    }
}

// Funksion për shtim
void addStudent(struct Student *s) {
    printf("\nEnter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress: ");
    scanf("%f", &s->progress);

    // përdor enum nga zgjedhja e user-it
    s->status = chooseStatus();
}

// Shfaq studentët (me switch për enum)
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

        switch (students[i].status) {
            case PASS:
                printf("Status: PASS\n");
                break;
            case FAIL:
                printf("Status: FAIL\n");
                break;
            default:
                printf("Status: UNKNOWN\n");
        }
    }
}

// Validim për menu
int getMenuChoice() {
    int choice;

    printf("\n--- MENU ---\n");
    printf("1. Add Student\n");
    printf("2. Show Students\n");
    printf("3. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice! Try again.\n");
        return -1;
    }

    return choice;
}

int main() {
    int choice;

    do {
        choice = getMenuChoice();

        if (choice == -1) continue;

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
        }

    } while (choice != 3);

    return 0;
}
