/**
    Name    : fonction.h
    Purpose : bibliothèque personnalisée qui contient toute les fonctions
    Authors :YOSSO Jean-Pierre Essotina && KPONOU Ephraïm
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

// Déclarations des fonctions
void welcome();
void getRandom(int limitNbre);
void getPersonnalizeRandom();
void playGame(int NBRE_ARRET);
void game(int NBRE_ARRET);
void personnalizeGame();
void enregistrerUtilisateurAvantJeu();
void ecrireTitre(FILE *fichier);
void Calcul_statistiques(int limitNbre);
void Calcul_statistiques_d();
void Calcul_statistiques_m();
void Calcul_statistiques_l();
void afficherHistorique(char *pseudo);

#endif // FONCTIONS_H_INCLUDED
