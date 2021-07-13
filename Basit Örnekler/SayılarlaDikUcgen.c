/*
**	@author Hasan Semih Aktaş
**	Sayılarla ucgen yazdırma
*/
#include <stdio.h>

int main(void) {
 int girilenSayi, yukseklik, ondekiBoslukSayisi;
 printf("n sayısını giriniz:\n");
 scanf("%d",&girilenSayi);
 yukseklik=girilenSayi;
 ondekiBoslukSayisi=girilenSayi;

 for(int sayac=1;sayac<=yukseklik;sayac++)
 {
   ondekiBoslukSayisi=ondekiBoslukSayisi-1;
   for(int sayac2=1;sayac2<=ondekiBoslukSayisi;sayac2++)
   {
    printf(" ");
   }
   for(int sayac2=1;sayac2<=sayac;sayac2++)
   {
      printf("%d",sayac2);
      
   }
   for(int sayac2=sayac-1;sayac2>0;sayac2--)
   {
     printf("%d",sayac2);
   }
   printf("\n");
 }
}