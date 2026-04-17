#include <stdio.h>    // për printf dhe scanf
#include <string.h>   // për string, nëse duhet më vonë

#define MAX_STUDENTS 5   // numri maksimal i regjistrimeve

// enum për statusin e progresit
enum Status {
    NEEDS_IMPROVEMENT,   // progres i ulët
    IN_PROGRESS,         // progres mesatar
    COMPLETED            // progres i mirë
};

// struktura për të ruajtur të dhënat e një studenti
struct Student {
    int id;                 // identifikuesi i studentit
    char name[50];          // emri i studentit
    float progress;         // progresi ose rezultati
    enum Status status;     // statusi i studentit
};

// funksion që llogarit statusin sipas progresit
void calculateStatus(struct Student *s) {   // pointer te studenti
    if (s->progress < 50) {                 // nëse progresi është më pak se 50
        s->status = NEEDS_IMPROVEMENT;      // statusi bëhet "Needs Improvement"
    } else if (s->progress < 80) {          // nëse progresi është më pak se 80
        s->status = IN_PROGRESS;            // statusi bëhet "In Progress"
    } else {                                // për të gjitha rastet tjera
        s->status = COMPLETED;              // statusi bëhet "Completed"
    }
}

// funksion që e printon statusin si tekst
void printStatus(enum Status status) {      // merr statusin si input
    switch (status) {                       // kontrollon statusin
        case NEEDS_IMPROVEMENT:             // nëse statusi është ky
            printf("Needs Improvement");    // printon këtë tekst
            break;                          // ndalet këtu
        case IN_PROGRESS:                   // nëse statusi është ky
            printf("In Progress");          // printon këtë tekst
            break;
        case COMPLETED:                     // nëse statusi është ky
            printf("Completed");            // printon këtë tekst
            break;
        default:                            // nëse ndodh diçka e papritur
            printf("Unknown");              // printon "Unknown"
    }
}

// funksion për të shtuar një student të ri
void addStudent(struct Student students[], int *count) {   // array + pointer te count
    if (*count >= MAX_STUDENTS) {                          // nëse lista është plot
        printf("Lista eshte plote. Nuk mund te shtohen me shume regjistrime.\n");
        return;                                            // del nga funksioni
    }

    printf("Shkruaj ID: ");                                // kërkon ID
    scanf("%d", &students[*count].id);                    // e ruan te studenti aktual

    printf("Shkruaj emrin: ");                            // kërkon emrin
    scanf(" %[^\n]", students[*count].name);             // lexon emrin me hapësira

    printf("Shkruaj progresin (0-100): ");                // kërkon progresin
    scanf("%f", &students[*count].progress);             // lexon progresin

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Progres i pavlefshem. Regjistrimi nuk u shtua.\n");   // mesazh gabimi
        return;                                                         // nuk e shton
    }

    calculateStatus(&students[*count]);   // llogarit statusin duke përdorur pointer
    (*count)++;                           // rrit numrin e studentëve të ruajtur

    printf("Regjistrimi u shtua me sukses.\n");   // mesazh suksesi
}

// funksion për të shfaqur të gjithë studentët
void showStudents(struct Student students[], int count) {   // merr array dhe count
    if (count == 0) {                                       // nëse nuk ka asnjë regjistrim
        printf("Nuk ka regjistrime te ruajtura.\n");        // mesazh
        return;                                             // del nga funksioni
    }

    printf("\n--- STUDENT PROGRESS TRACKER ---\n");         // titull
    for (int i = 0; i < count; i++) {                       // loop për çdo student
        printf("ID: %d\n", students[i].id);                 // printon ID
        printf("Name: %s\n", students[i].name);             // printon emrin
        printf("Progress: %.2f\n", students[i].progress);   // printon progresin
        printf("Status: ");                                 // etiketa e statusit
        printStatus(students[i].status);                    // printon statusin si tekst
        printf("\n-----------------------------\n");         // vijë ndarëse
    }
}

// funksioni kryesor
int main() {
    struct Student students[MAX_STUDENTS];   // krijon një listë fikse studentësh
    int count = 0;                           // sa studentë janë ruajtur deri tani
    int choice;                              // zgjedhja nga menuja

    do {                                     // loop i menusë
        printf("\n===== MENU =====\n");      
        printf("1. Add student record\n");   // opsioni 1
        printf("2. Show all records\n");     // opsioni 2
        printf("3. Exit\n");                 // opsioni 3
        printf("Zgjedh nje opcion: ");       
        scanf("%d", &choice);                // lexon zgjedhjen e përdoruesit

        switch (choice) {                    // kontrollon zgjedhjen
            case 1:                          // nëse zgjedh 1
                addStudent(students, &count); // thërret funksionin për shtim
                break;
            case 2:                          // nëse zgjedh 2
                showStudents(students, count); // thërret funksionin për shfaqje
                break;
            case 3:                          // nëse zgjedh 3
                printf("Programi po mbyllet.\n"); // mesazh daljeje
                break;
            default:                         // nëse zgjedhja nuk është valide
                printf("Zgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 3);                   // vazhdon derisa përdoruesi të zgjedhë Exit

    return 0;                                // përfundon programin
}
