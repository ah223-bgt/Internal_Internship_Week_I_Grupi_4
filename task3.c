#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5   // kufiri maksimal i regjistrimeve

// enum për statusin
enum Status {
    NEEDS_IMPROVEMENT = 1,
    IN_PROGRESS,
    COMPLETED
};

// struktura për student
struct Student {
    int id;                  // ID e studentit
    char name[50];           // emri i studentit
    float progress;          // progresi
    enum Status status;      // statusi me enum
};

// printon statusin si tekst
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

// zgjedh statusin nga përdoruesi
enum Status chooseStatus() {
    int choice;

    printf("Zgjedh statusin:\n");
    printf("1 - Needs Improvement\n");
    printf("2 - In Progress\n");
    printf("3 - Completed\n");
    scanf("%d", &choice);

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

// shton student
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
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

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    students[*count].status = chooseStatus();
    (*count)++;

    printf("Studenti u shtua me sukses!\n");
}

// shfaq studentët
void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("Nuk ka student te ruajtur.\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);
        printf("Status: ");
        printStatus(students[i].status);
        printf("\n------------------------\n");
    }
}

// raport analitik
void showReport(struct Student students[], int count) {
    if (count == 0) {
        printf("Nuk ka regjistrime. Raporti nuk mund te krijohet.\n");
        return;
    }

    int completedCount = 0;               // sa studentë janë completed
    float sum = 0;                        // shuma totale e progresit
    float max = students[0].progress;     // progresi më i lartë
    float min = students[0].progress;     // progresi më i ulët

    // kalon nëpër të gjithë studentët
    for (int i = 0; i < count; i++) {
        sum += students[i].progress;      // shton progresin në shumë

        if (students[i].status == COMPLETED) {
            completedCount++;             // numëron completed
        }

        if (students[i].progress > max) {
            max = students[i].progress;   // gjen max
        }

        if (students[i].progress < min) {
            min = students[i].progress;   // gjen min
        }
    }

    float average = sum / count;          // llogarit mesataren

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Total records: %d\n", count);
    printf("Completed records: %d\n", completedCount);
    printf("Average progress: %.2f\n", average);
    printf("Highest progress: %.2f\n", max);
    printf("Lowest progress: %.2f\n", min);

    // klasifikim me if/else
    if (average < 50) {
        printf("Overall performance: Needs improvement\n");
    } else if (average < 80) {
        printf("Overall performance: Acceptable / In progress\n");
    } else {
        printf("Overall performance: Very good\n");
    }

    if (completedCount == 0) {
        printf("No student has completed the progress yet.\n");
    } else if (completedCount < count) {
        printf("Some students have completed the progress.\n");
    } else {
        printf("All students have completed the progress.\n");
    }
}

// main
int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Zgjedh nje opcion: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 4) {
            printf("Zgjedhje e pavlefshme! Provo perseri.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                printf("Programi po mbyllet...\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
