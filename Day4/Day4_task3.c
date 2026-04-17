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

// Array + count
struct Student students[MAX];
int count = 0;

// Zgjedh statusin (Task 2)
enum Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nChoose Status:\n");
        printf("0. FAIL\n");
        printf("1. PASS\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: return FAIL;
            case 1: return PASS;
            default:
                printf("Invalid status! Try again.\n");
        }
    }
}

// Shtimi i studentit (Task 1 + pointer)
void addStudent(struct Student *s) {
    printf("\nEnter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress: ");
    scanf("%f", &s->progress);

    s->status = chooseStatus();
}

// Shfaq studentët (Task 1)
void showStudents() {
    if (count == 0) {
        printf("\nNo records available.\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

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

// Raporti analitik (Task 3)
void showReport() {
    if (count == 0) {
        printf("\nNo data available for report.\n");
        return;
    }

    int passCount = 0, failCount = 0;
    float total = 0;
    float max = students[0].progress;
    float min = students[0].progress;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].status == PASS)
            passCount++;
        else
            failCount++;

        if (students[i].progress > max)
            max = students[i].progress;

        if (students[i].progress < min)
            min = students[i].progress;
    }

    float avg = total / count;

    printf("\n===== REPORT =====\n");
    printf("Total Students: %d\n", count);
    printf("Passed: %d\n", passCount);
    printf("Failed: %d\n", failCount);
    printf("Average Progress: %.2f\n", avg);
    printf("Highest Progress: %.2f\n", max);
    printf("Lowest Progress: %.2f\n", min);

    // klasifikim me if/else
    if (avg >= 75)
        printf("Overall Performance: Excellent\n");
    else if (avg >= 50)
        printf("Overall Performance: Average\n");
    else
        printf("Overall Performance: Needs Improvement\n");
}

// Validim menu (Task 2)
int getMenuChoice() {
    int choice;

    printf("\n====== MENU ======\n");
    printf("1. Add Student\n");
    printf("2. Show Students\n");
    printf("3. Show Report\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice! Try again.\n");
        return -1;
    }

    return choice;
}

// Main
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
                    printf("\nStudent added successfully!\n");
                } else {
                    printf("\nMaximum limit reached!\n");
                }
                break;

            case 2:
                showStudents();
                break;

            case 3:
                showReport();
                break;

            case 4:
                printf("\nExiting program...\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
