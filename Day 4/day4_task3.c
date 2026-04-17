#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

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

const char* statusToText(enum Status status) {
    switch (status) {
        case JO_AKTIV: return "Jo Aktiv";
        case NE_PROGRES: return "Ne Progres";
        case PERFUNDUAR: return "Perfunduar";
        case SHKELQYESHEM: return "Shkelqyeshem";
        default: return "I panjohur";
    }
}

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

int idExists(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("\nLista eshte e mbushur. Maksimumi i regjistrimeve eshte %d.\n", MAX_RECORDS);
        return;
    }

    struct Student s;

    printf("\n--- Shto Student ---\n");

    printf("Jep ID: ");
    if (scanf("%d", &s.id) != 1 || s.id <= 0) {
        printf("ID i pavlefshem.\n");
        while (getchar() != '\n');
        return;
    }

    if (idExists(students, *count, s.id)) {
        printf("Ky ID ekziston tashme.\n");
        return;
    }

    printf("Jep emrin: ");
    scanf(" %49[^\n]", s.name);

    if (strlen(s.name) == 0) {
        printf("Emri nuk mund te jete bosh.\n");
        return;
    }

    printf("Jep progresin (0 - 100): ");
    if (scanf("%f", &s.progress) != 1 || s.progress < 0 || s.progress > 100) {
        printf("Progres i pavlefshem.\n");
        while (getchar() != '\n');
        return;
    }

    if (!chooseStatus(&s.status)) {
        return;
    }

    students[*count] = s;
    (*count)++;

    printf("Studenti u shtua me sukses.\n");
}

void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime te ruajtura.\n");
        return;
    }

    printf("\n===== LISTA E STUDENTEVE =====\n");
    for (int i = 0; i < count; i++) {
        printf("Regjistrimi #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);
        printf("Statusi: %s\n", statusToText(students[i].status));
        printf("---------------------------\n");
    }
}

void showReport(struct Student students[], int count) {
    if (count == 0) {
        printf("\n===== RAPORTI ANALITIK =====\n");
        printf("Lista eshte bosh. Nuk ka te dhena per analize.\n");
        return;
    }

    int completedCount = 0;
    float totalProgress = 0.0;
    float maxProgress = students[0].progress;
    float minProgress = students[0].progress;

    for (int i = 0; i < count; i++) {
        totalProgress += students[i].progress;

        if (students[i].status == PERFUNDUAR || students[i].status == SHKELQYESHEM) {
            completedCount++;
        }

        if (students[i].progress > maxProgress) {
            maxProgress = students[i].progress;
        }

        if (students[i].progress < minProgress) {
            minProgress = students[i].progress;
        }
    }

    float average = totalProgress / count;

    printf("\n===== RAPORTI ANALITIK =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i rasteve te perfunduara: %d\n", completedCount);
    printf("Mesatarja e progresit: %.2f\n", average);
    printf("Progresi me i larte: %.2f\n", maxProgress);
    printf("Progresi me i ulet: %.2f\n", minProgress);

    printf("\n--- Klasifikimi ---\n");

    if (average >= 85) {
        printf("Mesatarja e progresit eshte shume e larte.\n");
    } else if (average >= 50) {
        printf("Mesatarja e progresit eshte e kenaqshme.\n");
    } else if (average > 0) {
        printf("Mesatarja e progresit eshte e ulet dhe kerkon permiresim.\n");
    } else {
        printf("Nuk ka progres te regjistruar.\n");
    }

    if (completedCount == count) {
        printf("Te gjitha regjistrimet jane ne gjendje te mire ose te perfunduara.\n");
    } else if (completedCount > 0) {
        printf("Disa regjistrime jane te perfunduara, por ka ende pune per te bere.\n");
    } else {
        printf("Asnje regjistrim nuk eshte ende i perfunduar.\n");
    }

    if (maxProgress == minProgress) {
        printf("Te gjitha regjistrimet kane te njejtin nivel progresi.\n");
    } else {
        printf("Ekziston dallim i qarte mes progresit me te larte dhe me te ulet.\n");
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
        printf("3. Raporti analitik\n");
        printf("4. Dil\n");
        printf("Zgjedh: ");

        if (scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem.\n");
            while (getchar() != '\n');
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
                showReport(students, count);
                break;
            case 4:
                printf("Programi po mbyllet.\n");
                break;
            default:
                printf("Opsion i pavlefshem. Provo perseri.\n");
        }

    } while (choice != 4);

    return 0;
}
