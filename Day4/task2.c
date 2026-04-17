#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5   // kufiri maksimal i regjistrimeve

// enum për statusin
enum Status {
    NEEDS_IMPROVEMENT = 1,   // 1
    IN_PROGRESS,             // 2
    COMPLETED                // 3
};

// struktura për student
struct Student {
    int id;                  // ID
    char name[50];           // emri
    float progress;          // progresi
    enum Status status;      // statusi me enum
};

// funksion për të printuar statusin
void printStatus(enum Status status) {
    switch (status) {   // përdorim switch për enum
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

// funksion për të zgjedhur statusin nga përdoruesi
enum Status chooseStatus() {
    int choice;

    printf("Zgjedh statusin:\n");
    printf("1 - Needs Improvement\n");
    printf("2 - In Progress\n");
    printf("3 - Completed\n");

    scanf("%d", &choice);

    // validim i input-it për status
    switch (choice) {
        case 1:
            return NEEDS_IMPROVEMENT;
        case 2:
            return IN_PROGRESS;
        case 3:
            return COMPLETED;
        default:
            printf("Zgjedhje e pavlefshme! Statusi u vendos default.\n");
            return NEEDS_IMPROVEMENT;
    }
}

// funksion për të shtuar student
void addStudent(struct Student students[], int *count) {

    if (*count >= MAX_STUDENTS) {   // kontroll i kapacitetit
        printf("Lista eshte plote!\n");
        return;
    }

    printf("\n--- SHTO STUDENT ---\n");

    printf("Shkruaj ID: ");
    scanf("%d", &students[*count].id);

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Shkruaj progresin (0-100): ");
    scanf("%f", &students[*count].progress);

    // validim për progres
    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    // përdorim enum për status
    students[*count].status = chooseStatus();

    (*count)++;   // rrit numrin e regjistrimeve

    printf("Studenti u shtua me sukses!\n");
}

// funksion për të shfaqur studentët
void showStudents(struct Student students[], int count) {

    if (count == 0) {   // nëse nuk ka regjistrime
        printf("Nuk ka student!\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {   // loop për të gjithë studentët
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        printf("Status: ");
        printStatus(students[i].status);   // printon enum-in
        printf("\n-------------------\n");
    }
}

// MAIN
int main() {
    struct Student students[MAX_STUDENTS];   // array
    int count = 0;                           // numri aktual
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");

        printf("Zgjedh nje opcion: ");
        scanf("%d", &choice);

        // validim i menusë
        if (choice < 1 || choice > 3) {
            printf("Zgjedhje e pavlefshme! Provo perseri.\n");
            continue;   // rikthehet në menu
        }

        // switch për menu
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                printf("Programi po mbyllet...\n");
                break;
        }

    } while (choice != 3);   // loop vazhdon derisa user zgjedh Exit

    return 0;
}
