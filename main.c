/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Konteye macbookpro
 *
 * Created on 12 mars 2017, 02:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creerTable.h"
#include "enregistrement.h"
#include "rechercherColonne.h"
#include "recuperation.h"
#include "modification.h"
#include "suppression.h"

void connectionCreation() {
    char tab1[10], tab2[10], tab3[30] = "hh1";
    char tab4[20], tab5[20], tab6[20] = "h1h1";
    char creer[1] = "n", verify[1] = "y", quit[2] = " ";
    printf("WELCOME TO SORA SGBD\n");

    do {
        printf(">>");
        scanf("%s %s %s", tab1, tab2, tab3);
        switch (tab1[1]) {
            case 'r':
                if (strcmp(tab1, "create") == 0 && strcmp(tab2, "database") == 0 && strcmp(tab3, "hh1") != 0) {
                    FILE *fichier = fopen(tab3, "r");

                    if (fichier == NULL) {
                        fichier = fopen(tab3, "a+");

                        fclose(fichier);
                        FILE *bases = fopen("bases", "a+");
                        fprintf(bases, "%s\n", tab3);
                        fclose(bases);
                        printf(">>successful! Do you want to create table(y/n) ");
                        scanf("%s", creer);
                        if (strcmp(creer, "y") == 0) {
                            do {
                                printf(">>entrer command\n");
                                printf(">>");
                                scanf("%s %s %s", tab4, tab5, tab6);
                                if (strcmp(tab4, "create") == 0 && strcmp(tab5, "table") == 0 && strcmp(tab6, "h1h1") != 0) {

                                    creerTable(tab6, tab3);

                                    printf(">>want to create another table(y/n) ");
                                    scanf("%s", verify);
                                } else {
                                    printf(">>unknown command\n");
                                    fflush(stdin);
                                    printf(">>try again(y/n) ");
                                    scanf("%s", verify);
                                }
                            } while (strcmp(verify, "y") == 0);

                        }
                    } else {
                        printf(">>database already exist\n");
                    }

                } else {
                    printf(">>unknowm command\n");
                }

                break;
            case 'o':
                if (strcmp(tab1, "connect") == 0 && strcmp(tab2, "database") == 0 && strcmp(tab3, "hh1") != 0) {
                    int i = verificationExistenceTable("bases", tab3);

                    if (i) {
                        printf(">>connected\n");
                        do {
                            printf(">>");
                            scanf("%s %s %s", tab4, tab5, tab6);

                            if (strcmp(tab4, "create") == 0 && strcmp(tab5, "table") == 0 && strcmp(tab6, "hh1") != 0) {

                                creerTable(tab6, tab3);
                            } else if (strcmp(tab4, "insert") == 0 && strcmp(tab5, "into") == 0 && strcmp(tab6, "hh1") != 0) {
                                int search = verificationExistenceTable(tab3, tab6);

                                if (search) {
                                    int n = rechercherNbColonne(tab6);
                                    printf(">>");
                                    printf("%d columns\n", n);
                                    commandeInsertion(n, tab6);
                                } else {
                                    printf(">>%s does not exist in the database\n", tab6);
                                }
                            } else if (strcmp(tab4, "query") == 0 && strcmp(tab5, "in") == 0 && strcmp(tab6, "hh1") != 0) {
                                int l = verificationExistenceTable(tab3, tab6);
                                if (l) {
                                    char tab[6];
                                    printf(">>modify, select or delete? ");
                                    scanf("%s", tab);
                                    if (strcmp(tab, "modify") == 0) {

                                        appelerFonctionModification(tab6);
                                    } else if (strcmp(tab, "select") == 0) {
                                        appelerFonctionRecupertation(tab3, tab6);
                                    } else if (strcmp(tab, "delete") == 0) {
                                        appelerFonctionSuppression(tab6);
                                    } else {

                                        printf(">>unknown command\n");
                                    }


                                } else {
                                    printf(">>%s does not exist in the database\n", tab6);
                                }
                            }


                            else {

                                printf(">>unknown command\n");
                            }
                            fflush(stdin);
                            printf(">>again?(y/n) ");
                            scanf("%s", verify);

                        } while (strcmp(verify, "y") == 0);
                        printf(">>deconnected\n");
                    } else {
                        printf(">>database does not exist\n");
                    }
                } else {
                    printf(">>unknowm command\n");
                }
                break;
            default:
                printf(">>unknowm command\n");
                break;
        }
        printf(">>want to quit(y/n) ");
        scanf("%s", quit);
        if (strcmp(quit, "y") == 0) {
            exit(-1);
        }

    } while (tab1[1] != '!' && tab1[2] != '!');
}

int main(int argc, char** argv) {
    connectionCreation();
    return (EXIT_SUCCESS);
}

