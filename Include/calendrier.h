#ifndef __CALENDRIER_H__
#define __CALENDRIER_H__

typedef struct s_jour* Jour;
typedef struct s_semaine* Semaine;

typedef struct s_cours* Cours;
typedef struct s_prof* Prof;
typedef struct s_Formation* Formation;
typedef struct s_UE* UE;

void ajouteCours();
void ajouteProf();
void ajouteFormation();
void ajouteUE();

void supprimerCours();
void supprimerProf();
void supprimerFormation();
void supprimerUE();







#endif