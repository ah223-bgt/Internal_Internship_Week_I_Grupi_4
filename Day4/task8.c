#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[50];
    int progress;
    Status status;
} Student;

// ================= STATUS =================
void updateStatus(Student *s) {

    if (s->progress == 0)
        s->status = NOT_STARTED;
    else if (s->progress < 100)
        s->status = IN_PROGRESS;
    else
        s->status = COMPLETED;
}

void printStatus(Status s) {

    switch (s) {
        case NOT_STARTED: printf("Not Started"); break;
        case IN_PROGRESS: printf("In Progress"); break;
        case COMPLETED: printf("Completed"); break;
    }
}

// ================= PRINT =================
void printStudent(Student s) {

    printf("\n----------------------\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Progress: %d%%\n", s.progress);
    printf("Status: ");
    printStatus(s.status);
    printf("\n----------------------\n");
}

// ================= ADD =================
void addStudent(Student s[], int *count) {

    if (*count >= MAX_STUDENTS) {
        printf("List is full!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &s[*count].id);

    printf("Name: ");
    scanf("%s", s[*count].name);

    printf("Progress: ");
    scanf("%d", &s[*count].progress);

    if (s[*count].progress < 0 || s[*count].progress > 100) {
        printf("Invalid input!\n");
        return;
    }

    updateStatus(&s[*count]);

    (*count)++;
    printf("Student added!\n");
}

// ================= SHOW =================
void showStudents(Student s[], int count) {

    if (count == 0) {
        printf("No data.\n");
        return;
    }

    printf("\n===== STUDENTS =====\n");

    for (int i = 0; i < count; i++) {
        printStudent(s[i]);
    }
}

// ================= UPDATE (POINTER) =================
void updateStudentData(Student *s) {

    printf("New progress: ");
    scanf("%d", &s->progress);

    if (s->progress < 0 || s->progress > 100) {
        printf("Invalid!\n");
        return;
    }

    updateStatus(s);
    printf("Updated!\n");
}

// ================= DELETE =================
void deleteStudent(Student s[], int *count) {

    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (s[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Not found!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        s[i] = s[i + 1];
    }

    (*count)--;
    printf("Deleted!\n");
}

// ================= SEARCH =================
void searchStudent(Student s[], int count) {

    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (s[i].id == id) {

            printStudent(s[i]);

            if (s[i].progress < 30)
                printf("⚠ LOW PROGRESS\n");
            else if (s[i].progress < 70)
                printf("📌 NEEDS IMPROVEMENT\n");
            else
                printf("✅ GOOD PERFORMANCE\n");

            return;
        }
    }

    printf("Not found.\n");
}

// ================= REPORT =================
void report(Student s[], int count) {

    if (count == 0) {
        printf("No data.\n");
        return;
    }

    int sum = 0, completed = 0;
    int max = s[0].progress, min = s[0].progress;

    for (int i = 0; i < count; i++) {

        sum += s[i].progress;

        if (s[i].status == COMPLETED)
            completed++;

        if (s[i].progress > max) max = s[i].progress;
        if (s[i].progress < min) min = s[i].progress;
    }

    printf("\n===== REPORT =====\n");
    printf("Total: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Average: %.2f\n", (float)sum / count);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

// ================= RANKING =================
void sortStudents(Student s[], int count) {

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (s[j].progress < s[j + 1].progress) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n===== RANKING =====\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d%%\n", i + 1, s[i].name, s[i].progress);
    }
}

// ================= MAIN =================
int main() {

    Student s[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {

        printf("\n===== MENU =====\n");
        printf("1. Add\n");
        printf("2. Show\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Report\n");
        printf("7. Ranking\n");
        printf("8. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(s, &count);
                break;

            case 2:
                showStudents(s, count);
                break;

            case 3: {
                int id;
                printf("Enter ID: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (s[i].id == id) {
                        updateStudentData(&s[i]);
                        break;
                    }
                }
            } break;

            case 4:
                deleteStudent(s, &count);
                break;

            case 5:
                searchStudent(s, count);
                break;

            case 6:
                report(s, count);
                break;

            case 7:
                sortStudents(s, count);
                break;

            case 8:
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}
