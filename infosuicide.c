#include "infosuicide.h"



void field_counter (void *s, size_t len, void *data) {
   ((struct counts *)data)->fields++;
  /*static unsigned short int i;
  if(((i==0)||(i==1)||(i==2)||(i==3)||(i==4)||(i==5))^true)
  {
    i=0;
  }
  if(i==5){
    i=0;
  }
  if(i==8){
  printf("%u \t",i);
  printf(strcat(((char *)s),"\t"));
  sleep(1);
  }
  i++;
  */
}
void row_counter (int c, void *data) {
  ((struct counts *)data)->rows++;
 }

void country_loader(FILE * csv){
  
}

bool country_checker(char* entry){
  if(strcmp(entry,"France")==0){
    return(true);
  }else{
    return(false);
      }
  }

bool sex_asker(){
    char sex;
    bool result;
    while((((sex=='M')||(sex=='m'))||((sex=='F')||(sex=='f')))^true){
    printf("\n Votre sexe (M/F) : \n");
    scanf("%c",&sex);
    }
    if((sex=='M')||(sex=='m')){
      result=true;
    }else if((sex=='F')||(sex=='f')){
      result=false;
    }
    return(result);
}

void menu(int* choice){
  system("clear");
  printf("%s ██▓ ███▄    █   █████▒▒█████    ██████  █    ██  ██▓ ▄████▄   ██▓▓█████▄ ▓█████ \n", KRED);
  printf("%s▓██▒ ██ ▀█   █ ▓██   ▒▒██▒  ██▒▒██    ▒  ██  ▓██▒▓██▒▒██▀ ▀█  ▓██▒▒██▀ ██▌▓█   ▀ \n", KRED);
  printf("%s▒██▒▓██  ▀█ ██▒▒████ ░▒██░  ██▒░ ▓██▄   ▓██  ▒██░▒██▒▒▓█    ▄ ▒██▒░██   █▌▒███   \n", KRED);
  printf("%s░██░▓██▒  ▐▌██▒░▓█▒  ░▒██   ██░  ▒   ██▒▓▓█  ░██░░██░▒▓▓▄ ▄██▒░██░░▓█▄   ▌▒▓█  ▄ \n", KRED);
  printf("%s░██░▒██░   ▓██░░▒█░   ░ ████▓▒░▒██████▒▒▒▒█████▓ ░██░▒ ▓███▀ ░░██░░▒████▓ ░▒████▒\n", KRED);
  printf("%s░▓  ░ ▒░   ▒ ▒  ▒ ░   ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒ ░▓  ░ ░▒ ▒  ░░▓   ▒▒▓  ▒ ░░ ▒░ ░\n", KRED);
  printf("%s ▒ ░░ ░░   ░ ▒░ ░       ░ ▒ ▒░ ░ ░▒  ░ ░░░▒░ ░ ░  ▒ ░  ░  ▒    ▒ ░ ░ ▒  ▒  ░ ░  ░\n", KRED);
  printf("%s ▒ ░   ░   ░ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░   ░░░ ░ ░  ▒ ░░         ▒ ░ ░ ░  ░    ░   \n", KRED);
  printf("%s ░           ░            ░ ░        ░     ░      ░  ░ ░       ░     ░       ░  ░\n", KRED);
  printf("%s                                                     ░             ░             \n", KRED);



  printf("\t %sBienvenue dans l'application InfoSuicide : \n", KNRM);
  printf("Menu : \n");
  printf("0. Quitter l'application\n");
  printf("1. Nombre de suicides selon des critères\n");
  printf("2. Afficher le taux de suicide par année d'un pays\n");
  printf("3. Afficher la répartition de suicides par sexe pour un pays\n");
  printf("4. Trier (et afficher) les taux de suicide par ordre décroissant\n");
  printf("5. Calculer le taux de possibilité de suicide selon des critères (naive bayes)\n");
  scanf("%d", choice);


}
