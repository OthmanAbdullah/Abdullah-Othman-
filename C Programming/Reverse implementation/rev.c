#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"rev.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INITCAP 8
#define BUFSIZE 1024
char **read(FILE *fp, char **lines, int *lSize)
{
    int capacity = INITCAP;
    char temp[BUFSIZE];

    while (fscanf(fp, "%s", temp) != EOF)
    {
        lines[*lSize] = malloc(BUFSIZE * sizeof(char));

        if (capacity == *lSize)
        {
            capacity += capacity;
            lines = realloc(lines, capacity * sizeof(char *));
            for (int i = *lSize; i < capacity; i++)
            {
                lines[i] = malloc(BUFSIZE * sizeof(char));
            }
        }

        strcpy(lines[*lSize], temp);
        *(lSize) = *(lSize) + 1;
    }

    return lines;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void write(char **lines, int size)
{

    int Sword = 0;
    for (int i = (size - 1); i >= 0; i--)
    {
        printf("%d ", i + 1);
        Sword = strlen(lines[i]);

        for (int j = (Sword - 1); j > -1; j--)
        {
            printf("%c", lines[i][j]);
        }
        printf("\n");
    }
}

void reverse(FILE *fp)
{

    char **lines;
    lines = malloc(INITCAP * sizeof(char *));
    int size = 0;

    char **ln = read(fp, lines, &size);
    write(ln, size);

    for (int i = 0; i < size; i++)
    {
        free(lines[i]);
    }

    fclose(fp);
    free(lines);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////