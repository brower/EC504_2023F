#include<iostream>
#include <fstream>
#include<iomanip>
#include <cstdlib> 
#include <time.h>
#include <math.h>
#include <cstring>
using namespace std;


void swap(int* a, int* b);
void insertionsort(int a[], int N);
void mergeSort(int a[], int a_tmp[], int l, int r);
void quicksort(int a[], int l, int r);

int main()
{
  int Asize = 1000000;
  string SizeName = "1M";
  
  int a[Asize];
  int a_tmp[Asize];
  int i;
   ofstream outfile; 

for(i = 0;i<Asize;i++)
  a[i] = (rand() +1)%10000000  ;

 outfile.open("Random"+ SizeName +".txt");
 outfile << Asize << endl;
  for(int i= 0; i< Asize  ; i++)
    outfile << a[i] << endl;
  outfile.close();

  //mergeSort(a,  a_tmp, 0, Asize-1);
  quicksort( a, 0, Asize-1);

 outfile.open("Sorted"+SizeName +".txt");
outfile << Asize << endl;
  for(int i=0; i< Asize  ; i++)
    outfile << a[i] << endl;
  outfile.close();
   
  return 0;
}

void insertionsort(int a[],  int N)
  { 
    int i, j; 
    for (i = 1; i < N; i++)
      for (j = i; (j>0) && (a[j]< a[j-1]); j--)
        swap(&a[j],&a[j-1]);
  }

void mergeSort(int a[], int a_tmp[], int l, int r)
{

    int i, j, k, m;
   
    if (r > l)
      {
        m = (r+l)/2;
        mergeSort(a, a_tmp, l, m);  
        mergeSort(a,a_tmp, m+1, r);
        for (i = m+1; i > l; i--){
          a_tmp[i-1] = a[i-1];
        }
        for (j = m; j < r; j++){
          a_tmp[r+m-j] = a[j+1]; 
        }
        for (k = l; k <= r; k++){
          a[k] = (a_tmp[i] < a_tmp[j]) ? a_tmp[i++] : a_tmp[j--];       
        }
      }
  }

void quicksort(int a[], int l, int r)
  { 
    int i, j, v;

    if (r > l)
      { 
        v = a[r]; i = l-1; j = r;
        for (;;)
          { 
            while (a[++i] < v) ;
            while (a[--j] > v) ;
            if (i >= j) break;
            swap(&a[i], &a[j]);
          }
        swap(&a[i], &a[r]);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
      } 
  }

void swap(int* a, int* b)
{ 
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}
