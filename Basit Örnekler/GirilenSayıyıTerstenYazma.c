/*
**	@author Hasan Semih Aktaş
**	Girilen Sayıyı tersten yazdırma
*/

#include <stdio.h>
int main(void) {

  int girilenSayi;
  int ciktiRakam;
  printf("Bir sayı giriniz:\n");
  scanf("%d",&girilenSayi);
  printf("Sayının tersten yazılışı:");
  while( girilenSayi>10 ) {
  ciktiRakam = girilenSayi % 10;
  printf("%d",ciktiRakam);
  girilenSayi /= 10;
  }
  printf("%d\n",girilenSayi);
}