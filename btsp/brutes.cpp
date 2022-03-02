//file  : brutes.cpp
//author: ...
//desc. : this file contains the functions bruteForceRandom, and bruteForce5Loops.
#include <assert.h>
#include <iostream>

using namespace std;

extern void copy(double A[][2], int n, double B[][2]);
extern double cost(double A[][2], int n);
extern void print(double A[][2], int n);
extern void randomize_in_place(double A[][2], int n);
//---------------------------------------------------------------------------
//this function (hopefully - no guarantees) finds the optimal solution by
// repeatedly calling randomize_in_place while keeping track of the best
// solution.
//
// repeats is the number of repeats.
// A is the initial tour and n is its length.
// this function returns the best solution in A.
// note: to dynamically allocate 2D arrays, user the following:
// double  (*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
void bruteForceRandom(double A[][2], int n, long repeats) {
  double (*tmp)[2] = new double[n][2];
  double bestCost = INT_MAX;
  double currCost;
  for (int i = 0; i < repeats; i++) {
    randomize_in_place(A, n);
    currCost = cost(A, n);
    if (currCost <= bestCost) {
      bestCost = currCost;
      copy(tmp,n,A);
    }
  }
}
//---------------------------------------------------------------------------
//this function generates (exactly) all permutations of the tour A.
// your solution should be hard-coded to only work for an array of length 5.
// the optimal tour should be returned in A.  the number of permutations
// tested should be returned.
long bruteForce5Loops(double A[][2], int n) {
  assert(n == 5);  //only works for n=5
  long count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < n; y++) {

            count++;
          }
        }
      }
    }
  }
  return count;
}
//---------------------------------------------------------------------------