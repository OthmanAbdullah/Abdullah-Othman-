#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"

/////////////////////////////////////////////////////////////
void init(Set *set)
{

    set->items = NULL;
    set->size = 0;
}
/////////////////////////////////////////////////////////////
void dest(Set *set)
{

    for (int i = 0; i < set->size; i++)
    {
        free(set->items[i]);
    }

    free(set->items);
}
/////////////////////////////////////////////////////////////
int contains(Set *set, int num)
{
    for (int i = 0; i < set->size; i++)
    {
        if (*(set->items[i]) == num)
        {
            return 1;
        }
    }

    return 0;
}
/////////////////////////////////////////////////////////////
void insert(Set *set, int num)
{
    if (contains(set, num) == 0)
    {
        set->size++;
        set->items = realloc(set->items, set->size * sizeof(int *));
        set->items[set->size - 1] = malloc(sizeof(int));
        *(set->items[set->size - 1]) = num;
    }
}

/////////////////////////////////////////////////////////////

Set *set_union(Set *s1, Set *s2)
{

    Set *temp = malloc(sizeof(Set *));
    temp->items = malloc(sizeof(int *));
    temp->size = 0;
    for (int i = 0; i < s1->size; i++)
    {
        insert(temp, *(s1->items[i]));
    }

    for (int i = 0; i < s2->size; i++)
    {
        insert(temp, *(s2->items[i]));
    }

    return temp;
}

Set *set_intersection(Set *s1, Set *s2)
{

    Set *temp = malloc(sizeof(Set *));
    temp->items = malloc(sizeof(int *));
    temp->size = 0;
    for (int i = 0; i < s1->size; i++)
    {
        if (contains(s1, *(s2->items[i])))
        {
            temp->items[temp->size] = (s2->items[i]);
            temp->size++;
        }
    }
    return temp;
}

/////////////////////////////////////////////////////////////