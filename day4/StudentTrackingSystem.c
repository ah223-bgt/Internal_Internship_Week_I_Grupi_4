#include <stdio.h>

#define MAX 5

// Enum për status
typedef enum {
    KALOI,
    RREZOI
} Status;

// Struktura
typedef struct {
    int id;
    char name[30];
    float grade;
    Status status;
} Student;

Student s[MAX];
int count = 0;

// Funksion për status
const char* getStatus(Status st) {
    return (st == KALOI) ? "Kaloi" : "Rrezoi";
}

// Shto student
void addStudent() {
    if (count >= MAX) {
        printf("Lista eshte plot!\n");
        return;
    }

    printf("Emri: ");
    scanf("%s", s[count].name);

    printf("Nota: ");
    scanf("%f", &s[count].grade);

    s[count].id = count + 1;

    // vendos statusin
    if (s[count].grade >= 5)
        s[count].status = KALOI;
    else
        s[count].status = RREZOI;

    count++;
    printf("U shtua me sukses!\n");
}

// Shfaq studentet
void showStudents() {
    if (count == 0) {
        printf("Nuk ka studente.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d | %s | %.1f | %s\n",
               s[i].id,
               s[i].name,
               s[i].grade,
               getStatus(s[i].status));
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Shto\n2. Shfaq\n0. Dil\nZgjedh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 0: printf("Bye!\n"); break;
            default: printf("Gabim!\n");
        }

    } while (choice != 0);

    return 0;
}
