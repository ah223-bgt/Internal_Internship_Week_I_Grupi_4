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

void updateStatusByProgress(float progress, enum Status *status) {
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

void printStudent(struct Student student, int index) {
    printf("\nRegjistrimi #%d\n", index + 1);
    printf("ID: %d\n", student.id);
    printf("Emri: %s\n", student.name);
    printf("Progresi: %.2f\n", student.progress);
    printf("Statusi: %s\n", getStatusText(student.status));
    printf("-----------------------------\n");
}

void addStudent(struct Student students[], int *count) {
    struct Student s;

    if (*count >= MAX_STUDENTS) {
        printf("\nNuk mund te shtohen me shume regjistrime. Lista eshte e plote.\n");
        printf("Kapaciteti maksimal eshte %d regjistrime.\n", MAX_STUDENTS);
        return;
    }

    printf("\n--- Shto Regjistrim te Ri ---\n");

    printf("Jep ID: ");
    if (scanf("%d", &s.id) != 1) {
        printf("ID i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    if (s.id <= 0) {
        printf("ID duhet te jete numer pozitiv.\n");
        return;
    }

    if (idExists(students, *count, s.id)) {
        printf("Ky ID ekziston tashme. Jep nje ID tjeter.\n");
        return;
    }

    printf("Jep emrin: ");
    clearInputBuffer();
    if (fgets(s.name, sizeof(s.name), stdin) == NULL) {
        printf("Gabim gjate leximit te emrit.\n");
        return;
    }

    s.name[strcspn(s.name, "\n")] = '\0';

    if (strlen(s.name) == 0) {
        printf("Emri nuk mund te jete bosh.\n");
        return;
    }

    printf("Jep progresin (0 - 100): ");
    if (scanf("%f", &s.progress) != 1) {
        printf("Progresi i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    if (s.progress < 0 || s.progress > 100) {
        printf("Progresi duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    updateStatusByProgress(s.progress, &s.status);

    students[*count] = s;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    printf("Regjistrime aktuale: %d\n", *count);
    printf("Kapaciteti maksimal: %d\n", MAX_STUDENTS);
}

void showStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka asnje regjistrim te ruajtur.\n");
        return;
    }

    printf("\n===== LISTA E REGJISTRIMEVE =====\n");
    printf("Numri aktual i regjistrimeve: %d\n", count);
    printf("Kapaciteti maksimal: %d\n", MAX_STUDENTS);

    for (int i = 0; i < count; i++) {
        printStudent(students[i], i);
    }
}

int findStudentIndexById(struct Student students[], int count, int searchId) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            return i;
        }
    }
    return -1;
}

void showRecommendation(struct Student student) {
    printf("\n--- Vleresim / Rekomandim ---\n");

    if (student.progress == 0 && student.status == JO_AKTIV) {
        printf("Paralajmerim: studenti nuk ka filluar ende progresin.\n");
    } else if (student.progress > 0 && student.progress < 50 && student.status == NE_PROGRES) {
        printf("Rekomandim: progres i ulet, nevojitet me shume pune dhe ushtrime.\n");
    } else if (student.progress >= 50 && student.progress < 85 &&
               (student.status == PERFUNDUAR || student.status == NE_PROGRES)) {
        printf("Rekomandim: studenti eshte ne rruge te mire, por mund te permirësohet edhe me shume.\n");
    } else if (student.progress >= 85 && student.status == SHKELQYESHEM) {
        printf("Vleresim pozitiv: studenti ka performance shume te mire.\n");
    } else {
        printf("Kujdes: te dhenat duhen kontrolluar perseri per konsistence.\n");
    }
}

