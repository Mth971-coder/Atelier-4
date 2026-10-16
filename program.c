#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LIGNES 15

/* Affiche la ligne y de l'histogramme vertical :
   une colonne "xxx" si la valeur atteint y, sinon des espaces */
void afficher_ligne_histov(int valeurs[], int taille, float y)
{
    printf("| ");
    for (int k = 0; k < taille; k++) {
        if (valeurs[k] >= y) {
            printf("xxx ");
        } else {
            printf("    ");
        }
    }
    printf("\n");
}

int main(void)
{
    int valeurs[NB_VALEURS] = { 8, 4, 12 };

    /* Recherche du maximum (étape 2) */
    int maximum = valeurs[0];
    for (int i = 1; i < NB_VALEURS; i++) {
        if (valeurs[i] > maximum) {
            maximum = valeurs[i];
        }
    }

    for (int i = 0; i < MAX_LIGNES; i++) {
        float y = (float)maximum * (MAX_LIGNES - i) / MAX_LIGNES;
        afficher_ligne_histov(valeurs, NB_VALEURS, y);
    }
    printf("+---------------------------------------\n");
    return 0;
}


