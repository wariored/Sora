
/* 
 * File:   enregistrement.h
 * Author: macbookpro
 *
 * Created on 13 mars 2017, 00:07
 */

#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

typedef struct enregistrement {
char colonne1[50];
char colonne2[50];
char colonne3[50];

} Enregistrement;
void inserer(char nomT[20], Enregistrement ajout);
void commandeInsertion(int c, char tab3[30]);
int verificationExistenceTable(char nomB[30], char nomT[30]);

#endif /* ENREGISTREMENT_H */

