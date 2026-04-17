#include <stdio.h>

#define MAX 5

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

void printStatus(enum Status s)
{
    switch (s)
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

enum Status chooseStatus()
{
    int choice;

    do
    {
        printf("Choose status:\n");
        printf("1 - Fail\n");
        printf("2 - Pass\n");
        printf("3 - Excellent\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                return FAIL;
            case 2:
                return PASS;
            case 3:
                return EXCELLENT;
            default:
                printf("Invalid status! Try again.\n");
        }

    } while (1);
}

void addStudent(struct Student arr[], int *count)
{
    if (*count >= MAX)
    {
        printf("Maximum capacity reached!\n");
        return;
    }

    printf("\n--- Add Student ---\n");

    printf("Enter ID: ");
    scanf("%d", &arr[*count].id);

    if (arr[*count].id <= 0)
    {
        printf("Invalid ID!\n");
        return;
    }

    printf("Enter initial: ");
    scanf(" %c", &arr[*count].initial);

    printf("Enter progress (0-100): ");
    scanf("%f", &arr[*count].progress);

    if (arr[*count].progress < 0 || arr[*count].progress > 100)
    {
        printf("Invalid progress!\n");
        return;
    }

    arr[*count].status = chooseStatus();

    (*count)++;

    printf("Student added successfully!\n");
}

void showStudents(struct Student arr[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No records!\n");
        return;
    }

    printf("\n--- Students ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d\n", arr[i].id);
        printf("Initial: %c\n", arr[i].initial);
        printf("Progress: %.2f\n", arr[i].progress);
        printf("Status: ");
        printStatus(arr[i].status);
        printf("\n\n");
    }
}

void showReport(struct Student arr[], int count)
{
    int i;
    int failCount = 0;
    int passCount = 0;
    int excellentCount = 0;
    float totalProgress = 0;
    float average;
    float highest;
    float lowest;

    if (count == 0)
    {
        printf("\n--- Report ---\n");
        printf("No records available for analysis.\n");
        return;
    }

    highest = arr[0].progress;
    lowest = arr[0].progress;

    for (i = 0; i < count; i++)
    {
        totalProgress += arr[i].progress;

        if (arr[i].status == FAIL)
        {
            failCount++;
        }
        else if (arr[i].status == PASS)
        {
            passCount++;
        }
        else if (arr[i].status == EXCELLENT)
        {
            excellentCount++;
        }

        if (arr[i].progress > highest)
        {
            highest = arr[i].progress;
        }

        if (arr[i].progress < lowest)
        {
            lowest = arr[i].progress;
        }
    }

    average = totalProgress / count;

    printf("\n--- Report ---\n");
    printf("Total records: %d\n", count);
    printf("Average progress: %.2f\n", average);
    printf("Highest progress: %.2f\n", highest);
    printf("Lowest progress: %.2f\n", lowest);
    printf("Fail records: %d\n", failCount);
    printf("Pass records: %d\n", passCount);
    printf("Excellent records: %d\n", excellentCount);

    if (average < 50)
    {
        printf("Classification: Overall progress needs improvement.\n");
    }
    else if (average < 80)
    {
        printf("Classification: Overall progress is good.\n");
    }
    else
    {
        printf("Classification: Overall progress is excellent.\n");
    }

    if (excellentCount > failCount)
    {
        printf("Insight: More students are performing at excellent level than fail level.\n");
    }
    else if (failCount > excellentCount)
    {
        printf("Insight: There are more fail records than excellent ones.\n");
    }
    else
    {
        printf("Insight: Fail and excellent records are balanced.\n");
    }
}

int main()
{
    struct Student students[MAX];
    int count = 0;
    int choice;

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Add student\n");
        printf("2. Show students\n");
        printf("3. Show report\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid menu choice!\n");
        }

    } while (choice != 4);

    return 0;
}
