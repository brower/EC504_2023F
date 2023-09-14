#include <iostream>
#include <math.h>
using namespace std;

int  gcd(int p , int q );

  int main(int argc, char **argv) {
  int N, seed;
  cout << "Size of p and q is  ";
  cin >> N;
   cout << "The random seed is  ? ";
  cin >>seed;
    
   srand(seed); // fixes intial seed

   for(int trials = 0; trials < 32; trials++)
     {
       N = 2*N;
   int  p = rand()%N + 1;
   int  q = rand()%N + 1;

   cout << "The GCD of  p  = " << p << " q = " << q <<"   is "  << gcd(p,q) << endl;   
 
     }
   
 return 0;
}   


int  gcd(int p , int q)
{
  int r;
  int temp; 
  if (p < q) {temp = p; p = q; q = temp;} 
  while(q!=0)
    {
      r = p % q;
      p = q; q = r;
    }
  return p;
}


