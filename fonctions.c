#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "prototypes.h"

///* Inclusion des biblioth�ques standards et de nos fichier .h*/

void menu_choix()
{
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

        puts("            ================================");
        puts("                          MENU");
        puts("            ================================");
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
}

void parc(VTS *voitures, int nombre_voiture)
{
    int i;

    for (i = 1; i <= nombre_voiture; i++)
    {
        printf("Voiture No %d\n", i);
        printf("Modele: ");
        scanf("%s", voitures[i].modele);
        printf("Matricule: ");
        scanf("%s", voitures[i].matriculev);
        printf("Kilometrage: ");
        scanf("%f", &voitures[i].kilometrage);
        printf("Etat: ");
        scanf("%s", &voitures[i].etats);

        voitures->suivant = NULL;
        //printf("model  %s",voitures[i].modele);
        //printf("\nmatricule  %s\n",voitures[i].matriculev);
        ///printf("%d, %s, %s, %2.f, %c\n", i, voitures[i].modele,voitures[i].matricule, voitures[i].kilometrage, voitures[i].etat);
    }
}

void louer(char *matricule, VTS *voitures, int nombre) /// Fonction permettant de louer une voiture
{
    int i;
    int v = -5;
    int confirmation = 0;
    const char louer[10] = "Louer";

    for (i = 1; i <= nombre; i++)
    {
        //printf("\n%s\n",voitures[i].matriculev);

        // printf("%s\n",matricule);
        if (strcmp(matricule, voitures[i].matriculev) == 0)

        {
            // printf("cool");
            v = i;
        }
    }

    if (v == -5)
    {
        printf("Voiture inexistante\n");
    }
    else
    {
        if (voitures[v].etats == "Louer")
        {
            printf("Cette voiture a deja ete louee\n");
        }
        else
        {
            printf("Cette voiture est disponible\n");
            // printf("Modele: %s\nMatricule: %s\nKilometrage: %2.f\nEtat: %s\n", voitures[v].modele, voitures[v].matriculev, voitures[v].kilometrage, voitures[v].etat);
            printf("Tapez **1** pour confirmer la location et **2** pour annuler: ");
            scanf("%d", &confirmation);
            if (confirmation == 1)
            {
                voitures[i].etats == louer;
                printf("%s", voitures[v].etats);
                printf("Vous venez de louer cette voiture! A la prochaine\n");
                printf("Nous esperons vous revoir et notre voiture en etat!!");
            }
            else
            {
                printf("Location annulee, au revoir!\n");
            }
        }
    }
}

void retour_voiture(char *matricule, VTS *voitures, int nombre)
{

    const char louer[10] = "Louer";

    int v = -5, i;
    int reponseR = 0, kilometrageR = 0;

    for (i = 1; i <= nombre; i++)
    {
        printf("");

        if (strcmp(matricule, voitures[i].matriculev) == 0)

        {
            // printf("cool");
            v = i;
        }
    }

    if (v == -5)
    {
        printf("Voiture inexistante\n");
    }
    else
    {
        if (voitures[v].etats == "Dispo")
        {
            printf("Cette voiture n'a pas ete louee\n");
        }
        else if (voitures[v].etats == "Louer")
        {
            printf("Tapez **1** pour confirmer le retour de la voiture et **2** pour annuler: ");
            scanf("%d", &reponseR);
            if (reponseR == 1)
            {
                printf("Donnez le kilometrage parcouru\n");
                printf("kilometrage:");
                scanf("%d", &kilometrageR);
                // voitures[v].etats="Dispo";
                voitures[v].kilometrage = voitures[v].kilometrage + kilometrageR;
                printf("\n%s", voitures[v].etats);
            }
        }
    }
}

void etat_voiture(char *matricule, VTS *voitures, int nombre)
{
    int v = -5, i;
    int reponseR = 0, kilometrageR = 0;

    for (i = 1; i <= nombre; i++)
    {

        if (strcmp(matricule, voitures[i].matriculev) == 0)

        {
            // printf("cool");
            v = i;
        }
    }

    if (v == -5)
    {
        printf("Voiture inexistante\n");
    }
    else
    {
        printf("Modele: %s\n", voitures[v].modele);
        printf("Matricule: %s\n", voitures[v].matriculev);
        printf("Kilometrage: %2.f\n", voitures[v].kilometrage);
        printf("Etat: %s\n", voitures[v].etats);
    }
}
