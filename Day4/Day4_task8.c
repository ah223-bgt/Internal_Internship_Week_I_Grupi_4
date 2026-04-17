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

void printLine()
{
    printf("=====================================\n");
}

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

void setStatusFromProgress(struct Student *s)
{
    if (s->progress < 50)
    {
        s->status = FAIL;
    }
    else if (s->progress < 80)
    {
        s->status = PASS;
    }
    else
    {
        s->status = EXCELLENT;
    }
}

void showStudent(struct Student s, int index)
{
    printf("Record #%d\n", index + 1);
    printf("ID       : %d\n", s.id);
    printf("Initial  : %c\n", s.initial);
    printf("Progress : %.2f\n", s.progress);
    printf("Status   : ");
    printStatus(s.status);
    printf("\n");
    printLine();
}

void showStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo records available.\n");
        return;
    }

    printf("\nSTUDENT RECORDS\n");
    printLine();

    for (i = 0; i < count; i++)
    {
        showStudent(students[i], i);
    }
}

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nMaximum capacity reached.\n");
        return;
    }

    printf("\nADD STUDENT\n");
    printLine();

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    if (students[*count].id <= 0)
    {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter initial: ");
    scanf(" %c", &students[*count].initial);

    printf("Enter progress (0 - 100): ");
    scanf("%f", &students[*count].progress);

    if (students[*count].progress < 0 || students[*count].progress > 100)
    {
        printf("Invalid progress.\n");
        return;
    }

    setStatusFromProgress(&students[*count]);

    (*count)++;

    printf("Student added successfully.\n");
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

    printf("\nEDIT STUDENT\n");
    printLine();
    printf("Enter student ID to edit: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;

            printf("Current initial: %c\n", students[i].initial);
            printf("Enter new initial: ");
            scanf(" %c", &newInitial);

            printf("Current progress: %.2f\n", students[i].progress);
            printf("Enter new progress (0 - 100): ");
            scanf("%f", &newProgress);

            if (newProgress < 0 || newProgress > 100)
            {
                printf("Invalid progress.\n");
                return;
            }

            students[i].initial = newInitial;
            students[i].progress = newProgress;
            setStatusFromProgress(&students[i]);

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

    printf("\nDELETE STUDENT\n");
    printLine();
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
            return;
        }
    }

    if (!found)
    {
        printf("No student found with that ID.\n");
    }
}

void searchStudentById(struct Student students[], int count)
{
    int id;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo records available for search.\n");
        return;
    }

    printf("\nSEARCH STUDENT\n");
    printLine();
    printf("Enter student ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;
            showStudent(students[i], i);

            printf("Interpretation: ");
            if (students[i].progress < 40 && students[i].status == FAIL)
            {
                printf("Critical warning - very low progress.\n");
            }
            else if (students[i].progress >= 40 && students[i].progress < 50 && students[i].status == FAIL)
            {
                printf("Warning - close to passing.\n");
            }
            else if (students[i].progress >= 50 && students[i].progress < 70 && students[i].status == PASS)
            {
                printf("Recommendation - more practice is needed.\n");
            }
            else if (students[i].progress >= 70 && students[i].progress < 85 && students[i].status == PASS)
            {
                printf("Good result - continue improving.\n");
            }
            else if (students[i].progress >= 85 && students[i].status == EXCELLENT)
            {
                printf("Excellent result - keep this level.\n");
            }
            else
            {
                printf("Record is valid and stable.\n");
            }

            return;
        }
    }

    if (!found)
    {
        printf("No student found with that ID.\n");
    }
}

void updateProgressWithPointer(struct Student *s)
{
    float newProgress;

    printf("Current progress: %.2f\n", s->progress);
    printf("Enter new progress (0 - 100): ");
    scanf("%f", &newProgress);

    if (newProgress < 0 || newProgress > 100)
    {
        printf("Invalid progress.\n");
        return;
    }

    s->progress = newProgress;
    setStatusFromProgress(s);

    printf("Progress updated through pointer.\n");
}

void updateStudentById(struct Student students[], int count)
{
    int id;
    int i;

    if (count == 0)
    {
        printf("\nNo records available to update.\n");
        return;
    }

    printf("\nUPDATE STUDENT PROGRESS\n");
    printLine();
    printf("Enter student ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            updateProgressWithPointer(&students[i]);
            return;
        }
    }

    printf("No student found with that ID.\n");
}

void showReport(struct Student students[], int count)
{
    int i;
    int failCount = 0, passCount = 0, excellentCount = 0;
    float total = 0, average, highest, lowest;

    if (count == 0)
    {
        printf("\nNo records available for report.\n");
        return;
    }

    highest = students[0].progress;
    lowest = students[0].progress;

    for (i = 0; i < count; i++)
    {
        total += students[i].progress;

        if (students[i].status == FAIL)
        {
            failCount++;
        }
        else if (students[i].status == PASS)
        {
            passCount++;
        }
        else
        {
            excellentCount++;
        }

        if (students[i].progress > highest)
        {
            highest = students[i].progress;
        }

        if (students[i].progress < lowest)
        {
            lowest = students[i].progress;
        }
    }

    average = total / count;

    printf("\nREPORT\n");
    printLine();
    printf("Total records      : %d\n", count);
    printf("Average progress   : %.2f\n", average);
    printf("Highest progress   : %.2f\n", highest);
    printf("Lowest progress    : %.2f\n", lowest);
    printf("Fail count         : %d\n", failCount);
    printf("Pass count         : %d\n", passCount);
    printf("Excellent count    : %d\n", excellentCount);

    if (average < 50)
    {
        printf("Overall result     : Needs improvement\n");
    }
    else if (average < 80)
    {
        printf("Overall result     : Good progress\n");
    }
    else
    {
        printf("Overall result     : Excellent progress\n");
    }

    printLine();
}

void showRanking(struct Student students[], int count)
{
    int i, j;
    struct Student temp;
    struct Student ranked[MAX_STUDENTS];

    if (count == 0)
    {
        printf("\nNo records available for ranking.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        ranked[i] = students[i];
    }

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (ranked[j].progress > ranked[i].progress)
            {
                temp = ranked[i];
                ranked[i] = ranked[j];
                ranked[j] = temp;
            }
        }
    }

    printf("\nRANKING BY PROGRESS\n");
    printLine();

    for (i = 0; i < count; i++)
    {
        printf("Rank #%d\n", i + 1);
        printf("ID       : %d\n", ranked[i].id);
        printf("Initial  : %c\n", ranked[i].initial);
        printf("Progress : %.2f\n", ranked[i].progress);
        printf("Status   : ");
        printStatus(ranked[i].status);
        printf("\n");
        printLine();
    }
}

void showMenu()
{
    printf("\nSTUDENT PROGRESS TRACKER\n");
    printLine();
    printf("1. Add student\n");
    printf("2. Show students\n");
    printf("3. Edit student\n");
    printf("4. Delete student\n");
    printf("5. Search student by ID\n");
    printf("6. Update progress with pointer\n");
    printf("7. Show report\n");
    printf("8. Show ranking\n");
    printf("9. Exit\n");
    printLine();
    printf("Choice: ");
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        showMenu();
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
                editStudentById(students, count);
                break;
            case 4:
                deleteStudentById(students, &count);
                break;
            case 5:
                searchStudentById(students, count);
                break;
            case 6:
                updateStudentById(students, count);
                break;
            case 7:
                showReport(students, count);
                break;
            case 8:
                showRanking(students, count);
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 9);

    return 0;
}
