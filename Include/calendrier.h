

#ifndef __CALENDRIER_H__
#define __CALENDRIER_H__

#include <stdbool.h>     

typedef struct s_cours* Cours;      
typedef struct s_prof* Prof;
typedef struct s_Formation* Formation;
typedef struct s_UE* UE;
typedef struct s_Salle* Salle;

//structure fini

//COURS
Cours InitialiseCours();
void SetProf(Prof prof);
void SetSalle(Salle salle);
void SetUE(UE ue);

//PROF
Prof InitialiseProf();
void SetId(int id, Prof prof);
void SetNom(char* nom, Prof prof);
void AddCours(Cours cours, Prof prof);
bool CoursLibre(int horaire);

//UE
UE InitialiseUE();
void SetId(int id, UE ue);
void SetNom(char* nom, UE ue);
void AddCours(Cours cours, UE ue);

#endif