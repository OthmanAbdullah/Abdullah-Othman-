#ifndef CIRCLES_H
#define CIRCLES_H
enum Colors
{
    red,
    blue,
    green
};

typedef enum Colors Colors;

typedef struct Circle
{
    int x, y, r;
    Colors c;

} Circle;

typedef struct Square
{
    int x, y, h;
    Colors c;
} Square;

bool Checking(Square s, Circle c);
Circle **circle_in_square(Square s, Circle *arr, int *size);
Circle *smallest_blue(Circle *arr, int size);

#endif