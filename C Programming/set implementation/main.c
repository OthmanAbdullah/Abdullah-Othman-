#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"
int main(int argc, char *argv[])
{

    /// reading from a file

    Set s1, s2;

    init(&s1);
    init(&s2);

    FILE *fptr;

    int num;

    fptr = fopen(argv[1], "r");
    if (fptr != NULL)
    {
        while (fscanf(fptr, "%d", &num) != EOF)
        {
            insert(&s1, num);
        }
    }
    else
    {
        printf("Can't open the given file!\n");
    }

    fptr = fopen(argv[2], "r");
    if (fptr != NULL)
    {
        while (fscanf(fptr, "%d", &num) != EOF)
        {
            insert(&s2, num);
        }
    }
    else
    {
        printf("Can't open the given file!\n");
    }

    //--- Initializing sets ---//

    //--- Inserting elements ---//

    // insert(&s1, 1);
    // insert(&s1, 2);
    // insert(&s1, 3);
    // insert(&s1, 2);
    // insert(&s1, 3);
    // insert(&s1, 3);

    // insert(&s2, 2);
    // insert(&s2, 3);
    // insert(&s2, 4);
    // insert(&s2, 5);

    // --- Checking set elements ---//

    // if (s1.size != 3)
    //     printf("The size of s1 should be 3.\n");
    // if (s2.size != 4)
    //     printf("The size of s2 should be 4.\n");

    //--- Destructing original sets ---//

    Set *s = set_intersection(&s1, &s2);

    for (int i = 0; i < s->size; i++)
    {
        printf("%d\n", *(s->items[i]));
    }

    // if (s->size != 5 ||
    //     !contains(s, 1) ||
    //     !contains(s, 2) ||
    //     !contains(s, 3) ||
    //     !contains(s, 4) ||
    //     !contains(s, 5))
    //     printf("The intersection should be 1, 2, 3, 4, 5.\n");

    // s = set_intersection(&s1, &s2);

    // if (s->size != 2 || !contains(s, 2) || !contains(s, 3))
    //     printf("The intersection should be 2, 3.\n");

    dest(s);
    free(s);
    dest(&s1);
    dest(&s2);
    fclose(fptr);

    return 0;
}