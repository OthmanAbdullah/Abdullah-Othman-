#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h> //open,creat
#include <sys/types.h> //open
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h> //waitpid
#include <unistd.h> // fork
#include <dirent.h> 
#include <string.h>
#include "Report.h"


int main(int argc, char const *argv[])
{
    int isThereFile =0;
    char* myfile;
    if (argc > 1)
    {
        strcpy(myfile, argv[1]);
        isThereFile = 1;
    }
    isThereFile ? File(myfile): noFile(myfile);
    // File("qwerDB.txt");   
    return 0;
}
