#ifndef COMP_H
#define COMP_H
 
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>   //fork
#include <sys/wait.h> //waitpid
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#define MAX_LIMIT 1024
#define NUM_OF_MENU_OPTIONS 6
#define MAX_NUMBER_OF_BUNNIES_IN_SECOND_GROUP 128
#define MAX_NUMBER_OF_BUNNIES_IN_FIRST_GROUP 128
typedef struct
{
    char name[MAX_LIMIT];
    int area;
    int numOfEnteries;
} applicant;
void printPossibleAreas();
void validate(int *areaNum);
void addToFile(char *line, char *fname);
bool nameExistsInFile(char name[], char fname[]);
void add(char *fname);
char* nameFromLine(char *line);
bool isNameInLine(char *givenName, char *line);
void myStrcat(char *buffer,  int numOfEnteries,int area);
void modifyData(char *name, char *fname);
void modify(char *fname);
void delData(char *name, char *fname);
void Delete(char *fname);
int getIndexOfArea(char *area);
void getApplicantInfo(applicant *tmp, char *line);
void printApplicantsInArea(int choice, char *fname);
void ListByArea(char *fname);
void excute(int choice);
void Menu();
void StartWateringComp(char* fname);
char* extractAreaFromLine(char* line);
#endif