#include "infosuicide.h"



struct counts {
  long unsigned fields;
  long unsigned rows;
};

void cb1 (void *s, size_t len, void *data) { ((struct counts *)data)->fields++; }
void cb2 (int c, void *data) { ((struct counts *)data)->rows++; }

static int is_space(unsigned char c) {
  if (c == CSV_SPACE || c == CSV_TAB) return 1;
  return 0;
}

static int is_term(unsigned char c) {
  if (c == CSV_CR || c == CSV_LF) return 1;
  return 0;
}


int main(int argc, char *argv[]) {


    typedef struct person {
        unsigned short int age;
        bool sex;
        char* country;
        unsigned int year;
    }PERSON;

    PERSON q;
    char *sex ="M";
    struct tm * timeinfo;
    unsigned int year;
    int choice;
    
    FILE *fp;
    struct csv_parser p;
    char buf[1024];
    size_t bytes_read;
    unsigned char options = 0;
    struct counts c = {0, 0};



    if (argc < 2) {
      fprintf(stderr, "Usage: infosuicide [-s] files\n");
      exit(EXIT_FAILURE);
    }

    if (csv_init(&p, options) != 0) {
      fprintf(stderr, "Failed to initialize csv parser\n");
      exit(EXIT_FAILURE);
    }
    menu(&choice);

    csv_set_space_func(&p, is_space);
    csv_set_term_func(&p, is_term);

    while (*(++argv)) {
      if (strcmp(*argv, "-s") == 0) {
        options = CSV_STRICT;
        csv_set_opts(&p, options);
        continue;
      }

      fp = fopen(*argv, "rb");
      if (!fp) {
        fprintf(stderr, "Failed to open %s: %s\n", *argv, strerror(errno));
        continue;
      }

      while ((bytes_read=fread(buf, 1, 1024, fp)) > 0) {
        if (csv_parse(&p, buf, bytes_read, cb1, cb2, &c) != bytes_read) {
          fprintf(stderr, "Error while parsing file: %s\n", csv_strerror(csv_error(&p)));
        }
      }

      csv_fini(&p, cb1, cb2, &c);

      if (ferror(fp)) {
        fprintf(stderr, "Error while reading file %s\n", *argv);
        fclose(fp);
        continue;
      }

      fclose(fp);
      printf("%s: %lu fields, %lu rows\n", *argv, c.fields, c.rows);
    }

    csv_free(&p);
    exit(EXIT_SUCCESS);




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
    default :
        printf("test");
    }

}
