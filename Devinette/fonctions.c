/**
    Name    :
    Purpose :
    Authors :
    Date    :
**/
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

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

void getRandom(int limitNbre)
{
    srand(time(NULL));
    // generation du nombre aleatoire
    nbreAleatoire = rand() % (limitNbre + 1);
}

void game(int NBRE_ARRET)
{
    int nbre_tentatives = 0;
    int entreUser;

    welcome();

    while (nbre_tentatives < NBRE_ARRET) {
        printf("\nVeuillez entrer le nombre que vous pensez être le bon : ");
        scanf("%d", &entreUser);

        if (nbreAleatoire > entreUser) {
            printf("\nLe nombre secret est plus grand !\n");
        } else if (nbreAleatoire < entreUser) {
            printf("\nLe nombre secret est plus petit !\n");
        } else {
            printf("\n🎉 Bravo ! Vous avez trouvé le nombre secret en %d tentatives !\n", nbre_tentatives + 1);
            break;  // Sortie immédiate si le joueur trouve le bon nombre
        }

        nbre_tentatives++;
    }

    if (nbre_tentatives == NBRE_ARRET) {
        printf("\n💀 Vous avez épuisé toutes vos tentatives. Le nombre secret était : %d\n", nbreAleatoire);
    } else {
        // Affichage du classement en fonction des tentatives
        if (nbre_tentatives < 4) {
            printf("🔮 VOUS ÊTES UN SUPER VOYANT !\n");
        } else if (nbre_tentatives >3 && nbre_tentatives < 7) {
            printf("🔵 VOUS ÊTES UN SAGE VOYANT !\n");
        } else if (nbre_tentatives >6 && nbre_tentatives < 10) {
            printf("🟢 VOUS ÊTES UN APPRENTI VOYANT !\n");
        } else {
            printf("🟡 VOUS ÊTES UN VOYANT PUSILLANIME !\n");
        }
    }
}

void enregistrerUtilisateurAvantJeu() {
    char pseudo[20];

    printf("Entrez votre pseudo : ");
    scanf("%19s", pseudo);

    // Vérifier si l'utilisateur existe ou l'ajouter au fichier
    readUser(pseudo);  // Appelle la fonction qui gère l'inscription / vérification du joueur
}

// fonction qui permet de mettre le ttre dans le fichier
void ecrireTitre(FILE* fichier) {
    fprintf(fichier, "%-15s | %-15s\n", "PSEUDO", "MOT DE PASSE");
    fprintf(fichier, "----------------------------\n");
}
// fonction qui permet d'enregistrer le joueur et sont mot de passe

void readUser(char* pseudo) {
    FILE* fichier = fopen("sauvegarde.txt", "r+");
    if (fichier == NULL) {
        fichier = fopen("sauvegarde.txt", "w+"); // Création du fichier s'il n'existe pas
        if (fichier == NULL) {
            printf("❌ Erreur : impossible d'ouvrir le fichier.\n");
            return;
        }
        ecrireTitre(fichier); // Écrire les en-têtes si le fichier est nouveau
    }

    char ligne[50];
    char pseudoExistant[20];

    // Vérifier si le pseudo existe déjà
    rewind(fichier); // Revenir au début du fichier
    fgets(ligne, sizeof(ligne), fichier); // Ignorer la première ligne (titre)
    fgets(ligne, sizeof(ligne), fichier); // Ignorer la ligne de séparation

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%19s", pseudoExistant); // Extraire le pseudo
        if (strcmp(pseudoExistant, pseudo) == 0) {
            printf("✅ Bienvenue de retour, %s ! Vous pouvez continuer votre partie.\n", pseudo);
            fclose(fichier);
            return; // Sortie de la fonction si l'utilisateur existe
        }
    }

    // Si on arrive ici, l'utilisateur n'existe pas encore
    char motDePasse[20];
    printf("🔑 Nouvel utilisateur. Veuillez entrer un mot de passe : ");
    scanf("%19s", motDePasse);

    fseek(fichier, 0, SEEK_END); // Se placer à la fin du fichier
    fprintf(fichier, "%-15s | %-15s\n", pseudo, motDePasse);
    printf("✅ Votre compte a été créé avec succès !\n");

    fclose(fichier);
}
