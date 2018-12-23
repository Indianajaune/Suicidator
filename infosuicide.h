#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include "libcsv/csv.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct person {
    unsigned short int age;
    bool sex;
    char* country;
    unsigned int year;
}PERSON;

struct counts {
  long unsigned fields;
  long unsigned rows;
};

void cb1 (void *s, size_t len, void *data);
void cb2 (int c, void *data);

bool country_checker(char*);

bool sex_asker();

void menu(int*);
