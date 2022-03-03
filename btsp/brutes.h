#pragma once
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
  double(*tmp)[2] = new double[n][2];
  double bestCost = INT_MAX;
  double currCost;
  for (int i = 0; i < repeats; i++) {
    randomize_in_place(A, n);
    currCost = cost(A, n);
    if (currCost <= bestCost) {
      bestCost = currCost;
      copy(tmp, n, A);
    }
  }
  copy(A, n, tmp);
}
//---------------------------------------------------------------------------
//this function generates (exactly) all permutations of the tour A.
// your solution should be hard-coded to only work for an array of length 5.
// the optimal tour should be returned in A.  the number of permutations
// tested should be returned.
bool isValidPermutation(int i, int j, int k, int x, int y) {
  if (i == j || i == k || i == x || i == y) {
    return false;
  }
  if (j == k || j == x || j == y) {
    return false;
  }
  if (k == x || k == y) {
    return false;
  }
  if (x == y) {
    return false;
  }
  return true;
}

long bruteForce5Loops(double A[][2], int n) {
  assert(n == 5);  //only works for n=5
  long count = 0, countValid = 0;
  double currCost = 0, bestCost = INT_MAX;
  double(*tmp)[2] = new double[n][2];
  double(*cpy)[2] = new double[n][2];
  for (int i = 0; i < n; i++) {//first element
    for (int j = 0; j < n; j++) {//second element
      for (int k = 0; k < n; k++) {//third element
        for (int x = 0; x < n; x++) {//fourth element
          for (int y = 0; y < n; y++) {//fifth element
            if (isValidPermutation(i, j, k, x, y)) {
              cpy[0][0] = A[i][0];
              cpy[0][1] = A[i][1];
              cpy[1][0] = A[j][0];
              cpy[1][1] = A[j][1];
              cpy[2][0] = A[k][0];
              cpy[2][1] = A[k][1];
              cpy[3][0] = A[x][0];
              cpy[3][1] = A[x][1];
              cpy[4][0] = A[y][0];
              cpy[4][1] = A[y][1];

              //cout << i << ", " << j << ", " << k << ", " << x << ", " << y << endl;
              currCost = cost(cpy, n);
              countValid++;
              if (currCost <= bestCost) {
                bestCost = currCost;
                copy(tmp, n, cpy);
              }
            }
            count++;
          }
        }
      }
    }
  }
  cout << "BEST COST: " << bestCost << endl;
  cout << count << " valid: " << countValid << endl;
  copy(A, n, tmp);
  return count;
}
//---------------------------------------------------------------------------