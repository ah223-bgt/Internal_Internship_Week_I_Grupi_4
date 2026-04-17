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

void showStatus(enum Status status)
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
        printf("\nMaximum limit reached. No more records can be added.\n");
        return;
    }

    printf("\n--- Add Student Record ---\n");

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter initial: ");
    scanf(" %c", &students[*count].initial);

    printf("Enter progress/result: ");
    scanf("%f", &students[*count].progress);

    setStatus(&students[*count]);

    (*count)++;

    printf("Record added successfully.\n");
    printf("Current records: %d / %d\n", *count, MAX_STUDENTS);
}

void showAllStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo records stored yet.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");

    for (i = 0; i < count; i++)
    {
        printf("Record %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Initial: %c\n", students[i].initial);
        printf("Progress: %.2f\n", students[i].progress);
        printf("Status: ");
        showStatus(students[i].status);
        printf("\n\n");
    }

    printf("Total stored records: %d\n", count);
    printf("Maximum capacity: %d\n", MAX_STUDENTS);
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n=== Student Progress Tracker ===\n");
        printf("1. Add record\n");
        printf("2. Show all records\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
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
                printf("Invalid option. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
