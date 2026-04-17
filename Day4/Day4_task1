#include <stdio.h>
#include <string.h>

#define MAX 5   // kapaciteti maksimal

// Enum për status
enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

// Struct për student
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Funksion për shtim
void addStudent(struct Student s[], int *count) {

    // Kontroll kapaciteti
    if (*count >= MAX) {
        printf("Nuk mund te shtosh me shume! Lista eshte plot (%d).\n", MAX);
        return;
    }

    printf("\n--- Shto Student ---\n");

    printf("ID: ");
    scanf("%d", &s[*count].id);

    printf("Emri: ");
    scanf("%s", s[*count].name);

    printf("Progresi (0-100): ");
    scanf("%f", &s[*count].progress);

    // Validim progresi
    if (s[*count].progress < 0 || s[*count].progress > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    printf("Status (1-Not Started, 2-In Progress, 3-Completed): ");
    int st;
    scanf("%d", &st);

    // Validim statusi
    if (st < 1 || st > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    s[*count].status = st;

    (*count)++; // rrit numrin aktual

    printf("Studenti u shtua me sukses!\n");
}

// Funksion për shfaqje të gjitha
void showStudents(struct Student s[], int count) {

    if (count == 0) {
        printf("Nuk ka regjistrime!\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {

        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", s[i].id);
        printf("Emri: %s\n", s[i].name);
        printf("Progresi: %.2f\n", s[i].progress);

        switch (s[i].status) {
            case NOT_STARTED:
                printf("Status: Not Started\n");
                break;
            case IN_PROGRESS:
                printf("Status: In Progress\n");
                break;
            case COMPLETED:
                printf("Status: Completed\n");
                break;
            default:
                printf("Status: Unknown\n");
        }
    }

    printf("\nTotali i regjistrimeve: %d / %d\n", count, MAX);
}

int main() {

    struct Student students[MAX]; // array për shumë regjistrime
    int count = 0;               // sa janë aktualisht
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(students, &count);
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                printf("Programi u mbyll.\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 3);

    return 0;
}
