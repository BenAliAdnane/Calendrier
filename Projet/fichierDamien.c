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

// Gestion de la liste des salles

void addSalle(ListeSalle Listesalle, Salle salle){

    //Si la liste est vide
    if(Listesalle->salle = NULL){
        Listesalle->salle = salle;
        Listesalle->suivant = InitialisationListeSalle();
    }
    else{
        ListeSalle ListeTemp = Listesalle;
        bool present = false;
        
        while (!present && ListeTemp->suivant != NULL){
            
            if (ListeTemp->salle->nom == salle->nom){
                present = true;
            }
            ListeTemp = ListeTemp->suivant;

        }

        if (!present){
            ListeTemp->suivant = InitialisationListeSalle();
            ListeTemp->suivant->salle = salle;
        }
        else{
            printf("La salle %s existe deja\n", salle->nom);
        }

    }

}

void supprSalle(ListeSalle Listesalle, Salle salle){

    // si la liste est vide
    if (Listesalle->salle == NULL){
        printf("Erreur : la salle %s nest pas presente dans la liste", salle->nom);
    }
    // si une seule salle dans la liste
    if (Listesalle->suivant = NULL){
        if (Listesalle->salle->nom == salle->nom)
            Listesalle = InitialisationListeSalle();
        else
            printf("Erreur : la salle %s nest pas presente dans la liste", salle->nom);
    }
    else{

        ListeSalle ListeTemp = Listesalle;
        bool present = false;

        while(!present && ListeTemp->suivant->suivant != NULL){
            if (ListeTemp->suivant->salle->nom == salle->nom)
                present = true;
            ListeTemp = ListeTemp->suivant;
        }

        if(!present)
            printf("Erreur : la salle %s nest pas presente dans la liste", salle->nom);
        else
            ListeTemp->suivant = ListeTemp->suivant->suivant;

    }

}


// Gestion de la liste des formations

void addFormation(ListeFormation Listeformation, Formation formation){

    //Si la liste est vide
    if(Listeformation->formation = NULL){
        Listeformation->formation = formation;
        Listeformation->suivant = InitialisationListeFormation();
    }
    else{
        ListeFormation ListeTemp = Listeformation;
        bool present = false;
        
        while (!present && ListeTemp->suivant != NULL){
            
            if (ListeTemp->formation->nom == formation->nom){
                present = true;
            }
            ListeTemp = ListeTemp->suivant;

        }

        if (!present){
            ListeTemp->suivant = InitialisationListeFormation();
            ListeTemp->suivant->formation = formation;
        }
        else{
            printf("La formation %s existe deja\n", formation->nom);
        }

    }

}

void supprFormation(ListeFormation Listeformation, Formation formation){

    // si la liste est vide
    if (Listeformation->formation == NULL){
        printf("Erreur : la formation %s nest pas presente dans la liste", formation->nom);
    }
    // si un seul prof dans la liste
    if (Listeformation->suivant = NULL){
        if (Listeformation->formation->nom == formation->nom)
            Listeformation = InitialisationListeFormation();
        else
            printf("Erreur : la formation %s nest pas presente dans la liste", formation->nom);
    }
    else{

        ListeFormation ListeTemp = Listeformation;
        bool present = false;

        while(!present && ListeTemp->suivant->suivant != NULL){
            if (ListeTemp->suivant->formation->nom == formation->nom)
                present = true;
            ListeTemp = ListeTemp->suivant;
        }

        if(!present)
            printf("Erreur : la formation %s nest pas presente dans la liste", formation->nom);
        else
            ListeTemp->suivant = ListeTemp->suivant->suivant;

    }

}

// Gestion de la liste des profs

void addProf(ListeProf Listeprof, Prof prof){

    //Si la liste est vide
    if(Listeprof->prof = NULL){
        Listeprof->prof = prof;
        Listeprof->suivant = InitialisationListeProf();
    }
    else{
        ListeProf ListeTemp = Listeprof;
        bool present = false;
        
        while (!present && ListeTemp->suivant != NULL){
            
            if (ListeTemp->prof->nom == prof->nom){
                present = true;
            }
            ListeTemp = ListeTemp->suivant;

        }

        if (!present){
            ListeTemp->suivant = InitialisationListeProf();
            ListeTemp->suivant->prof = prof;
        }
        else{
            printf("La prof %s existe deja\n", prof->nom);
        }

    }

}

