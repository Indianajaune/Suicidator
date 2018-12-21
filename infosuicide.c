#include "infosuicide.h"


bool country_checker(char* entry){
  if(strcmp(entry,"France")==0){
    return(true);
  }else{
    return(false);
      }
  }

void menu(int* choice){
  printf("\e[1;1H\e[2J");
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
