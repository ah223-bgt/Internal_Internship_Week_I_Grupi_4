#include <stdio.h>

#define MAX_STUDENTS 5

enum Status
{
    NEEDS_PRACTICE = 1,
    GOOD_PROGRESS,
    EXCELLENT_PROGRESS
};

struct Student
{
    int id;
    char initial;
    float progress;
    enum Status status;
};

void setStatus(struct Student *s)
{
    if (s->progress < 50)
    {
        s->status = NEEDS_PRACTICE;
    }
    else if (s->progress < 80)
    {
        s->status = GOOD_PROGRESS;
    }
    else
    {
        s->status = EXCELLENT_PROGRESS;
    }
}

void printStatus(enum Status status)
{
    switch (status)
    {
        case NEEDS_PRACTICE:
            printf("Needs Practice");
            break;
        case GOOD_PROGRESS:
            printf("Good Progress");
            break;
        case EXCELLENT_PROGRESS:
            printf("Excellent Progress");
            break;
        default:
            printf("Unknown");
    }
}

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nMaximum capacity reached.\n");
        return;
    }

    printf("\n--- Add Student ---\n");

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter initial: ");
    scanf(" %c", &students[*count].initial);

    printf("Enter progress: ");
    scanf("%f", &students[*count].progress);

    setStatus(&students[*count]);

    printf("\nStudent added successfully.\n");
    printf("Assigned status: ");
    printStatus(students[*count].status);
    printf("\n");

    (*count)++;
}

void showAllStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Initial: %c\n", students[i].initial);
        printf("Progress: %.2f\n", students[i].progress);
        printf("Status: ");
        printStatus(students[i].status);
        printf("\n");
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n=== Student Progress Tracker ===\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showAllStudents(students, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
