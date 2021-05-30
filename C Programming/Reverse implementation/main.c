#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"rev.h"
int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 1)
    {
        fp = stdin;
        reverse(fp);
    }

    for (int i = 1; i < argc; i++)
    {

        fp = fopen(argv[i], "r");
        reverse(fp);
    }

    ///////////////////////////////////////////////////////

    return 0;
}
