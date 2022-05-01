#include <stdlib.h>
#include <stdio.h>
#include "../Include/calendrier.h"
#include <json-c/json.h>
#include "../Include/sha1.h"
#include "../Include/menus.h"


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



void MainMenu(ListeFormation formations, ListeProf profs, ListeSalle salles, BYTE* hash){
    int r;
    printf("\nChoisissez le menus :\n\n\t1 - admin\n\t2 - clients\n\t0 - quitter\n");
    scanf("%d",&r);
    while(r!=0){
        if (r==1){
            char* mdp;
            printf("mot de passe :\n");
            scanf("%s", &mdp);
            SHA1_CTX ctx;
            BYTE buf[400];

            sha1_init(&ctx);

            sha1_update(&ctx, mdp, strlen(mdp));

            sha1_final(&ctx, buf);

            if(memcmp(hash, buf, SHA1_BLOCK_SIZE)){
                menuAdmin(formations, profs, salles);
            }
            else{
                printf("Mauvais mot de passe");
            }
        }
        else if(r==2){

            menuClients(formations, profs, salles);
        }
        printf("\nChoisissez le menus :\n\n\t1 - admin\n\t2 - clients\n\t0 - quitter\n");
        scanf("%d",&r);
    }
}




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

    
    
    
    FILE* fMdp;
    char buffer4[1024];
    struct JSON_Object *parsed_json4;
    struct JSON_Object *mdp;
    fMdp = fopen("mdp.json", "r");
    fread(buffer4, 1024, 1, fMdp);
    fclose(fMdp);
    
    MainMenu(buffer1, buffer2, buffer3, buffer4);
    
    return 0;
}