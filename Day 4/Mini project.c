#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

enum Status {
    JO_AKTIV = 1,
    NE_PROGRES,
    PERFUNDUAR,
    SHKELQYESHEM
};

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

const char* getStatusText(enum Status status) {
    switch (status) {
        case JO_AKTIV: return "Jo Aktiv";
        case NE_PROGRES: return "Ne Progres";
        case PERFUNDUAR: return "Perfunduar";
        case SHKELQYESHEM: return "Shkelqyeshem";
        default: return "Status i Panjohur";
    }
}

void updateStatusByProgress(float progress, enum Status *status) {
    if (progress == 0) *status = JO_AKTIV;
    else if (progress < 50) *status = NE_PROGRES;
    else if (progress < 85) *status = PERFUNDUAR;
    else *status = SHKELQYESHEM;
}

int idExists(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++)
        if (students[i].id == id) return 1;
    return 0;
}

int findIndexById(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++)
        if (students[i].id == id) return i;
    return -1;
}

void printStudent(struct Student s, int i) {
    printf("\n[%d]\nID: %d\nEmri: %s\nProgresi: %.2f\nStatusi: %s\n------------------\n",
           i+1, s.id, s.name, s.progress, getStatusText(s.status));
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nLista eshte e plote.\n");
        return;
    }

    struct Student s;

    printf("\nID: ");
    if (scanf("%d", &s.id) != 1 || s.id <= 0) {
        printf("ID i pavlefshem.\n"); clearInputBuffer(); return;
    }

    if (idExists(students, *count, s.id)) {
        printf("ID ekziston.\n"); return;
    }

    printf("Emri: ");
    clearInputBuffer();
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Progresi (0-100): ");
    if (scanf("%f", &s.progress) != 1 || s.progress < 0 || s.progress > 100) {
        printf("Progres i pavlefshem.\n"); clearInputBuffer(); return;
    }

    updateStatusByProgress(s.progress, &s.status);

    students[*count] = s;
    (*count)++;
    printf("U shtua me sukses.\n");
}

void showAll(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka te dhena.\n"); return;
    }

    for (int i = 0; i < count; i++)
        printStudent(students[i], i);
}

void updateProgress(struct Student *s) {
    float p;
    printf("Progresi i ri: ");
    if (scanf("%f", &p) != 1 || p < 0 || p > 100) {
        printf("Gabim.\n"); clearInputBuffer(); return;
    }

    s->progress = p;
    updateStatusByProgress(p, &s->status);
    printf("U perditesua.\n");
}

void editStudent(struct Student students[], int count) {
    int id = 0;
    printf("ID: ");
    scanf("%d", &id);

    int i = findIndexById(students, count, id);
    if (i == -1) {
        printf("Nuk u gjet.\n"); return;
    }

    printf("1. Emri\n2. Progresi\n3. Te dyja\nZgjedh: ");
    int ch; scanf("%d", &ch);

    if (ch == 1 || ch == 3) {
        printf("Emri i ri: ");
        clearInputBuffer();
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;
    }

    if (ch == 2 || ch == 3)
        updateProgress(&students[i]);
}

void deleteStudent(struct Student students[], int *count) {
    int id;
    printf("ID per fshirje: ");
    scanf("%d", &id);

    int i = findIndexById(students, *count, id);
    if (i == -1) {
        printf("Nuk u gjet.\n"); return;
    }

    for (int j = i; j < *count - 1; j++)
        students[j] = students[j + 1];

    (*count)--;
    printf("U fshi.\n");
}

void search(struct Student students[], int count) {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    int i = findIndexById(students, count, id);
    if (i == -1) {
        printf("Nuk u gjet.\n"); return;
    }

    printStudent(students[i], i);

    if (students[i].progress < 50)
        printf("Rekomandim: puno ma shume.\n");
    else if (students[i].progress > 85)
        printf("Shkelqyeshem.\n");
}

void statistics(struct Student s[], int c) {
    if (c == 0) return;

    float sum = 0, max = s[0].progress, min = s[0].progress;
    int done = 0;

    for (int i = 0; i < c; i++) {
        sum += s[i].progress;
        if (s[i].progress > max) max = s[i].progress;
        if (s[i].progress < min) min = s[i].progress;
        if (s[i].status >= PERFUNDUAR) done++;
    }

    printf("\nMesatarja: %.2f\nMax: %.2f\nMin: %.2f\nTe perfunduara: %d\n",
           sum/c, max, min, done);
}

void sortByProgress(struct Student s[], int c) {
    struct Student temp;

    for (int i = 0; i < c - 1; i++)
        for (int j = 0; j < c - i - 1; j++)
            if (s[j].progress < s[j+1].progress) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }

    printf("\n--- Rankimi ---\n");
    showAll(s, c);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0, ch;

    do {
        printf("\n===== MENU =====\n");
        printf("1.Shto\n2.Shfaq\n3.Kerko\n4.Update\n5.Edit\n6.Fshi\n7.Statistika\n8.Rendit\n9.Dil\nZgjedh: ");

        if (scanf("%d", &ch) != 1) {
            clearInputBuffer();
            continue;
        }

        switch (ch) {
            case 1: addStudent(students, &count); break;
            case 2: showAll(students, count); break;
            case 3: search(students, count); break;
            case 4: {
                int id;
                printf("ID: "); scanf("%d", &id);
                int i = findIndexById(students, count, id);
                if (i != -1) updateProgress(&students[i]);
            } break;
            case 5: editStudent(students, count); break;
            case 6: deleteStudent(students, &count); break;
            case 7: statistics(students, count); break;
            case 8: sortByProgress(students, count); break;
        }

    } while (ch != 9);

    return 0;
}
