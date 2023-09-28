#include<iostream>
#include<fstream>
#include <cstdlib> 
using namespace std;

#define ListSize  1000000
#define INT  int 

void swap(INT* a, INT* b);
void insertionsort(INT a[], INT N);
void mergeSort(INT a[], INT a_tmp[],INT l,INT r);

int main(){
   INT a[ListSize];
   INT a_tmp[ListSize];
   INT  i;
    char FileName[80];
    sprintf(FileName,"Sorted%d.txt",ListSize);
    ofstream outfile(FileName);
   
    for(i = 0;i<ListSize;i++)
        a[i] = (rand() +1)%1000000000  ;    
     
     mergeSort(a,  a_tmp, 0, ListSize-1);
    // insertionsort(a, ListSize);

    cout << ListSize << "\n";
    for(i = 0;i<ListSize;i++)
        cout << a[i] << "\n";

 
    outfile << ListSize << endl;
    for(i = 0;i<ListSize;i++)
        outfile << a[i] << endl;

    outfile.close();
  return 0;
}

void insertionsort(INT a[],  INT N)
  {
    INT swap_count = -1;
    INT i, j; 
    for (i = 1; i < N; i++)
      for (j = i; (j>0) && (a[j]< a[j-1]); j--)
        swap(&a[j],&a[j-1]);
  }

void mergeSort(INT a[], INT  a_tmp[], INT l, INT r)
{
   INT i, j, k, m;
    
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


void swap(INT* a, INT* b)
{ 
    INT temp;
    temp = *a; 
    *a = *b; 
    *b = temp;
}
