#include <stdio.h>

#define MAX 5

// enum për status
enum Status
{
    FAIL = 1,
    PASS,
    EXCELLENT
};

// struktura e studentit
struct Student
{
    int id;
    char initial;
    float progress;
    enum Status status;
};

// print status
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

// zgjedhja e statusit me validim
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
            case 1: return FAIL;
            case 2: return PASS;
            case 3: return EXCELLENT;
            default:
                printf("Invalid status! Try again.\n");
        }

    } while (1);
}

// shtimi i studentit
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

    // zgjedh statusin
    arr[*count].status = chooseStatus();

    (*count)++;

    printf("Student added successfully!\n");
}

// shfaqja
void showStudents(struct Student arr[], int count)
{
    if (count == 0)
    {
        printf("No records!\n");
        return;
    }

    printf("\n--- Students ---\n");

    for (int i = 0; i < count; i++)
    {
        printf("ID: %d\n", arr[i].id);
        printf("Initial: %c\n", arr[i].initial);
        printf("Progress: %.2f\n", arr[i].progress);
        printf("Status: ");
        printStatus(arr[i].status);
        printf("\n\n");
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
        printf("3. Exit\n");
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid menu choice!\n");
        }

    } while (choice != 3);

    return 0;
}