void searchStudentById(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkese.\n");
        return;
    }

    int searchId;
    int index;

    printf("\nJep ID-ne per kerkese: ");
    if (scanf("%d", &searchId) != 1) {
        printf("ID i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    index = findStudentIndexById(students, count, searchId);

    if (index == -1) {
        printf("Nuk u gjet asnje regjistrim me kete ID.\n");
        return;
    }

    printf("\n--- Regjistrimi u Gjet ---\n");
    printStudent(students[index], index);
    showRecommendation(students[index]);
}

void searchStudentByName(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkese.\n");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("\nJep emrin per kerkese: ");
    clearInputBuffer();
    if (fgets(searchName, sizeof(searchName), stdin) == NULL) {
        printf("Gabim gjate leximit te emrit.\n");
        return;
    }

    searchName[strcspn(searchName, "\n")] = '\0';

    if (strlen(searchName) == 0) {
        printf("Emri i kerkuar nuk mund te jete bosh.\n");
        return;
    }

    printf("\n--- Rezultatet e Kerkimit ---\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printStudent(students[i], i);
            showRecommendation(students[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Nuk u gjet asnje regjistrim me emrin \"%s\".\n", searchName);
    }
}

void searchMenu(struct Student students[], int count) {
    int choice;

    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkese.\n");
        return;
    }

    printf("\n===== MENU KERKIMI =====\n");
    printf("1. Kerko sipas ID-se\n");
    printf("2. Kerko sipas emrit\n");
    printf("Zgjedh nje opsion: ");

    if (scanf("%d", &choice) != 1) {
        printf("Input i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    switch (choice) {
        case 1:
            searchStudentById(students, count);
            break;
        case 2:
            searchStudentByName(students, count);
            break;
        default:
            printf("Opsion i pavlefshem ne menune e kerkimit.\n");
    }
}

void updateStudentProgress(struct Student *student) {
    float newProgress;

    printf("\n--- Perditeso Progresin ---\n");
    printf("Adresa e regjistrimit ne memorie: %p\n", (void*)student);
    printf("Progresi aktual: %.2f\n", student->progress);
    printf("Jep progresin e ri (0 - 100): ");

    if (scanf("%f", &newProgress) != 1) {
        printf("Input i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    if (newProgress < 0 || newProgress > 100) {
        printf("Progresi duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    printf("Progresi para ndryshimit: %.2f\n", student->progress);
    student->progress = newProgress;
    updateStatusByProgress(student->progress, &student->status);
    printf("Progresi pas ndryshimit: %.2f\n", student->progress);
    printf("Statusi i ri: %s\n", getStatusText(student->status));
}

void updateStudentMenu(struct Student students[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("\nNuk ka regjistrime per perditesim.\n");
        return;
    }

    printf("\nJep ID-ne e studentit qe don me perditesu: ");
    if (scanf("%d", &id) != 1) {
        printf("ID i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    index = findStudentIndexById(students, count, id);

    if (index == -1) {
        printf("Nuk u gjet asnje student me kete ID.\n");
        return;
    }

    printStudent(students[index], index);
    updateStudentProgress(&students[index]);
}

void showStatistics(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNuk ka te dhena per statistika.\n");
        return;
    }

    float total = 0.0f;
    float maxProgress = students[0].progress;
    float minProgress = students[0].progress;
    int countJoAktiv = 0;
    int countNeProgres = 0;
    int countPerfunduar = 0;
    int countShkelqyeshem = 0;
    int completedCases = 0;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].progress > maxProgress) {
            maxProgress = students[i].progress;
        }

        if (students[i].progress < minProgress) {
            minProgress = students[i].progress;
        }

        if (students[i].status == JO_AKTIV) {
            countJoAktiv++;
        } else if (students[i].status == NE_PROGRES) {
            countNeProgres++;
        } else if (students[i].status == PERFUNDUAR) {
            countPerfunduar++;
            completedCases++;
        } else if (students[i].status == SHKELQYESHEM) {
            countShkelqyeshem++;
            completedCases++;
        }
    }

    printf("\n===== RAPORTI ANALITIK =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Rastet e perfunduara: %d\n", completedCases);
    printf("Mesatarja e progresit: %.2f\n", total / count);
    printf("Progresi me i larte: %.2f\n", maxProgress);
    printf("Progresi me i ulet: %.2f\n", minProgress);
    printf("Jo Aktiv: %d\n", countJoAktiv);
    printf("Ne Progres: %d\n", countNeProgres);
    printf("Perfunduar: %d\n", countPerfunduar);
    printf("Shkelqyeshem: %d\n", countShkelqyeshem);

    printf("\n--- Interpretimi ---\n");

    if ((total / count) >= 85) {
        printf("Mesatarja e progresit eshte shume e larte.\n");
    } else if ((total / count) >= 50) {
        printf("Mesatarja e progresit eshte e kenaqshme.\n");
    } else if ((total / count) > 0) {
        printf("Mesatarja e progresit eshte e ulet dhe kerkon permiresim.\n");
    } else {
        printf("Nuk ka progres te regjistruar.\n");
    }

    if (completedCases == count) {
        printf("Te gjitha regjistrimet jane te perfunduara ose shume te mira.\n");
    } else if (completedCases > 0) {
        printf("Disa regjistrime jane te perfunduara, por jo te gjitha.\n");
    } else {
        printf("Asnje regjistrim nuk eshte perfunduar ende.\n");
    }

    if (maxProgress == minProgress) {
        printf("Te gjitha regjistrimet kane te njejtin nivel progresi.\n");
    } else {
        printf("Ekziston dallim i qarte mes progresit me te larte dhe me te ulet.\n");
    }
}

void showCapacityInfo(int count) {
    printf("\n--- Informacion mbi Kapacitetin ---\n");
    printf("Numri aktual i regjistrimeve: %d\n", count);
    printf("Kapaciteti maksimal: %d\n", MAX_STUDENTS);
    printf("Hapesira e lire: %d\n", MAX_STUDENTS - count);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== CONSOLE-BASED STUDENT PROGRESS TRACKER =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Kerko regjistrim\n");
        printf("4. Perditeso progresin e studentit\n");
        printf("5. Shfaq raportin analitik\n");
        printf("6. Shfaq kapacitetin\n");
        printf("7. Dil\n");
        printf("Zgjedh nje opsion: ");

        if (scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem ne menu. Provo perseri.\n");
            clearInputBuffer();
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
                searchMenu(students, count);
                break;
            case 4:
                updateStudentMenu(students, count);
                break;
            case 5:
                showStatistics(students, count);
                break;
            case 6:
                showCapacityInfo(count);
                break;
            case 7:
                printf("Programi po mbyllet. Faleminderit!\n");
                break;
            default:
                printf("Opsion i pavlefshem. Provo perseri.\n");
        }

    } while (choice != 7);

    return 0;
}
