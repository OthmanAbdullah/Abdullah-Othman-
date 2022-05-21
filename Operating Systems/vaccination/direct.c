#include "direct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int has_txt_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 4 && strcmp(name + len - 4, ".txt") == 0;
}

char* printDir(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    char** Files;
    Files = (char**) malloc(100* sizeof(char*));
    for(int i=0; i<100; i++)
    {
        Files[i] = (char*) malloc(100*sizeof(char));
    }
    int cnt =0;
    char* return_string;
    return_string = (char*) malloc(100*sizeof(char));
    if (d) {
    printf("/-----------------------------\n");
    printf("Input the number of the file you want to select:\n");
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type==DT_REG && has_txt_extension(dir->d_name)){
            Files[cnt] = dir->d_name;
            printf("(%d). %s\n",cnt, dir->d_name);
            cnt++;
        }
    }
    closedir(d);
    int mynum = 0;
    scanf("%d", &mynum);
    strcpy(return_string, Files[mynum]);
    printf("%s\n",return_string);
    free(Files);
    }
    return return_string;
}
