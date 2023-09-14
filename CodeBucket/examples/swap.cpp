#include <iostream>
using namespace std;

void swap(int * ptnum1, int * ptnum2)
{
  int temp;
  temp = *ptnum1;
  *ptnum1 = *ptnum2;
  *ptnum2 = temp;
}

int main()
{ 
   
  int num1 = 4;
  int num2 = 6;
  int *pt1 =  &num1;
  int *pt2 = &num2;
  

  cout <<  *pt1 << "  " << *pt2 << endl;

   swap(pt1, pt2);

   cout <<  *pt1 << "  " << *pt2 << endl;

 return 0;
}   
