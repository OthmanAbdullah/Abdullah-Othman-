#ifndef MAP_H
#define MAP_H
#define WORD_BUFFER_SIZE 32
/////////////////////////////////////////////////////////////
typedef struct Pair
{
    char str[WORD_BUFFER_SIZE];
    int num;
} Pair;

/////////////////////////////////////////////////////////////

typedef struct Map
{
    Pair **items;
    int size;
} Map;

void init(Map *arr);
void dest(Map *arr);
Pair *find(Map *arr, char *str);
void set(Map *arr, char *str, int num);
int get(Map *arr, char *str);
void print(Map *arr);

#endif