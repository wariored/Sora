#include"rechercherColonne.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAILLE_MAX 1000

int rechercherNbColonne(char nomTable[30]) {
    FILE * fichier = fopen(nomTable, "r");
    char nColonne[10] = " ";
    int indice = 0;
    char chaine[TAILLE_MAX] = "";
    if (fichier != NULL) {
        //rewind(fichier);
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            indice++;
            if (indice == 1) {
                strcpy(nColonne, chaine);
            }
        }
    }
    int n = atoi(nColonne);
    fclose(fichier);
    return n;
}
