void editRegjistrim(struct Regjistrim *r) {

    printf("\n--- EDIT REGJISTRIMI ---\n");

    printf("Piket aktuale: %.2lf\n", r->pike);
    printf("Piket e reja: ");
    scanf("%lf", &r->pike);

    int s;
    printf("Statusi i ri:\n");
    printf("1. Nevojitet ushtrim\n");
    printf("2. Gati per vazhdim\n");
    printf("3. Gati per sfide\n");
    printf("Zgjedhja: ");
    scanf("%d", &s);

    if(s>=1 && s<=3)
        r->status = s;
    else
        printf("Status i pavlefshem, u mbajt i vjetri.\n");

    printf("Regjistrimi u perditesua.\n");
}
