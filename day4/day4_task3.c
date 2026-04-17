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

    // klasifikim me if/else
    if (s[count].grade >= 5)
        s[count].status = KALOI;
    else
        s[count].status = RREZOI;

    count++;
    printf("U shtua me sukses!\n");
}

// shfaq + raport analitik
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

// menu
int main() {
    int choice;

    while (1) {
        printf("\n1.Shto  2.Raport  0.Dil\nZgjedh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showReport(); break;
            case 0: return 0;
            default: printf("Gabim!\n");
        }
    }
}
