/**
    Name    : menu.h
    Purpose : biblioth�que qui contient les fontions pour faire appel aux menus
    Authors : YOSSO Jean-Pierre Essotina && KPONOU Ephra�m
**/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
// D�clarations des fonctions
void menuJeu();              // G�re le menu de s�lection des niveaux de jeu
void menu();                 // Affiche le menu principal (Jouer/Historique/Quitter)
void menuHistorique();       // G�re l'affichage de l'historique des parties

// D�clarations des variables globales (si elles existent dans d'autres fichiers)
extern int authenticated;    // Variable globale pour l'authentification
extern char pseudo[20];      // Variable globale pour stocker le pseudo


#endif // MENU_H_INCLUDED
