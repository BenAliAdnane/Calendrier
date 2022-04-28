#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"

int main(){

    int motDePasse=5567;
    int reponse;
    printf("                Calendrier, Mot de Passe, JSon\n\nEntrez le mot de passe ==> ");
    scanf("%d",&reponse);

    if(reponse == motDePasse){
        printf("\nMot de passe correct");
        int accesListeSalle =1;
        int accesListeProf =2;
        int accesListeFormation =3;
        printf("\nAcceder aux \n1 : Listes des Salles\n2 : Listes des Professeurs\n3 : Listes des Formations\nVotre reponse ==> ");
        int rep;
        scanf("%d",&rep);
        
        if(rep==1){
            //mettre JSon DataSalle
        }
        else if(rep==2){
            //mettre JSon DataSalle
        }
        else if(rep==3){
            //mettre JSon DataSalle
        }else{
            printf("\nERREUR : mauvaise saisi");
        }
        printf("\nAu revoir");
    }
    else{
        printf("\nERREUR: ACCES REFUSE");
    }
}