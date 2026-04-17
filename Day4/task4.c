#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
} Status;

typedef struct {
    int id;
    char name[50];
    int progress;
    Status status;
} Student;

// ================= STATUS =================
void printStatus(Status s) {
    switch (s) {
        case NOT_STARTED: printf("Not Started"); break;
        case IN_PROGRESS: printf("In Progress"); break;
        case COMPLETED: printf("Completed"); break;
    }
}

// ================= ADD =================
void addStudent(Student s[], int *count) {

    if (*count >= MAX_STUDENTS) {
        printf("List is full!\n");
        return;
    }

    printf("\nID: ");
    scanf("%d", &s[*count].id);

    printf("Name: ");
    scanf("%s", s[*count].name);

    printf("Progress (0-100): ");
    scanf("%d", &s[*count].progress);

    if (s[*count].progress < 0 || s[*count].progress > 100) {
        printf("Invalid progress!\n");
        return;
    }

    // status automatik
    if (s[*count].progress == 0)
        s[*count].status = NOT_STARTED;
    else if (s[*count].progress < 100)
        s[*count].status = IN_PROGRESS;
    else
        s[*count].status = COMPLETED;

    (*count)++;
    printf("Student added!\n");
}

// ================= SHOW =================
void showStudents(Student s[], int count) {

    if (count == 0) {
        printf("No data.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d | Name: %s | Progress: %d%% | ",
               s[i].id, s[i].name, s[i].progress);
        printStatus(s[i].status);
    }
    printf("\n");
}

// ================= POINTER FUNCTION =================
void updateStudent(Student *st) {

    printf("\nUpdating: %s\n", st->name);

    printf("Enter new progress: ");
    scanf("%d", &st->progress);

    if (st->progress < 0 || st->progress > 100) {
        printf("Invalid!\n");
        return;
    }

    // ndryshon direkt (pointer)
    if (st->progress == 0)
        st->status = NOT_STARTED;
    else if (st->progress < 100)
        st->status = IN_PROGRESS;
    else
        st->status = COMPLETED;

    printf("Updated successfully!\n");
}

// ================= UPDATE BY ID =================
void updateByID(Student s[], int count) {

    if (count == 0) {
        printf("No data.\n");
        return;
    }

    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < count; i++) {

        if (s[i].id == id) {
            found = 1;

            //  POINTER përdoret këtu
            updateStudent(&s[i]);

            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// ================= MAIN =================
int main() {

    Student s[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {

        printf("\n--- MENU ---\n");
        printf("1. Add\n");
        printf("2. Show\n");
        printf("3. Update (Pointer)\n");
        printf("4. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(s, &count);
                break;

            case 2:
                showStudents(s, count);
                break;

            case 3:
                updateByID(s, count);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}
