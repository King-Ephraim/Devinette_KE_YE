#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "fonctions.h"

void menuJeu() {
    // goal : Présentation du menu du jeu et exécution du jeu en fonction du choix de l'utilisateur

    setlocale(LC_CTYPE, "");
    int choixJeu = 0;

    enregistrerUtilisateurAvantJeu();
    if (!authenticated) {
        printf("\n🛑 L'authentification est requise ! Sortie du jeu.\n");
        return;
    }

    printf("\n\n\t\t=== 🎮 MENU DE JEU ===\n");
    printf("\n1. 🟢 DÉBUTANT (1-100)");
    printf("\n2. 🟡 MOYEN (1-500)");
    printf("\n3. 🔴 LÉGENDE (1-2000)");
    printf("\n4. 🛠️  PERSONNALISÉ");
    printf("\n5. ↩️  RETOUR");
    printf("\n6. 🚪 QUITTER");

    do {
        printf("\n\n👉 Votre choix (1-6) : ");
        scanf("%d", &choixJeu);
    } while(choixJeu < 1 || choixJeu > 6);

    switch(choixJeu) {
        case 1:
            getRandom(100);
            game(10);
            Calcul_statistiques_d();
            break;
        case 2:
            getRandom(500);
            game(20);
            Calcul_statistiques_m();
            break;
        case 3:
            getRandom(2000);
            game(25);
            Calcul_statistiques_l();
            break;
        case 4:
            getPersonnalizeRandom();
            personnalizeGame();
            break;
        case 5:
            menu();
            break;
        case 6:
            printf("\n👋 Au revoir !\n");
            exit(0);
        default:
            printf("\n🛑 Erreur de sélection !\n");
    }
}

void menu() {
    //goal : Présentation de l'option de jeu, celle de la consultation de son historique et celle permettant de quitter le jeu

    setlocale(LC_CTYPE, "");
    int choix = 0;

    printf("\n\n\t\t=== 🌟 MENU PRINCIPAL ===\n");
    printf("\n1. ▶️  JOUER");
    printf("\n2. 📜 HISTORIQUE");
    printf("\n3. ❌ QUITTER");

    do {
        printf("\n\n👉 Votre choix (1-3) : ");
        scanf("%d", &choix);
    } while(choix < 1 || choix > 3);

    switch(choix) {
        case 1:
            system("cls");
            menuJeu();
            break;
        case 2:
            system("cls");
            menuHistorique();
            break;
        case 3:
            printf("\n👋 Au revoir ! À bientôt !\n");
            exit(0);
    }
}

void menuHistorique() {
    // goal : Authentifier le compte du jour et lui afficher éventuellement son historique et archives

    char pseudoInput[20], mdp[20];
    int tentatives = 0, auth = 0;

    printf("\n\n\t\t=== 🔐 AUTHENTIFICATION ===\n");
    printf("\nEntrez votre pseudo : ");
    scanf("%19s", pseudoInput);

    FILE* fichier = fopen("sauvegarde.txt", "r");
    if (!fichier) {
        printf("\n📭 Aucun utilisateur enregistré !\n");
        return;
    }

    char ligne[100], pseudoExistant[20], mdpExistant[20];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (sscanf(ligne, "%19s | %19s", pseudoExistant, mdpExistant) == 2) {
            if (strcmp(pseudoExistant, pseudoInput) == 0) {
                do {
                    printf("🔑 Mot de passe : ");
                    scanf("%19s", mdp);
                    if (strcmp(mdp, mdpExistant) == 0) {
                        auth = 1;
                        break;
                    } else {
                        tentatives++;
                        printf("❌ Erreur (%d/2 tentatives)\n", tentatives);
                    }
                } while (tentatives < 2);
                break;
            }
        }
    }
    fclose(fichier);

    if (auth) {
        system("cls");
        afficherHistorique(pseudoInput);
    } else {
        printf("\n🔒 Accès refusé !\n");
    }
    menu();
}
