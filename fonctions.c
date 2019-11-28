#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "prototypes.h"

///* Inclusion des biblioth�ques standards et de nos fichier .h*/

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
