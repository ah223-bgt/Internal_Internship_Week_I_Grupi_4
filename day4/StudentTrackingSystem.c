#include <stdio.h>

#define MAX 5

// Enum për status
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

// Funksion për status (kthen string)
const char* getStatus(Status st) {
    switch (st) {
        case AKTIV:  return "Aktiv";
        case KALOI:  return "Kaloi";
        case RREZOI: return "Rrezoi";
        default:     return "Unknown";
    }
}

// Zgjedh status me switch + validim (nga task2)
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

// Shto student (task1 + task2 enhancement)
void addStudent() {
    if (count >= MAX) {
        printf("\nLista eshte plote! Nuk mund te shtosh me shume (%d/%d)\n", count, MAX);
        return;
    }

    printf("\n--- SHTIMI I STUDENTIT ---\n");

    printf("Emri: ");
    scanf("%s", s[count].name);

    printf("Nota: ");
    scanf("%f", &s[count].grade);

    s[count].id = count + 1;

    // Zgjedh status me enum
    s[count].status = chooseStatus();

    count++;

    printf("Studenti u shtua me sukses! (%d/%d)\n", count, MAX);
}

// Shfaq studentet (task1)
void showStudents() {
    if (count == 0) {
        printf("\nNuk ka student te regjistruar.\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {
        printf("ID: %d | Emri: %s | Nota: %.1f | Statusi: %s\n",
               s[i].id,
               s[i].name,
               s[i].grade,
               getStatus(s[i].status));
    }
}

// Shfaq + raport analitik (task3)
void showReport() {
    if (count == 0) {
        printf("\nNuk ka te dhena per analize.\n");
        return;
    }

    float sum = 0, max = s[0].grade, min = s[0].grade;
    int passed = 0;

    for (int i = 0; i < count; i++) {
        float g = s[i].grade;

        sum += g;

        if (g > max) max = g;
        if (g < min) min = g;

        if (s[i].status == KALOI)
            passed++;
    }

    float avg = sum / count;

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Total student: %d\n", count);
    printf("Kaluan: %d\n", passed);
    printf("Mesatarja e notave: %.2f\n", avg);
    printf("Nota me e larte: %.2f\n", max);
    printf("Nota me e ulet: %.2f\n", min);

    // interpretim (if/else)
    printf("\n--- VLERESIMI I PERGJITHSHEM ---\n");

    if (avg >= 8)
        printf("Shume mire performance e larte!\n");
    else if (avg >= 5)
        printf("Mesatare - ka vend per permiresim.\n");
    else
        printf("E dobet - nevojitet pune serioze.\n");
}

// Perditeso student me pointer (task4)
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

// Menu kryesore
int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT TRACKER SYSTEM =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq te gjithe\n");
        printf("3. Raport analitik\n");
        printf("4. Perditeso student\n");
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

            case 3:
                showReport();
                break;

            case 4: {
                int id;
                float newGrade;

                printf("\nSheno ID e studentit: ");
                scanf("%d", &id);

                printf("Sheno noten e re: ");
                scanf("%f", &newGrade);

                updateStudent(&id, newGrade);
                break;
            }

            case 0:
                printf("Programi po mbyllet...\n");
                return 0;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }
    }
}