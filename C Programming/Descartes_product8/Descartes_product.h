#ifndef DESCARTES_PRODUCT
#define DESCARTES_PRODUCT

typedef struct pair
{

    int x;
    int y;

} pair;
int contained(pair **temp, pair pairs, int cnt);
pair **filter_duplicates(int *Ssize, pair **arr);

pair **Descartes_product(int arr1[], int size1, int arr2[], int size2, int *Ssize);

#endif