void supprProf(ListeProf Listeprof, Prof prof){

    // si la liste est vide
    if (Listeprof->prof == NULL){
        printf("Erreur : la prof %s nest pas presente dans la liste", prof->nom);
    }
    // si un seul prof dans la liste
    if (Listeprof->suivant = NULL){
        if (Listeprof->prof->nom == prof->nom)
            Listeprof = InitialisationListeProf();
        else
            printf("Erreur : la prof %s nest pas presente dans la liste", prof->nom);
    }
    else{

        ListeProf ListeTemp = Listeprof;
        bool present = false;

        while(!present && ListeTemp->suivant->suivant != NULL){
            if (ListeTemp->suivant->prof->nom == prof->nom)
                present = true;
            ListeTemp = ListeTemp->suivant;
        }

        if(!present)
            printf("Erreur : la prof %s nest pas presente dans la liste", prof->nom);
        else
            ListeTemp->suivant = ListeTemp->suivant->suivant;

    }

}


// Gestion de la liste des ues

void addUE(ListeUE ListeUe, UE ue){

    //Si la liste est vide
    if(ListeUe->ue = NULL){
        ListeUe->ue = ue;
        ListeUe->suivant = InitialisationListeUE();
    }
    else{
        ListeUE ListeTemp = ListeUe;
        bool present = false;
        
        while (!present && ListeTemp->suivant != NULL){
            
            if (ListeTemp->ue->nom == ue->nom){
                present = true;
            }
            ListeTemp = ListeTemp->suivant;

        }

        if (!present){
            ListeTemp->suivant = InitialisationListeUE();
            ListeTemp->suivant->ue = ue;
        }
        else{
            printf("La ue %s existe deja\n", ue->nom);
        }

    }

}

void supprUE(ListeUE ListeUe, UE ue){

    // si la liste est vide
    if (ListeUe->ue == NULL){
        printf("Erreur : la ue %s nest pas presente dans la liste", ue->nom);
    }
    // si un seul ue dans la liste
    if (ListeUe->suivant = NULL){
        if (ListeUe->ue->nom == ue->nom)
            ListeUe = InitialisationListeUE();
        else
            printf("Erreur : la ue %s nest pas presente dans la liste", ue->nom);
    }
    else{

        ListeUE ListeTemp = ListeUe;
        bool present = false;

        while(!present && ListeTemp->suivant->suivant != NULL){
            if (ListeTemp->suivant->ue->nom == ue->nom)
                present = true;
            ListeTemp = ListeTemp->suivant;
        }

        if(!present)
            printf("Erreur : la ue %s nest pas presente dans la liste", ue->nom);
        else
            ListeTemp->suivant = ListeTemp->suivant->suivant;

    }

}
















// Fonctions pour les Salles

Salle InitialiseSalle(){
    Salle s = malloc(sizeof(S_Salle));
    s->nom = 0;
    s->cours = malloc(20*sizeof(S_cours));
    for (int i = 0; i < 20; i++)
    {
        s->cours[i] = InitialiseCours();
    }
    
    return s;
}

void SetNomSalle(Salle salle, int nom){
    salle->nom = nom;
}

bool CoursLibreSalle(Salle salle, int horaire){
    return (salle->cours[horaire -1] == InitialiseCours());
}

void AddCoursSalle(Salle salle, Cours cours){
    if (CoursLibreSalle(salle, cours->horaire)){
        salle->cours[cours->horaire - 1] = cours;
    }
    else{
        printf("La salle %d n'est pas libre ?? cet horaire. Utiliser SupprCoursSalle(salle, cours) pour supprimer un cours.\n", salle->nom);
    }
}

void SupprCoursSalle(Salle salle, Cours cours){
    if (!CoursLibreSalle(salle, cours->horaire)){
        salle->cours[cours->horaire - 1] = InitialiseCours();
    }
    else{
        printf("La salle %d n'a pas de cours cet horaire.\n", salle->nom);
    }
}

// Fonctions pour les Formations :


Formation InitialiseFormation(){
    
    Formation f = (Formation)malloc(sizeof(S_Formation));
    f-> id = 0;
    f-> nom = NULL;
    f->ListeUE = (ListeUE)malloc(sizeof(S_ListeUE));
    f->ListeUE->suivant = NULL;
    for (int i = 0; i < 20; i++)
    {
        f->cours[i] = InitialiseCours();
    }
    return f;
}


void SetIdFormation(Formation formation, int id){
    formation->id = id;
}

void SetNomFormation(Formation formation, char* nom){
    formation->nom = nom;
}


bool CoursLibreFormation(Formation formation, int horaire){
    return (formation->cours[horaire -1] == InitialiseCours());
}


