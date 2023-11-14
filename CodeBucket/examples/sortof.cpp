#include<iostream>
#include<iomanip>
#include <cstdlib> 
#include <time.h>
#include <math.h>
using namespace std;

void swap(int* a, int* b);
void insertionsort(int a[], int N);
void quicksort(int a[], int l, int r);

int main()
{
  int a[10];
  for(int i =0;i<10;i++)
    { 
    a[i] = rand()%100;    
    cout << a[i] <<endl;
    };
 
  //  insertionsort(a,10);
  quicksort(a,0,9);

  cout << " SORTED " << endl;

  for(int i =0;i<10;i++)
  cout << a[i] <<endl;
  return 0;
}

void insertionsort(int a[], int N)
  { 
    int i, j; 
    for (i = 1; i < N; i++)
      for (j = i; (j>0) && (a[j]< a[j-1]); j--)
        swap(&a[j],&a[j-1]);
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
