#include <stdio.h>
#include <string.h>

#define MAX 5

typedef enum {
    AKTIV = 1,
    KALOI,
    RREZOI
} Status;

typedef struct {
    int id;
    char name[30];
    float grade;
    Status status;
} Student;

Student s[MAX];
int count = 0;

// ===== HELPER FUNCTIONS =====

// status -> tekst
const char* getStatus(Status st) {
    switch (st) {
        case AKTIV: return "Aktiv";
        case KALOI: return "Kaloi";
        case RREZOI: return "Rrezoi";
        default: return "Unknown";
    }
}

// gjej student sipas ID (ULJE e repetition)
int findStudentIndex(int id) {
    for (int i = 0; i < count; i++)
        if (s[i].id == id)
            return i;
    return -1;
}

// header clean
void printHeader(char title[]) {
    printf("\n===== %s =====\n", title);
}

// zgjedh status
Status chooseStatus() {
    int choice;
    while (1) {
        printf("1.Aktiv  2.Kaloi  3.Rrezoi\nZgjedh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: return AKTIV;
            case 2: return KALOI;
            case 3: return RREZOI;
            default: printf("Gabim!\n");
        }
    }
}

// ===== CORE FUNCTIONS =====

void addStudent() {
    if (count >= MAX) {
        printf("Lista plote!\n");
        return;
    }

    printHeader("SHTO STUDENT");

    printf("Emri: ");
    scanf("%s", s[count].name);

    printf("Nota: ");
    scanf("%f", &s[count].grade);

    s[count].id = count + 1;
    s[count].status = chooseStatus();

    count++;
    printf("U shtua me sukses!\n");
}

void showStudents() {
    if (!count) {
        printf("Nuk ka studente.\n");
        return;
    }

    printHeader("LISTA");

    printf("ID   Emri        Nota   Status\n");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-4d %-10s %-6.1f %-10s\n",
               s[i].id, s[i].name, s[i].grade, getStatus(s[i].status));
    }
}

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

    printHeader("RAPORT");

    printf("Total: %d\nKaluan: %d\nMesatarja: %.2f\nMax: %.1f\nMin: %.1f\n",
           count, passed, avg, max, min);
}

void updateStudent(int *id, float newGrade) {
    int index = findStudentIndex(*id);

    if (index == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    s[index].grade = newGrade;
    s[index].status = (newGrade >= 5) ? KALOI : RREZOI;

    printf("U perditesua!\n");
}

void editStudent() {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    int index = findStudentIndex(id);

    if (index == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    printf("Emri i ri: ");
    scanf("%s", s[index].name);

    printf("Nota e re: ");
    scanf("%f", &s[index].grade);

    s[index].status = (s[index].grade >= 5) ? KALOI : RREZOI;

    printf("U editua!\n");
}

void deleteStudent() {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    int index = findStudentIndex(id);

    if (index == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    for (int i = index; i < count - 1; i++)
        s[i] = s[i + 1];

    count--;

    for (int i = 0; i < count; i++)
        s[i].id = i + 1;

    printf("U fshi!\n");
}

void searchStudent() {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    int index = findStudentIndex(id);

    if (index == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    Student st = s[index];

    printf("%d | %s | %.1f | %s\n",
           st.id, st.name, st.grade, getStatus(st.status));

    if (st.grade < 5)
        printf("Warning: Deshton\n");
    else if (st.grade < 7)
        printf("Mesatare\n");
    else
        printf("Shume mire\n");
}

void sortStudents() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (s[j].grade < s[j + 1].grade) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printHeader("RANKING");

    for (int i = 0; i < count; i++)
        printf("#%d %s (%.1f)\n", i + 1, s[i].name, s[i].grade);
}

// ===== MENU =====

void showMenu() {
    printf("\n1.Add 2.Show 3.Report 4.Update 5.Search\n");
    printf("6.Rank 7.Edit 8.Delete 0.Exit\n");
    printf("Zgjedh: ");
}

// ===== MAIN =====

int main() {
    int c;

    while (1) {
        showMenu();
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
