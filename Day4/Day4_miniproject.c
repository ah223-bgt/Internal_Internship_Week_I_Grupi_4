#include <stdio.h>
#include <string.h>

#define MAX 5   // Numri maksimal i studenteve

// Enum për statusin e studentit
enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

// Struktura për student
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// Funksion që përdor pointer për të ndryshuar progresin
void updateProgress(float *p) {
    *p = *p + 10;   // rrit progresin për 10

    // kufizo maksimumin në 100
    if (*p > 100) {
        *p = 100;
    }
}

// Funksion për shtimin e studentit
void addStudent(struct Student s[], int *count) {

    // kontroll nëse lista është plot
    if (*count >= MAX) {
        printf("Lista eshte plot!\n");
        return;
    }

    // marrja e të dhënave
    printf("Shkruaj ID: ");
    scanf("%d", &s[*count].id);

    printf("Shkruaj emrin: ");
    scanf("%s", s[*count].name);

    printf("Shkruaj progresin (0-100): ");
    scanf("%f", &s[*count].progress);

    // validimi i progresit
    if (s[*count].progress < 0 || s[*count].progress > 100) {
        printf("Progres i pavlefshem!\n");
        return;
    }

    // marrja e statusit
    printf("Status (1-Not Started, 2-In Progress, 3-Completed): ");
    int st;
    scanf("%d", &st);

    // validimi i statusit
    if (st < 1 || st > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    // ruajtja e statusit
    s[*count].status = st;

    // rrit numrin e studenteve
    (*count)++;

    printf("Studenti u shtua me sukses!\n");
}

// Funksion për shfaqjen e studentëve
void showStudents(struct Student s[], int count) {

    // kontroll nëse lista është bosh
    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    // loop për shfaqje
    for (int i = 0; i < count; i++) {

        printf("\n--- Student %d ---\n", i + 1);
        printf("ID: %d\n", s[i].id);
        printf("Emri: %s\n", s[i].name);
        printf("Progresi: %.2f\n", s[i].progress);

        // përdorim switch për enum
        switch (s[i].status) {
            case NOT_STARTED:
                printf("Status: Not Started\n");
                break;
            case IN_PROGRESS:
                printf("Status: In Progress\n");
                break;
            case COMPLETED:
                printf("Status: Completed\n");
                break;
            default:
                printf("Status: Unknown\n");
        }
    }
}

// Funksion për rritjen e progresit sipas ID
void increaseProgress(struct Student s[], int count) {
    int id;
    printf("Shkruaj ID e studentit: ");
    scanf("%d", &id);

    // kërkimi i studentit
    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {

            // përdorim pointer për ndryshim
            updateProgress(&s[i].progress);

            printf("Progresi u rrit me sukses!\n");
            return;
        }
    }

    // nëse nuk gjendet
    printf("Studenti nuk u gjet!\n");
}

int main() {

    struct Student students[MAX];  // lista e studenteve
    int count = 0;                // numri aktual
    int choice;                  // zgjedhja nga menu

    // menu loop
    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Rrit progresin\n");
        printf("4. Dil\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &choice);

        // switch për menu
        switch (choice) {

            case 1:
                addStudent(students, &count);
                break;

            case 2:
                showStudents(students, count);
                break;

            case 3:
                increaseProgress(students, count);
                break;

            case 4:
                printf("Programi u mbyll.\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 4);

    return 0;
}
