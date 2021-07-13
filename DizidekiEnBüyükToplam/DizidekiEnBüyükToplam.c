/*
*   @author Hasan Semih Aktaş <hsemihaktas@gmail.com>
*   @since 27.03.2021 13.30
*/

#include <limits.h>
#include <stdio.h>
 

int max(int a,int b,int c){ //Hangi sayının büyük oldugunu bulan fonksiyon
    if(a>b && a>c)
        return a;
    else if(b>a && b>c)
        return b;
    else
        return c;    
}

//yazmanız gereken asil fonksyon budur. Gerekirse ekstra yardımcı fonksiyon yazabilirsiniz.
int ortaninToplami(int arr[], int sol, int orta, int sag)
{
    int toplam = 0;
        int solToplam = 0;
        for (int i = orta; i >= sol; i--) {
            toplam = toplam + arr[i];
            if (toplam > solToplam)
                solToplam = toplam;
        }
        
        toplam = 0;
        int sagToplam = 0;
        for (int i = orta + 1; i <= sag; i++) {
            toplam = toplam + arr[i];
            if (toplam > sagToplam)
                sagToplam = toplam;
        }

        return max(solToplam + sagToplam, solToplam, sagToplam);
    
}


//diziyi, ilk indisi, son indisi input olarak alır.
int enBuyukToplam(int arr[],int sag,int sol){
    

    
    //base case
    if(sag==sol)
    return arr[sag];
    
      // Find middle point
    int orta = (sag + sol) / 2;
 
    /* 3 ihtimalin maxmumunu dondurunuz
            1. maximum sol tarafta
            2. maximum sag tarafta
            3.maximum sağ ve solun ortasının toplamında */
    
    //aşağıdaki max fonksyonunu yazın
    return max(enBuyukToplam(arr, sol, orta),
               enBuyukToplam(arr, orta + 1, sag),
               ortaninToplami(arr, sag, orta, sol)); //bu fonksiyonu yukarıya yazın
    
}


int main()
{ //mainde hiçbir şey değiştirmeyiniz.
    
    //diziyi tanımla
    int arr[]={-2, -5, 6, -2, -3, 1, 5, -6};
    
    //dizinin boyunu bul
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //fonksiyonu çağır
    
    int toplam_max = enBuyukToplam(arr, 0, n - 1);
    
    //yazdır
    printf("%d",toplam_max);
    
    return 0;
    
}