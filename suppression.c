#include "modification.h"
#include "rechercherColonne.h"
#include "suppression.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void supprimerLigne(char nomT[30], int indice, char colonne[30], char initialValue[30]) {
    char chaine[50], value1[30], value2[30], value3[30], colonne1[30], colonne2[30], colonne3[30], colonne4[30];
    FILE* table = fopen(nomT, "r");

    int c = rechercherNbColonne(nomT), val = 0, a = 0, i = 0;
    switch (c) {
        case 1:
            while (fgets(chaine, 50, table) != NULL) {
                val++;
                if (val == 1)
                    fscanf(table, "%s ", colonne1);
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
        default:
            printf(">>%s column does not exist\n", colonne);
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
                            if (strcmp(initialValue, value1) == 0) {
                                i = 1;
                            } else {
                                FILE* new = fopen("oklahoma", "a+");
                                if (val == 1) {
                                    fprintf(new, "%s", chaine);
                                    fprintf(new, "%s\n", value1);
                                }
                                else
                                    fprintf(new, "%s\n", value1);
                                fclose(new);
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
                            if (strcmp(initialValue, value1) == 0) {
                                i = 1;
                            } else {

                                FILE* new = fopen("oklahoma", "a+");
                                if (val == 1) {
                                    fprintf(new, "%s", chaine);
                                    fprintf(new, "%s %s\n", value1, value2);
                                }
                                else
                                    fprintf(new, "%s %s\n", value1, value2);
                                fclose(new);
                            }
                        }
                        if (a == 2) {
                            fscanf(table, "%s %s", value1, value2);
                            if (strcmp(initialValue, value2) == 0) {
                                i = 1;
                            } else {
                                FILE* new = fopen("oklahoma", "a+");
                                if (val == 1) {
                                    fprintf(new, "%s", chaine);
                                    fprintf(new, "%s %s\n", value1, value2);
                                }
                                else
                                    fprintf(new, "%s %s\n", value1, value2);
                                fclose(new);
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
                            if (strcmp(initialValue, value1) == 0) {
                                i = 1;
                            } else {
                                FILE* new = fopen("oklahoma", "a+");
                                if (val == 1) {
                                    fprintf(new, "%s", chaine);
                                    fprintf(new, "%s %s %s\n", value1, value2, value3);
                                }
                                else
                                    fprintf(new, "%s %s %s\n", value1, value2, value3);
                                fclose(new);
                            }
                        }
                        if (a == 2) {
                            fscanf(table, "%s %s %s", value1, value2, value3);
                            if (strcmp(initialValue, value2) == 0) {
                                i = 1;
                            } else {
                                FILE* new = fopen("oklahoma", "a+");
                                if (val == 1) {
                                    fprintf(new, "%s", chaine);
                                    fprintf(new, "%s %s %s\n", value1, value2, value3);
                                }
                                else
                                    fprintf(new, "%s %s %s\n", value1, value2, value3);
                                fclose(new);
                            }
                        }
                        if (a == 3) {
                            fscanf(table, "%s %s %s", value1, value2, value3);
                            if (strcmp(initialValue, value3) == 0) {
                                i = 1;
                            } else {
                                FILE* new = fopen("oklahoma", "a+");
                                if (val == 1) {
                                    fprintf(new, "%s", chaine);
                                    fprintf(new, "%s %s %s\n", value1, value2, value3);
                                }
                                else
                                    fprintf(new, "%s %s %s\n", value1, value2, value3);
                                fclose(new);
                            }
                        }
                    }
                }
                break;
        }
        if (a != 0) {

            remove(nomT);
            rename("oklahoma", nomT);
        }
        if (i != 0) printf(">>succesfull\n");
    }
    if (a == 0) {
        printf(">>%s column does not exist\n", colonne);
        remove("oklahoma");
    }
    if (i == 0) printf(">>%s does not exist in this table\n", initialValue);
}
void appelerFonctionSuppression(char nomT[30]) {
    char select1[30], select2[30] = " ", select3[30], select4[30] = " ", chaine[50];
    int indice = 0;

    printf(">>");
    scanf("%s %s %s %s", select1, select2, select3, select4);
    if (strcmp(select1, "delete") == 0 && strcmp(select2, "where") == 0 && strcmp(select3, " ") != 0 && strcmp(select4, " ") != 0) {
        FILE* table = fopen(nomT, "r");
        while (fgets(chaine, 50, table) != NULL) {
            indice++;
        }
        fclose(table);
        supprimerLigne(nomT, indice, select3, select4);
    } else {
        printf(">>unknown command\n");
    }
}

