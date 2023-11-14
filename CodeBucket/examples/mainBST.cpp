#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
using namespace std;


/***********************************************************
Main progam template test BST Search 
************************************************************/

static int OpCount = 0;

int localSize = 10;

int main(int argc, char *argv[]) 
{

   /* Timeing and IO setup */
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_seconds_heap_sort;  // Holds the final run time
  ifstream infile;
  ofstream outfile;
  
  /* Local data */
  int n;
 int i;
 
  
  // Input Data:  DO NOT CHANGE 
  infile.open(argv[1]);

  int* InputList = NULL;
  
  if(!infile)
    {
      cout << "No input files so put in InputList file of size = "<<  localSize  << endl;
      n = localSize;
      cout << "n  = " << n << endl;
      InputList = new int[n+1];
      InputList[0] = n;  // Set zero entry in in heap to n
      for(int i=1; i<n+1 ; i++)  InputList[i] = rand()%100000;
      // Define out put file
       outfile.open("SortedRandomList.dat");
    }
  else
    {
      infile >> n;
      InputList = new int[n+1];
      InputList[0] = n;  // Set zero entry in in heap to n	    
      for(int i=1; i<n+1 ; i++) infile >> InputList[i];
      infile.close();
      // Define out put file 
      outfile.open(strcat(argv[1],"_out"));
    }


   for( i = 1; i < InputList[0]; i++ )
     cout << "i  = "<< i << " Elements " << InputList[i] << endl;
     
  /* Test Search Tree */  
   
   SearchTree T;
   Position P;
   
   T = MakeEmpty( NULL );
   for( i = 1; i < n + 1; i++ )
     T = Insert( InputList[i], T );
   
   cout << "Find  " <<  InputList[13%n+1] << endl;
   P = Find( InputList[13%n+1], T );
   if(P != NULL)  cout << " Found    " <<  Retrieve( P )  << endl;
   
   T = Delete(  InputList[13%n + 1], T );
   
   P = Find( InputList[13%n +1 ], T );
   
   if(P == NULL)  cout << "After Delete " << InputList[13%n + 1] << " not found "  << endl;
   
   cout <<"Min is  " << Retrieve( FindMin( T ) ) << "    Max is  " << Retrieve( FindMax( T ) ) << endl;
				  
    

    return 0;
}

