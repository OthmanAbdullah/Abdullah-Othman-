
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circles.h"

bool Checking(Square s, Circle c)
{

    if ((s.y + (s.h / 2)) >= (c.y + c.r) && (s.y - (s.h / 2)) <= (c.y - c.r) && (s.x + s.h) >= (c.x + c.r) && (s.x - s.h) <= (c.x - c.r))
    {

        return true;
    }

    return false;
}

Circle **circle_in_square(Square s, Circle *arr, int *size)
{

    Circle **circles = malloc(sizeof(Circle *));
    if (circles == NULL)
    {
        printf("No enough memory!");
        exit(1);
    }

    int cnt = 0;

    for (int i = 0; i < *size; i++)
    {
        if (Checking(s, arr[i]))
        {
            circles[cnt] = malloc(sizeof(Circle));
            if (circles[cnt] == NULL)
            {
                printf("No enough memory!");
                exit(1);
            }
            circles[cnt]->c = arr[i].c;
            circles[cnt]->y = arr[i].y;
            circles[cnt]->r = arr[i].r;
            circles[cnt]->x = arr[i].x;
            cnt++;
            circles = realloc(circles, cnt * sizeof(Circle *));
            if (circles == NULL)
            {
                printf("No enoygh memory!");
                exit(1);
            }
        }
    }
    *size = cnt - 1;
    return circles;
}

Circle *smallest_blue(Circle *arr, int size)
{
    Circle *smallest;
    smallest = NULL;

    bool l = false;
    int smallRid = 0;

    for (int i = 0; i < size; i++)
    {

        if (l == false && arr[i].c == blue)
        {
            smallRid = arr[i].r;
            smallest = &arr[i];
            l = true;
        }

        if (l == true && (3.14 * arr[i].r * arr[i].r) < (3.14 * smallest->r * smallest->r))
        {
            smallest = &arr[i];
            smallRid = arr[i].r;
        }
    }
    return smallest;
}
