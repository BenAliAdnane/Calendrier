#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"

struct s_edt* Edt;
struct s_jour* Jour;
struct s_semaine* Semaine;

void ajouteCours();
void ajouteProf();
void ajouteFormation();
void ajouteUE();

void supprimerCours();
void supprimerProf();
void supprimerFormation();
void supprimerUE();