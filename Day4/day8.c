#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM
enum Status { NOT_STARTED = 1, IN_PROGRESS, COMPLETED };

// STRUCT
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// ===== HELPER FUNCTIONS =====

// Shfaq status si tekst
void printStatus(enum Status st) {
    if (st == NOT_STARTED) printf("Not Started");
    else if (st == IN_PROGRESS) printf("In Progress");
    else if (st == COMPLETED) printf("Completed");
}

// Përditëso status automatik
void updateStatus(struct Student *s) {
    if (s->progress >= 100) s->status = COMPLETED;
    else if (s->progress >= 50) s->status = IN_PROGRESS;
    else s->status = NOT_STARTED;
}

// ===== CORE FUNCTIONS =====

// ADD
void addStudent(struct Student s[], int *count) {

    if (*count >= MAX) {
        printf("Lista eshte plot!\n");
        return;
    }

    printf("\n--- SHTO STUDENT ---\n");

    printf("ID: "); scanf("%d", &s[*count].id);
    printf("Emri: "); scanf("%s", s[*count].name);
    printf("Progresi: "); scanf("%f", &s[*count].progress);

    if (s[*count].progress < 0 || s[*count].progress > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    updateStatus(&s[*count]);
    (*count)++;

    printf("U shtua me sukses!\n");
}

// SHOW
void showStudents(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    printf("\n===== LISTA =====\n");

    for (int i = 0; i < count; i++) {
        printf("[%d] ID:%d | %-10s | %6.2f | ",
               i, s[i].id, s[i].name, s[i].progress);
        printStatus(s[i].status);
        printf("\n");
    }
}

// EDIT
void editStudent(struct Student s[], int count) {

    int id;
    printf("ID: "); scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (s[i].id == id) {

            printf("Emri i ri: ");
            scanf("%s", s[i].name);

            printf("Progresi i ri: ");
            scanf("%f", &s[i].progress);

            if (s[i].progress < 0 || s[i].progress > 100) {
                printf("Gabim!\n");
                return;
            }

            updateStatus(&s[i]);
            printf("U perditesua!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// DELETE
void deleteStudent(struct Student s[], int *count) {

    int id;
    printf("ID: "); scanf("%d", &id);

    for (int i = 0; i < *count; i++) {

        if (s[i].id == id) {

            for (int j = i; j < *count - 1; j++)
                s[j] = s[j + 1];

            (*count)--;

            printf("U fshi!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// SORT
void sortStudents(struct Student s[], int count) {

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (s[j].progress < s[j + 1].progress) {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }

    printf("U rendit!\n");
}

// REPORT
void report(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    float sum = 0, max = s[0].progress, min = s[0].progress;

    for (int i = 0; i < count; i++) {
        sum += s[i].progress;

        if (s[i].progress > max) max = s[i].progress;
        if (s[i].progress < min) min = s[i].progress;
    }

    float avg = sum / count;

    printf("\n===== RAPORT =====\n");
    printf("Total: %d\n", count);
    printf("Mesatarja: %.2f\n", avg);
    printf("Max: %.2f | Min: %.2f\n", max, min);

    if (avg >= 80) printf("Performanca: Shume e mire\n");
    else if (avg >= 50) printf("Performanca: Mesatare\n");
    else printf("Performanca: E ulet\n");
}

// ===== MAIN =====
int main() {

    struct Student students[MAX];
    int count = 0, choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto\n2. Shfaq\n3. Edit\n4. Delete\n5. Sort\n6. Raport\n7. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: editStudent(students, count); break;
            case 4: deleteStudent(students, &count); break;
            case 5: sortStudents(students, count); break;
            case 6: report(students, count); break;
            case 7: printf("Bye!\n"); break;
            default: printf("Gabim!\n");
        }

    } while (choice != 7);

    return 0;
}