void AddCoursFormation(Formation formation, Cours cours){
    if (CoursLibreFormation(formation, cours->horaire)){
        formation->cours[cours->horaire - 1] = cours;
    }
    else{
        printf("La formation %s ?? dej?? un cours ?? cette horaire. Utiliser SupprCours(formation, Cours) pour supprimer ce cours\n", formation->nom);
    }
}

void SupprCoursFormation(Formation formation, Cours cours){
    if (!CoursLibreFormation(formation, cours->horaire)){
        formation->cours[cours->horaire - 1] = InitialiseCours();
    }
    else{
        printf("La formation %sn'a pas de cours ?? cette horaire.\n", formation->nom);
    } 
}

void AddUEFormation(Formation formation, UE ue){
    // on v??rifie l'absence de l'UE
    ListeUE UETemp;
    bool present = false;
    UETemp = formation->ListeUE;
    while (UETemp->suivant != NULL && !present){
        if (UETemp->ue->id = ue->id){
            present = true;
        }
        UETemp = UETemp->suivant;
    }
    if (present){
        printf("L'UE %s est d??ja pr??sente dans la liste des UE de la formation %s", ue->nom, formation->nom);
    }
    else{;
        UETemp->suivant = (ListeUE)malloc(sizeof(S_ListeUE));
        UETemp->suivant->ue = ue;
    }
}

void SupprUEFormation(Formation formation, UE ue){
    // on v??rifie la pr??sence de l'UE
    ListeUE UETemp;
    bool present = false;
    UETemp = formation->ListeUE;

    if (formation->ListeUE->ue->id == ue-> id)
        formation->ListeUE = formation->ListeUE->suivant;

    while (UETemp->suivant->suivant != NULL && !present){   // on s'arrete ?? l'avant dernier
        if (UETemp->suivant->ue->id = ue->id){
            present = true;
        }else{
        UETemp = UETemp->suivant;
        }
    }
    if(present){
        UETemp->suivant = UETemp->suivant->suivant;
    }
    else if (UETemp->suivant->ue->id = ue->id){             //si l'ue est la derniere dans la liste
        UETemp->suivant = NULL;
    }
}







void nouveauProf(char* nom, int id, ListeProf Listeprof){
    Prof p = InitialiseProf();
    SetNomProf(nom, p);
    SetIdProf(id, p);
    addProf(Listeprof, p);
}


void nouvelleSalle(int nom, ListeSalle Listesalle){
    Salle s = InitialiseSalle();
    SetNomSalle(nom, s);
    addSalle(Listesalle, s);
}


void nouvelleFormation(char* nom, int id, ListeFormation Listeformation){
    Formation f = InitialiseFormation();
    SetNomFormation(f, nom);
    SetIdFormation(f, id);
    addFormation(Listeformation, f);
}


void nouvelleUE(char* nom, int id, ListeUE ListeUe){
    UE ue = InitialiseUE();
    SetNomUE(nom, ue);
    SetIdUE(id, ue);
    addUE(ListeUe, ue);
}





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
            printf("Nom du prof ?? ajouter :\n");
            scanf("%s", &nom);
            prinf("Id du prof ?? ajouter:\n");
            scanf("%d",&id);
            nouveauProf(nom, id, profs);
        }
        else if (r==2){// suppression d'un prof
            Prof p = InitialiseProf();
            char* nom;
            printf("Nom du prof ?? supprimer :\n");
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
            printf("Nom de la salle ?? ajouter:\n");
            scanf("%d", &nom);
            nouvelleSalle(nom, salles);
        }
        else if (r==2){// suppression d'une salle
            Salle s = InitialiseSalle();
            int nom;
            printf("Nom de la salle ?? suppriemr :\n");
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
            printf("Nom de la formation ?? ajouter :\n");
            scanf("%s", &nom);
            prinf("Id de la formation ?? ajouter:\n");
            scanf("%d",&id);
            nouvelleFormation(nom, id, formations);
        }
        else if (r==2){// suppression d'une formation
            Formation f = InitialiseFormation();
            char* nom;
            printf("Nom de la formation ?? supprimer :\n");
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
    printf("Nom de la formation o?? ajouter un cours :\n");
    scanf("%s",&nomFormation);
    printf("Horaire du cours ?? ajouter :\n");
    scanf("%d", &horaire);
    horaire--;

    char* nomSalle;
    printf("Nom de la salle o?? ajouter un cours :\n");
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
    printf("Nom de la formation o?? supprimer un cours :\n");
    scanf("%s",&nomFormation);
    printf("Horaire du cours ?? supprimer :\n");
    scanf("%d", &horaire);
    horaire--;

    char* nomSalle;
    printf("Nom de la salle o?? supprimer un cours :\n");
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