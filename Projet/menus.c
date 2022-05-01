#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../Include/menus.h"
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

struct s_ListeSalle{
    Salle salle;
    ListeSalle suivant;
};
struct s_ListeFormation{
    Formation formation;
    ListeFormation suivant;
};
struct s_ListeProf{
    Prof prof;
    ListeProf suivant;
};

// GESTION DES MENUS

void menuEDTProfs(ListeProf profs){
    char* nom;
    printf("Nom du prof :\n");
    scanf("%s",&nom);
    ListeProf ProfTemp = profs;
    while (ProfTemp->suivant!=NULL){
        if (ProfTemp->prof->nom==nom){
            afficherEDT(ProfTemp->prof->cours);
        }
        ProfTemp = ProfTemp->suivant;
    }
}

void menuEDTSalle(ListeSalle salles){
    int nom;
    printf("Nom de la salle :\n");
    scanf("%d",&nom);
    ListeSalle SalleTemp = salles;
    while (SalleTemp->suivant!=NULL){
        if (SalleTemp->salle->nom==nom){
            afficherEDT(SalleTemp->salle->cours);
        }
        SalleTemp = SalleTemp->suivant;
    }
}

void menuEDTFormations(ListeFormation formations){
    char* nom;
    printf("Nom de la formation :\n");
    scanf("%s",&nom);
    ListeFormation FormationTemp = formations;
    while (FormationTemp->suivant!=NULL){
        if (FormationTemp->formation->nom==nom){
            afficherEDT(FormationTemp->formation->cours);
        }
        FormationTemp = FormationTemp->suivant;
    }
}

void afficherEDT(Cours* cours){
    for (int i = 0 ; i < 20 ; i ++){
        if(cours[i]->prof->id==0){
            printf("\nCours %d :\nHoraire Libre\n", i+1);
        }
        else{
            printf("\n Cours %d :\nUE : %s\nProf : %s\nSalle : %d\n",i+1, cours[i]->ue->nom, cours[i]->prof->nom, cours[i]->salle->nom);
        }
    }
}

