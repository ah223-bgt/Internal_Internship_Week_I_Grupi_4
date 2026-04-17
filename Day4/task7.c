#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int age;
    float score;
};

struct Student students[MAX];
int count = 0;

// Shto regjistrim
void addStudent() {
    if (count >= MAX) {
        printf("\nNuk mund te shtohen me shume regjistrime.\n");
        return;
    }

    printf("\n--- SHTO REGJISTRIM ---\n");

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[count].name);

    printf("Shkruaj moshen: ");
    scanf("%d", &students[count].age);

    printf("Shkruaj score: ");
    scanf("%f", &students[count].score);

    count++;
    printf("Regjistrimi u shtua me sukses.\n");
}

// Shfaq te gjitha regjistrimet
void displayStudents() {
    if (count == 0) {
        printf("\nNuk ka regjistrime per t'u shfaqur.\n");
        return;
    }

    printf("\n========== LISTA E REGJISTRIMEVE ==========\n");
    for (int i = 0; i < count; i++) {
        printf("Indeksi: %d | Emri: %s | Mosha: %d | Score: %.2f\n",
               i,
               students[i].name,
               students[i].age,
               students[i].score);
    }
}

// Kerko sipas emrit
void searchStudent() {
    char searchName[50];
    int found = 0;

    if (count == 0) {
        printf("\nNuk ka regjistrime per kerkim.\n");
        return;
    }

    printf("\n--- KERKO REGJISTRIM ---\n");
    printf("Shkruaj emrin qe don me kerku: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("U gjet: Indeksi: %d | Emri: %s | Mosha: %d | Score: %.2f\n",
                   i,
                   students[i].name,
                   students[i].age,
                   students[i].score);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Nuk u gjet asnje regjistrim me kete emer.\n");
    }
}

// Ranko sipas score
void rankStudents() {
    if (count == 0) {
        printf("\nNuk ka regjistrime per rankim.\n");
        return;
    }

    struct Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[j].score > students[i].score) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n========== RANKIMI SIPAS SCORE ==========\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Emri: %s | Mosha: %d | Score: %.2f\n",
               i + 1,
               students[i].name,
               students[i].age,
               students[i].score);
    }
}

// Ndrysho regjistrim
void editStudent() {
    int index;

    if (count == 0) {
        printf("\nNuk ka regjistrime per ndryshim.\n");
        return;
    }

    displayStudents();

    printf("\nShkruaj indeksin e regjistrimit qe don me ndryshu: ");
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Indeks i pavlefshem. Nuk u be asnje ndryshim.\n");
        return;
    }

    printf("\n--- REGJISTRIMI AKTUAL ---\n");
    printf("Emri: %s | Mosha: %d | Score: %.2f\n",
           students[index].name,
           students[index].age,
           students[index].score);

    printf("\n--- NDRYSHO REGJISTRIM ---\n");

    printf("Shkruaj emrin e ri: ");
    scanf(" %[^\n]", students[index].name);

    printf("Shkruaj moshen e re: ");
    scanf("%d", &students[index].age);

    printf("Shkruaj score te ri: ");
    scanf("%f", &students[index].score);

    printf("Regjistrimi u ndryshua me sukses.\n");
}

// Fshi regjistrim
void deleteStudent() {
    int index;

    if (count == 0) {
        printf("\nNuk ka regjistrime per fshirje.\n");
        return;
    }

    displayStudents();

    printf("\nShkruaj indeksin e regjistrimit qe don me fshi: ");
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Indeks i pavlefshem. Nuk u be asnje fshirje.\n");
        return;
    }

    printf("\nPo fshihet: %s | Mosha: %d | Score: %.2f\n",
           students[index].name,
           students[index].age,
           students[index].score);

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;

    printf("Regjistrimi u fshi me sukses.\n");
    printf("Numri total i regjistrimeve: %d\n", count);
}

int main() {
    int choice;

    do {
        printf("\n=====================================\n");
        printf("         MINI-PROJEKTI FINAL         \n");
        printf("=====================================\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Kerko regjistrim sipas emrit\n");
        printf("4. Ranko regjistrimet sipas score\n");
        printf("5. Ndrysho regjistrim\n");
        printf("6. Fshi regjistrim\n");
        printf("7. Dil nga programi\n");
        printf("=====================================\n");
        printf("Zgjedh opsionin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                rankStudents();
                break;
            case 5:
                editStudent();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                printf("\nProgrami u mbyll me sukses.\n");
                break;
            default:
                printf("\nZgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 7);

    return 0;
}
