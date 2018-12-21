#include "infosuicide.h"


int main() {


    typedef struct request {
        unsigned short int age;
        bool sex;
        char* country;
        unsigned int year;
    }request;

    request q;
    char *sex ="M";
    struct tm * timeinfo;
    unsigned int year;

    unsigned short int choice;
    printf("Bienvenue dans l'application InfoSuicide : \n");
    printf("Menu : \n");
    printf("0. Quitter l'application");
    printf("1. Nombre de suicides selon des critères");
    printf("2. Afficher le taux de suicide par année d'un pays");
    printf("3. Afficher la répartition de suicides par sexe pour un pays");
    printf("4. Trier (et afficher) les taux de suicide par ordre décroissant");
    printf("5. Calculer le taux de possibilité de suicide selon des critères (naive bayes)");

    switch(choice){

    case 0 :
        return(0);
    case 1 :

        printf("\e[1;1H\e[2J");
        printf("Veuillez entrer vos donnees : \n");
        printf("Votre age : \n");
        scanf("%d", &q.age);
        printf("\n Votre sexe (M/F) : \n");
        scanf("%d", sex);
        if ((strcmp(sex, "M" != 0) && (strcmp(sex, "F") != 0))){
            scanf("%d", sex);
        }else if (strcmp(sex, "F") == 0) {
            q.sex = true;
        }else if (strcmp(sex, "M") == 0) {
                q.sex = false;
            }
        printf("\n Votre Pays : \n");
            scanf("%s", &q.country);
            country_checker(q.country);
        printf("Votre annee : \n");
        scanf("%f", year);
        q.year = year;

    case 2 :
        printf("\e[1;1H\e[2J");
        printf("Veuillez entrer vos donnees : \n");
        printf("\n Votre Pays : \n");
        scanf("%s", &q.country);
        country_checker(q.country);
        printf("Votre annee : \n");
        scanf("%f", year);
        q.year = year;
    case 3 :
        printf("\n Votre Pays : \n");
        scanf("%s", &q.country);
        country_checker(q.country);
    case 4 :

    case 5 :
        printf("\e[1;1H\e[2J");
        printf("Veuillez entrer vos donnees : \n");
        printf("Votre age : \n");
        scanf("%d", &q.age);
        printf("\n Votre sexe (M/F) : \n");
        scanf("%d", sex);
        if ((strcmp(sex, "M" != 0) && (strcmp(sex, "F") != 0))) {
            scanf("%d", sex);
        }
        else if (strcmp(sex, "F") == 0) {
            q.sex = true;
        }
        else if (strcmp(sex, "M") == 0) {
            q.sex = false;
        }
        printf("\n Votre Pays : \n");
        scanf("%s", &q.country);
        country_checker(q.country);
        printf("Votre annee : \n");
        scanf("%f", year);
        q.year = year;
    }

}
