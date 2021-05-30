#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "rl.h"

int main(int argc, char *argv[])
{

    Vector v;
    int capacity = atoi(argv[1]);

    initialize(&v, capacity);

    char temp;
    int temp2;

    for (int i = 1; i < argc; i += 2)
    {
        temp = argv[i][0];
        temp2 = atoi(argv[i + 1]);
        switch (temp)
        {
        case 'a':
            append(&v, temp2);
            break;
        case 'r':
            printf("%d\n", retrieve(&v, atoi(argv[i + 1])));
            break;
        case 'i':
            insert(&v, atoi(argv[i + 1]), atoi(argv[i + 2]));
            i++;
            break;

        case 'e':
            assert(erase(&v, atoi(argv[i + 1])));
            break;
        case 's':
            assert(set_capacity(&v, atoi(argv[i + 1])));

            break;

        case 'S':
            assert(safe_append(&v, atoi(argv[i + 1])));

            break;

        default:
            dispose(&v);
            break;
        }
    }

    return 0;
}
