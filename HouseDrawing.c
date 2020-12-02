#include <stdio.h>
#include <conio.h>
// min 12
//oranlar 35 lik genişliğe göre alunmıştır.
int len  ,lenkontrol,mod= 0;
int main() 
{   
    printf("Genislik Giriniz: ");
    scanf("%d",&len);
    while (len < 12)
    {
        printf("Genislik Sayi Olup 11 den Buyuk olmali");
        printf("\nTekrar Giriniz:");
        scanf("%d",&len);
    }
    if (len % 2 == 0)
    {
        mod=2;
    }
    else
    {
        mod=1;
    }
    
    cati();
    if(len/ 4 % 2 == 0) // çatı genişliği çift ise +1 vererek çatıya göre oranlama
    {
        lenkontrol= len-(((len/ 4 )+1)*2)-((len/7)*2)-((mod-1)*2); //iki pencere arasi mesafe hesaplama           
    }
    else// çatı genişliği tek ise çatıya göre oranlama
    {
        lenkontrol= len-((len/ 4)*2)-((len/7)*2)-((mod-1)*2);
    }
    govde();
    getch();
    return 0;
}
void govde ()
{
    for (int i = 0; i<(len/2-((len/8)+1))/4;i++)//pencere üst gövde
    {
        for (int j = 0 ; j<len;j++)
        {
            printf("0");
        }       
        printf("\n");
    }
    for (int i = 0;i<(len/8)+1;i++)// pencere
    {
        for (int j =0;j<len/7;j++) //sol kısım
        {
            printf("0");
        }
        pencere(i);
        
        for (int j =0;j<lenkontrol;j++) //orta kısım
            {
                printf("0");
            }
        
        pencere(i);
        for (int j =0;j<len/7;j++) //sağ kısım
        {
            printf("0");
        }
        printf("\n");

    }
    
    for (int i = 0; i<((len/2-((len/8)+1))/4)+1;i++)//pencere alt gövde
    {
        for (int j = 0 ; j<len;j++)
        {
            printf("0");
        }       
        printf("\n");
    }
    
    for (int i = 0;i<(len/8)+1;i++)//kapı
    {
        for (int j = 0;j<((len /2)-(len/8))-(mod-1);j++)//sol kısım
        {
            printf("0");
        }
        for (int j = 0;j < len/8;j++)//kapı sol bosluk
        {
            printf(" ");
        }
        for(int j = 0; j<mod;j++)
        {
            printf("*");//orta kısım
        }
        for (int j = 0;j < len/8;j++)//kapı sağ bosluk
        {
            printf(" ");
        }
        for (int j = 0;j<((len /2)-(len/8))-(mod-1);j++)//sağ karakter
        {
            printf("0");
        }
        printf("\n");
    }
}




void pencere(int i)
{         
    if(i == len/16)// pencerenin ortası ise
    {
        if(len/ 4 % 2 == 0)//çatı genişliği int olarak +sız çift ise +1 vererek çatıya oranlama
        {
            for(int j =0 ;j<(len/4)+1;j++)
            {
                printf("*");
            }
        }
        else//çatı genişliği int olarak +sız tek ise + vermeden çatıya oranlama
        {           
            for(int j =0 ;j<(len/4)+(mod-1);j++)
            {
                printf("*");
            }
        }              
    }
    else
    {
        for (int j = 0; j<len/8;j++)//pencere sol bosluk
        {
            printf(" ");
        }
        for(int j = 0; j<mod;j++)
        {
            printf("*");//orta kısım
        }       
        for (int j = 0; j<len/8;j++)//pencere sağ bosluk
        {
            printf(" ");
        }
    }                          
}




void cati()//çatı
{    
        for (int i = 0; i < (len/4)+1-(mod-1);i++)
        {
            for(int j=0;j < ((len /2)-(i*2))-(mod-1);j++)//ilk boşluklar
            {
                printf(" ");
            }
            for(int j = 0;j< i*2;j++)//sol karakter
            {
                printf("/");
            }
            for(int j = 0; j<mod;j++)
            {
                printf("+");//orta kısım
            }            
            for(int j = 0;j< i*2;j++)//sağ karakter
            {
                printf("\\");
            }
            printf("\n");
        }    
}