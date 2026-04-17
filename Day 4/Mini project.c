#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// Enum për statusin e nxënësit
enum Status {
    JO_AKTIV = 0,
    NE_PROGRES = 1,
    PERFUNDUAR = 2,
    SHKELQYESHEM = 3
};

// Struktura për një regjistrim të nxënësit
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Funksion për të kthyer statusin si tekst
const char* getStatusText(enum Status status) {
    switch (status) {
        case JO_AKTIV:
            return "Jo Aktiv";
        case NE_PROGRES:
            return "Ne Progres";
        case PERFUNDUAR:
            return "Perfunduar";
        case SHKELQYESHEM:
            return "Shkelqyeshem";
        default:
            return "Status i Panjohur";
    }
}

// Funksion me pointer: përditëson statusin sipas progresit
void updateStatusByProgress(float progress, enum Status *status) {
    if (progress < 0 || progress > 100) {
        return;
    }

    if (progress == 0) {
        *status = JO_AKTIV;
    } else if (progress > 0 && progress < 50) {
        *status = NE_PROGRES;
    } else if (progress >= 50 && progress < 85) {
        *status = PERFUNDUAR;
    } else {
        *status = SHKELQYESHEM;
    }
}

// Shtimi i një regjistrimi
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nNuk mund te shtohen me shume regjistrime. Lista eshte e plote.\n");
        return;
    }

    struct Student s;

    printf("\n--- Shto Regjistrim te Ri ---\n");

    printf("Jep ID: ");
    scanf("%d", &s.id);

    if (s.id <= 0) {
        printf("ID duhet te jete numer pozitiv.\n");
        return;
    }

    // kontroll nëse ID ekziston
    for (int i = 0; i < *count; i++) {
        if (students[i].id == s.id) {
            printf("Ky ID ekziston tashme. Jep nje ID tjeter.\n");
            return;
        }
    }

    printf("Jep emrin: ");
    scanf(" %49[^\n]", s.name);

    if (strlen(s.name) == 0) {
        printf("Emri nuk mund te jete bosh.\n");
        return;
    }

    printf("Jep progresin (0 - 100): ");
    scanf("%f", &s.progress);

    if (s.progress < 0 || s.progress > 100) {
        printf("Progresi duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    // Statusi caktohet automatikisht me pointer
    updateStatusByProgress(s.progress, &s.status);

    students[*count] = s;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
}

// Shfaqja e të gjithë regjistrimeve
void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka asnje regjistrim te ruajtur.\n");
        return;
    }

    printf("\n--- Lista e Regjistrimeve ---\n");
    for (int i = 0; i < count; i++) {
        printf("Regjistrimi %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);
        printf("Statusi: %s\n", getStatusText(students[i].status));
        printf("-----------------------------\n");
    }
}

// Kërkim i një studenti sipas ID-së
void searchStudentById(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkese.\n");
        return;
    }

    int searchId;
    int found = 0;

    printf("\nJep ID-ne per kerkese: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("\n--- Regjistrimi u Gjet ---\n");
            printf("ID: %d\n", students[i].id);
            printf("Emri: %s\n", students[i].name);
            printf("Progresi: %.2f\n", students[i].progress);
            printf("Statusi: %s\n", getStatusText(students[i].status));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim me kete ID.\n");
    }
}

// Statistika bazike
void showStatistics(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka te dhena per statistika.\n");
        return;
    }

    float total = 0;
    int countJoAktiv = 0, countNeProgres = 0, countPerfunduar = 0, countShkelqyeshem = 0;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].status == JO_AKTIV) {
            countJoAktiv++;
        } else if (students[i].status == NE_PROGRES) {
            countNeProgres++;
        } else if (students[i].status == PERFUNDUAR) {
            countPerfunduar++;
        } else if (students[i].status == SHKELQYESHEM) {
            countShkelqyeshem++;
        }
    }

    printf("\n--- Statistikat ---\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Mesatarja e progresit: %.2f\n", total / count);
    printf("Jo Aktiv: %d\n", countJoAktiv);
    printf("Ne Progres: %d\n", countNeProgres);
    printf("Perfunduar: %d\n", countPerfunduar);
    printf("Shkelqyeshem: %d\n", countShkelqyeshem);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Console-based Student Progress Tracker =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Kerko regjistrim sipas ID\n");
        printf("4. Shfaq statistikat\n");
        printf("5. Dil\n");
        printf("Zgjedh nje opsion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                searchStudentById(students, count);
                break;
            case 4:
                showStatistics(students, count);
                break;
            case 5:
                printf("Programi po mbyllet. Faleminderit!\n");
                break;
            default:
                printf("Opsion i pavlefshem. Provo perseri.\n");
        }

    } while (choice != 5);

    return 0;
}
