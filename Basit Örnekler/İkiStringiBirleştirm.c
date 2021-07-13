#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char *string_birlestir(char *str1, char *str2)
{
    int i=0;
    char* kelime=(char*) malloc(20);
    for(i=0;i<strlen(str1);i++)
    {
        *(kelime+i)=*(str1+i);
    }
    *(kelime+i)=' ';
    i++;
    for(int j=0;j<strlen(str2);j++,i++)
    {
        *(kelime+i)=*(str2+j);
    }
    int sayac=i;
    for(int d=0;d<20-sayac;d++,i++)
    {
        *(kelime+i)=' ';
    }

    return kelime;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    char *ptr="ilk ve";
    char *ptr2="son";
    printf("%20s",string_birlestir(ptr,ptr2));
    
    return 0;
}