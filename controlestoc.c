#include <stdio.h>

typedef struct {
int id;
char nom[30];
int quantitat;
float preu;
} Producte;

int main() {
    int opcion;
    
    while (1) {
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
        
        switch (opcion) {
            case 1:
                printf("Afegir producte\n");
                break;
            case 2:
                printf("Mostrar productes\n");
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