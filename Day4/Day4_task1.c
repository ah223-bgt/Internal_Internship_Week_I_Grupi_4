#include <stdio.h>
#include <string.h>

#define MAX 5

// Enum për statusin
enum Status {
    FAIL,
    PASS
};

// Struktura e studentit
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Array për ruajtjen e studentëve
struct Student students[MAX];
int count = 0;

// Funksion për shtimin e një studenti (me pointer)
void addStudent(struct Student *s) {
    printf("\nEnter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress: ");
    scanf("%f", &s->progress);

    // Vendos statusin bazuar në progres
    if (s->progress >= 50) {
        s->status = PASS;
    } else {
        s->status = FAIL;
    }
}

// Funksion për shfaqjen e të gjithë studentëve
void showStudents() {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

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

// Funksioni kryesor
int main() {
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                // Kontrollo nëse ka vend në array
                if (count < MAX) {
                    addStudent(&students[count]); // pointer përdoret këtu
                    count++;
                    printf("\nStudent added successfully!\n");
                } else {
                    printf("\nMaximum limit reached! Cannot add more students.\n");
                }
                break;

            case 2:
                showStudents();
                break;

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
