#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* ters_cevir(char *string){
    int baslangic,son;

    char* temp =(char*) malloc(strlen(string));
    son = strlen(string)-1;

    for(baslangic = 0 ; baslangic < strlen(string); baslangic++) {
        *(temp+baslangic)=*(string+son);
         son--;
    }

    temp[baslangic]='\0';
    return temp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    char* arr="merhaba";
    ters_cevir(arr);
    printf("%s",ters_cevir(arr));

    
    return 0;
}