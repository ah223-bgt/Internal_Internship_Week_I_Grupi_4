#include <stdio.h>
#include <string.h>

#define MAX 5

// ENUM
enum Status { FAIL = 0, PASS = 1 };

// STRUCT
struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// GLOBAL VARIABLES
struct Student students[MAX];
int count = 0;

// 🔹 FIND STUDENT INDEX
int findStudentIndex(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}

// 🔹 PRINT STUDENT
void printStudent(struct Student s, int index) {
    printf("%d) ID:%d | %-10s | %6.2f | %s\n",
           index + 1,
           s.id,
           s.name,
           s.progress,
           s.status == PASS ? "PASS" : "FAIL");
}

// 🔹 ADD STUDENT
void addStudent() {
    if (count >= MAX) {
        printf("Limit reached!\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Progress: ");
    scanf("%f", &students[count].progress);

    students[count].status =
        (students[count].progress >= 50) ? PASS : FAIL;

    count++;
}

// 🔹 SHOW ALL
void showStudents() {
    if (count == 0) {
        printf("\nNo records.\n");
        return;
    }

    printf("\n==== STUDENT LIST ====\n");
    for (int i = 0; i < count; i++) {
        printStudent(students[i], i);
    }
}

// 🔹 UPDATE (Pointer logic)
void updateStudent() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int i = findStudentIndex(id);

    if (i == -1) {
        printf("Not found.\n");
        return;
    }

    printf("New progress: ");
    scanf("%f", &students[i].progress);

    students[i].status =
        (students[i].progress >= 50) ? PASS : FAIL;

    printf("Updated successfully!\n");
}

// 🔹 EDIT (2 fields)
void editStudent() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int i = findStudentIndex(id);

    if (i == -1) {
        printf("Not found.\n");
        return;
    }

    printf("New name: ");
    scanf("%s", students[i].name);

    printf("New progress: ");
    scanf("%f", &students[i].progress);

    students[i].status =
        (students[i].progress >= 50) ? PASS : FAIL;

    printf("Edited successfully!\n");
}

// 🔹 DELETE
void deleteStudent() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int i = findStudentIndex(id);

    if (i == -1) {
        printf("Not found.\n");
        return;
    }

    for (int j = i; j < count - 1; j++) {
        students[j] = students[j + 1];
    }

    count--;
    printf("Deleted successfully!\n");
}

// 🔹 SEARCH + WARNING
void searchStudent() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int i = findStudentIndex(id);

    if (i == -1) {
        printf("Not found.\n");
        return;
    }

    printStudent(students[i], i);

    if (students[i].progress < 50)
        printf("WARNING: At risk!\n");
    else if (students[i].progress >= 85)
        printf("EXCELLENT!\n");
    else
        printf("GOOD.\n");
}

// 🔹 REPORT
void showReport() {
    if (count == 0) {
        printf("No data.\n");
        return;
    }

    float total = 0;
    float max = students[0].progress;
    float min = students[0].progress;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].progress > max) max = students[i].progress;
        if (students[i].progress < min) min = students[i].progress;
    }

    printf("\n==== REPORT ====\n");
    printf("Total: %d\n", count);
    printf("Average: %.2f\n", total / count);
    printf("Max: %.2f | Min: %.2f\n", max, min);
}

// 🔹 SORT (Ranking)
void sortStudents() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].progress < students[j + 1].progress) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n=== RANKING (HIGH → LOW) ===\n");
    showStudents();
}

// 🔹 MAIN MENU
int main() {
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1.Add  2.Show  3.Update\n");
        printf("4.Edit 5.Delete 6.Search\n");
        printf("7.Report 8.Ranking 9.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: updateStudent(); break;
            case 4: editStudent(); break;
            case 5: deleteStudent(); break;
            case 6: searchStudent(); break;
            case 7: showReport(); break;
            case 8: sortStudents(); break;
            case 9: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}
