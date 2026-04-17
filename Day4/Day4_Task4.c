#include <stdio.h>

struct Student
{
    int id;
    float progress;
};

void updateProgress(struct Student *s)
{
    float newProgress;

    printf("Current progress: %.2f\n", s->progress);
    printf("Enter new progress: ");
    scanf("%f", &newProgress);

    s->progress = newProgress; // ndryshon vlerën reale

    printf("Updated progress: %.2f\n", s->progress);
}

int main()
{
    struct Student students[2] = {
        {1, 40.0},
        {2, 70.0}
    };

    int id;

    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < 2; i++)
    {
        if (students[i].id == id)
        {
            updateProgress(&students[i]); // 🔥 pointer
            break;
        }
    }

    printf("\nAfter update:\n");

    for (int i = 0; i < 2; i++)
    {
        printf("ID: %d, Progress: %.2f\n", students[i].id, students[i].progress);
    }

    return 0;
}
