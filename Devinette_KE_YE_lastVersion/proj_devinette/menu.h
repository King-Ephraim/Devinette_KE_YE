/**
    Name    : menu.h
    Purpose : bibliothèque qui contient les fontions pour faire appel aux menus
    Authors : YOSSO Jean-Pierre Essotina && KPONOU Ephraïm
**/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
// Déclarations des fonctions
void menuJeu();              // Gère le menu de sélection des niveaux de jeu
void menu();                 // Affiche le menu principal (Jouer/Historique/Quitter)
void menuHistorique();       // Gère l'affichage de l'historique des parties

// Déclarations des variables globales (si elles existent dans d'autres fichiers)
extern int authenticated;    // Variable globale pour l'authentification
extern char pseudo[20];      // Variable globale pour stocker le pseudo


#endif // MENU_H_INCLUDED
