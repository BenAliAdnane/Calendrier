#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
    ListeUE ListeUE;
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


struct s_ListeUE{
    UE ue;
    ListeUE suivant;
}S_ListeUE;


// Fonctions pour les Salles

Salle InitialiseSalle(){
    Salle s = malloc(sizeof(S_Salle));
    s->nom = 0;
    s->cours = malloc(20*sizeof(S_cours));
    for (int i = 0; i < 20; i++)
    {
        s->cours[i] = InitialiseCours();
    }
    
    return s;
}

void SetNomSalle(Salle salle, int nom){
    salle->nom = nom;
}

bool CoursLibreSalle(Salle salle, int horaire){
    return (salle->cours[horaire -1] == InitialiseCours());
}

void AddCoursSalle(Salle salle, Cours cours){
    if (CoursLibreSalle(salle, cours->horaire)){
        salle->cours[cours->horaire - 1] = cours;
    }
    else{
        printf("La salle %d n'est pas libre à cet horaire. Utiliser SupprCoursSalle(salle, cours) pour supprimer un cours.\n", salle->nom);
    }
}

void SupprCoursSalle(Salle salle, Cours cours){
    if (!CoursLibreSalle(salle, cours->horaire)){
        salle->cours[cours->horaire - 1] = InitialiseCours();
    }
    else{
        printf("La salle %d n'a pas de cours cet horaire.\n", salle->nom);
    }
}

// Fonctions pour les Formations :


Formation InitialiseFormation(){
    
    Formation f = (Formation)malloc(sizeof(S_Formation));
    f-> id = 0;
    f-> nom = NULL;
    f->ListeUE = (ListeUE)malloc(sizeof(S_ListeUE));
    f->ListeUE->suivant = NULL;
    for (int i = 0; i < 20; i++)
    {
        f->cours[i] = InitialiseCours();
    }
    return f;
}


void SetIdFormation(Formation formation, int id){
    formation->id = id;
}

void SetNomFormation(Formation formation, char* nom){
    formation->nom = nom;
}


bool CoursLibreFormation(Formation formation, int horaire){
    return (formation->cours[horaire -1] == InitialiseCours());
}


void AddCoursFormation(Formation formation, Cours cours){
    if (CoursLibreFormation(formation, cours->horaire)){
        formation->cours[cours->horaire - 1] = cours;
    }
    else{
        printf("La formation %s à dejà un cours à cette horaire. Utiliser SupprCours(formation, Cours) pour supprimer ce cours\n", formation->nom);
    }
}

void SupprCoursFormation(Formation formation, Cours cours){
    if (!CoursLibreFormation(formation, cours->horaire)){
        formation->cours[cours->horaire - 1] = InitialiseCours();
    }
    else{
        printf("La formation %sn'a pas de cours à cette horaire.\n", formation->nom);
    } 
}

void AddUEFormation(Formation formation, UE ue){
    // on vérifie l'absence de l'UE
    ListeUE UETemp;
    bool present = false;
    UETemp = formation->ListeUE;
    while (UETemp->suivant != NULL && !present){
        if (UETemp->ue->id = ue->id){
            present = true;
        }
        UETemp = UETemp->suivant;
    }
    if (present){
        printf("L'UE %s est déja présente dans la liste des UE de la formation %s", ue->nom, formation->nom);
    }
    else{;
        UETemp->suivant = (ListeUE)malloc(sizeof(S_ListeUE));
        UETemp->suivant->UE = ue;
    }
}

void SupprUEFormation(Formation formation, UE ue){
    // on vérifie la présence de l'UE
    ListeUE UETemp;
    bool present = false;
    UETemp = formation->ListeUE;

    if (formation->ListeUE->UE->id == ue-> id)
        formation->ListeUE = formation->ListeUE->suivant;

    while (UETemp->suivant->suivant != NULL && !present){   // on s'arrete à l'avant dernier
        if (UETemp->suivant->ue->id = ue->id){
            present = true;
        }else{
        UETemp = UETemp->suivant;
        }
    }
    if(present){
        UETemp->suivant = UETemp->suivant->suivant;
    }
    else if (UETemp->suivant->UE->id = ue->id){             //si l'ue est la derniere dans la liste
        UETemp->suivant = NULL;
    }
}