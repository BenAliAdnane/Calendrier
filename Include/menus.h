#ifndef __MENUI_H__
#define MENUS_H__


void menuClients(ListeFormation formations, ListeProf profs, ListeSalle salles);

void menuAdmin(ListeFormation formations, ListeProf profs, ListeSalle salles);

void MainMenu(ListeFormation formations, ListeProf profs, ListeSalle salles);
    
void GestionEDT(ListeFormation formations, ListeProf profs, ListeSalle salles);

void menuEDTSupprimer(ListeFormation formations, ListeProf profs, ListeSalle salles);

void menuEDTAjouter(ListeFormation formations, ListeProf profs, ListeSalle salles);

void menuGestionFormations(ListeFormation formations, ListeProf profs, ListeSalle salles);

void menuGestionSalle(ListeFormation formations, ListeProf profs, ListeSalle salles);

void menuGestionProfs(ListeFormation formations, ListeProf profs, ListeSalle salles);

void afficherEDT(Cours* cours);

void menuEDTFormations(ListeFormation formations);

void menuEDTSalle(ListeSalle salles);

void menuEDTProfs(ListeProf profs);

#endif