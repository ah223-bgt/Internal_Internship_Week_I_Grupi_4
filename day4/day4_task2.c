#include <stdio.h>

#define MAX 5

// ENUM për status
typedef enum {
    AKTIV = 1,
    KALOI = 2,
    RREZOI = 3
} Status;

// Struktura e studentit
typedef struct {
    int id;
    char name[30];
    float grade;
    Status status;
} Student;

Student s[MAX];
int count = 0;

// kthen status në tekst
const char* getStatus(Status st) {
    switch (st) {
        case AKTIV:  return "Aktiv";
        case KALOI:  return "Kaloi";
        case RREZOI: return "Rrezoi";
        default:     return "Unknown";
    }
}

// zgjedh status me switch + validim
Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nZgjidh statusin:\n");
        printf("1. Aktiv\n2. Kaloi\n3. Rrezoi\nZgjedh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: return AKTIV;
            case 2: return KALOI;
            case 3: return RREZOI;
            default:
                printf("Gabim! Provo perseri.\n");
        }
    }
}

// shto student
void addStudent() {
    if (count >= MAX) {
        printf("Lista eshte plote (%d/%d)\n", count, MAX);
        return;
    }

    printf("\nEmri: ");
    scanf("%s", s[count].name);

    printf("Nota: ");
    scanf("%f", &s[count].grade);

    s[count].id = count + 1;

    // enum real usage
    s[count].status = chooseStatus();

    count++;

    printf("Studenti u shtua me sukses!\n");
}

// shfaq studentët
void showStudents() {
    if (count == 0) {
        printf("Nuk ka studente.\n");
        return;
    }

    printf("\n--- LISTA ---\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d | %s | %.1f | %s\n",
               s[i].id,
               s[i].name,
               s[i].grade,
               getStatus(s[i].status));
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
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
