#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"



struct s_cours{
    int horaire;    // Entre 1 et 20  : 1-4 = lundi, 5-8 = mardi, ... 16-20 = vendredi
    UE ue;
    Prof prof;
    Salle salle;
}S_cours;

struct s_prof{
    int id;
    char* nom;
    Cours* cours;
}S_prof;

struct s_Formation{
    int id;
    char* nom;
    UE* ue;
    Cours* cours;
}S_Formation;

struct s_UE{
    int id;
    char* nom;
    Cours* cours;
}S_UE;

struct s_Salle{
    int nom;
    Cours* cours;
}S_Salle;




void ajouteCours();
void ajouteProf();
void ajouteFormation();
void ajouteUE();

void supprimerCours();
void supprimerProf();
void supprimerFormation();
void supprimerUE();