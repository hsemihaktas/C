#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

int karakter_say(char* string, char* ch){
    int kelimeSayisi=0;
    int a=strlen(string);

    for(int i=0;i<a;i++)
    {
        if(islower(string[i])!=0 && (int)string[i]==(int)*ch)kelimeSayisi++;
        if(islower(string[i])!=0 && (int)string[i]==(int)*ch-32)kelimeSayisi++;
        if(islower(string[i])==0 && (int)string[i]==(int)*ch)kelimeSayisi++;
        if(islower(string[i])==0 && (int)string[i]==(int)*ch-32)kelimeSayisi++;
        
    }
 
    
    return kelimeSayisi;
}

//buraya fonksiyonu yazınız

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char* mystring="Ali Eve Gel";
    char *ch="e";
    
    printf("%d\n",karakter_say(mystring,ch));
    printf("%d\n",karakter_say("Merhaba","a"));
    printf("Adana\'daki karakter sayısı %d\n",karakter_say("Adana","a"));
    
    
       
    
    return 0;
}