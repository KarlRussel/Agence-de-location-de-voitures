#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct Voiture VTS;

struct Voiture
{
    char modele[15];
    char matriculev[15];
    float kilometrage;
    char etats[10];

    VTS *suivant;
};

#endif // STRUCTURE_H_INCLUDED
