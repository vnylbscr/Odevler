#include "stdio.h"
int Topla(int a,int b)
{
return a+b;
}
int Cikar(int a,int b)
{
return a-b;
	
}
int Carp(int a,int b)

{
	return a*b;
}

void DiziYazdir(int *p,int uzunluk)
{
	int i=0;
	for(;i<uzunluk;i++)
	{ 
		printf("%d ", p[i]);
	}
}
int DiziTopla(int *p,int uzunluk)
{ 
int i=0; 
int toplam=0; 
for(;i<uzunluk;i++)  

toplam += p[i]; 

return toplam;
}
int main()
{
	int x,y;
	
	printf("x:"); 
	
	scanf("%d",&x); 
	
	printf("y:"); 
	
	scanf("%d",&y); 
	
	int sonuc = x+y; 
	
	printf("Sonuc:%d\n\n",sonuc); 
	
	int *dizi = malloc(3*sizeof(int)); 
	
	dizi[0]=x; 
	
	int mert=0;
	
	dizi[1]=y; 
	
	dizi[2]=sonuc;
	
	DiziYazdir(dizi,3); 
	
	printf("\n\nToplam Deger:%d",
	
	DiziTopla(dizi,3)); 
	
	free(dizi); 
	
	return 0;

}
