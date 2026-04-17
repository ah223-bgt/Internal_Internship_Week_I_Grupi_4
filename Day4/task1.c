#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5   // kapaciteti maksimal i regjistrimeve

// enum për statusin e progresit
enum Status {
    NEEDS_IMPROVEMENT,
    IN_PROGRESS,
    COMPLETED
};

// struktura për një student
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// funksion për të llogaritur statusin me pointer
void calculateStatus(struct Student *s) {
    if (s->progress < 50) {
        s->status = NEEDS_IMPROVEMENT;
    } else if (s->progress < 80) {
        s->status = IN_PROGRESS;
    } else {
        s->status = COMPLETED;
    }
}

// funksion për të printuar statusin si tekst
void printStatus(enum Status status) {
    switch (status) {
        case NEEDS_IMPROVEMENT:
            printf("Needs Improvement");
            break;
        case IN_PROGRESS:
            printf("In Progress");
            break;
        case COMPLETED:
            printf("Completed");
            break;
        default:
            printf("Unknown");
    }
}

// funksion për të shtuar një regjistrim të ri
void addStudent(struct Student students[], int *count) {
    // kontrollon nëse është arritur kufiri maksimal
    if (*count >= MAX_STUDENTS) {
        printf("Lista eshte plote. Nuk mund te shtohen me shume regjistrime.\n");
        return;
    }

    printf("\n--- SHTO REGJISTRIM TE RI ---\n");

    printf("Shkruaj ID: ");
    scanf("%d", &students[*count].id);

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Shkruaj progresin (0-100): ");
    scanf("%f", &students[*count].progress);

    // validim i progresit
    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Progres i pavlefshem. Regjistrimi nuk u shtua.\n");
        return;
    }

    // llogarit statusin
    calculateStatus(&students[*count]);

    // rrit numrin aktual të regjistrimeve
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    printf("Regjistrime aktuale: %d / %d\n", *count, MAX_STUDENTS);
}

// funksion për të shfaqur të gjitha regjistrimet
void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("Nuk ka regjistrime te ruajtura.\n");
        return;
    }

    printf("\n--- TE GJITHA REGJISTRIMET ---\n");

    for (int i = 0; i < count; i++) {
        printf("Regjistrimi #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);
        printf("Status: ");
        printStatus(students[i].status);
        printf("\n-----------------------------\n");
    }

    printf("Numri aktual i regjistrimeve: %d\n", count);
    printf("Kapaciteti maksimal: %d\n", MAX_STUDENTS);
}

// funksioni kryesor
int main() {
    struct Student students[MAX_STUDENTS];   // array me madhësi fikse
    int count = 0;                           // numri aktual i regjistrimeve
    int choice;                              // zgjedhja e menusë

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Add student record\n");
        printf("2. Show all records\n");
        printf("3. Exit\n");
        printf("Zgjedh nje opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                printf("Programi po mbyllet.\n");
                break;
            default:
                printf("Zgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 3);

    return 0;
}
