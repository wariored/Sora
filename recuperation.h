/* 
 * File:   recuperation.h
 * Author: macbookpro
 *
 * Created on 14 mars 2017, 22:10
 */

#ifndef RECUPERATION_H
#define RECUPERATION_H

void recupererTout(char nomB[30], char nomT[30]);
void selectionColonne(char nomT[30], int indice);
void recupererParSelection1(char nomT[30], int indice, char colonne[30],char value[30]);
void appelerFonctionRecupertation(char nomB[30], char nomT[30]);
#endif /* RECUPERATION_H */

