#include <stdio.h> // library për input/output

int main()
{
    // deklarimi i variablave
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    // marrja e input-it
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali); // hapësirë për input korrekt

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjidh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // kontrolli i moshes
    if (mosha < 15 || mosha > 25)
    {
        printf("\nNuk ploteson kushtin e moshes!\n");
    }
    else
    {
        printf("\nMosha eshte valide.\n");
    }

    // klasifikimi sipas pikeve
    printf("Vleresimi: ");
    if (piket < 50)
    {
        printf("Nevojitet me shume ushtrim\n");
    }
    else if (piket < 80)
    {
        printf("Gati per vazhdim\n");
    }
    else
    {
        printf("Gati per sfide\n");
    }

    // zgjedhja e punetorise me switch
    printf("Punetoria e zgjedhur: ");
    switch (opsioni)
    {
        case 1:
            printf("Programim bazik\n");
            break; // ndal te ky rast
        case 2:
            printf("Web Development\n");
            break;
        case 3:
            printf("Cyber Security\n");
            break;
        default:
            printf("Opsion i pavlefshem\n"); // input jo valid
    }

    // permbledhja finale
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", piket);
    printf("Opsioni: %d\n", opsioni);

    return 0; // fundi i programit
}
