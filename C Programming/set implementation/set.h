#ifndef SET_H
#define SET_H

/////////////////////////////////////////////////////////////
typedef struct Set
{
    int **items;
    int size;

} Set;

void init(Set *set);
void dest(Set *set);
int contains(Set *set, int num);
void insert(Set *set, int num);
Set *set_union(Set *s1, Set *s2);
Set *set_intersection(Set *s1, Set *s2);

#endif