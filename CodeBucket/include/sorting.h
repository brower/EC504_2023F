#include <stdlib.h>
extern int *b;


void insertionsort(int a[], int N)
  { 
    int i, j; 
    for (i = 1; i < N; i++)
      for (j = i; (j>0) && (a[j]< a[j-1]); j--)
        swap(&a[j],&a[j-1]);
  }


void bubblesort(int a[], int N)
{
  int i, j;
  for (i = 0; i < N-1; i++)
    for (j = N-1; j > i; j--)
      if (a[j] < a[j-1]) 
     swap(&a[j], &a[j-1]);
}


void selectionsort(int a[], int N)
{ 
  int i, j, min;
   
  for (i = 0; i < N-1; i++)
    { 
      min = i;
      for (j = N-1; j > i; j--) 
        if (a[j] < a[min]) 
          min = j; 
      swap(&a[i], &a[min]);
    } 
  
}


void mergesort(int a[], int l, int r)
{

    int i, j, k, m;
   
    if (r > l)
      {
        m = (r+l)/2;
        mergesort(a, l, m);  
        mergesort(a, m+1, r);
        for (i = m+1; i > l; i--){
          b[i-1] = a[i-1];
        }
        for (j = m; j < r; j++){
          b[r+m-j] = a[j+1]; 
        }
        for (k = l; k <= r; k++){
          a[k] = (b[i] < b[j]) ? b[i++] : b[j--];
           
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

void shellsort(int a[], int N)
  { 
    int i, j, h , v;
   for (h = 1; h <= N/9; h = 3*h+1) ;
    for ( ; h > 0; h /= 3)
      for (i = h; i < N; i++)
        { 
          v = a[i];  
          for( j = i; (j>=h) && (a[j-h] > v); j -= h){
             a[j] = a[j-h]; 
          }
          a[j] = v;  
        } 
  }









