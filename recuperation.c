#include "recuperation.h"
#include "rechercherColonne.h"
#include "enregistrement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recupererTout(char nomB[30], char nomT[30]) {
    char chaine1[50], chaine2[50], value1[30], value2[30], value3[30];
    int indice = 0, val = 0;
    int n = verificationExistenceTable(nomB, nomT);
    if (n) {
        FILE* table = fopen(nomT, "r");
        while (fgets(chaine2, 50, table) != NULL) {
            indice++;
        }
        fclose(table);
        selectionColonne(nomT, indice);

    } else {
        printf(">>%s does not exist in the database\n", nomT);
    }
}

void selectionColonne(char nomT[30], int indice) {
    char chaine[50], value1[30], value2[30], value3[30];
    int c = rechercherNbColonne(nomT), val = 0;
    FILE* table = fopen(nomT, "r");
    switch (c) {
        case 1:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val <= indice - 1) {
                    fscanf(table, "%s", value1);
                    printf("| %-20s|\n", value1);
                    printf("-----------------------\n");
                }
            }
            break;
        case 2:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val <= indice - 1) {
                    fscanf(table, "%s %s", value1, value2);
                    printf("| %-20s| %-23s|\n", value1, value2);
                    printf("------------------------------------------------\n");
                }
            }
            break;
        case 3:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val <= indice - 1) {
                    fscanf(table, "%s %s %s", value1, value2, value3);
                    printf("| %-15s| %-23s   | %-15s|\n", value1, value2, value3);
                    printf("---------------------------------------------------------------\n");
                }
            }
            break;
    }
    fclose(table);
}

void recupererParSelection1(char nomT[30], int indice, char colonne[30], char value[30]) {
    char chaine[50], value1[30], value2[30], value3[30], colonne1[30], colonne2[30], colonne3[30], colonne4[30];
    FILE* table = fopen(nomT, "r");
    int c = rechercherNbColonne(nomT), val = 0, a = 0;
    switch (c) {
        case 1:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val == 1)
                    fscanf(table, "%s ", colonne1);
                printf("| %-20s|\n", colonne1);
                printf("-----------------------\n");
                if (strcmp(colonne, colonne1) == 0) {
                    a = 1;
                }
            }
            break;
        case 2:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val == 1) {
                    fscanf(table, "%s %s", colonne1, colonne2);
                    printf("| %-20s| %-23s|\n", colonne1, colonne2);
                    printf("------------------------------------------------\n");
                    if (strcmp(colonne, colonne1) == 0) {
                        a = 1;
                    } else if (strcmp(colonne, colonne2) == 0) {
                        a = 2;
                    }
                }
            }
            break;
        case 3:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val == 1) {
                    fscanf(table, "%s %s %s", colonne1, colonne2, colonne3);
                    printf("| %-15s| %-23s   | %-15s|\n", colonne1, colonne2, colonne3);
                    printf("---------------------------------------------------------------\n");
                    if (strcmp(colonne, colonne1) == 0) {
                        a = 1;
                    } else if (strcmp(colonne, colonne2) == 0) {
                        a = 2;
                    } else if (strcmp(colonne, colonne3) == 0) {
                        a = 3;
                    }
                }
            }
            break;
    }
    fclose(table);
    table = fopen(nomT, "r");
    val = 0;
    if (a == 1 || a == 2 || a == 3) {
        switch (c) {
            case 1:
                while (fgets(chaine, 50, table) != NULL) {
                    val++;
                    if (val <= indice - 1) {
                        if (a == 1) {
                            fscanf(table, "%s", value1);
                            if (strcmp(value, value1) == 0) {
                                printf("| %-20s|\n", value1);
                                printf("-----------------------\n");
                            }
                        }
                    }
                }
                break;
            case 2:
                while (fgets(chaine, 50, table) != NULL) {
                    val++;
                    if (val <= indice - 1) {
                        if (a == 1) {
                            fscanf(table, "%s %s", value1, value2);
                            if (strcmp(value, value1) == 0) {
                                printf("| %-20s| %-23s|\n", value1, value2);
                                printf("------------------------------------------------\n");
                            }
                        }
                        if (a == 2) {
                            fscanf(table, "%s %s", value1, value2);
                            if (strcmp(value, value2) == 0) {
                                printf("| %-20s| %-23s|\n", value1, value2);
                                printf("------------------------------------------------\n");
                            }
                        }
                    }
                }
                break;
            case 3:
                while (fgets(chaine, 50, table) != NULL) {
                    val++;
                    if (val <= indice - 1) {
                        if (a == 1) {
                            fscanf(table, "%s %s %s", value1, value2, value3);
                            if (strcmp(value, value1) == 0) {
                                printf("| %-15s| %-23s   | %-15s|\n", value1, value2, value3);
                                printf("---------------------------------------------------------------\n");
                            }
                        }
                        if (a == 2) {
                            fscanf(table, "%s %s %s", value1, value2, value3);
                            if (strcmp(value, value2) == 0) {
                                printf("| %-15s| %-23s   | %-15s|\n", value1, value2, value3);
                                printf("---------------------------------------------------------------\n");
                            }
                        }
                        if (a == 3) {
                            fscanf(table, "%s %s %s", value1, value2, value3);
                            if (strcmp(value, value3) == 0) {
                                printf("| %-15s| %-23s   | %-15s|\n", value1, value2, value3);
                                printf("---------------------------------------------------------------\n");
                            }
                        }
                    }
                }
                break;
        }
    }
}

void appelerFonctionRecupertation(char nomB[30], char nomT[30]) {
    char select1[30], select2[30], select3[30], select4[30] = " ", select5[30] = " ", chaine[50];
    int indice = 0;

    printf(">>");
    scanf("%s %s %s %s %s", select1, select2, select3, select4, select5);
    if (strcmp(select1, "select") == 0 && strcmp(select2, "*") == 0 && strcmp(select3, "for") == 0 && strcmp(select4, "results") == 0 && strcmp(select5, "all") == 0) {
        recupererTout(nomB, nomT);
    } else if (strcmp(select1, "select") == 0 && strcmp(select2, "*") == 0 && strcmp(select3, "where") == 0 && strcmp(select4, " ") != 0 && strcmp(select5, " ") != 0) {
        FILE* table = fopen(nomT, "r");
        while (fgets(chaine, 50, table) != NULL) {
            indice++;
        }
        recupererParSelection1(nomT, indice, select4, select5);
    } else {
        printf(">>unknown command\n");
    }
}





