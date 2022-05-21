#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h> //open,creat
#include <sys/types.h> //open
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <dirent.h> 
#include <string.h>

struct Report
{
    char name[100];
    char birth_year[20];
    char phone_number[40];
    char free[20];
    int vaccinated;
    int cnt;
};
void modify_file(const char* filename, struct Report *Data);
struct Report* findData(char* Filename);
int* countPatients(char* filename, int* cnt);
void launchBus(char* filename);
void noFile( char* myfile);
void File( char* myfile);
char* totalList();
int Displaymenu(char* Filename, int isThereFile);
int DisplayFiles();
void readFile(char* Filename);
void editFile(char* Filename);
void removeFile(char* Filename);
void addtoFile(char* Filename);
void handleSignle(int signum);
