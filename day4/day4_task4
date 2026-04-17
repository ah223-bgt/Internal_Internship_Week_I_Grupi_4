#include <stdio.h>

#define MAX 5

typedef enum {
    AKTIV = 1,
    KALOI = 2,
    RREZOI = 3
} Status;

typedef struct {
    int id;
    char name[30];
    float grade;
    Status status;
} Student;

Student s[MAX];
int count = 0;

// kthen status
const char* getStatus(Status st) {
    switch (st) {
        case AKTIV: return "Aktiv";
        case KALOI: return "Kaloi";
        case RREZOI: return "Rrezoi";
        default: return "Unknown";
    }
}

// shto student
void addStudent() {
    if (count >= MAX) {
        printf("Lista eshte plote!\n");
        return;
    }

    printf("Emri: ");
    scanf("%s", s[count].name);

    printf("Nota: ");
    scanf("%f", &s[count].grade);

    s[count].id = count + 1;

    if (s[count].grade >= 5)
        s[count].status = KALOI;
    else
        s[count].status = RREZOI;

    count++;

    printf("U shtua me sukses!\n");
}

// 📌 FUNKSION ME POINTER (KRYESORI I TASK 4)
void updateStudent(int *id, float newGrade) {
    for (int i = 0; i < count; i++) {

        if (s[i].id == *id) {   // përdorim pointer

            s[i].grade = newGrade;

            // update status
            if (s[i].grade >= 5)
                s[i].status = KALOI;
            else
                s[i].status = RREZOI;

            printf("Studenti u perditesua me sukses!\n");
            return;
        }
    }

    printf("Studenti me kete ID nuk u gjet!\n");
}

// shfaq studentet
void showStudents() {
    if (count == 0) {
        printf("Nuk ka studente.\n");
        return;
    }

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
        printf("\n1.Shto  2.Shfaq  3.Update  0.Dil\nZgjedh: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                showStudents();
                break;

            case 3: {
                int id;
                float newGrade;

                printf("Sheno ID e studentit: ");
                scanf("%d", &id);

                printf("Sheno noten e re: ");
                scanf("%f", &newGrade);

                updateStudent(&id, newGrade); // 📌 pointer me &
                break;
            }

            case 0:
                return 0;

            default:
                printf("Gabim!\n");
        }
    }
}
