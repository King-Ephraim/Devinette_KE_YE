/*
Name : devinette.c
Authors : YOSSO Jean-Pierre Essotina && KPONOU Ephra�m
Date : 06/02/2025
Purpose : ex�cution des fonctions n�c�ssaires pour le jeu
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


