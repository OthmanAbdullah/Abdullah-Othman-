#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "rle.h"

int main() {

char input_text[500];
printf("\nEnter The input_text : ");
scanf("%s",input_text);
int size =  strlen(input_text) ;

int i = 0 ; 
    while (i < size)
    {
        if (*(input_text + i) < 79 || *(input_text + i) > 122)
          {
     printf("Bad input!");
     return (0);
        }
    i++;
    }



struct Encoded* EncodedTxt=NULL;
EncodedTxt=Encode(input_text);

for (int i = 0 ; i < EncodedTxt->length ; i++)
    {
        printf("%c%d", EncodedTxt->arr[i]->c , EncodedTxt->arr[i]->n );
    }



char* DecodedTxt;
DecodedTxt= Decode(EncodedTxt);
printf("-> %s",DecodedTxt);




for (int j = 0 ; j < EncodedTxt->length ; j++)
 {
   free(EncodedTxt->arr[j]);
 }

 free(EncodedTxt);
 free(DecodedTxt);

   return(0);
}


