/*
**	@author Hasan Semih Aktaş
**	100 ile 999 arasındaki tum rakamları çift olan sayıların kaç tane oldugunu bulma
*/

#include <stdio.h>
int main(void) {

  int yuzlerbasamagi, onlarbasamagi, birlerbasamagi, toplamciftsayisi=0;
    for(int sayac=101;sayac<=999;sayac++)
    { 
      yuzlerbasamagi=sayac/100;
      onlarbasamagi=(sayac-yuzlerbasamagi*100)/10;
      birlerbasamagi=(sayac-yuzlerbasamagi*100-onlarbasamagi*10);

      if(yuzlerbasamagi%2==0 && onlarbasamagi%2==0 && birlerbasamagi%2==0)
      {
        
        printf("%d\n",sayac);
        toplamciftsayisi++;
        
      }
    }
    printf("Tüm basamakları çift %d sayi vardır",toplamciftsayisi);
}