void menuGestionProfs(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - Ajouter un prof\n\t2 - supprimer un prof\n\t3 - Afficher Liste prof\n\t4 - Afficher EDT prof\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if(r==1){ //ajout d'un prof
            char *nom;
            int id;
            printf("Nom du prof à ajouter :\n");
            scanf("%s", &nom);
            prinf("Id du prof à ajouter:\n");
            scanf("%d",&id);
            nouveauProf(nom, id, profs);
        }
        else if (r==2){// suppression d'un prof
            Prof p = InitialiseProf();
            char* nom;
            printf("Nom du prof à supprimer :\n");
            scanf("%s",&nom);
            SetNomProf(nom, p);
            supprProf(profs, p);
        }
        else if(r==3){// Afficher Liste Prof
            ListeProf ProfTemp = profs;
            while (ProfTemp->suivant!=NULL){
                printf("Nom : %s\n ID : %s\n\n", ProfTemp->prof->nom, ProfTemp->prof->id);
                ProfTemp = ProfTemp->suivant;
            }
        }
        else if (r==4){// Afficher EDT Prof
            menuEDTProfs(profs);
        }
        
        printf("\nChoisissez le menus :\n\n\t1 - Ajouter un prof\n\t2 - supprimer un prof\n\t3 - Afficher Liste prof\n\t4 - Afficher EDT prof\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}


void menuGestionSalle(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - Ajouter une salle\n\t2 - supprimer une salle\n\t3 - Afficher Liste salle\n\t4 - Afficher EDT salle\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if(r==1){ //ajout d'une salle
            int nom;
            printf("Nom de la salle à ajouter:\n");
            scanf("%d", &nom);
            nouvelleSalle(nom, salles);
        }
        else if (r==2){// suppression d'une salle
            Salle s = InitialiseSalle();
            int nom;
            printf("Nom de la salle à suppriemr :\n");
            scanf("%d",&nom);
            SetNomSalle(nom, s);
            supprSalle(salles, s);
        }
        else if(r==3){// Afficher Liste Salle
            ListeSalle SalleTemp = salles;
            while (SalleTemp->suivant!=NULL){
                printf("Nom : %s\n", SalleTemp->salle->nom);
                SalleTemp = SalleTemp->suivant;
            }
        }
        else if (r==4){// Afficher EDT Salle
            menuEDTProfs(salles);
        }
        
        printf("\nChoisissez le menus :\n\n\t1 - Ajouter une salle\n\t2 - supprimer une salle\n\t3 - Afficher Liste salle\n\t4 - Afficher EDT salle\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}


void menuGestionFormations(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - Ajouter une formation\n\t2 - supprimer une formation\n\t3 - Afficher Liste Formation\n\t4 - Afficher EDT Formation\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if(r==1){ //ajout d'une formation
            char *nom;
            int id;
            printf("Nom de la formation à ajouter :\n");
            scanf("%s", &nom);
            prinf("Id de la formation à ajouter:\n");
            scanf("%d",&id);
            nouvelleFormation(nom, id, formations);
        }
        else if (r==2){// suppression d'une formation
            Formation f = InitialiseFormation();
            char* nom;
            printf("Nom de la formation à supprimer :\n");
            scanf("%s",&nom);
            SetNomFormation(nom, f);
            supprFormation(formations, f);
        }
        else if(r==3){// Afficher Liste formation
            ListeFormation FormationTemp = formations;
            while (FormationTemp->suivant!=NULL){
                printf("Nom : %s\n ID : %s\n\n", FormationTemp->formation->nom, FormationTemp->formation->id);
                FormationTemp = FormationTemp->suivant;
            }
        }
        else if (r==4){// Afficher EDT Formation
            menuEDTFormations(formations);
        }
        
        printf("\nChoisissez le menus :\n\n\t1 - Ajouter une formation\n\t2 - supprimer une formation\n\t3 - Afficher Liste Formation\n\t4 - Afficher EDT Formation\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}

void menuEDTAjouter(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int horaire;
    char* nomFormation;
    printf("Nom de la formation où ajouter un cours :\n");
    scanf("%s",&nomFormation);
    printf("Horaire du cours à ajouter :\n");
    scanf("%d", &horaire);
    horaire--;

    char* nomSalle;
    printf("Nom de la salle où ajouter un cours :\n");
    scanf("%s",&nomSalle);

    char* nomProf;
    printf("Nom du prof :\n");
    scanf("%s",&nomProf);

    Cours cours = InitialiseCours();
    cours->horaire = horaire;
    
    ListeFormation FormationTemp = formations;
    bool trouveFormation = false;
    
    while (FormationTemp != NULL && !trouveFormation){
        if (FormationTemp->formation->nom != nomFormation)
            FormationTemp = FormationTemp->suivant;
    }

    ListeProf ProfTemp = profs;
    bool trouveProf;
    while (ProfTemp != NULL && !trouveProf){
        if (ProfTemp->prof->nom != nomProf)
            ProfTemp = ProfTemp->suivant;
    }

    ListeSalle SalleTemp = salles;
    bool trouveSalle;
    while (SalleTemp != NULL && !trouveSalle){
        if (SalleTemp->salle->nom != nomSalle)
            SalleTemp = SalleTemp->suivant;
    }

    char* nomUE;
    printf("Nom de l'UE :\n");
    scanf("%s",&nomUE);

    bool trouveUE;
    ListeUE UETemp = FormationTemp->formation->ListeUE;
    while (UETemp != NULL && !trouveUE){
        if (UETemp->ue->nom != nomUE)
            UETemp = UETemp->suivant;
    }

    if(trouveFormation && trouveProf && trouveSalle && trouveSalle){
        cours->prof=ProfTemp;
        cours->salle=SalleTemp;
        cours->ue = UETemp;
        AddCoursFormation(FormationTemp->formation, cours);
        AddCoursProf(ProfTemp->prof, cours);
        AddCoursSalle(SalleTemp->salle, cours);
    }


}


void menuEDTSupprimer(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int horaire;
    char* nomFormation;
    printf("Nom de la formation où supprimer un cours :\n");
    scanf("%s",&nomFormation);
    printf("Horaire du cours à supprimer :\n");
    scanf("%d", &horaire);
    horaire--;

    char* nomSalle;
    printf("Nom de la salle où supprimer un cours :\n");
    scanf("%s",&nomSalle);

    char* nomProf;
    printf("Nom du prof :\n");
    scanf("%s",&nomProf);

    Cours cours = InitialiseCours();
    cours->horaire = horaire;
    
    ListeFormation FormationTemp = formations;
    bool trouveFormation = false;
    
    while (FormationTemp != NULL && !trouveFormation){
        if (FormationTemp->formation->nom != nomFormation)
            FormationTemp = FormationTemp->suivant;
    }

    ListeProf ProfTemp = profs;
    bool trouveProf;
    while (ProfTemp != NULL && !trouveProf){
        if (ProfTemp->prof->nom != nomProf)
            ProfTemp = ProfTemp->suivant;
    }

    ListeSalle SalleTemp = salles;
    bool trouveSalle;
    while (SalleTemp != NULL && !trouveSalle){
        if (SalleTemp->salle->nom != nomSalle)
            SalleTemp = SalleTemp->suivant;
    }

    char* nomUE;
    printf("Nom de l'UE :\n");
    scanf("%s",&nomUE);

    bool trouveUE;
    ListeUE UETemp = FormationTemp->formation->ListeUE;
    while (UETemp != NULL && !trouveUE){
        if (UETemp->ue->nom != nomUE)
            UETemp = UETemp->suivant;
    }
    
    if(trouveFormation && trouveProf && trouveSalle && trouveSalle){
        cours->prof=ProfTemp;
        cours->salle=SalleTemp;
        cours->ue = UETemp;
        SupprCoursFormation(FormationTemp->formation, cours);
        SupprCoursProf(ProfTemp->prof, cours);
        SupprCoursSalle(SalleTemp->salle, cours);
    }
}


void GestionEDT(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - Ajouter un cours\n\t2 - Supprimer un cours\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if(r==1){
            menuEDTAjouter(formations, profs, salles);
        }
        else if (r==2){
            menuEDTSupprimer(formations, profs, salles);
        }
        
        printf("\nChoisissez le menus :\n\n\t1 - Ajouter un cours\n\t2 - Supprimer un cours\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}


void menuClients(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - afficher l'EDT d'une formation\n\t2 - afficher l'EDT d'une salle\n\t3 - afficher l'EDT d'un prof\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if(r==1){
            menuEDTFormations(formations);
        }
        else if (r==2){
            menuEDTSalles(salles);
        }
        else if(r==3){
            menuEDTProfs(profs);
        }
        
        printf("\nChoisissez le menus :\n\n\t1 - afficher l'EDT d'une formation\n\t2 - afficher l'EDT d'une salle\n\t3 - afficher l'EDT d'un prof\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}


void menuAdmin(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - gestion prof\n\t2 - gestion salles\n\t3 - gestion formations\n\t4 - gestion EDT\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if(r==1){
            menuGestionProfs(formations, profs, salles);
        }
        else if (r==2){
            menuGestionSalles(formations, profs, salles);
        }
        else if(r==3){
            menuGestionFormations(formations, profs, salles);
        }
        else if(r==4){
            menuGestionEDT(formations, profs, salles);
        }
        printf("\nChoisissez le menus :\n\n\t1 - gestion prof\n\t2 - gestion salles\n\t3 - gestion formations\n\t4 - gestion EDT\n\t0 - quitter\n");
        scanf("%d",&r);
    }

}



void MainMenu(ListeFormation formations, ListeProf profs, ListeSalle salles){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - admin\n\t2 - clients\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if (r==1){
            menuAdmin(formations, profs, salles);
        }
        else if(r==2){
            menuClients(formations, profs, salles);
        }
        printf("\nChoisissez le menus :\n\n\t1 - admin\n\t2 - clients\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}