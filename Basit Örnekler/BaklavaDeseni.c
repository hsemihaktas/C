/*
**	@author Hasan Semih Aktaş
**	+ ve * dan baklava deseni yapma
*/

#include <stdio.h>

int main(void) {
  int girilenSayi, artiSayisi=1, yildizSayisi;

  printf("N sayısını giriniz \n");
  scanf("%d",&girilenSayi);
  

  for(int sayac=1; sayac<=girilenSayi/2;sayac++ )
  {
    yildizSayisi = girilenSayi - artiSayisi;
    for(int sayac2=1; sayac2<=yildizSayisi/2;sayac2++)
    {
      printf("*");
    } 
    for(int sayac2=1;sayac2<=artiSayisi;sayac2++)
    {
      printf("+");
    }
    for(int sayac2=1; sayac2<=yildizSayisi/2;sayac2++)
    {
      printf("*");
    } 
    artiSayisi+=2;
    printf("\n");
  }
  for(int sayac=1;sayac<=girilenSayi;sayac++)
  {
    printf("+");
  }
  printf("\n");

  for(int sayac=1; sayac<=girilenSayi/2;sayac++ )
  {
    artiSayisi-=2;
    yildizSayisi = girilenSayi - artiSayisi;
    for(int sayac2=1; sayac2<=yildizSayisi/2;sayac2++)
    {
      printf("*");
    } 
    for(int sayac2=1;sayac2<=artiSayisi;sayac2++)
    {
      printf("+");
    }
    for(int sayac2=1; sayac2<=yildizSayisi/2;sayac2++)
    {
      printf("*");
    } 
    printf("\n");
  }
}


