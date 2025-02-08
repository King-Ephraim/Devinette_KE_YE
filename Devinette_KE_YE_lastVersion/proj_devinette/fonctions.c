#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "fonctions.h"
#include "menu.h"

int nbreAleatoire, entreUser, nombrelimit, cptTab;
int entre_User[100];
char pseudo[20];
int authenticated = 0;

void welcome() {

    //goal : Brève présentation du jeu

    system("cls");
    printf("\n\n********************************************");
    printf("\n******    🎲 JEU DE DEVINETTE 🎲    ********");
    printf("\n********************************************");
    printf("\n\n🔍 Objectif : Devinez le nombre secret !");
    printf("\n💡 Indice : On vous dira si le nombre recherché est plus grand ou plus petit.\n\n");
}

void getRandom(int limitNbre) {
    // goal : generation nombre aléatoire

    srand(time(NULL));
    nbreAleatoire = rand() % limitNbre + 1;
}

void getPersonnalizeRandom() {
    // goal : génération nombre aléatoire pour une partie personnalisée et saisie du nombre aléatoire maximum

    printf("\n🎯 Entrez la borne maximale : ");
    scanf("%d", &nombrelimit);
    getRandom(nombrelimit);
}

void playGame(int NBRE_ARRET) {
     /**
    goal : devinette du nombre aléatoire et affichage du message de félicitation
    parameters : Nombre maximum de tentatives autorisés
    **/

    int tentatives = 0;
    char rejouer[4];
    cptTab = 0;

    while (tentatives < NBRE_ARRET) {
        printf("\n🔢 Tentative %d/%d : ", tentatives + 1, NBRE_ARRET);
        scanf("%d", &entreUser);

        entre_User[cptTab] = entreUser ; // pour enrégistrer les saisies de l'utilisateur
        cptTab++;

        if (nbreAleatoire > entreUser) {
            printf("📈 Plus grand !\n");
        } else if (nbreAleatoire < entreUser) {
            printf("📉 Plus petit !\n");
        } else {
            printf("\n🎉 Bravo ! Le nombre secret a été trouvé en %d tentative(s) !\n", tentatives + 1);
            break;
        }
        tentatives++;
    }


    if (tentatives == NBRE_ARRET) {
        printf("\n💀 Vous avez épuisé toutes vos tentatives. Le nombre secret était : %d\n", nbreAleatoire);
    } else {
        // Affichage du message de félicitation en fonction des tentatives
        if (tentatives < 4) {
            printf("🔮 VOUS ÊTES UN SUPER VOYANT !\n");
        } else if (tentatives >3 && tentatives < 7) {
            printf("🔵 VOUS ÊTES UN SAGE VOYANT !\n");
        } else if (tentatives >6 && tentatives < 10) {
            printf("🟢 VOUS ÊTES UN APPRENTI VOYANT !\n");
        } else {
            printf("🟡 VOUS ÊTES UN VOYANT PUSILLANIME !\n");
        }
    }

    printf("\n🔄 Rejouer ? (O/N) : ");
    scanf("%s", rejouer);
    if (strcmp(rejouer, "O") == 0 || strcmp(rejouer, "o") == 0) {
        system("cls");
        menuJeu();
    }
}

void game(int NBRE_ARRET) {
    /*
    goal : jouer le jeu
    parameters : nombre maximum de tentatives autorisés
    */

    welcome();
    playGame(NBRE_ARRET);
}

void personnalizeGame() {
    // goal : jouer une partie de jeu personnalisée

    printf("\n\t=== 🛠️  MODE PERSONNALISÉ ===\n");
    printf("🔢 Nombre max de tentatives : ");
    int maxTentatives;
    scanf("%d", &maxTentatives);
    playGame(maxTentatives);
    Calcul_statistiques(nombrelimit);
}

