#include <stdio.h>
#include <string.h>

#define MAX 5

// Enum
enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

// Struct
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Shto student
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

    printf("Status (1-Not Started, 2-In Progress, 3-Completed): ");
    int st;
    scanf("%d", &st);

    if (st < 1 || st > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    s[*count].status = st;
    (*count)++;

    printf("U shtua me sukses!\n");
}

// Shfaq
void showStudents(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

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

// 🔥 SEARCH + FILTER
void searchStudent(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    int choice;
    printf("\nKërko sipas:\n1 - ID\n2 - Emër\nZgjedhja: ");
    scanf("%d", &choice);

    int found = 0;

    if (choice == 1) {

        int id;
        printf("Shkruaj ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {

            if (s[i].id == id) {
                found = 1;

                printf("\n--- REZULTATI U GJET ---\n");
                printf("ID: %d\n", s[i].id);
                printf("Emri: %s\n", s[i].name);
                printf("Progresi: %.2f\n", s[i].progress);

                // 🔥 logjikë paralajmëruese
                if (s[i].progress < 30) {
                    printf("PARALAJMERIM: Progres shume i ulet!\n");
                } else if (s[i].progress < 70) {
                    printf("REKOMANDIM: Vazhdo punen rregullisht.\n");
                } else {
                    printf("SHUME MIRE: Performancë e lartë.\n");
                }
            }
        }

    } else if (choice == 2) {

        char name[50];
        printf("Shkruaj emrin: ");
        scanf("%s", name);

        for (int i = 0; i < count; i++) {

            if (strcmp(s[i].name, name) == 0) {
                found = 1;

                printf("\n--- REZULTATI U GJET ---\n");
                printf("ID: %d\n", s[i].id);
                printf("Emri: %s\n", s[i].name);
                printf("Progresi: %.2f\n", s[i].progress);

                // logjikë paralajmëruese
                if (s[i].progress < 30) {
                    printf("PARALAJMERIM: Duhet permiresim i madh!\n");
                } else if (s[i].progress < 70) {
                    printf("REKOMANDIM: Je ne rruge te mire.\n");
                } else {
                    printf("SHUME MIRE: Nivel i larte.\n");
                }
            }
        }

    } else {
        printf("Zgjedhje e pavlefshme!\n");
        return;
    }

    if (!found) {
        printf("Asnje rezultat nuk u gjet!\n");
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
        printf("3. Kërko student\n");
        printf("4. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: printf("Programi u mbyll.\n"); break;
            default: printf("Gabim!\n");
        }

    } while (choice != 4);

    return 0;
}
