
//	@author Hasan Semih Aktaş
//	Bir dosyayı başka bir dosyanın üstüne yazdırma ve sonra kopyalanan dosyayı silme.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    FILE *hedef, *kaynak;
    hedef=fopen("dosya1.txt","a");//Dosyanın üstüne yazdırmak için "a" kullanıyoruz.
    kaynak=fopen("dosya2.txt","r");
    fputc('\n',hedef);//İlk cümle direk yanına değilde alt satırdan başlatmak için kullandım.
    while((ch=fgetc(kaynak))!=EOF)
    {
        fputc(ch,hedef);
    }
    fclose(hedef);
    fclose(kaynak);
   if (remove("dosya2.txt") == 0) 
      printf("Dosya Başarılı Bir Şekilde Silindi."); 
   else
      printf("Dosya Silinemedi.");

    return 0;
}
