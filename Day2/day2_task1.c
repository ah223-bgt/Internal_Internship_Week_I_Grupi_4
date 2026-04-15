#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double gpa;
    short groupNumber = 4;
    long studentID = 231L;

    printf("User Profile Setup\n");

    printf("Enter your age (int): ");
    scanf("%d", &age);

    printf("Enter your first initial (char): ");
    scanf(" %c", &initial);

    printf("Enter your height in meters (float): ");
    scanf("%f", &height);

    printf("Enter your GPA (double): ");
    scanf("%lf", &gpa);

    printf("\n--- Student Profile Summary ---\n");
    printf("Initial: %c\n", initial);
    printf("Age: %d years old\n", age);
    printf("Height: %.2f meters\n", height);
    printf("GPA: %.2lf\n", gpa);
    printf("Group Number (short): %hd\n", groupNumber);
    printf("Student ID (long): %ld\n", studentID);

    return 0;
}
