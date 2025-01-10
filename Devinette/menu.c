/**
    Name    :
    Purpose :
    Authors :
    Date    :
**/
#include <stdio.h>
#include "menu.h"
#include "fonctions.h"

void menu(){

    int choix = 0;

    printf("\n\t\t=== SELECTIONNER UNE OPTION ===\n\n");

    printf("\n1. AJOUTER UN UTILISATEUR") ;
    printf("\n2. SUPPRIMER UN UTILISATEUR") ;
    printf("\n3. JOUER") ;
    printf("\n4. QUITTER") ;

   do
   {
     printf("\nSelectionner une option (1-4) : ") ;
     scanf("%d",&choix);
   }while(choix < 1 || choix > 4) ;


    switch (choix)
    {
            case 1 :
                 readUser();
                break ;
            case 2 :
                printf("ajout") ;
                break ;
            case 3:
                getRandom() ;
                game() ;
                break;
            case 4 :
                break;
            default :
                printf("erreur de choix !!") ;
                break;
    }
}
