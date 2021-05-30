#ifndef RLE_H_INCLUDED
#define RLE_H_INCLUDED

struct Pair {
char c;
int n;
};

struct Encoded{
int length;
struct Pair **arr;
};


struct Encoded* Encode ( char*);

char* Decode (struct Encoded*);


#endif
