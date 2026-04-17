#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// enum për statusin
enum Status {
    NEEDS_IMPROVEMENT = 1,
    IN_PROGRESS,
    COMPLETED
};

// struktura për student
struct Student {
    int id;                  // ID e studentit
    char name[50];           // emri
    float progress;          // progresi
    enum Status status;      // statusi
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

// zgjedh statusin
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

// shfaq të gjithë studentët
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

    int completedCount = 0;
    float sum = 0;
    float max = students[0].progress;
    float min = students[0].progress;

    for (int i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].status == COMPLETED) {
            completedCount++;
        }

        if (students[i].progress > max) {
            max = students[i].progress;
        }

        if (students[i].progress < min) {
            min = students[i].progress;
        }
    }

    float average = sum / count;

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Total records: %d\n", count);
    printf("Completed records: %d\n", completedCount);
    printf("Average progress: %.2f\n", average);
    printf("Highest progress: %.2f\n", max);
    printf("Lowest progress: %.2f\n", min);

    if (average < 50) {
        printf("Overall performance: Needs improvement\n");
    } else if (average < 80) {
        printf("Overall performance: Acceptable / In progress\n");
    } else {
        printf("Overall performance: Very good\n");
    }
}

// funksion për të dhënë mesazh interpretues
void showRecommendation(struct Student s) {
    printf("Interpretim: ");

    if (s.progress < 50 && s.status == NEEDS_IMPROVEMENT) {
        printf("Warning - studenti ka progres te ulet dhe ka nevoje per me shume ushtrime.\n");
    } 
    else if (s.progress >= 50 && s.progress < 80 && s.status == IN_PROGRESS) {
        printf("Recommendation - studenti eshte ne rruge te mire, por duhet te vazhdoje punen.\n");
    } 
    else if (s.progress >= 80 && s.status == COMPLETED) {
        printf("Excellent - studenti ka performance shume te mire dhe ka perfunduar me sukses.\n");
    } 
    else if (s.progress >= 80 && s.status != COMPLETED) {
        printf("Notice - progresi eshte i larte, por statusi nuk eshte Completed. Kontrollo te dhenat.\n");
    } 
    else if (s.progress < 50 && s.status != NEEDS_IMPROVEMENT) {
        printf("Warning - progres i ulet, por status jo i pershtatshem. Kontrollo regjistrimin.\n");
    } 
    else {
        printf("Studenti ka nje gjendje mesatare dhe duhet monitorim i vazhdueshem.\n");
    }
}

// kërko student sipas ID ose emrit
void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("Nuk ka regjistrime per te kerkuar.\n");
        return;
    }

    int option;
    int found = 0;

    printf("\n--- SEARCH STUDENT ---\n");
    printf("1. Kerko sipas ID\n");
    printf("2. Kerko sipas emrit\n");
    printf("Zgjedh nje opcion: ");
    scanf("%d", &option);

    if (option == 1) {
        int searchId;
        printf("Shkruaj ID-ne: ");
        scanf("%d", &searchId);

        for (int i = 0; i < count; i++) {
            if (students[i].id == searchId) {
                found = 1;

                printf("\n--- REZULTATI I GJETUR ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);
                printf("Status: ");
                printStatus(students[i].status);
                printf("\n");

                showRecommendation(students[i]);
            }
        }

        if (!found) {
            printf("Nuk u gjet asnje student me kete ID.\n");
        }

    } else if (option == 2) {
        char searchName[50];
        printf("Shkruaj emrin: ");
        scanf(" %[^\n]", searchName);

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                found = 1;

                printf("\n--- REZULTATI I GJETUR ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);
                printf("Status: ");
                printStatus(students[i].status);
                printf("\n");

                showRecommendation(students[i]);
            }
        }

        if (!found) {
            printf("Nuk u gjet asnje student me kete emer.\n");
        }

    } else {
        printf("Zgjedhje e pavlefshme ne search menu.\n");
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
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Zgjedh nje opcion: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
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
                searchStudent(students, count);
                break;
            case 5:
                printf("Programi po mbyllet...\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
