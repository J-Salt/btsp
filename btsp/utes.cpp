//file  : utes.cpp
//author: ...
//desc. : this file contains the following utility functions:
//            copy, cost, fact, factRecursive, print, and randomize_in_place.
#include <assert.h>
#include <iostream>
#include <math.h>
#include <random>
#include <time.h>

using namespace std;

mt19937_64 g;  //our random number generator
//---------------------------------------------------------------------------
//this function copies the tour in src (of length n) into tour dst (also of
// length n. the caller must properly init and allocate the tours. this is
// useful for keeping a copy of the best so far.
void copy(double dst[][2], int n, double src[][2]) {           //definition of the copy function
  for (int i = 0; i < n; i++) {                                //for-loop to increment over the elements in the arrays
    dst[i][0] = src[i][0];                                     //copies the x into the destination
    dst[i][1] = src[i][1];                                     //copies the y into the destination
  }
}


//---------------------------------------------------------------------------
//this functions returns the cost of tour A (of length n).
// don't forget that the distance from the end back to the start must be 
// included.
double costSingle(double A[][2], int a, int b) {               //helper function to calculate the cost between two points(Euclidean Distance)
  double diff1 = A[b][0] - A[a][0], diff2 = A[b][1] - A[a][1]; //(x2-x1) and (y2-y1)
  return sqrt(diff1 * diff1 + diff2 * diff2);                  //(distance = (x2-x1)**2 + (y2-y1)**2)
}

double cost(double A[][2], int n) {                            //calculates the total cost of the tour including the distance from end to start
  
  double tcost = 0;                                            //initializes tcost to zero
  for (int i = 0; i < n-1; i++) {                              //for-loop to increment over the tour
    tcost += costSingle(A, i, i + 1);                          //cost between each of the elements in the array
  }
  tcost += costSingle(A, n-1,0);                               //cost from end back to the start
  return tcost;                                                //returns the total cost
}


//---------------------------------------------------------------------------
//non-recursive version of n factorial.  n! is returned.
long fact(long n) {                                            //incremental method of finding n!
  
  long factorial = 1;                                          //initializes factorial to 1
  for (int i = n; i > 0; i--) {                                //starts at n and decrements until it equals 1
    factorial *= i;                                            //multiplies the current facorial value by the next element (total * n-1)
  }
  return factorial;                                            //returns the factorial
}
//---------------------------------------------------------------------------
//recursive version of n factorial.  n! is returned.
long factRecursive(long n) {                                   //function definition of recursive factorial
  if (n == 1) {                                                //base case
    return n;                                                  //returns 1
  }
  return n * factRecursive(n - 1);                             //recusively calls the factRecursive function with n-1
}
//---------------------------------------------------------------------------
//pretty print (to cout or stdout) tour A of length n.
void print(double A[][2], int n) {                             //function to print the tour
  for (int i = 0; i < n; i++) {                                //iterates through the tour
    cout << "{ " << A[i][0] << ", " << A[i][1] << " }" << endl;//prints each x,y combo from the array
  }
}
//---------------------------------------------------------------------------
//randomize tour A of length n in place
void randomize_in_place(double A[][2], int n) {                //function to randomize A in place using Fisher-Yates method
  uniform_int_distribution<int> uid(0, n - 1);                 //creates a uniform distribution from 0 to n-1
  int j;                                                       //initalizes j
  double tempX, tempY;                                         //initializes two temp values for x and y
  for (int i = n-1; i > 0; i--) {                              //starts at the last element and goes to the second element
    j = uid(g);                                                //set j to a random index
    tempX = A[i][0];                                           //saves the current element in A[i][0] (x)
    tempY = A[i][1];                                           //saves the current element in A[i][1] (y)
    A[i][0] = A[j][0];                                         //replaces this value with the random one
    A[i][1] = A[j][1];                                         //replaces this value with the random one
    A[j][0] = tempX;                                           //puts the original element in the place of the moved element
    A[j][1] = tempY;                                           //puts the original element in the place of the moved element
  }
}
//---------------------------------------------------------------------------
