#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototypes.h"
///* Inclusion des biblioth�ques standards et de nos fichier .h*/

int main()
{
    // int nombre_voiture = 0; /// D�claration d'une variable nombre_voiture de type int initialis� � 0
    //VTS *voitures;  /// D�claration d'une variable voitures de type Vts
    // int i;

    ///* Allocation de m�moire pour la structure Vts*///
    // voitures = malloc(nombre_voiture * sizeof(VTS));

    /// Demande du nombre de voiture qu'il veut mettre dans son parc
    //printf("Entrez le nombre de voiture que composera votre parc: ");
    //scanf("%d", &nombre_voiture);

    ///Appel de la fonction parc pour pouvoir cr�er le parc de voiture
    ///parc(voitures, nombre_voiture);

    system("cls");

    ///Appel de la fonction menu permettant de faire le choix de service

    VTS *voiture_a_louer;
    char *matricule[15];
    int pourMenu = 0, choice; ///le choix au niveau du menu
    int nombre_voiture = 0;   /// D�claration d'une variable nombre_voiture de type int initialis� � 0
    VTS *voitures;            /// D�claration d'une variable voitures de type Vts
    ///* Allocation de m�moire pour la structure Vts*///
    printf("Entrez le nombre de voiture que composera votre parc: ");
    scanf("%d", &nombre_voiture);

    voitures = malloc(nombre_voiture * sizeof(VTS));

    parc(voitures, nombre_voiture);

    do
    {

        puts("================================");
        puts("MENU");
        puts("================================");
        puts("�������������������������������������������������������������������������������");
        puts("1: Louer une voiture           :\tPour ce choix tapez 1========>>>");
        puts("2: Retour dune voiture         :\tPour ce choix tapez 2========>>>");
        puts("3: Etat dune voiture           :\tPour ce choix tapez 3========>>>");
        puts("4: Etat du parc de voitures    :\tPour ce choix tapez 4========>>>");
        puts("5: Sauvegarder letat du parc   :\tPour ce choix tapez 5========>>>");
        puts("0: Fin du programme             :\tPour ce choix tapez 0=======>>>");
        puts("�������������������������������������������������������������������������������");
        printf("========================>>>");
        printf("VEUILLEZ FAIRE UN CHOIX SVP\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nLouer une voiture");
            printf("\nEntrez le matricule de la voiture que vous voulez");
            printf("\nMatricule:");
            scanf("%s", matricule);
            //printf("%s",matricule);
            louer(matricule, voitures, nombre_voiture);
            printf("Voulez-vous revenir au menu??\n");
            printf("Tapez '1' pour retourner au menu et '2' pour quitteer");
            scanf("%d", &pourMenu);
            if (pourMenu == 1)
            {
                menu_choix();
            }

            //louer();
            ///il faut inserer la fonction de louer voiture ici
            break;
        case 2:
            printf("\nRetour dune voiture");
            printf("\nEntrez le matricule de la voiture que vous voulez retourner");
            printf("\nMatricule:");
            scanf("%s", matricule);
            retour_voiture(matricule, voitures, nombre_voiture);
            printf("Voulez-vous revenir au menu??\n");
            printf("Tapez '1' pour retourner au menu et '2' pour quitteer");
            scanf("%d", &pourMenu);
            if (pourMenu == 1)
            {
                menu_choix();
            }

            ///il faut inserer la fonction de retour voiture ici
            break;
        case 3:
            printf("\nEtat de la voiture");
            printf("\nEntrez le matricule de la voiture dont vous voulez voir l'etat");
            printf("\nMatricule:");
            scanf("%s", matricule);
            etat_voiture(matricule, voitures, nombre_voiture);
            printf("Voulez-vous revenir au menu??\n");
            printf("Tapez '1' pour retourner au menu et '2' pour quitteer");
            scanf("%d", &pourMenu);
            if (pourMenu == 1)
            {
                menu_choix();
            }

            ///il faut inserer la fonction etat de la voiture ici
            break;
        case 4:
            printf("\nEtat du parc");

            printf("Voulez-vous revenir au menu??\n");
            printf("Tapez '1' pour retourner au menu et '2' pour quitteer");
            scanf("%d", &pourMenu);
            if (pourMenu == 1)
            {
                menu_choix();
            }

            ///il faut inserer la fonction etat du parc ici
            break;
        case 5:
            printf("\nSauvegarde du parc");

            printf("Voulez-vous revenir au menu??\n");
            printf("Tapez '1' pour retourner au menu et '2' pour quitteer");
            scanf("%d", &pourMenu);
            if (pourMenu == 1)
            {
                menu_choix();
            }

            ///il faut inserer la fonction sauvegarde parc ici
            break;
        case 0:
            printf("\nFin de Votre Programme");
            return;
            break;
        default:
            system("cls");
            printf("\n  Erreur, veuillez choisir entre 1 ou 2 ou 3 ou 4 ou 5 ou 0");
            break;
        }
    } while (choice < 0 || choice > 5);
    return 0;
}
