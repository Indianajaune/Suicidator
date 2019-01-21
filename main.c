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
    int choice;
    PERSON q;

    //Message affiché si aucun fichier fourni en argument
    if (argc < 2) {
      fprintf(stderr, "Utilisation: ./infosuicide [-s] files\n");
      exit(EXIT_FAILURE);
    }
    //Message affiché si problème à l'init dee l'analyseur
    if (csv_init(&p, options) != 0) {
      fprintf(stderr, "Echec de l'initialisation de l'analyseur CSV \n");
      exit(EXIT_FAILURE);
    }

    //Sert à affectr les caractères utiles du format CSV
    csv_set_space_func(&p, is_space);
    csv_set_term_func(&p, is_term);

    //Gestion du mode "strict" et des paramètres de libcsv (à ignorer pour l'instant)
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

      //appel de l'analyseur CSV sur le fichier fourni en argument avec les fonctions de callbacks de décompte des lignes et colonnes
      while ((bytes_read=fread(buf, 1, 1024, fp)) > 0) {
        if (csv_parse(&p, buf, bytes_read, field_counter, row_counter, &c) != bytes_read) {
          fprintf(stderr, "Erreur lors de l'analyse du fichier: %s\n", csv_strerror(csv_error(&p)));
        }
      }

      //sert a terminer le process précédent
      csv_fini(&p, field_counter, row_counter, &c);

      if (ferror(fp)) {
        fprintf(stderr, "Erreur de lecture de %s\n", *argv);
        fclose(fp);
        continue;
      }

      fclose(fp);

    }

    csv_free(&p);
    //test de validité du fichier (si il est vide, le programme se termine)
    if((c.fields==0)||(c.rows==0)){
      fprintf(stderr, "Fichier vide ou non valide \n" );
      sleep(3);
      exit(EXIT_FAILURE);
    }
    //init du tableau qui garde les données du CSV dans la RAM
    ENTRY data[50000] ;
    //affectation du tableau avec les données du fichier CSV
    if (csvToStruct(data, "who_suicide_statistics.csv",c.rows)==false){
      exit(EXIT_FAILURE);
    }else
    //fin du décompte, est utile pour voir le temps qu'a mis le process d'init
    t = clock()-t;
    //on affiche les données du CSV ainsi que le temps que le temps d'init
    printf("%sFichier countenant %lu colonnes et %lu lignes \n",KYEL,c.fields,c.rows);
    printf("Initialise en %ld ticks (%f seconds) \n",t,((float)t)/CLOCKS_PER_SEC);
    //sert a afficher temporairement les données précédentes avant de passer au menu
    sleep(4);

    menu(&choice);


    switch(choice){

    case 0 :
        exit(EXIT_SUCCESS);
        return(0);
        break;
    case 1 :
      display_data(data,c.rows);
      choice = 0;
        break;
    case 2 :
      q=information_asker();
      printf((char *)q.country);
      display_suicide_rate(data,c.rows,q.country,q.year);
      choice = 0;
        break;
    case 3 :
        printf("Entrez un pays : \t");
        scanf (" %[^\t\n]s", &q.country);
        display_parity(data, c.rows, q.country);
        choice = 0;
        break;
    case 4 :
        break;
    case 5 :

        break;
    default :
        printf("test");
        break;
    }

}
