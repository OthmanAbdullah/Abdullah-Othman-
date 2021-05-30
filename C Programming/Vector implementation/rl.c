#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "rl.h"
#define MY_MACRO

bool initialize(Vector *v, int capacity)
{
    if (capacity >= 0)
    {
        v->ptr = malloc(capacity * sizeof(int));
        v->current_size = 0;
        v->capacity = capacity;
        return true;
    }

    return false;
}

void dispose(Vector *v)
{
    free(v->ptr);
    v->capacity = 0;
}

bool append(Vector *v, int e)
{
    if (v->current_size < v->capacity)
    {
        v->ptr[v->current_size] = e;
        v->current_size++;
        return true;
    }

    return false;
}

int retrieve(Vector *v, int i)
{
    return v->ptr[i];
}

bool insert(Vector *v, int ind, int e)
{

    if (v->capacity == v->current_size)
        return false;

    int i = v->current_size;

    while (i != ind)
    {
        v->ptr[i] = v->ptr[i - 1];
        i--;
    }

    v->ptr[ind] = e;
    v->current_size++;
    return true;
}

bool erase(Vector *v, int ind)
{
    if (ind < v->current_size && ind > -1)
    {
        for (int i = ind; i < v->current_size - 1; i++)
        {
            v->ptr[i] = v->ptr[i + 1];
        }

        v->current_size--;
        return true;
        // realloc (v.ptr ,  )
    }

    return false;
}

bool set_capacity(Vector *v, int c)
{

    if (c >= v->current_size)
    {
        v->capacity = c;
        realloc(v->ptr, (v->capacity * sizeof(Vector)));
        printf("successfully allocated \n");
        return true;
    }

    return false;
}

bool safe_append(Vector *v, int e)
{
    if (v->current_size >= v->capacity)
    {
        realloc(v->ptr, ((2 * v->capacity) * sizeof(Vector)));
    }

    //   if (v->current_size < v->capacity)
    //     {
    v->ptr[v->current_size] = e;
    v->current_size++;
    return true;
    // }

    // return false;
}

bool safe_insert(Vector *v, int ind, int e)
{

    if (v->current_size >= v->capacity)
    {
        realloc(v->ptr, ((2 * v->capacity) * sizeof(Vector)));
    }

    if (v->capacity == v->current_size)
        return false;

    int i = v->current_size;

    while (i != ind)
    {
        v->ptr[i] = v->ptr[i - 1];
        i--;
    }

    v->ptr[ind] = e;
    v->current_size++;
    return true;
}
