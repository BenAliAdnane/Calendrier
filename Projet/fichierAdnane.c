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

struct s_UE{
    int id;
    char* nom;
    Cours* cours;
}S_UE;



Cours InitialiseCours(){

    Cours newCours= (Cours)malloc(sizeof(struct s_cours));

    newCours->horaire=0;
    newCours->ue=InitialiseUE();
    newCours->prof=InitialiseProf();
    newCours->salle=InitialiseSalle();

    return newCours;

}

void SetProfCours(Cours cours, Prof prof){
    cours->prof=prof;
}
void setSalleCours(Cours cours, Salle salle){
    cours->salle=salle;
}
void setUECours(Cours cours, UE ue){
    cours->ue=ue;
}

// all

Prof InitialiseProf(){

    Prof newProf=(Prof)malloc(sizeof(struct s_prof));

    newProf->id=0;
    newProf->nom=NULL;
    for(int i=0; i<20; i++){
        newProf->cours[i]=InitialiseCours();
    }
    return newProf;
}
void SetIdProf(int id, Prof prof){
    prof->id=id;
}
void SetNomProf(char* nom, Prof prof){
    prof->nom=nom;
}
bool CoursLibreProf(int horaire, Prof prof){
    return (prof->cours[horaire-1]==InitialiseCours());
}
void SupprCoursProf(Prof prof, Cours coursAEnlever){
    prof->cours[coursAEnlever->horaire -1]=InitialiseCours();
}

void AddCoursProf(Cours coursAMettre, Prof prof){
    if(CoursLibre(coursAMettre->horaire, prof)==0){
        prof->cours[coursAMettre->horaire - 1]=coursAMettre;
    }
}

//AddCours + CoursLibre

UE InitialiseUE(){
    UE newUE=(UE)malloc(sizeof(struct s_UE));
    newUE->id=0;
    newUE->nom=NULL;
    for(int i=0; i<20; i++){
        newUE->cours[i]=InitialiseCours();
    }
    return newUE;
}

void SetIdUE(int id, UE ue){
    ue->id=id;
}

void SetNomUE(char* nom, UE ue){
    ue->nom=nom;
}

void AddCoursUE(Cours coursAMettre, UE ue){
    int a=0;
    for(int i=0; ue->cours[i]!=InitialiseCours();i++){
        a++;
    }
    if(a<20){
        ue->cours[a]=coursAMettre;
    }else{
        printf("Plus d'emplacement");
    }
}
void SupprCoursUE(UE ue, Cours coursAEnlever){
        ue->cours[coursAEnlever->horaire -1]=InitialiseCours();
}