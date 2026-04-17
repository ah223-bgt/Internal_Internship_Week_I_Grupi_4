#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM
enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

// STRUCT
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// ADD
void addStudent(struct Student s[], int *count) {

    if (*count >= MAX) {
        printf("Lista eshte plot!\n");
        return;
    }

    printf("\n--- SHTO STUDENT ---\n");

    printf("ID: ");
    scanf("%d", &s[*count].id);

    printf("Emri: ");
    scanf("%s", s[*count].name);

    printf("Progresi (0-100): ");
    scanf("%f", &s[*count].progress);

    if (s[*count].progress < 0 || s[*count].progress > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    printf("Status (1-Not Started, 2-In Progress, 3-Completed): ");
    int st;
    scanf("%d", &st);

    if (st < 1 || st > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    s[*count].status = st;
    (*count)++;

    printf("Studenti u shtua!\n");
}

// SHOW
void showStudents(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    printf("\n--- STUDENTET ---\n");

    for (int i = 0; i < count; i++) {

        printf("\nID: %d\n", s[i].id);
        printf("Emri: %s\n", s[i].name);
        printf("Progresi: %.2f\n", s[i].progress);

        switch (s[i].status) {
            case NOT_STARTED: printf("Status: Not Started\n"); break;
            case IN_PROGRESS: printf("Status: In Progress\n"); break;
            case COMPLETED: printf("Status: Completed\n"); break;
        }
    }
}

// POINTER UPDATE
void updateStudent(struct Student *s) {

    float add;
    printf("Sa ta rrisim progresin? ");
    scanf("%f", &add);

    s->progress += add;

    if (s->progress > 100) s->progress = 100;

    if (s->progress >= 100)
        s->status = COMPLETED;
    else if (s->progress >= 50)
        s->status = IN_PROGRESS;
}

// EDIT
void editStudent(struct Student s[], int count) {

    int id;
    printf("ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            updateStudent(&s[i]);
            printf("U perditesua!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// 🔥 SORT (RANKIM SIPAS PROGRESIT)
void sortStudents(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    // Bubble sort (descending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (s[j].progress < s[j + 1].progress) {

                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n--- RANKING (SIPAS PROGRESIT) ---\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i + 1, s[i].name, s[i].progress);
    }
}

// MAIN
int main() {

    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Update progres\n");
        printf("4. Ranking\n");
        printf("5. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: editStudent(students, count); break;
            case 4: sortStudents(students, count); break;
            case 5: printf("Programi u mbyll.\n"); break;
            default: printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 5);

    return 0;
}
