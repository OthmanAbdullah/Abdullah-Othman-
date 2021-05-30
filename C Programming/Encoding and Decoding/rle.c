#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "rle.h"


struct Encoded* Encode( char *original_text){
struct Encoded* EncodedTxt;
EncodedTxt = (struct Encoded* ) malloc (sizeof(struct Encoded));
EncodedTxt->length = 1;
int size = strlen(original_text);
 for (int i =1 ; i < size ;i++)
 {
     if (original_text[i] != original_text[i-1])
         {
             EncodedTxt->length++;
         }
 }
EncodedTxt->arr = (struct Pair** ) malloc ((EncodedTxt->length)*sizeof(struct Pair*));
 for (int j = 0 ; j < EncodedTxt->length  ; j++)
 {
     EncodedTxt->arr[j] = (struct Pair* ) malloc (sizeof(struct Pair));
 }
 int ind=0;
EncodedTxt->arr[ind]->c = original_text[0];
EncodedTxt->arr[ind]->n = 1;
for (int i =1 ; i < size ;i++)
 {
     if (original_text[i] == original_text[i-1])
         {
             EncodedTxt->arr[ind]->n++;

         }
    else
         {
            ind++;
           EncodedTxt->arr[ind]->c = original_text[i];
            EncodedTxt->arr[ind]->n = 1;
         }
 }
return EncodedTxt;
}






char* Decode (struct Encoded* EncodedTxt){

char* original_text ;
int size_string;
for (int i = 0 ; i < EncodedTxt->length ;i++)
{
size_string += EncodedTxt->arr[i]->n;
}
original_text  = (char*) malloc (size_string*sizeof(char));
int charNum=0;
for(int j = 0 ; j < EncodedTxt->length;j++)
{
    for(int f = 0 ; f < EncodedTxt->arr[j]->n;f++)
    {
        original_text [charNum] = EncodedTxt->arr[j]->c;
        charNum++;
    }
}
return original_text ;
}