void enregistrerUtilisateurAvantJeu() {
    // goal : ajout d'un utilisateur avant de jouer

    char mdp[20], ligne[100], pseudoExistant[20], mdpExistant[20];
    authenticated = 0;

    printf("\n👤 Entrez votre pseudo : ");
    scanf("%19s", pseudo);

    FILE* fichier = fopen("sauvegarde.txt", "r+");
    if (!fichier) {
        fichier = fopen("sauvegarde.txt", "w+");
        fprintf(fichier, "%-15s | %-15s\n", "PSEUDO", "MOT_DE_PASSE");
        fprintf(fichier, "----------------------------\n");
    }

    rewind(fichier);
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (sscanf(ligne, "%19s | %19s", pseudoExistant, mdpExistant) == 2) {
            if (strcmp(pseudoExistant, pseudo) == 0) {
                int tentatives = 0;
                do {
                    printf("🔑 Mot de passe : ");
                    scanf("%19s", mdp);
                    if (strcmp(mdp, mdpExistant) == 0) {
                        authenticated = 1;
                        printf("\n✅ Authentification réussie !\n");
                        break;
                    } else {
                        printf("❌ Erreur (%d/2)\n", ++tentatives);
                    }
                } while (tentatives < 2);
                break;
            }
        }
    }

    if (!authenticated) {
        printf("🔑 Créez un mot de passe : ");
        scanf("%19s", mdp);
        fprintf(fichier, "%-15s | %-15s\n", pseudo, mdp);
        authenticated = 1;
        printf("\n✅ Compte créé avec succès !\n");
    }

    fclose(fichier);
}


void afficherHistorique(char* pseudo) {
    // goal : afficher l'historique du joueur

    FILE* fichier = fopen("statistiques.txt", "r");
    if (!fichier) {
        printf("\n📭 Aucun historique disponible !\n");
        return;
    }

    char ligne[100];
    printf("\n\t=== 📅 HISTORIQUE DE %s ===\n", pseudo);
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, pseudo)) {
            printf("\n");
            for (int i = 0; i < 5; i++) {
                printf("%s", ligne);
                fgets(ligne, sizeof(ligne), fichier);
            }
        }
    }
    fclose(fichier);
    printf("\n\nAppuyez sur Entrée pour continuer...");
    getchar();
    getchar();
}


void Calcul_statistiques_d() {

    // goal : calculer et enrégistrer dans un fichier l'espérance mathématique, la variance et l'écart-type pour le niveau débutant
    double var, esperance, ecartType ;

    esperance=0;

    // calcul de l'espérance mathématique
    for (cptTab = 0; cptTab<11; cptTab++ )
    {
        esperance = esperance + entre_User[cptTab]*0.01; // 0.01 est la probabilité d'apparition d'un nombre dans ce niveau
        }

    // calcul de la variance
    for (cptTab = 0; cptTab<100; cptTab++ )
    {
        var = var + (entre_User[cptTab] - esperance)*(entre_User[cptTab] - esperance)*0.01 ;
        }
    // calcul de l'ecartType
    ecartType = sqrt(var);

    FILE* fichier = fopen("statistiques.txt", "a");
    time_t now;
    time(&now);

    fprintf(fichier, "\n=== 🕒 PARTIE DU %s", ctime(&now));
    fprintf(fichier, "👤 Pseudo : %s\n", pseudo);
    fprintf(fichier, "🎯 Niveau : Débutant\n");
    fprintf(fichier, "🔢 Nombre secret : %d\n", nbreAleatoire);
    fprintf(fichier, "⏳ Tentatives : %d\n", cptTab);
    fprintf(fichier, "○  Espérance mathématiques : %lf \n", esperance);
    fprintf(fichier, "○  Variance : %lf\n", var);
    fprintf(fichier, "○  Ecart-type : %lf\n", ecartType);
    fprintf(fichier, "----------------------------\n");
    fclose(fichier);
}

