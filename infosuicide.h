//utilisation du C11 lors de la compilation pour permettre les commentaires en "//"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <regex.h>
#include "libcsv/csv.h"
#include "darknet/include/darknet.h"

//utilise pour coloriser le terminal
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"



//wrapper utilise pour rentrer une personne age est compris
typedef struct person {
    unsigned short int age;
    bool sex;
    char country[50];
    unsigned int year;
}PERSON;

//encapsulation d'une personne dans une entree (qui correspond en fait a une ligne du csv)
typedef struct entry {
    PERSON dead;
    int population;
    unsigned int suicides_no;
}ENTRY;


//utilise pour compter les lignes et colonnes
struct counts {
  long unsigned fields;
  long unsigned rows;
};

//fonctions dites "callback" utilisees pour compter les lignes et colonnes lors de l'appel de csv_parse()
void field_counter (void *s, size_t len, void *data);
void row_counter (int c, void *data);



//sert a verifier si le pays est valide
bool country_checker(char*);

//sert a a demander a l'utilisateur le sexe en format "M/F" pour ensuite le restituer en booleen
bool sex_asker();

void display_data(ENTRY * data, long unsigned max);


bool csvToStruct(ENTRY *data, char *path_to_file, long unsigned max);
//sert a afficher le menu
void menu(int*);
