#include <stdio.h>

#define MAX 5

// Statusi i studentit
typedef enum {
    KALOI,
    RREZOI
} Status;

// Struktura e studentit
typedef struct {
    int id;
    char name[30];
    float grade;
    Status status;
} Student;

// Array për ruajtjen e studentëve
Student students[MAX];
int count = 0;   // numri aktual i studentëve

// Funksion për status
const char* getStatus(Status s) {
    return (s == KALOI) ? "Kaloi" : "Rrezoi";
}

// Shto student të ri
void addStudent() {
    if (count >= MAX) {
        printf("\nLista eshte plote! Nuk mund te shtosh me shume (%d/%d)\n", count, MAX);
        return;
    }

    printf("\n--- SHTIMI I STUDENTIT ---\n");

    printf("Emri: ");
    scanf("%s", students[count].name);

    printf("Nota: ");
    scanf("%f", &students[count].grade);

    students[count].id = count + 1;

    if (students[count].grade >= 5)
        students[count].status = KALOI;
    else
        students[count].status = RREZOI;

    count++;

    printf("Studenti u shtua me sukses! (%d/%d)\n", count, MAX);
}

// Shfaq të gjithë studentët
void showStudents() {
    if (count == 0) {
        printf("\nNuk ka student te regjistruar.\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d | Emri: %s | Nota: %.1f | Statusi: %s\n",
               students[i].id,
               students[i].name,
               students[i].grade,
               getStatus(students[i].status));
    }
}

// Menu kryesore
int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT TRACKER =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq te gjithe\n");
        printf("0. Dil\n");
        printf("Zgjedh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                showStudents();
                break;

            case 0:
                printf("Programi po mbyllet...\n");
                return 0;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }
    }
}
