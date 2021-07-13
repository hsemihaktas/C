#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int ters_ile_ayni_mi(char* string, int ilk , int son)
{
    if (string[ilk] != string[son]) 
    return 0; 

    if (ilk < son + 1) 
    return ters_ile_ayni_mi(string, ilk + 1, son - 1); 

    return 1; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    char arr[20];
    scanf("%20s",arr);  
    printf("%d",ters_ile_ayni_mi(arr,0,strlen(arr)-1));


    return 0;
}