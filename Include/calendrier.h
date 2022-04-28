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
void SetProfCours(Cours cours, Prof prof);
void setSalleCours(Cours cours, Salle salle);
void setUECours(Cours cours, UE ue);

//PROF
Prof InitialiseProf();
void SetIdProf(int id, Prof prof);
void SetNomProf(char* nom, Prof prof);
void AddCoursProf(Cours cours, Prof prof);
bool CoursLibreProf(int horaire, Prof prof);
void SupprCoursProf(Prof prof, Cours cours);

//UE
UE InitialiseUE();
void SetIdUE(int id, UE ue);
void SetNomUE(char* nom, UE ue);
void AddCoursUE(Cours cours, UE ue);
void SupprCoursUE(UE ue, Cours cours);

//Salle

Salle InitialiseSalle();
void SetNomSalle(Salle salle, int nom);
bool CoursLibreSalle(Salle salle, int horaire);
void AddCoursSalle(Salle salle, Cours cours);
void SupprCoursSalle(Salle salle, Cours cours);

Formation InitialiseFormation();
void SetIdFormation(Formation formation, int id);
void SetNomFormation(Formation formation, char* nom);
bool CoursLibreFormation(Formation formation, int horaire);
void AddCoursFormation(Formation formation, Cours cours);
void SupprCoursFormation(Formation formation, Cours cours);
void AddUEFormation(Formation formation, UE ue);
void SupprUEFormation(Formation formation, UE ue);

//Liste chainée

typedef struct s_ListeSalle* ListeSalle;
typedef struct s_ListeFormation* ListeFormation;
typedef struct s_ListeProf* ListeProf;

ListeSalle InitialisationListeSalle();
ListeFormation InitialisationListeFormation();
ListeProf InitialisationListeProf();


void addSalle(ListeSalle Listesalle, Salle salle);
void supprSalle(ListeSalle Listesalle, Salle salle);
void addFormation(ListeFormation Listeformation, Formation formation);
void supprFormation(ListeFormation Listeformation, Formation formation);
void addProf(ListeProf Listeprof, Prof prof);
void supprProf(ListeProf Listeprof, Prof prof);
void addUE(ListeUE ListeUe, UE ue);
void supprUE(ListeUE ListeUe, UE ue);



#endif