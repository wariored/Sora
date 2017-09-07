#include "enregistrement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserer(char nomT[20], Enregistrement ajout) {
    FILE* table = fopen(nomT, "r");
    if (table != NULL) {
        table = fopen(nomT, "a+");
        fprintf(table, "%s ", ajout.colonne1);
        fprintf(table, "%s ", ajout.colonne2);
        fprintf(table, "%s \n", ajout.colonne3);
        fclose(table);
    } else {
        printf(">>table does not exist");
    }

}

void commandeInsertion(int c, char tab3[30]) {
    char tab4[50], tab5[50], tab6[50];
    printf(">>columns' name or values(names, if you just created the table): ");

    switch (c) {
        case 1:
            scanf("%s", tab4);
            break;
        case 2:
            scanf("%s %s", tab4, tab5);
            break;
        case 3:
            scanf("%s %s %s", tab4, tab5, tab6);
            break;
    }
    Enregistrement ajout;
    strcpy(ajout.colonne1, tab4);
    strcpy(ajout.colonne2, tab5);
    strcpy(ajout.colonne3, tab6);
    inserer(tab3, ajout);
}

int verificationExistenceTable(char nomB[30], char nomT[30]) {
    char chaine[30];
    int search = 0;
    FILE* baseDonnee = fopen(nomB, "r");
    while (fgets(chaine, 30, baseDonnee) != NULL) {
        chaine[strlen(chaine) - 1] = '\0';
        if (strcmp(chaine, nomT) == 0) {
            search = 1;
            break;
        }
    }
    return search;
}
