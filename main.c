#include "infosuicide.h"




static int is_space(unsigned char c) {
  if (c == CSV_SPACE || c == CSV_TAB) return 1;
  return 0;
}

static int is_term(unsigned char c) {
  if (c == CSV_CR || c == CSV_LF) return 1;
  return 0;
}


int main(int argc, char *argv[]) {
    system("clear");
    clock_t t;
    t=clock();
    FILE *fp;
    struct csv_parser p;
    char buf[1024];
    size_t bytes_read;
    unsigned char options = 0;
    struct counts c = {0, 0};

    if (argc < 2) {
      fprintf(stderr, "Utilisation: ./infosuicide [-s] files\n");
      exit(EXIT_FAILURE);
    }

    if (csv_init(&p, options) != 0) {
      fprintf(stderr, "Echec de l'initialisation de l'analyseur CSV \n");
      exit(EXIT_FAILURE);
    }

    //PERSON q;
    int choice;


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
        fprintf(stderr, "Echec de l'ouverture de %s: %s\n", *argv, strerror(errno));
        continue;
      }

      while ((bytes_read=fread(buf, 1, 1024, fp)) > 0) {
        if (csv_parse(&p, buf, bytes_read, field_counter, row_counter, &c) != bytes_read) {
          fprintf(stderr, "Erreur lors de l'analyse du fichier: %s\n", csv_strerror(csv_error(&p)));
        }
      }

      csv_fini(&p, field_counter, row_counter, &c);

      if (ferror(fp)) {
        fprintf(stderr, "Erreur de lecture de %s\n", *argv);
        fclose(fp);
        continue;
      }

      fclose(fp);

    }
    csv_free(&p);
    t = clock()-t;
    printf("%sFichier countenant %lu colonnes et %lu lignes \n",KYEL,c.fields,c.rows);
    printf("Initialise en %ld ticks (%f seconds) \n",t,((float)t)/CLOCKS_PER_SEC);
    sleep(3);
    if((c.fields==0)||(c.rows==0)){
      exit(EXIT_FAILURE);
    }
    menu(&choice);



    switch(choice){

    case 0 :
        exit(EXIT_SUCCESS);
        return(0);
        break;
    case 1 :

        fp = fopen(*argv, "r");
        if (!fp) {
          fprintf(stderr, "Echec de l'ouverture de %s: %s\n", *argv, strerror(errno));
        }

        fclose(fp);
      /*
        system("clear");
        printf("Veuillez entrer vos donnees : \n");
        printf("Votre age : \n");
        scanf("%d", &q.age);
        q.sex=sex_asker();
        printf("\n Votre Pays : \n");
            scanf("%s", &q.country);
            country_checker(q.country);
        printf("Votre annee : \n");
        scanf("%f", year);
        q.year = year;
        */
        break;
    case 2 :
    /*
        system("clear");
        printf("Veuillez entrer vos donnees : \n");
        printf("\n Votre Pays : \n");
        scanf("%s", &q.country);
        country_checker(q.country);
        printf("Votre annee : \n");
        scanf("%f", year);
        q.year = year;
        */
        break;
    case 3 :
    /*
        printf("\n Votre Pays : \n");
        scanf("%s", &q.country);
        country_checker(q.country);
        */
        break;
    case 4 :
        break;
    case 5 :
    /*
        system("clear");
        printf("Veuillez entrer vos donnees : \n");
        printf("Votre age : \n");
        scanf("%d", &q.age);
        printf("\n Votre sexe (M/F) : \n");
        scanf("%d", sex);
        if ((strcmp(sex, "M") != 0) && (strcmp(sex, "F") != 0)) {
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
        */
        break;
    default :
        printf("test");
        break;
    }

}