void Calcul_statistiques_m() {

    // goal : calculer et enrégistrer dans un fichier l'espérance mathématique, la variance et l'écart-type pour le niveau moyen
    double var, esperance, ecartType ;

    esperance=0;

    // calcul de l'espérance mathématique
    for (cptTab = 0; cptTab<11; cptTab++ )
    {
        esperance = esperance + entre_User[cptTab]*0.002 ; // 0.002 est la probabilité d'apparition d'un nombre dans ce niveau
        }

    // calcul de la variance
    for (cptTab = 0; cptTab<21; cptTab++ )
    {
        var = var + (entre_User[cptTab] - esperance)*(entre_User[cptTab] - esperance)*0.002 ;
        }
    // calcul de l'ecartType
    ecartType = sqrt(var);

    FILE* fichier = fopen("statistiques.txt", "a");
    time_t now;
    time(&now);

    fprintf(fichier, "\n=== 🕒 PARTIE DU %s", ctime(&now));
    fprintf(fichier, "👤 Pseudo : %s\n", pseudo);
    fprintf(fichier, "🎯 Niveau : Moyen\n");
    fprintf(fichier, "🔢 Nombre secret : %d\n", nbreAleatoire);
    fprintf(fichier, "⏳ Tentatives : %d\n", cptTab);
    fprintf(fichier, "○  Espérance mathématiques : %lf \n", esperance);
    fprintf(fichier, "○  Variance : %lf\n", var);
    fprintf(fichier, "○  Ecart-type : %lf\n", ecartType);
    fprintf(fichier, "----------------------------\n");
    fclose(fichier);
}

void Calcul_statistiques_l() {

    // goal : calculer et enrégistrer dans un fichier l'espérance mathématique, la variance et l'écart-type pour le niveau Légendaire
    double var, esperance, ecartType ;

    esperance=0;

    // calcul de l'espérance mathématique
    for (cptTab = 0; cptTab<11; cptTab++ )
    {
        esperance = esperance + entre_User[cptTab]*0.0005 ; // 0.0005 est la probabilité d'apparition d'un nombre dans ce niveau
        }

    // calcul de la variance
    for (cptTab = 0; cptTab<26; cptTab++ )
    {
        var = var + (entre_User[cptTab] - esperance)*(entre_User[cptTab] - esperance)*0.0005 ;
        }
    // calcul de l'ecartType
    ecartType = sqrt(var);

    FILE* fichier = fopen("statistiques.txt", "a");
    time_t now;
    time(&now);

    fprintf(fichier, "\n=== 🕒 PARTIE DU %s", ctime(&now));
    fprintf(fichier, "👤 Pseudo : %s\n", pseudo);
    fprintf(fichier, "🎯 Niveau : Légendaire\n");
    fprintf(fichier, "🔢 Nombre secret : %d\n", nbreAleatoire);
    fprintf(fichier, "⏳ Tentatives : %d\n", cptTab);
    fprintf(fichier, "○  Espérance mathématiques : %lf \n", esperance);
    fprintf(fichier, "○  Variance : %lf\n", var);
    fprintf(fichier, "○  Ecart-type : %lf\n", ecartType);
    fprintf(fichier, "----------------------------\n");
    fclose(fichier);
}


void Calcul_statistiques(int nombrelimit)
{
    // goal : calculer l'espérance mathématique, la variance et l'écart-type
    double var, esperance, ecartType,proba ;

    proba= 1/nombrelimit ; // probabilité d'apparition d'un nombre
    esperance=0;

    // calcul de l'espérance mathématique
    for (cptTab = 0; cptTab<100; cptTab++ )
    {
        esperance = esperance + entre_User[cptTab]*proba;
        }

    // calcul de la variance
    for (cptTab = 0; cptTab<100; cptTab++ )
    {
        var = var + (entre_User[cptTab] - esperance)*(entre_User[cptTab] - esperance)*proba ;
        }
    // calcul de l'ecartType
    ecartType = sqrt(var);

     FILE* fichier = fopen("statistiques.txt", "a");
    time_t now;
    time(&now);

    fprintf(fichier, "\n=== 🕒 PARTIE DU %s", ctime(&now));
    fprintf(fichier, "👤 Pseudo : %s\n", pseudo);
    fprintf(fichier, "🎯 Niveau : Personnalisé\n");
    fprintf(fichier, "🔢 Nombre secret : %d\n", nbreAleatoire);
    fprintf(fichier, "⏳ Tentatives : %d\n", cptTab);
    fprintf(fichier, "○  Espérance mathématiques : %lf \n", esperance);
    fprintf(fichier, "○  Variance : %lf\n", var);
    fprintf(fichier, "○  Ecart-type : %lf\n", ecartType);
    fprintf(fichier, "----------------------------\n");
    fclose(fichier);
}















