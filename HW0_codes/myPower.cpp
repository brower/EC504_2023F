#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include <math.h>
using namespace std;

/***********************************************************
Main progam template for practice exercise HomeworkZero

see https://www.programiz.com/c-programming/library-function/math.h/pow

Comment to get a nice scaling you should average over many power in a
give range using 

 srand(137); // fixes intial seed 
  int randint = rand() + 1;  //  Can vary to get average performance.
  N = randint%(pow(10,digits)
 
************************************************************/

double slowPower(double x,  unsigned int N);
double fastPower(double x,  unsigned int N);
double cPower(double x,  unsigned int N);
double veryfastPower(double x,  unsigned int N);


int main() 
{
  //default values
  unsigned int N; //[0 to 4294967295]. Log[10, 4294967295] = 9.63296
  double x =  1.0000001234;   // Max 1.79769e+308] have to addjust to avoid overflow
  N = 1;
  FILE * outfile;
  outfile = fopen("CompareTiming.txt", "w");
  
  fprintf(outfile,"# log10(N)                     cPower                            slowPower                       fastPower                   veryfast Power \n");
  
  
  for(int digits = 1; digits < 10 ;digits++)
    {
      N = 10*N;
      
      /* Timeing and IO setup */
      chrono::time_point<chrono::steady_clock> start, stop; 
      chrono::duration<double> difference_in_time;
      double difference_in_sec_slow; // Holds the final run time
      double difference_in_sec_fast; // Holds the final run time
      double difference_in_sec_c; // Holds the final run time
      double difference_in_sec_veryfast; // final run time  
      
      
      start = chrono::steady_clock::now();
      double power_c = cPower(x,N);
      stop = chrono::steady_clock::now();
      difference_in_time = stop - start;
      difference_in_sec_c= double(difference_in_time.count());
      
      start = chrono::steady_clock::now();
      double power_slow = slowPower(x,N);
      stop = chrono::steady_clock::now();
      difference_in_time = stop - start;
      difference_in_sec_slow= double(difference_in_time.count());
      
      start = chrono::steady_clock::now();
      double power_fast = fastPower(x,N);
      stop = chrono::steady_clock::now();
      difference_in_time = stop - start;
      difference_in_sec_fast= double(difference_in_time.count());
      
      start = chrono::steady_clock::now();
      double power_veryfast = veryfastPower(x,N);
      stop = chrono::steady_clock::now();
      difference_in_time = stop - start;
      difference_in_sec_veryfast= double(difference_in_time.count());
      
      cout << endl << " For N = " << N <<endl;
      cout << "powerC =    " << power_c   << "  Time = " <<  difference_in_sec_c << endl;
      cout << "powerSlow = " << power_slow <<"  Time = " <<  difference_in_sec_slow << endl;
      cout << "powerFast = " << power_fast <<"  Time = " <<  difference_in_sec_fast << endl;
      cout << "powerveryFast = " << power_veryfast <<"  Time = " <<  difference_in_sec_veryfast << endl;
      
      
      fprintf(outfile," %20d   %25.20e   %25.20e    %25.20e   %25.20e \n",digits, difference_in_sec_c,   difference_in_sec_slow,  difference_in_sec_fast, difference_in_sec_veryfast );
      
      // outfile <<  difference_in_sec_c <<"  "<<  difference_in_sec_slow <<"  "<< difference_in_sec_fast <<"  "<< difference_in_sec_veryfast << endl;
    }
  
  fprintf(outfile,"\n");
  fclose(outfile);
  
  return 0;
}

/****************************************
Funtions provided below
****************************************/

double cPower(double x,  unsigned int N)
{
  return pow(x, (double)N);
}

double slowPower(double x,  unsigned int N)
{
  double pow = 1.0;
  int i;
  for( i = 0;  i < N; i++)
    {
      pow = x*pow;
    }
  // if(i < N)   cout <<"Slow Failed with iteration stop at i = " << i << endl;
  return pow ;
}
//This function needs to be fixed!
double  fastPower(double x,  unsigned int N)
{
  double pow = 1.0;
  while(N > 0)
    { 
      if(N%2) pow *= x ; // Update pow 
      N = N -1 ; // THIS IS A WRONG ADD LINE FIX IT
      
       //and you must update x as below  in veryFastPower
      
    }
  return pow;
}

double veryfastPower(double x,  unsigned int N)
{
  double pow = 1.0;
  for (;;)
    {
      if (N & 1)  //Copies a bit to the result if it exists in both operands.
	pow *= x;
      N >>= 1;  //Binary Right Shift Operator. 
      if (!N)  // Check for zero
	break;
      x = x*x;
    }
  
  return pow;
}


