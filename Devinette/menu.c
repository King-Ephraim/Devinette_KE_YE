/**
    Name    :
    Purpose :
    Authors :
    Date    :
**/
#include <stdio.h>
#include "menu.h"
#include "fonctions.h"
void menuJeu()
{

    int choixJeu = 0;

    enregistrerUtilisateurAvantJeu() ;
    printf("\n\t\t=== SELECTIONNER UN NIVEAU DE JEU ===\n\n");

    printf("\n1. DÉBUTANT") ;
    printf("\n2. MOYEN") ;
    printf("\n3. LÉGENDE") ;
    printf("\n4. PERSONNALISÉ") ;
    printf("\n5. RETOUR") ;
    printf("\n6. QUITTER") ;

    do
   {
     printf("\nSelectionner une option (1-5) : ") ;
     scanf("%d",&choixJeu);
   } while(choixJeu < 1 || choixJeu > 6) ;

    switch (choixJeu)
    {
            case 1 :
                getRandom(25) ;
                game(10) ;
                break ;
            case 2 :
                getRandom(50) ;
                game(25) ;
                break ;
            case 3 :
                getRandom(100) ;
                game(30) ;
                break ;
            case 4 :
                getRandom(10) ;
                game(10) ;
                break ;
            case 5 :
                menu() ;
                break ;
            case 6 :
                printf("Au revoir 👋👋\n");
                break ;
            default :
                printf("🛑 erreur de choix 🛑!!") ;
                break;
    }

}
void menu()
{

    int choix = 0;

    printf("\n\t\t=== SELECTIONNER UNE OPTION ===\n\n");

    printf("\n1. JOUER") ;
    printf("\n2. QUITTER") ;

   do
   {
     printf("\nSelectionner une option (1-2) : ") ;
     scanf("%d",&choix);
   }while(choix < 1 || choix > 2) ;


    switch (choix)
    {
            case 1 :
                menuJeu() ;
                break ;
            case 2 :
                printf("Au revoir 👋👋\n");
                break ;
            default :
                printf("🛑 erreur de choix !! 🛑") ;
                break;
    }
}
