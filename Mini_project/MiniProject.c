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

void showOneStudent(struct Student s)
{
    printf("ID: %d\n", s.id);
    printf("Initial: %c\n", s.initial);
    printf("Progress: %.2f\n", s.progress);
    printf("Status: ");
    printStatus(s.status);
    printf("\n");
}

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nMaximum capacity reached. Cannot add more records.\n");
        return;
    }

    printf("\n--- Add Student Record ---\n");

    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);

    if (students[*count].id <= 0)
    {
        printf("Invalid ID. It must be greater than 0.\n");
        return;
    }

    printf("Enter student initial: ");
    scanf(" %c", &students[*count].initial);

    printf("Enter progress/result (0 - 100): ");
    scanf("%f", &students[*count].progress);

    if (students[*count].progress < 0 || students[*count].progress > 100)
    {
        printf("Invalid progress. It must be between 0 and 100.\n");
        return;
    }

    setStatus(&students[*count]);

    printf("\n--- New Student Added ---\n");
    showOneStudent(students[*count]);

    (*count)++;

    printf("\nStored records: %d / %d\n", *count, MAX_STUDENTS);
}

void showAllStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records stored yet.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRecord #%d\n", i + 1);
        showOneStudent(students[i]);
    }

    printf("\nCurrent total: %d\n", count);
    printf("Maximum capacity: %d\n", MAX_STUDENTS);
}

void showStatistics(struct Student students[], int count)
{
    int i;
    int needsPracticeCount = 0;
    int goodProgressCount = 0;
    int excellentCount = 0;
    float total = 0;

    if (count == 0)
    {
        printf("\nNo records available for statistics.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total += students[i].progress;

        switch (students[i].status)
        {
            case NEEDS_PRACTICE:
                needsPracticeCount++;
                break;
            case GOOD_PROGRESS:
                goodProgressCount++;
                break;
            case EXCELLENT_PROGRESS:
                excellentCount++;
                break;
        }
    }

    printf("\n--- Statistics ---\n");
    printf("Total students: %d\n", count);
    printf("Average progress: %.2f\n", total / count);
    printf("Needs Practice: %d\n", needsPracticeCount);
    printf("Good Progress: %d\n", goodProgressCount);
    printf("Excellent Progress: %d\n", excellentCount);
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n==============================\n");
        printf(" Student Progress Tracker\n");
        printf("==============================\n");
        printf("1. Add student record\n");
        printf("2. Show all records\n");
        printf("3. Show statistics\n");
        printf("4. Exit\n");
        printf("==============================\n");
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
                showStatistics(students, count);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
