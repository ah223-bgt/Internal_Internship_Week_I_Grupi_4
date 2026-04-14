#include <stdio.h>

int main() {
    // Student details
    char name[] = "Andi";
    char surname[] = "Ademaj";
    char school[] = "British Gymnasium of Technology";
    char className[] = "XI";

    // Display report
    printf("\n============================\n");
    printf("     STUDENT REPORT\n");
    printf("============================\n");
    printf("Name    : %s %s\n", name, surname);
    printf("School  : %s\n", school);
    printf("Class   : %s\n", className);
    printf("============================\n");

    return 0;
}
