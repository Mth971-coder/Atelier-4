#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LONGUEUR 50
#define PAS 10   /* une graduation tous les 10 caractères */

/* Histogramme horizontal avec graduation et lignes de suivi '.' */
int main(void)
{
    int valeurs[NB_VALEURS] = { 8, 4, 12 };

    int maximum = valeurs[0];
    for (int i = 1; i < NB_VALEURS; i++) {
        if (valeurs[i] > maximum) {
            maximum = valeurs[i];
        }
    }
    float echelle = (float)MAX_LONGUEUR / maximum;

    for (int i = 0; i < NB_VALEURS; i++) {
        int nb_croix = (int)(valeurs[i] * echelle);
        printf("| ");
        for (int j = 1; j <= MAX_LONGUEUR; j++) {
            if (j <= nb_croix) {
                printf("x");
            } else if (j % PAS == 0) {
                printf(".");      /* ligne de suivi */
            } else {
                printf(" ");
            }
        }
        printf(" %d\n", valeurs[i]);
    }

    /* Axe */
    printf("+-");
    for (int j = 1; j <= MAX_LONGUEUR; j++) {
        printf(j % PAS == 0 ? "+" : "-");
    }
    printf("\n");

    /* Valeurs de la graduation */
    printf("  ");
    for (int j = 1; j <= MAX_LONGUEUR; j++) {
        if (j % PAS == 0) {
            printf("%-*d", PAS, (int)(j / echelle + 0.5f));
        }
    }
    printf("\n");
    return 0;
}



