/*
Name : devinette.c
Authors : YOSSO Jean-Pierre Essotina && KPONOU Ephraïm
Date : 06/02/2025
Purpose : exécution des fonctions nécéssaires pour le jeu
*/

#include <stdio.h>
#include <locale.h>
#include "menu.h"

int main()
{
    setlocale(LC_CTYPE, "");

    system("color F0");
    menu();
    return 0;
}


