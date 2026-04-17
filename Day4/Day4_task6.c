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

    printf("\n--- Student Ranking By Progress ---\n");

    for (i = 0; i < count; i++)
    {
        printf("Rank #%d\n", i + 1);
        printf("ID: %d\n", ranked[i].id);
        printf("Initial: %c\n", ranked[i].initial);
        printf("Progress: %.2f\n", ranked[i].progress);
        printf("Status: ");
        printStatus(ranked[i].status);
        printf("\n\n");
    }
}
