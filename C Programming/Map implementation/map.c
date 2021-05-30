#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"

//////////////////////////////////////////////////////////////

void init(Map *arr)
{
    arr->items = NULL;
    arr->size = 0;
}

//////////////////////////////////////////////////////////////

void dest(Map *arr)
{
    //   printf("recived %d to deallocate\n", arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        free(arr->items[i]);
        // printf("succesfully freed \n");
    }
    free(arr->items);
}

/////////////////////////////////////////////////////////////

Pair *find(Map *arr, char *str)
{
    for (int i = 0; i < arr->size; i++)
        if (strcmp(str, arr->items[i]->str) == 0)
        {
            return arr->items[i];
        }

    return NULL;
}

/////////////////////////////////////////////////////////////

void set(Map *arr, char *str, int num)
{
    // printf("Allocated \n");
    arr->size++;
    arr->items = (Pair **)realloc(arr->items, (arr->size * sizeof(Pair *)));
    arr->items[arr->size - 1] = malloc(sizeof(Pair));

    strcpy(arr->items[arr->size - 1]->str, str);
    num++;
    arr->items[arr->size - 1]->num = num;
}

/////////////////////////////////////////////////////////////

int get(Map *arr, char *str)
{
    //  printf("recived word : %s \n", str);
    Pair *ptr;
    ptr = find(arr, str);

    if (ptr == NULL)
    {
        set(arr, str, 0);
        return 0;
    }
    ptr->num++;
    return ptr->num;
}
/////////////////////////////////////////////////////////////

void print(Map *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%s    ->     %d\n", arr->items[i]->str, arr->items[i]->num);
    }
}
/////////////////////////////////////////////////////////////