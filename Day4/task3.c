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

// Shtim studenti
void addStudent(struct Student s[], int *count) {

    if (*count >= MAX) {
        printf("Lista eshte plot!\n");
        return;
    }

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

    printf("U shtua me sukses!\n");
}

// Shfaqje
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

// 🔥 FUNKSIONI I RI – RAPORT ANALITIK
void report(struct Student s[], int count) {

    if (count == 0) {
        printf("\nNuk ka te dhena per raport!\n");
        return;
    }

    int completedCount = 0;
    float sum = 0;
    float max = s[0].progress;
    float min = s[0].progress;

    for (int i = 0; i < count; i++) {

        sum += s[i].progress;

        if (s[i].status == COMPLETED) {
            completedCount++;
        }

        if (s[i].progress > max) {
            max = s[i].progress;
        }

        if (s[i].progress < min) {
            min = s[i].progress;
        }
    }

    float avg = sum / count;

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Totali i studenteve: %d\n", count);
    printf("Te perfunduar: %d\n", completedCount);
    printf("Mesatarja e progresit: %.2f\n", avg);
    printf("Progresi maksimal: %.2f\n", max);
    printf("Progresi minimal: %.2f\n", min);

    // Klasifikim me if/else
    if (avg >= 80) {
        printf("Performanca eshte shume e mire.\n");
    } else if (avg >= 50) {
        printf("Performanca eshte mesatare.\n");
    } else {
        printf("Performanca eshte e ulet.\n");
    }
}

int main() {

    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Raport analitik\n");
        printf("4. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: report(students, count); break;
            case 4: printf("Programi u mbyll.\n"); break;
            default: printf("Gabim!\n");
        }

    } while (choice != 4);

    return 0;
}
