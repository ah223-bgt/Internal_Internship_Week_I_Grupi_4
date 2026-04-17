#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

// ENUM për statusin
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

// Konvertim i statusit në tekst
const char* statusToText(enum Status status) {
    switch (status) {
        case JO_AKTIV: return "Jo Aktiv";
        case NE_PROGRES: return "Ne Progres";
        case PERFUNDUAR: return "Perfunduar";
        case SHKELQYESHEM: return "Shkelqyeshem";
        default: return "I panjohur";
    }
}

// Funksion për zgjedhjen e statusit me validim
int chooseStatus(enum Status *status) {
    int choice;

    printf("\nZgjedh statusin:\n");
    printf("1 - Jo Aktiv\n");
    printf("2 - Ne Progres\n");
    printf("3 - Perfunduar\n");
    printf("4 - Shkelqyeshem\n");
    printf("Zgjedh: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            *status = (enum Status)choice;
            return 1;
        default:
            printf("Zgjedhje e pavlefshme per status.\n");
            return 0;
    }
}

// Kontroll për ID ekzistues
int idExists(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) return 1;
    }
    return 0;
}

// Shtimi i studentit me validim të fortë
void addStudent(struct Student students[], int *count) {

    if (*count >= MAX_RECORDS) {
        printf("\nLista eshte e mbushur (%d regjistrime max).\n", MAX_RECORDS);
        return;
    }

    struct Student s;

    printf("\n--- Shto Student ---\n");

    printf("Jep ID: ");
    if (scanf("%d", &s.id) != 1 || s.id <= 0) {
        printf("ID i pavlefshem.\n");
        while(getchar() != '\n'); // pastrim input
        return;
    }

    if (idExists(students, *count, s.id)) {
        printf("Ky ID ekziston.\n");
        return;
    }

    printf("Jep emrin: ");
    scanf(" %49[^\n]", s.name);

    if (strlen(s.name) == 0) {
        printf("Emri nuk lejohet bosh.\n");
        return;
    }

    printf("Jep progresin (0-100): ");
    if (scanf("%f", &s.progress) != 1 || s.progress < 0 || s.progress > 100) {
        printf("Progres i pavlefshem.\n");
        while(getchar() != '\n');
        return;
    }

    // zgjedh statusin me enum + switch
    if (!chooseStatus(&s.status)) {
        return;
    }

    students[*count] = s;
    (*count)++;

    printf("Studenti u shtua me sukses.\n");
}

// Shfaqja e të gjithë studentëve
void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime.\n");
        return;
    }

    printf("\n===== LISTA =====\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);
        printf("Statusi: %s\n", statusToText(students[i].status));
        printf("------------------\n");
    }
}

int main() {
    struct Student students[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Dil\n");
        printf("Zgjedh: ");

        if (scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem!\n");
            while(getchar() != '\n');
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
                printf("Duke dalur...\n");
                break;

            default:
                printf("Opsion i pavlefshem! Provo perseri.\n");
        }

    } while (choice != 3);

    return 0;
}
