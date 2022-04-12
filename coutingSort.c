#include<stdio.h>  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //dizide bulunan maksimum elemanı buluyoruz...
}  
  
void countSort(int a[], int n) // sayma sıralamsını gerçekleştirme işlevi
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //[max+1] boyutunda sayı dizisi oluşturuyoruz  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Bütün sıfırlarla sayı dizisini başlatma
  }  
    
  for (int i = 0; i < n; i++) // eleman sayısını saklama
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; // verilerin  görülme sıklığı
  
  /*Burada ki döngü, sayı dizisindeki orijinal dizinin her bir öğesinin dizinini bulur ve
    elemanları çıktı dizisine yerleştirelim*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // aynı sayıları azaltma işlemi
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //sıralanmış öğeleri ana dizide saklıyoruz
   }  
}  
  
void printDizi(int a[], int n) //diziyi yazdırma
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main() {  
    int a[] = { 15, 32, 23, 4, 53, 12, 500 };  
    int n = sizeof(a)/sizeof(a[0]);  
    printf("Dizi elemanlarini siralamadan once: \n");  
    printDizi(a, n);  
    countSort(a, n);  
    printf("\nSiralamadan sonra dizi elemanlari: \n");    
    printDizi(a, n);  
    return 0;  
  
}  
