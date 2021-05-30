#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"

int main(int argc, char *argv[])
{
    char string[WORD_BUFFER_SIZE] = "hello";
    Map arr;
    init(&arr);
    arr.items = (Pair **)malloc(sizeof(Pair *));

    FILE *fptr;
    char temp[WORD_BUFFER_SIZE];

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {

            fptr = fopen(argv[i], "r");
            if (fptr != NULL)
            {
                while (fscanf(fptr, "%s", temp) != EOF)
                {
                    get(&arr, temp);
                }
            }
            else
            {
                printf("Can't open the given file!\n");
            }
        }
    }

    else
    {
        fptr = stdin;
        if (fptr != NULL)
        {
            while (fscanf(fptr, "%s", temp) != EOF)
            {
                get(&arr, temp);
            }
        }
    }

    print(&arr);
    fclose(fptr);
    dest(&arr);
    return 0;
}