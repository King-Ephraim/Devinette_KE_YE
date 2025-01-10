/**
    Name    :
    Purpose :
    Authors :
    Date    :
**/
#include <stdio.h>
#include "fonctions.h"
#define NBRE_TANTATIVES_TOTAL 21

// Déclaration des variables globales
int nbreAleatoire, entreUser;
void welcome()
{
    printf("\033[1m");
    printf("*************************************\n");
    printf("******    JEU DE DEVINETTE    *******\n");
    printf("*************************************\n");
    printf("\033[0m");
    printf("\033[4mRègle de jeu \033[0m: \nLe jeu consiste à deviner le nombre aléatoire\n");
    printf("généré tout en vous indiquant si vous y êtes ou non \n\n");
}

void getRandom()
{
    // declaration de la variable de la borne maximale
    int limitNbre;

    srand(time(NULL));
    printf("Entrez la borne maximale : ");
    scanf("%d", &limitNbre);

    while( limitNbre < 10 )
    {
        printf("Entrez la borne maximale( borne doit etre superieure a 10 ) : ");
        scanf("%d", &limitNbre);
    }

    // generation du nombre aleatoire
    nbreAleatoire = rand() % (limitNbre + 1);
}

void game()
{
    int nbre_tentatives = 0 ;
    int NBRE_ARRET = 0 ;

    welcome() ;

    while(NBRE_ARRET < NBRE_TANTATIVES_TOTAL)
    {

        printf("\nVeuillez entrer le nombre que vous pensez être le bon :" );
        scanf("%d", &entreUser);

        if( nbreAleatoire > entreUser)
        {
            printf("\nnombre secret plus grand\n");
        }
        else if(nbreAleatoire < entreUser)
        {
            printf("\nnombre secret  plus petit\n");
        }
        nbre_tentatives++ ;
        NBRE_ARRET ++ ;

    }


    if (entreUser == nbreAleatoire)
    {
        if(nbre_tentatives < 4)
        {
            printf(" VOUS ÊTES UN SUPER VOYANT") ;
        }
        else if( nbre_tentatives > 3 && nbre_tentatives < 7)
        {
            printf(" VOUS ÊTES UN SAGE VOYANT") ;
        }
        else if (nbre_tentatives > 6 && nbre_tentatives < 10 )
        {
            printf(" VOUS ÊTES UN APPRENTI VOYANT") ;
        }
        else if ( nbre_tentatives >= 10)
        {
            printf(" VOUS ÊTES UN VOYANT PUSILLANIME") ;
        }

    }

}

void readUser()
{
    FILE* fichier = NULL;
    fichier = fopen("sauvegarde.txt" , "r+") ;
        if(fichier != NULL){
           char pseudo[20] ;


            printf("entrer votre pseudo : ") ;
            scanf("%s" ,pseudo);

            fprintf(fichier , "%s" ,pseudo) ;
        }
        else
        {
            printf("Impossible d'ecrire dans le fichier sauvegarde.txt") ;
        }

    fclose(fichier);
}
