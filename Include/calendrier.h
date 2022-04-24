
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
void SetProf(Prof prof);
void SetSalleProf(Salle salle);
void SetUEProf(UE ue);

//PROF
Prof InitialiseProf();
void SetIdPRof(int id, Prof prof);
void SetNomProf(char* nom, Prof prof);
void AddCoursProf(Cours cours, Prof prof);
bool CoursLibreProf(int horaire);

//UE
UE InitialiseUE();
void SetIdUE(int id, UE ue);
void SetNomUE(char* nom, UE ue);
void AddCoursUE(Cours cours, UE ue);

//SALLE
Salle InitialiseSalle();
void SetNomSalle(Salle salle, int nom);
void AddCoursSalle(Salle salle, Cours cours);
void SupprCoursSalle(Salle salle, Cours cours);
bool CoursLibreSalle(Salle salle, int horaire);

//FORMATION
Formation InitialiseFormation();
void SetId(Formation formation, int id);
void SetNom(Formation formation, char* nom);
void AddUE(Formation formation, UE ue);
void SupprUE(Formation formation, UE ue);
void AddCours(Formation formation, Cours cours);
void SupprCours(Formation formation, Cours cours);
bool CoursLibre(Formation formation, int horaire);

#endif