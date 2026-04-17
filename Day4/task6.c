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

// Funksioni per shtimin e nje regjistrimi
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

// Funksioni per shfaqjen e te gjitha regjistrimeve
void displayStudents() {
    if (count == 0) {
        printf("\nNuk ka regjistrime per t'u shfaqur.\n");
        return;
    }

    printf("\n========== LISTA E REGJISTRIMEVE ==========\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Emri: %s | Mosha: %d | Score: %.2f\n",
               i + 1,
               students[i].name,
               students[i].age,
               students[i].score);
    }
}

// Funksioni per kerkimin sipas emrit
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
            printf("U gjet: Emri: %s | Mosha: %d | Score: %.2f\n",
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

// Funksioni per renditje / rankim sipas score
void rankStudents() {
    struct Student temp;

    if (count == 0) {
        printf("\nNuk ka regjistrime per rankim.\n");
        return;
    }

    // Renditja nga score me i madh te me i vogel
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[j].score > students[i].score) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n========== RANKIMI FINAL SIPAS SCORE ==========\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Mosha: %d | Score: %.2f\n",
               i + 1,
               students[i].name,
               students[i].age,
               students[i].score);
    }
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
        printf("5. Dil nga programi\n");
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
                printf("\nProgrami u mbyll me sukses.\n");
                break;
            default:
                printf("\nZgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 5);

    return 0;
}
