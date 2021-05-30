#ifndef VECTOR_H
#define VECTOR_H
typedef struct Vector
{
    int capacity;
    int current_size;
    int *ptr;
} Vector;
bool initialize(Vector *v, int capacity);
void dispose(Vector *v);
bool append(Vector *v, int e);
int retrieve(Vector *v, int i);
bool insert(Vector *v, int ind, int e);
bool erase(Vector *v, int ind);
bool set_capacity(Vector *v, int c);
bool safe_append(Vector *v, int e);
bool safe_insert(Vector *v, int ind, int e) ; 
#endif