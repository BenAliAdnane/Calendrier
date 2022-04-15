#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"



struct s_cours{
    int horaire;    // Entre 1 et 20  : 1-4 = lundi, 5-8 = mardi, ... 16-20 = vendredi
    UE ue;
    Prof prof;
}S_cours;

struct s_prof{
    int id;
    string nom;
    Cours[20] cours;
}S_prof;

struct s_Formation{
    int id;
    string nom;
    UE* ue;
}S_Formation;

struct s_UE{
    int id;
    string nom;
    Cours[20] cours;
}S_UE;


void ajouteCours();
void ajouteProf();
void ajouteFormation();
void ajouteUE();

void supprimerCours();
void supprimerProf();
void supprimerFormation();
void supprimerUE();