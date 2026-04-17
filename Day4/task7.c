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

    printf("ID: ");
    scanf("%d", &s[*count].id);

    printf("Emri: ");
    scanf("%s", s[*count].name);

    printf("Progresi: ");
    scanf("%f", &s[*count].progress);

    printf("Status (1-3): ");
    int st;
    scanf("%d", &st);

    if (st < 1 || st > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    s[*count].status = st;
    (*count)++;
}

// SHOW
void showStudents(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n[%d] ID: %d | %s | %.2f\n",
               i, s[i].id, s[i].name, s[i].progress);
    }
}

// 🔥 EDIT (ndryshon 2 fusha: name + progress)
void editStudent(struct Student s[], int count) {

    int id;
    printf("Shkruaj ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (s[i].id == id) {

            printf("Studenti u gjet!\n");

            printf("Emri i ri: ");
            scanf("%s", s[i].name);

            printf("Progresi i ri: ");
            scanf("%f", &s[i].progress);

            if (s[i].progress < 0 || s[i].progress > 100) {
                printf("Progres i pavlefshem!\n");
                return;
            }

            // update status automatik
            if (s[i].progress >= 100)
                s[i].status = COMPLETED;
            else if (s[i].progress >= 50)
                s[i].status = IN_PROGRESS;
            else
                s[i].status = NOT_STARTED;

            printf("U perditesua!\n");
            return;
        }
    }

    printf("Studenti nuk u gjet!\n");
}

// 🔥 DELETE (fshirje sipas ID)
void deleteStudent(struct Student s[], int *count) {

    int id;
    printf("Shkruaj ID per fshirje: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {

        if (s[i].id == id) {

            // zhvendos elementet majtas
            for (int j = i; j < *count - 1; j++) {
                s[j] = s[j + 1];
            }

            (*count)--; // zvogelo numrin

            printf("Studenti u fshi me sukses!\n");
            return;
        }
    }

    printf("Studenti nuk u gjet!\n");
}

// SORT
void sortStudents(struct Student s[], int count) {

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (s[j].progress < s[j + 1].progress) {

                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("U rendit!\n");
}

// MAIN
int main() {

    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto\n");
        printf("2. Shfaq\n");
        printf("3. Edit\n");
        printf("4. Delete\n");
        printf("5. Sort\n");
        printf("6. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: editStudent(students, count); break;
            case 4: deleteStudent(students, &count); break;
            case 5: sortStudents(students, count); break;
            case 6: printf("Bye!\n"); break;
            default: printf("Gabim!\n");
        }

    } while (choice != 6);

    return 0;
}
