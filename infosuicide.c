#include "infosuicide.h"



void field_counter (void *s, size_t len, void *data) { ((struct counts *)data)->fields++; }

void row_counter (int c, void *data) { ((struct counts *)data)->rows++; }


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
    sleep(1);
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
  while (fgets(buf, sizeof buf, file) != NULL){
    if(++line_count >= i){
      break;
    }
  }

    const char delim[2] = ",";



      token = strtok(buf, delim);


      while( token != NULL ) {


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
          data[i].suicides_no=(unsigned int)atoi(token);
          token = strtok(NULL, delim);
          j++;

          break;
        case 5 :
          data[i].population=(int)atoi(token);

          token = strtok(NULL, delim);

          j=0;
          break;
        default :
          printf("Something's wrong \n");
          exit(EXIT_FAILURE);
          break;
      }



}

    }







  fclose(file);
  return true;
}

void display_data(ENTRY * data, long unsigned max){
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

PERSON information_asker(){
  PERSON p;
  p.sex=sex_asker();
  printf("Entrez  l'âge de la personne : \t");
  scanf("%u",&p.age);
  if(p.age<=14){
    p.age=1;
  }else if((p.age >= 15)&&(p.age<=24)){
    p.age=2;
  }else if((p.age>=25)&&(p.age<=34)){
    p.age=3;
  }else if((p.age>=35)&&(p.age<=54)){
    p.age=4;
  }else if((p.age>=55)&&(p.age<=74)){
    p.age=5;
  }else p.age = 6;
  printf("\n entrez le pays : \t");
  scanf (" %[^\t\n]s", &p.country);
  printf("\n entrez l'année :  \t");
  scanf("%u",&p.year);
  return(p);
}

void display_suicide_rate(ENTRY * data, unsigned int max,char country[50],unsigned int year){
  unsigned int i;
  unsigned long int population=0,deathes=0;
  float suicide_rate;
  for(i=1;i<max-1;i++){
    if((strcmp(country,data[i].dead.country)==0)&&(data[i].dead.year==year))
    {
        population=population+data[i].population;
        deathes=deathes+data[i].suicides_no;


    }
  }
  suicide_rate=(float)deathes/(float)population;
  printf("\npopulation : %i",population);
  printf("\nmorts : %i",deathes);
  printf("\n taux de suicide : %f %\n",suicide_rate);
}


void display_parity(ENTRY * data, unsigned int max,char country[50]){
  unsigned int i;
  unsigned long int population_m=0,deathes_m=0,population_f=0,deathes_f=0,population=0,deathes=0;
  float suicide_rate_m,suicide_rate_f;
  for(i=1;i<max-1;i++){
    if((strcmp(country,data[i].dead.country)==0)&&(data[i].dead.sex==true))
    {
        population_m=population_m+data[i].population;
        deathes_m=deathes_m+data[i].suicides_no;


    }

    if((strcmp(country,data[i].dead.country)==0)&&(data[i].dead.sex==false))
    {
        population_f=population_f+data[i].population;
        deathes_f=deathes_f+data[i].suicides_no;


    }
  }
  deathes = deathes_m+deathes_f;
  population = population_f  + population_m;
  suicide_rate_m=(float)deathes_m/(float)deathes;
  suicide_rate_f=(float)deathes_f/(float)deathes;
  printf("\npopulation : %i de femmes , %i d'hommes",population_f,population_m);
  printf("\nmorts : %i de femmes , %i  d'hommes",deathes_f, deathes_m);
  printf("\ntaux de suicide : %f pour cent de femmes , %f pour cent d'hommes\n",suicide_rate_f ,suicide_rate_m);

}

void menu(int* choice){
  system("clear");
  printf("%s ██▓ ███▄    █   █████▒▒█████    ██████  █    ██  ██▓ ▄████▄   ██▓▓█████▄ ▓█████ \n▓██▒ ██ ▀█   █ ▓██   ▒▒██▒  ██▒▒██    ▒  ██  ▓██▒▓██▒▒██▀ ▀█  ▓██▒▒██▀ ██▌▓█   ▀ \n▒██▒▓██  ▀█ ██▒▒████ ░▒██░  ██▒░ ▓██▄   ▓██  ▒██░▒██▒▒▓█    ▄ ▒██▒░██   █▌▒███   \n░██░▓██▒  ▐▌██▒░▓█▒  ░▒██   ██░  ▒   ██▒▓▓█  ░██░░██░▒▓▓▄ ▄██▒░██░░▓█▄   ▌▒▓█  ▄ \n░██░▒██░   ▓██░░▒█░   ░ ████▓▒░▒██████▒▒▒▒█████▓ ░██░▒ ▓███▀ ░░██░░▒████▓ ░▒████▒\n░▓  ░ ▒░   ▒ ▒  ▒ ░   ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒ ░▓  ░ ░▒ ▒  ░░▓   ▒▒▓  ▒ ░░ ▒░ ░\n ▒ ░░ ░░   ░ ▒░ ░       ░ ▒ ▒░ ░ ░▒  ░ ░░░▒░ ░ ░  ▒ ░  ░  ▒    ▒ ░ ░ ▒  ▒  ░ ░  ░\n ▒ ░   ░   ░ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░   ░░░ ░ ░  ▒ ░░         ▒ ░ ░ ░  ░    ░   \n ░           ░            ░ ░        ░     ░      ░  ░ ░       ░     ░       ░  ░\n                                                     ░             ░             \n", KRED);



  printf("\t %sBienvenue dans l'application InfoSuicide : \n", KNRM);
  printf("Menu : \n");
  printf("0. Quitter l'application\n");
  printf("1. Afficher les données\n");
  printf("2. Afficher le taux de suicide par année d'un pays\n");
  printf("3. Afficher la répartition de suicides par sexe pour un pays\n");
  printf("4. Trier (et afficher) les taux de suicide par ordre décroissant\n");
  printf("5. Calculer le taux de possibilité de suicide selon des critères (naive bayes)\n");
  scanf("%d", choice);


}
