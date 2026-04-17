#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

enum Status {
    JO_AKTIV,
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
        case JO_AKTIV:
            return "Jo Aktiv";
        case NE_PROGRES:
            return "Ne Progres";
        case PERFUNDUAR:
            return "Perfunduar";
        case SHKELQYESHEM:
            return "Shkelqyeshem";
        default:
            return "I panjohur";
    }
}

void updateStatus(float progress, enum Status *status) {
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
        printf("\nNuk mund te shtohen me shume regjistrime.\n");
        printf("Eshte arritur kufiri maksimal prej %d regjistrimeve.\n", MAX_RECORDS);
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

    if (idExists(students, *count, s.id)) {
        printf("Ky ID ekziston tashme. Zgjedh nje ID tjeter.\n");
        return;
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
        printf("Progresi duhet te jete ne intervalin 0 - 100.\n");
        return;
    }

    updateStatus(s.progress, &s.status);

    students[*count] = s;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    printf("Regjistrime aktuale: %d\n", *count);
    printf("Kapacitet maksimal: %d\n", MAX_RECORDS);
}

void showAllStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka ende regjistrime te ruajtura.\n");
        return;
    }

    printf("\n===== TE GJITHA REGJISTRIMET =====\n");
    printf("Regjistrime aktuale: %d\n", count);
    printf("Kapacitet maksimal: %d\n", MAX_RECORDS);
    printf("-----------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("Regjistrimi #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);
        printf("Statusi: %s\n", statusToText(students[i].status));
        printf("-----------------------------------\n");
    }
}

void showCapacityInfo(int count) {
    printf("\n--- Informacion mbi Kapacitetin ---\n");
    printf("Regjistrime aktuale: %d\n", count);
    printf("Kapacitet maksimal: %d\n", MAX_RECORDS);
    printf("Hapesire e lire: %d\n", MAX_RECORDS - count);
}

int main() {
    struct Student students[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Shfaq kapacitetin\n");
        printf("4. Dil\n");
        printf("Zgjedh nje opsion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showAllStudents(students, count);
                break;
            case 3:
                showCapacityInfo(count);
                break;
            case 4:
                printf("Programi po mbyllet. Faleminderit!\n");
                break;
            default:
                printf("Opsion i pavlefshem. Provo perseri.\n");
        }

    } while (choice != 4);

    return 0;
}
