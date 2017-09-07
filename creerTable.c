#include "creerTable.h"
#include "enregistrement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creerTable(char nomTable[20], char nomBase[20]) {
    char nom[20];
    FILE *fichier = fopen(nomTable, "r");
    if (fichier != NULL) {
        printf(">>file already exists\n");
    } else {
        char n[3], k;
        printf(">>how many colums? ");
        scanf("%s", n);
        k = atoi(n);
        fichier = fopen(nomTable, "a+");
        fprintf(fichier, "%s\n", n);
        fseek(fichier, 0, SEEK_END);
        commandeInsertion(k, nomTable);
        printf(">>successful\n");
        fclose(fichier);
        fichier = fopen(nomBase, "a+");
        fprintf(fichier, "%s\n", nomTable);
        fclose(fichier);
    }


}