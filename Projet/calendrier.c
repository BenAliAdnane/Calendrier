#include <stdlib.h>
#include <stdio.h>
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



//Salle

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
    return (salle->cours[horaire -1]->horaire == 0);
}

void AddCoursSalle(Salle salle, Cours cours){
    if (CoursLibreSalle(salle, cours->horaire)){
        salle->cours[cours->horaire - 1] = cours;
    }
    else{
        printf("La salle %d n'est pas libre à cet horaire. Utiliser SupprCoursSalle(salle, cours) pour supprimer un cours.\n", salle->nom);
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
        printf("La formation %s à dejà un cours à cette horaire. Utiliser SupprCours(formation, Cours) pour supprimer ce cours\n", formation->nom);
    }
}

void SupprCoursFormation(Formation formation, Cours cours){
    if (!CoursLibreFormation(formation, cours->horaire)){
        formation->cours[cours->horaire - 1] = InitialiseCours();
    }
    else{
        printf("La formation %sn'a pas de cours à cette horaire.\n", formation->nom);
    } 
}

void AddUEFormation(Formation formation, UE ue){
    // on vérifie l'absence de l'UE
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
        printf("L'UE %s est déja présente dans la liste des UE de la formation %s", ue->nom, formation->nom);
    }
    else{;
        UETemp->suivant = (ListeUE)malloc(sizeof(S_ListeUE));
        UETemp->suivant->ue = ue;
    }
}

void SupprUEFormation(Formation formation, UE ue){
    // on vérifie la présence de l'UE
    ListeUE UETemp;
    bool present = false;
    UETemp = formation->ListeUE;

    if (formation->ListeUE->ue->id == ue-> id)
        formation->ListeUE = formation->ListeUE->suivant;

    while (UETemp->suivant->suivant != NULL && !present){   // on s'arrete à l'avant dernier
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


// Fonctions pour les cours

Cours InitialiseCours(){

    Cours newCours= (Cours)malloc(sizeof(struct s_cours));

    newCours->horaire=0;
    newCours->ue=InitialiseUE();
    newCours->prof=InitialiseProf();
    newCours->salle=InitialiseSalle();

    return newCours;

}

void SetProfCours(Cours cours, Prof prof){
    cours->prof=prof;
}
void setSalleCours(Cours cours, Salle salle){
    cours->salle=salle;
}
void setUECours(Cours cours, UE ue){
    cours->ue=ue;
}

// Fonctions pour les profs

Prof InitialiseProf(){

    Prof newProf=(Prof)malloc(sizeof(struct s_prof));

    newProf->id=0;
    newProf->nom=NULL;
    for(int i=0; i<20; i++){
        newProf->cours[i]=InitialiseCours();
    }
    return newProf;
}
void SetIdProf(int id, Prof prof){
    prof->id=id;
}
void SetNomProf(char* nom, Prof prof){
    prof->nom=nom;
}
bool CoursLibreProf(int horaire, Prof prof){
    return (prof->cours[horaire-1]->horaire==0);
}
void SupprCoursProf(Prof prof, Cours coursAEnlever){
    prof->cours[coursAEnlever->horaire -1]=InitialiseCours();
}

void AddCoursProf(Cours coursAMettre, Prof prof){
    if(CoursLibre(coursAMettre->horaire, prof)==0){
        prof->cours[coursAMettre->horaire - 1]=coursAMettre;
    }
}

//AddCours + CoursLibre

UE InitialiseUE(){
    UE newUE=(UE)malloc(sizeof(struct s_UE));
    newUE->id=0;
    newUE->nom=NULL;
    for(int i=0; i<20; i++){
        newUE->cours[i]=InitialiseCours();
    }
    return newUE;
}

void SetIdUE(int id, UE ue){
    ue->id=id;
}

void SetNomUE(char* nom, UE ue){
    ue->nom=nom;
}

void AddCoursUE(Cours coursAMettre, UE ue){
    int a=0;
    for(int i=0; ue->cours[i]->horaire!=0;i++){
        a++;
    }
    if(a<20){
        ue->cours[a]=coursAMettre;
    }else{
        printf("Plus d'emplacement");
    }
}
void SupprCoursUE(UE ue, Cours coursAEnlever){
        ue->cours[coursAEnlever->horaire -1]=InitialiseCours();
}







// GESTION DES LISTES


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
            printf("Le prof %s existe deja\n", prof->nom);
        }

    }

}

void supprProf(ListeProf Listeprof, Prof prof){

    // si la liste est vide
    if (Listeprof->prof == NULL){
        printf("Erreur : le prof %s nest pas presente dans la liste", prof->nom);
    }
    // si un seul prof dans la liste
    if (Listeprof->suivant = NULL){
        if (Listeprof->prof->nom == prof->nom)
            Listeprof = InitialisationListeProf();
        else
            printf("Erreur : le prof %s nest pas presente dans la liste", prof->nom);
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
            printf("Erreur : le prof %s nest pas presente dans la liste", prof->nom);
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
            printf("L'ue %s existe deja\n", ue->nom);
        }

    }

}

void supprUE(ListeUE ListeUe, UE ue){

    // si la liste est vide
    if (ListeUe->ue == NULL){
        printf("Erreur : l'ue %s nest pas presente dans la liste", ue->nom);
    }
    // si un seul ue dans la liste
    if (ListeUe->suivant = NULL){
        if (ListeUe->ue->nom == ue->nom)
            ListeUe = InitialisationListeUE();
        else
            printf("Erreur : l'ue %s nest pas presente dans la liste", ue->nom);
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
            printf("Erreur : l'ue %s nest pas presente dans la liste", ue->nom);
        else
            ListeTemp->suivant = ListeTemp->suivant->suivant;

    }

}


// CREATION DE NOUVEAUX PROF/UE/SALLE/FORMATIONS

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
