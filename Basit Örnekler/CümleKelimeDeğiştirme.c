#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* ters_cevir(char *string, char *aranankelime, char *yenikelime){
    int i = 0 ,j = 0;
    
    char* adres = strstr(string, aranankelime);
    char* temp = malloc(20);
    
    for (i = 0; string + i < adres ; i++){
        *(temp + i) = *(string + i);
    }
    for (int j = 0; j < strlen(yenikelime) ; j++, i++){
        *(temp + i) = *(yenikelime + j);
    }
    *(temp + i) = ' ';
    i++;
    for (int k = 1; *(adres + strlen(aranankelime) + k) != '\0' ; k++, i++ ){
        *(temp + i) = *(adres + (strlen(aranankelime)+ k)); 
    }
    int l = strlen(temp);
    for (int a = 0 ; a < 20 - l ; a++, i++){
        *(temp + i) = ' ';
    }
    return temp;
   
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    char *ptr="Ali eve gel.";
    char *aranan="eve";
    char  *yeni="okula";
    
    printf("%20s",ters_cevir(ptr, aranan, yeni));
    return 0;
}