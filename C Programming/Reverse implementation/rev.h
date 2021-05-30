#ifndef REV_H
#define REV_H

char **read(FILE *fp, char **lines, int *lSize);
void write(char **lines, int size);
void reverse(FILE *fp);

#endif