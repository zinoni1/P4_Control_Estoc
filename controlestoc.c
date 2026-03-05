#include <stdio.h>

typedef struct
{
    int id;
    char nom[30];
    int quantitat;
    float preu;
} Producte;

void afegirProducte(Producte *producte);
void mostrarProductes(Producte magatzem[], int numProductes);
Producte *cercarProducte(Producte magatzem[], int numProductes, int id);
void vendreProducte(Producte magatzem[], int numProductes);
void reposarProducte(Producte magatzem[], int numProductes);
float calcularValorTotal(Producte magatzem[], int numProductes);
Producte *producteAmbMenysEstoc(Producte magatzem[], int numProductes);

int main()
{
    int opcion;
    int id;
    Producte magatzem[10];
    int numProductes = 0;

    while (1)
    {
        printf("\n=== CONTROL D'ESTOC ===\n");
        printf("1. Afegir producte\n");
        printf("2. Mostrar productes\n");
        printf("3. Vendre producte\n");
        printf("4. Reposar producte\n");
        printf("5. Cercar producte per ID\n");
        printf("6. Valor total del magatzem\n");
        printf("7. Producte amb menys estoc\n");
        printf("0. Sortir\n");
        printf("\nSelecciona una opcio: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Afegir producte\n");
            if (numProductes >= 10)
            {
                printf("Magatzem ple!\n");
                break;
            }
            afegirProducte(&magatzem[numProductes]);
            numProductes++;
            break;
        case 2:
            printf("Mostrar productes\n");
            mostrarProductes(magatzem, numProductes);
            break;
        case 3:
            printf("Vendre producte\n");
            break;
        case 4:
            printf("Reposar producte\n");
            break;
        case 5:
            printf("Cercar producte per ID\n");

            break;
        case 6:
            printf("Valor total del magatzem\n");
            break;
        case 7:
            printf("Producte amb menys estoc\n");
            break;
        case 0:
            printf("Sortint...\n");
            return 0;
        default:
            printf("Opcio invalida\n");
        }
    }

    return 0;
}

void afegirProducte(Producte *producte)
{
    static int nextId = 1;
    producte->id = nextId++;
    printf("Introdueix el nom del producte: ");
    scanf("%s", producte->nom);
    printf("Introdueix la quantitat: ");
    scanf("%d", &producte->quantitat);
    printf("Introdueix el preu: ");
    scanf("%f", &producte->preu);
}

void mostrarProductes(Producte magatzem[], int numProductes)
{
    if (numProductes == 0)
    {
        printf("No hi ha productes al magatzem.\n");
        return;
    }
    else
    {
        for (int i = 0; i < numProductes; i++)
        {
            printf("ID: %d, Nom: %s, Quantitat: %d, Preu: %.2f\n", magatzem[i].id, magatzem[i].nom, magatzem[i].quantitat, magatzem[i].preu);
        }
    }
}