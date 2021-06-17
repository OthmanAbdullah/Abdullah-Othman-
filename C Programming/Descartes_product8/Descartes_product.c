#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Descartes_product.h"
#define MY_MICRO 100
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ISIn(pair **temp, int a, int b, int cnt2)
{

    for (int i = 0; i < cnt2; i++)
    {
        if (temp[i]->x == a && temp[i]->y == b)
            return 1;
    }

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
pair **filter_duplicates(int *Ssize, pair **arr)
{

    pair **temp = malloc(sizeof(pair *));
    if (temp == NULL)
    {
        printf("error allocation failed!\n");
        exit(1);
    }
    int cnt = 0;
    for (int i = 0; i < *Ssize; i++)
    {
        if (ISIn(temp, arr[i]->x, arr[i]->y, cnt) == 0)
        {

            temp[cnt] = malloc(sizeof(pair));
            if (temp[cnt] == NULL)
            {
                printf("error allocation failed!\n");
                exit(1);
            }
            temp[cnt]->x = arr[i]->x;
            temp[cnt]->y = arr[i]->y;

            cnt++;
            temp = realloc(temp, (cnt + 1) * sizeof(pair *));
            if (temp == NULL)
            {
                printf("error allocation failed!\n");
                exit(1);
            }
        }
    }

    *Ssize = cnt;
    return temp;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

pair **Descartes_product(int arr1[], int size1, int arr2[], int size2, int *Ssize)
{
    pair **out_arr = malloc(sizeof(pair *));
    if (out_arr == NULL)
    {
        printf("The allocation failed , no enough memory!!\n");
        exit(1);
    }

    int cnt = 0;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {

            out_arr[cnt] = malloc(sizeof(pair));
            if (out_arr[cnt] == NULL)
            {
                printf("The allocation failed , no enough memory!!\n");
                exit(1);
            }
            out_arr[cnt]->x = arr1[i];
            out_arr[cnt]->y = arr2[j];
            cnt++;
            out_arr = realloc(out_arr, (cnt + 1) * sizeof(pair *));
            if (out_arr == NULL)
            {
                printf("The allocation failed , no enough memory!!\n");
                exit(1);
            }
        }
    }

    *Ssize = cnt;
    int temp = cnt;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    pair **pr = filter_duplicates(Ssize, out_arr);

    for (int i = 0; i < temp; i++)
    {
        if (out_arr[i] != NULL)
        {

            free(out_arr[i]);
        }
        else
        {
            printf("error\n");
            exit(1);
        }
    }
    out_arr = pr;

    return out_arr;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
