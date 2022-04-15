#ifndef __CALENDRIER_H__
#define __CALENDRIER_H__

typedef struct s_cours* Cours;
typedef struct s_prof* Prof;
typedef struct s_Formation* Formation;
typedef struct s_UE* UE;
typedef struct s_Salle* Salle;

void ajouteCours();
void ajouteProf();
void ajouteFormation();
void ajouteUE();

void supprimerCours();
void supprimerProf();
void supprimerFormation();
void supprimerUE();


#endif