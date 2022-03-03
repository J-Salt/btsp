#pragma once
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
void copy(double dst[][2], int n, double src[][2]) {
  for (int i = 0; i < n; i++) {
    dst[i][0] = src[i][0];
    dst[i][1] = src[i][1];
  }
}
//---------------------------------------------------------------------------
//this functions returns the cost of tour A (of length n).
// don't forget that the distance from the end back to the start must be 
// included.
double costSingle(double A[][2], int a, int b) {
  double diff1 = A[b][0] - A[a][0], diff2 = A[b][1] - A[a][1];
  return sqrt(diff1 * diff1 + diff2 * diff2);
}

double cost(double A[][2], int n) {

  double tcost = 0;
  for (int i = 0; i < n - 1; i++) {
    tcost += costSingle(A, i, i + 1);
  }
  tcost += costSingle(A, n - 1, 0);
  return tcost;
}


//---------------------------------------------------------------------------
//non-recursive version of n factorial.  n! is returned.
long fact(long n) {

  long factorial = 1;
  for (int i = n; i > 0; i--) {
    factorial *= i;
  }
  return factorial;
}
//---------------------------------------------------------------------------
//recursive version of n factorial.  n! is returned.
long factRecursive(long n) {
  if (n == 1) {
    return n;
  }
  return n * factRecursive(n - 1);
}
//---------------------------------------------------------------------------
//pretty print (to cout or stdout) tour A of length n.
void print(double A[][2], int n) {
  for (int i = 0; i < n; i++) {
    cout << "{ " << A[i][0] << ", " << A[i][1] << " }" << endl;
  }
}
//---------------------------------------------------------------------------
//randomize tour A of length n in place
void randomize_in_place(double A[][2], int n) {
  uniform_int_distribution<int> uid(0, n - 1);
  int randomPos[] = { 0,1,2,3,4 };
  int j;
  double tempX, tempY;
  for (int i = n - 1; i > 0; i--) {
    j = uid(g);
    tempX = A[i][0];
    tempY = A[i][1];
    A[i][0] = A[j][0];
    A[i][1] = A[j][1];
    A[j][0] = tempX;
    A[j][1] = tempY;
  }
}
//---------------------------------------------------------------------------
