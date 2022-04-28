#ifndef __CALENDRIER_H__
#define __CALENDRIER_H__

#include <stdbool.h>     

typedef struct s_cours* Cours;      
typedef struct s_prof* Prof;
typedef struct s_Formation* Formation;
typedef struct s_UE* UE;
typedef struct s_Salle* Salle;
typedef struct s_ListeUE* ListeUE;

//structure fini

//COURS
Cours InitialiseCours();
void SetProf(Cours cours, Prof prof);
void SetSalle(Cours cours, Salle salle);
void SetUE(Cours cours, UE ue);

//PROF
Prof InitialiseProf();
void SetIdProf(int id, Prof prof);
void SetNomProf(char* nom, Prof prof);
void AddCoursProf(Cours cours, Prof prof);
bool CoursLibre(int horaire, Prof prof);
void SupprCoursProf(Prof prof, Cours cours);

//UE
UE InitialiseUE();
void SetIdUE(int id, UE ue);
void SetNomUE(char* nom, UE ue);
void AddCoursUE(Cours cours, UE ue);
void SupprCoursUE(UE ue, Cours cours);

//Salle

Salle InitialiseSalle();

#endif