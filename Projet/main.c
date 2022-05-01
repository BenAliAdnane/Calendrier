#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"
#include <json-c/json.h>

int main(){

    FILE *fFormation;
    FILE *fProf;
    FILE *fSalle;

    char buffer1[1024];
    char buffer2[1024];
    char buffer3[1024];

    struct JSON_object *parsed_json1;
    struct JSON_object *parsed_json2;
    struct JSON_object *parsed_json3;
    struct JSON_object *nom;
    struct JSON_object *id;
    struct JSON_object *ListeUE;

    struct JSON_object *UE;

    size_t n_ListeUE;
    size_t i;

    fFormation = fopen("Formation.json", "r");
    fread(buffer1, 1024, 1, fFormation);
    fclose(fFormation);

    fProf = fopen("Prof.json", "r");
    fread(buffer2, 1024, 1, fProf);
    fclose(fProf);

    fSalle = fopen("Salle.json", "r");
    fread(buffer3, 1024, 1, fSalle);
    fclose(fSalle);

    parsed_json1= json_tokener_parse(buffer1);
    parsed_json2= json_tokener_parse(buffer2);
    parsed_json3= json_tokener_parse(buffer3);

    
    
    



    int motDePasse=5567;
    int reponse;
    printf("                Calendrier, Mot de Passe, JSon\n\nEntrez le mot de passe ==> ");
    scanf("%d",&reponse);

    if(reponse == motDePasse){
        printf("\nMot de passe correct");
        int accesListeSalle =1;
        int accesListeProf =2;
        int accesListeFormation =3;
        printf("\nAcceder aux \n1 : Listes des Professeurs\n2 : Listes des Salles\n3 : Listes des Formations\nVotre reponse ==> ");
        int rep;
        scanf("%d",&rep);
        
        if(rep==1){
            json_object_object_get_ex(parsed_json2,"nom", &nom);
            json_object_object_get_ex(parsed_json2,"id", &id);

            printf("Nom: %s\n", json_object_get_string(parsed_json2,nom));
            printf("Id: %d\n", json_object_get_int(parsed_json2,id));
        }
        else if(rep==2){
            json_object_object_get_ex(parsed_json3,"nom", &nom);

            printf("Nom: %s\n", json_object_get_string(parsed_json3,nom));
        }
        else if(rep==3){
            json_object_object_get_ex(parsed_json1,"nom", &nom);
            json_object_object_get_ex(parsed_json1,"ListeUE", &ListeUE);

            n_ListeUE = json_object_array_length(ListeUE);
            printf("Trouver %lu UE\n", n_ListeUE);
            for(i=0; i<n_ListeUE;i++){
                UE = json_object_array_get_idx(ListeUE,i);

                printf("\t\t%lu. %s\n", i+1, json_object_get_string(parsed_json1,UE));
            }

                    
        }else{
            printf("\nERREUR : mauvaise saisi");
        }
        printf("\n\nAu revoir");
    }
    else{
        printf("\nERREUR: ACCES REFUSE");
    }
}