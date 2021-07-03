#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circles.h"

int main()
{

    Circle c;
    c.x = 1;
    c.y = 2;
    c.r = 3;
    c.c = red;

    Circle c1;
    c1.x = 2;
    c1.y = 0;
    c1.r = 4;
    c1.c = blue;

    Circle c2;
    c2.x = 2;
    c2.y = 0;
    c2.r = 1;
    c2.c = blue;

    Square s;
    s.x = 2;
    s.y = 0;
    s.h = 10;

    Square s2;
    s2.x = 2;
    s2.y = 0;
    s2.h = 2;

    Circle cis[3] = {c, c1, c2};
    int size = 3;

    Circle **temp = circle_in_square(s2, cis, &size);

    printf(" Size %d ", size);

    for (int i = 0; i < size; i++)
    {
        printf("%d \n", temp[i]->r);
    }

    Circle *cir = smallest_blue(cis, 3);

    for (int i = 0; i < size; i++)
    {

        free(temp[i]);
    }
    free(temp);

    return 0;
}