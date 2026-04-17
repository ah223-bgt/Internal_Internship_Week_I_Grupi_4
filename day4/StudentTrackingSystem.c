#include <stdio.h>
#include <string.h>

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

// status -> tekst
const char* getStatus(Status st) {
    switch (st) {
        case AKTIV: return "Aktiv";
        case KALOI: return "Kaloi";
        case RREZOI: return "Rrezoi";
        default: return "Unknown";
    }
}

// zgjedh status
Status chooseStatus() {
    int choice;
    while (1) {
        printf("\n1.Aktiv  2.Kaloi  3.Rrezoi\nZgjedh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: return AKTIV;
            case 2: return KALOI;
            case 3: return RREZOI;
            default: printf("Gabim!\n");
        }
    }
}

// ADD
void addStudent() {
    if (count >= MAX) {
        printf("Lista plote!\n");
        return;
    }

    printf("Emri: ");
    scanf("%s", s[count].name);

    printf("Nota: ");
    scanf("%f", &s[count].grade);

    s[count].id = count + 1;
    s[count].status = chooseStatus();

    count++;
}

// SHOW
void showStudents() {
    if (!count) {
        printf("Nuk ka studente.\n");
        return;
    }

    for (int i = 0; i < count; i++)
        printf("%d | %s | %.1f | %s\n",
               s[i].id, s[i].name, s[i].grade, getStatus(s[i].status));
}

// REPORT
void showReport() {
    if (!count) return;

    float sum = 0, max = s[0].grade, min = s[0].grade;
    int passed = 0;

    for (int i = 0; i < count; i++) {
        float g = s[i].grade;
        sum += g;

        if (g > max) max = g;
        if (g < min) min = g;

        if (s[i].status == KALOI) passed++;
    }

    float avg = sum / count;

    printf("\nTotal: %d | Kaluan: %d | Avg: %.2f | Max: %.1f | Min: %.1f\n",
           count, passed, avg, max, min);
}

// UPDATE me pointer (task4)
void updateStudent(int *id, float newGrade) {
    for (int i = 0; i < count; i++) {
        if (s[i].id == *id) {
            s[i].grade = newGrade;
            s[i].status = (newGrade >= 5) ? KALOI : RREZOI;
            printf("Updated!\n");
            return;
        }
    }
    printf("Nuk u gjet!\n");
}

// ✏️ TASK 7 – EDIT (ndrysho 2 fusha)
void editStudent() {
    if (!count) return;

    int id;
    printf("ID per edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {

            printf("Emri i ri: ");
            scanf("%s", s[i].name);

            printf("Nota e re: ");
            scanf("%f", &s[i].grade);

            // update status automatik
            s[i].status = (s[i].grade >= 5) ? KALOI : RREZOI;

            printf("U editua me sukses!\n");
            return;
        }
    }

    printf("Studenti nuk u gjet!\n");
}

// 🗑️ TASK 7 – DELETE
void deleteStudent() {
    if (!count) return;

    int id;
    printf("ID per fshirje: ");
    scanf("%d", &id);

    int index = -1;

    // gjej index
    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Studenti nuk u gjet!\n");
        return;
    }

    // shift array (shum e rendesishme)
    for (int i = index; i < count - 1; i++) {
        s[i] = s[i + 1];
    }

    count--; // update count

    // rregullo ID-t (opsionale por clean)
    for (int i = 0; i < count; i++) {
        s[i].id = i + 1;
    }

    printf("Studenti u fshi me sukses!\n");
}

// SEARCH
void searchStudent() {
    if (!count) return;

    int opt, found = 0;
    printf("1.ID  2.Emri: ");
    scanf("%d", &opt);

    if (opt == 1) {
        int id; scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (s[i].id == id) {
                found = 1;
                printf("%d | %s | %.1f\n", s[i].id, s[i].name, s[i].grade);

                if (s[i].grade < 5)
                    printf("Warning: Deshton\n");
                else if (s[i].grade < 7)
                    printf("Ok por mundet ma mire\n");
                else
                    printf("Shume mire\n");
            }
        }
    }
    else if (opt == 2) {
        char name[30]; scanf("%s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(s[i].name, name) == 0) {
                found = 1;
                printf("%d | %s | %.1f\n", s[i].id, s[i].name, s[i].grade);
            }
        }
    }

    if (!found) printf("Nuk u gjet!\n");
}

// SORT
void sortStudents() {
    if (!count) return;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (s[j].grade < s[j + 1].grade) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n--- RANKING ---\n");
    for (int i = 0; i < count; i++)
        printf("#%d %s (%.1f)\n", i + 1, s[i].name, s[i].grade);
}

// MAIN
int main() {
    int c;

    while (1) {
        printf("\n1.Add 2.Show 3.Report 4.Update 5.Search 6.Rank 7.Edit 8.Delete 0.Exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: showReport(); break;

            case 4: {
                int id; float g;
                printf("ID: "); scanf("%d", &id);
                printf("Nota: "); scanf("%f", &g);
                updateStudent(&id, g);
                break;
            }

            case 5: searchStudent(); break;
            case 6: sortStudents(); break;
            case 7: editStudent(); break;
            case 8: deleteStudent(); break;

            case 0: return 0;
            default: printf("Gabim!\n");
        }
    }
}
