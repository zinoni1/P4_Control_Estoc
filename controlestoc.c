#include <stdio.h>

typedef struct
{
    int id;
    char nom[30];
    int quantitat;
    float preu;
} Producte;

void afegirProducte(Producte *producte, int *numProductes, Producte magatzem[]);
void mostrarProductes(Producte magatzem[], int numProductes);
void cercarProducte(Producte magatzem[], int numProductes);
void vendreProducte(Producte magatzem[], int numProductes);
void reposarProducte(Producte magatzem[], int numProductes);
void calcularValorTotal(Producte magatzem[], int numProductes);
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
            afegirProducte(&magatzem[numProductes], &numProductes, magatzem);
            break;
        case 2:
            printf("Mostrar productes\n");
            mostrarProductes(magatzem, numProductes);
            break;
        case 3:
            printf("Vendre producte\n");
            vendreProducte(magatzem, numProductes);
            break;
        case 4:
            printf("Reposar producte\n");
            reposarProducte(magatzem, numProductes);
            break;
        case 5:
            printf("Cercar producte per ID\n");
            cercarProducte(magatzem, numProductes);

            break;
        case 6:
            printf("Valor total del magatzem\n");
            calcularValorTotal(magatzem, numProductes);
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

void afegirProducte(Producte *producte, int *numProductes, Producte magatzem[]){
    if (*numProductes >= 10) {
        printf("Magatzem ple!\n");
    } else {
        static int nextId = 1;
        producte->id = nextId++;
        printf("Introdueix el nom del producte: ");
        scanf("%s", producte->nom);
        printf("Introdueix la quantitat: ");
        scanf("%d", &producte->quantitat);
        printf("Introdueix el preu: ");
        scanf("%f", &producte->preu);
        (*numProductes)++;
    }
}
    
void mostrarProductes(Producte magatzem[], int numProductes){
    if (numProductes == 0) {
        printf("No hi ha productes al magatzem.\n");
        return;
    } else {
        for (int i = 0; i < numProductes; i++) {
            printf("ID: %d, Nom: %s, Quantitat: %d, Preu: %.2f\n", magatzem[i].id, magatzem[i].nom, magatzem[i].quantitat, magatzem[i].preu);
        }
    }
}
void cercarProducte(Producte magatzem[], int numProductes){
    int id;
    printf("Introdueix l'id del producte a cercar: ");
    scanf("%d", &id);

    for (int i = 0; i < numProductes; i++) {
        if (magatzem[i].id == id){
            printf("Producte trobat: ID: %d, Nom: %s, Quantitat: %d, Preu: %.2f\n",
                   magatzem[i].id, magatzem[i].nom, magatzem[i].quantitat, magatzem[i].preu);
            return;
        }
    }
    printf("Producte no trobat\n");
}
void reposarProducte(Producte magatzem[], int numProductes){
    int id, quantitat;

    for(int i = 0; i < numProductes; i++) {
        printf("\n");
        printf("ID: %d, Nom: %s, Quantitat: %d, Preu: %.2f\n", magatzem[i].id, magatzem[i].nom, magatzem[i].quantitat, magatzem[i].preu);
    }
    printf("\n");
    printf("Introdueix l'id del producte a reposar: ");
    scanf("%d", &id);
    printf("Introdueix la quantitat a reposar: ");
    scanf("%d", &quantitat);

    for (int i = 0; i < numProductes; i++) {
        if (magatzem[i].id == id) {
            magatzem[i].quantitat += quantitat;
            printf("----------------------------------------\n");
            printf("Quantitat anterior al reposat: %d\n", magatzem[i].quantitat - quantitat);
            printf("Reposat realitzat. Quantitat actual: %d\n", magatzem[i].quantitat);
            printf("----------------------------------------\n");
            return;
        }
    }
    printf("Producte no trobat\n");
}
void vendreProducte(Producte magatzem[], int numProductes){
    int id, quantitat;

    for(int i = 0; i < numProductes; i++) {
        printf("ID: %d, Nom: %s, Quantitat: %d, Preu: %.2f\n", magatzem[i].id, magatzem[i].nom, magatzem[i].quantitat, magatzem[i].preu);
    }

    printf("Introdueix l'id del producte a vendre: ");
    scanf("%d", &id);
    printf("Introdueix la quantitat a vendre: ");
    scanf("%d", &quantitat);

    for (int i = 0; i < numProductes; i++) {
        if (magatzem[i].id == id) {
            if (magatzem[i].quantitat >= quantitat) {
                magatzem[i].quantitat -= quantitat;
                printf("----------------------------------------\n");
                printf("Quantitat anterior a la venta: %d\n", magatzem[i].quantitat + quantitat);
                printf("Venda realitzada. Quantitat restant: %d\n", magatzem[i].quantitat);
                printf("----------------------------------------\n");
            } else {
                printf("No hi ha suficient estoc per a aquesta venda.\n");
            }
            return;
        }
    }
    printf("Producte no trobat\n");
}

void calcularValorTotal(Producte magatzem[], int numProductes){
    float valorTotal = 0.0;

    for (int i = 0; i < numProductes; i++) {
        valorTotal += magatzem[i].quantitat * magatzem[i].preu;
    }
    printf("----------------------------------------\n");
    printf("Valor total del magatzem: %.2f\n", valorTotal);
    printf("----------------------------------------\n");
}