#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Descartes_product.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    // int arr1[15] = {1,1,1,1 , 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //  int arr2[12] = {11, 2, 2, 31, 41, 51, 61, 71, 81, 91, 10, 10};

    // int arr1[4] = {1, 1, 2, 2};
    // int arr2[4] = {3, 3, 4, 4};

    int arr1[4] = {1, 2, 3, 4};
    int arr2[4] = {5, 6, 7, 8};

    int size = 0;
    pair **arr3 = Descartes_product(arr1, 4, arr2, 4, &size);

    // printf("the size : %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d- (%d , %d)\n", i + 1, arr3[i]->x, arr3[i]->y);
    }

    for (int i = 0; i < size; i++)
    {
        if (arr3[i] != NULL)
        {
            // printf("freed\n");
            free(arr3[i]);
        }
        else
        {
            printf("Error in the deallocation operation!! \n");
            return 1;
        }
    }

    free(arr3);

    return 0;
}