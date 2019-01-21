#include "infosuicide.h"



void field_counter (void *s, size_t len, void *data) {
   ((struct counts *)data)->fields++;

  // static unsigned short int i;
  // if(((i==0)||(i==1)||(i==2)||(i==3)||(i==4)||(i==5))^true)
  // {
  //   printf("%.*s\n", len, data);
  // }
  // if(i==5){
  //   i=0;
  // }
  // if(i==8){
  // printf("%u \t",i);
  // printf(strcat(((char *)s),"\t"));
  // sleep(1);
  // }
  // i++;

}

void row_counter (int c, void *data) {
  ((struct counts *)data)->rows++;
 }

 void field_saver(void *s, size_t len, void *data){

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

bool csvToStruct(ENTRY *data, char *path_to_file, long unsigned max) {
  char buf[1024];
  int line_count = 0;
  unsigned int i,j=0;
  char *token;

  FILE *file = fopen(path_to_file, "r");

  if (!file) {
    fprintf(stderr, "Can't open file.\n");
    exit(EXIT_FAILURE);
  }

  for(i=0;i<((unsigned int)max)-1 ;i++){
  while (fgets(buf, sizeof buf, file) != NULL)
    if (++line_count >= i)
      break;
      printf(buf);
      const char delim[2] = ",";


      /* get the first token */
      token = strtok(buf, delim);

      /* walk through other tokens */
      while( token != NULL ) {
      printf( " %s\n", token );

      switch(j){
        case 0 :



          strcpy(data[i].dead.country, token);

          token = strtok(NULL, delim);

          j++;

          break;
        case 1 :

          data[i].dead.year= (unsigned int)atoi(token);
          token = strtok(NULL, delim);
          j++;

          break;
        case 2 :

          if(strcmp("male",token)==0){
            data[i].dead.sex=true;
          }else if(strcmp("male",token)==0){
            data[i].dead.sex=false;
          }
          token = strtok(NULL, delim);
          j++;

          break;
        case 3 :
          if(strcmp(token,"5-14 years")==0){
            data[i].dead.age=1;
          }else if(strcmp(token,"15-24 years")==0){
            data[i].dead.age=2;
          }else if(strcmp(token,"25-34 years")==0){
            data[i].dead.age=3;
          }else if(strcmp(token,"35-54 years")==0){
            data[i].dead.age=4;
          }else if(strcmp(token,"55-74 years")==0){
            data[i].dead.age=5;
          }else if(strcmp(token,"75+ years")==0){
            data[i].dead.age=6;
          }
          token = strtok(NULL, delim);
          j++;

          break;
        case 4 :
          data[i].suicides_no= (unsigned int)atoi(token);
          token = strtok(NULL, delim);
          j++;

          break;
        case 5 :
          data[i].population= (int)atoi(token);

          token = strtok(NULL, delim);

          j=0;
          break;
        default :
          printf("Something's wrong");
          exit(EXIT_FAILURE);
          break;
      }



}

    }







  fclose(file);
  return true;
}

display_data(ENTRY * data, long unsigned max){
  long unsigned i;
  for(i=0;i< max- 1;i++){
  printf("country : %s\t", data[i].dead.country);
  printf("year : %u \t",data[i].dead.year);
  if(data[i].dead.sex==false){
    printf("sex : female \t");
  }else printf("sex : male \t");

  switch(data[i].dead.age){
    case 1 :
      printf("age : 5-14 \t");
      break;
    case 2 :
      printf("age : 15-24 \t");
      break;
    case 3 :
        printf("age : 25-34 \t");
      break;
    case 4 :
        printf("age : 35-54 \t");
      break;
    case 5 :
        printf("age : 55-74 \t");
      break;
    case 6 :
        printf("age : 75+ \t");
      break;


  }
  printf("suicides_no : %u \t", data[i].suicides_no);
  printf("population : %u \n", data[i].population);
  }

}

void menu(int* choice){
  system("clear");
  printf("%s ██▓ ███▄    █   █████▒▒█████    ██████  █    ██  ██▓ ▄████▄   ██▓▓█████▄ ▓█████ \n▓██▒ ██ ▀█   █ ▓██   ▒▒██▒  ██▒▒██    ▒  ██  ▓██▒▓██▒▒██▀ ▀█  ▓██▒▒██▀ ██▌▓█   ▀ \n▒██▒▓██  ▀█ ██▒▒████ ░▒██░  ██▒░ ▓██▄   ▓██  ▒██░▒██▒▒▓█    ▄ ▒██▒░██   █▌▒███   \n░██░▓██▒  ▐▌██▒░▓█▒  ░▒██   ██░  ▒   ██▒▓▓█  ░██░░██░▒▓▓▄ ▄██▒░██░░▓█▄   ▌▒▓█  ▄ \n░██░▒██░   ▓██░░▒█░   ░ ████▓▒░▒██████▒▒▒▒█████▓ ░██░▒ ▓███▀ ░░██░░▒████▓ ░▒████▒\n░▓  ░ ▒░   ▒ ▒  ▒ ░   ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒ ░▓  ░ ░▒ ▒  ░░▓   ▒▒▓  ▒ ░░ ▒░ ░\n ▒ ░░ ░░   ░ ▒░ ░       ░ ▒ ▒░ ░ ░▒  ░ ░░░▒░ ░ ░  ▒ ░  ░  ▒    ▒ ░ ░ ▒  ▒  ░ ░  ░\n ▒ ░   ░   ░ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░   ░░░ ░ ░  ▒ ░░         ▒ ░ ░ ░  ░    ░   \n ░           ░            ░ ░        ░     ░      ░  ░ ░       ░     ░       ░  ░\n                                                     ░             ░             \n", KRED);



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
