#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototypes.h"
///* Inclusion des bibliothèques standards et de nos fichier .h*/


int main()
{
   // int nombre_voiture = 0; /// Déclaration d'une variable nombre_voiture de type int initialisé à 0
    //VTS *voitures;  /// Déclaration d'une variable voitures de type Vts
   // int i;

    ///* Allocation de mémoire pour la structure Vts*///
   // voitures = malloc(nombre_voiture * sizeof(VTS));

    /// Demande du nombre de voiture qu'il veut mettre dans son parc
    //printf("Entrez le nombre de voiture que composera votre parc: ");
    //scanf("%d", &nombre_voiture);

    ///Appel de la fonction parc pour pouvoir créer le parc de voiture
    ///parc(voitures, nombre_voiture);

    system("cls");

    ///Appel de la fonction menu permettant de faire le choix de service

    menu_choix();






    return 0;
}
