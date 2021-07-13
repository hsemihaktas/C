#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int kelime_say(char* paragraf, char* kelime){
    int kelimeSayisi = 0;
    bool t = true;
    int l1 = strlen(paragraf);
    int l2 = strlen(kelime);
    int i = 0, j = 0;
    while (i < l1){
        if (paragraf[i] == kelime[0]){
            while(j <= l2 ){
                if (j == l2  && *(paragraf + i + j) != ' '){
                    t = false;
                }
                if (j != l2 && *(paragraf + i + j) != *(kelime + j)){
                    t = false;
                }
                j++;
            }
            if (t) {
                kelimeSayisi++;
            }
            t = true;
            j = 0;
        }
        i++;
    }
    return kelimeSayisi;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */


    printf("%d \n",kelime_say("Bir berber bir berbere gel beraber bir berber dükkanı açalım demiş", "berber"));

    printf("%d \n",kelime_say("Bir berber bir berbere gel beraber bir berber dükkanı açalım demiş", "berbere"));
    printf("%d \n",kelime_say("Bir berber bir berbere gel beraber bir berber dükkanı açalım demiş", "kim demiş"));

    return 0;
}