#include <stdio.h>

#define MAX_STUDENTS 5

enum Status
{
    FAIL = 1,
    PASS,
    EXCELLENT
};

struct Student
{
    int id;
    char initial;
    float progress;
    enum Status status;
};

void printStatus(enum Status status)
{
    switch (status)
    {
        case FAIL:
            printf("Fail");
            break;
        case PASS:
            printf("Pass");
            break;
        case EXCELLENT:
            printf("Excellent");
            break;
        default:
            printf("Unknown");
    }
}

void showStudent(struct Student s)
{
    printf("ID: %d\n", s.id);
    printf("Initial: %c\n", s.initial);
    printf("Progress: %.2f\n", s.progress);
    printf("Status: ");
    printStatus(s.status);
    printf("\n");
}

void showWarningOrRecommendation(struct Student s)
{
    printf("Interpretation: ");

    if (s.progress < 40 && s.status == FAIL)
    {
        printf("Critical warning - very low progress and fail status.\n");
    }
    else if (s.progress >= 40 && s.progress < 50 && s.status == FAIL)
    {
        printf("Warning - close to passing, but still below target.\n");
    }
    else if (s.progress >= 50 && s.progress < 70 && s.status == PASS)
    {
        printf("Recommendation - acceptable result, but more practice is needed.\n");
    }
    else if (s.progress >= 70 && s.progress < 85 && s.status == PASS)
    {
        printf("Good result - continue working to reach excellent level.\n");
    }
    else if (s.progress >= 85 && s.status == EXCELLENT)
    {
        printf("Excellent result - keep this performance level.\n");
    }
    else if (s.progress >= 80 && s.status == PASS)
    {
        printf("Check record - high progress but status is only Pass.\n");
    }
    else if (s.progress < 50 && s.status == EXCELLENT)
    {
        printf("Check record - status does not match progress.\n");
    }
    else
    {
        printf("Record is valid. Monitor progress normally.\n");
    }
}

void searchStudentById(struct Student students[], int count)
{
    int id;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo records available for search.\n");
        return;
    }

    printf("\n--- Search Student By ID ---\n");
    printf("Enter student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;

            printf("\n--- Search Result ---\n");
            showStudent(students[i]);
            showWarningOrRecommendation(students[i]);
            break;
        }
    }

    if (!found)
    {
        printf("No student found with that ID.\n");
    }
}

int main()
{
    struct Student students[MAX_STUDENTS] =
    {
        {101, 'A', 35.0, FAIL},
        {102, 'B', 67.5, PASS},
        {103, 'C', 90.0, EXCELLENT},
        {104, 'D', 82.0, PASS},
        {105, 'E', 45.0, FAIL}
    };

    int count = 5;
    int choice;

    do
    {
        printf("\n=== Task 5 Menu ===\n");
        printf("1. Search student by ID\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                searchStudentById(students, count);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 2);

    return 0;
}
