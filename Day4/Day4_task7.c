#include <stdio.h>

#define MAX_STUDENTS 5

struct Student
{
    int id;
    char initial;
    float progress;
};

void showStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo records available.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < count; i++)
    {
        printf("Record #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Initial: %c\n", students[i].initial);
        printf("Progress: %.2f\n\n", students[i].progress);
    }
}

void editStudentById(struct Student students[], int count)
{
    int id;
    int i;
    int found = 0;
    char newInitial;
    float newProgress;

    if (count == 0)
    {
        printf("\nNo records available to edit.\n");
        return;
    }

    printf("\n--- Edit Student ---\n");
    printf("Enter student ID to edit: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;

            printf("Student found.\n");
            printf("Current initial: %c\n", students[i].initial);
            printf("Enter new initial: ");
            scanf(" %c", &newInitial);

            printf("Current progress: %.2f\n", students[i].progress);
            printf("Enter new progress (0 - 100): ");
            scanf("%f", &newProgress);

            if (newProgress < 0 || newProgress > 100)
            {
                printf("Invalid progress. It must be between 0 and 100.\n");
                return;
            }

            students[i].initial = newInitial;
            students[i].progress = newProgress;

            printf("Record updated successfully.\n");
            return;
        }
    }

    if (!found)
    {
        printf("No student found with that ID.\n");
    }
}

void deleteStudentById(struct Student students[], int *count)
{
    int id;
    int i;
    int j;
    int found = 0;

    if (*count == 0)
    {
        printf("\nNo records available to delete.\n");
        return;
    }

    printf("\n--- Delete Student ---\n");
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;

            for (j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("Record deleted successfully.\n");
            printf("Current records: %d\n", *count);
            return;
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
        {101, 'A', 45.0},
        {102, 'B', 70.0},
        {103, 'C', 88.5}
    };

    int count = 3;
    int choice;

    do
    {
        printf("\n=== Task 7 Menu ===\n");
        printf("1. Show students\n");
        printf("2. Edit student\n");
        printf("3. Delete student\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                showStudents(students, count);
                break;
            case 2:
                editStudentById(students, count);
                break;
            case 3:
                deleteStudentById(students, &count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 4);

    return 0;
}
