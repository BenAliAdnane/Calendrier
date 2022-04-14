#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"



struct s_cours{
    int horaire;    // 1-4, horaire de la journée : 1 = 8h-10h ; 2 = 10h-12h ; 3 = 14h-16h ; 4 = 16h-18h
    UE ue;
    Prof prof;
    Jour jour;
}S_cours;

struct s_prof{
    int id;
    Formation formation;    // tableau de formation ou une seule formation ?
    Cours cours;            // tableau de cours ou un seul cours ?
    UE ue;                  // tableau d'UE ou une seule UE ?
}S_prof;

struct s_Formation{
    int id;
    UE* ue;
    Prof* prof;
    Cours* cours;
}S_Formation;

struct s_UE{
    int id;
    Prof prof;          // tableau de prof ou un seul prof ?
    Cours* cours;
    Formation formation;
}S_UE;


void ajouteCours();
void ajouteProf();
void ajouteFormation();
void ajouteUE();

void supprimerCours();
void supprimerProf();
void supprimerFormation();
void supprimerUE();