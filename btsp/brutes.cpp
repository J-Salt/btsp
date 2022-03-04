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
void bruteForceRandom(double A[][2], int n, long repeats) {  //function definition for random brute force method
  double (*tmp)[2] = new double[n][2];                       //temporary array used to store the best tour so far
  double bestCost = INT_MAX;                                 //sets the best cost to "infinity"
  double currCost;                                           //current cost of the current tour
  for (int i = 0; i < repeats; i++) {                        //for-loop to randomize and calculate the cost based on the number of repeats
    randomize_in_place(A, n);                                //calls function to randomize the tour
    currCost = cost(A, n);                                   //sets the current cost to the cost of the current tour
    if (currCost <= bestCost) {                              //if-statement to see if the current cost is lower than the best so far
      bestCost = currCost;                                   //updates best cost
      copy(tmp,n,A);                                         //copys this tour into the temp array
    }
  }
  copy(A,n,tmp);                                             //copys the best tour into A
}

//------------------------------------------------------------------------------

bool isValidPermutation(int i, int j, int k, int x, int y) { //helper function to check if, based on the current permutation of i,j,k,x and y, that there are no repeats
  if (i == j || i == k || i == x || i == y) {                //checks if the value in i is repeated
    return false;                                            //return false if theres a duplicate index value
  }
  if (j == k || j == x || j == y) {                          //checks if the value in j is repeated
    return false;                                            //return false if theres a duplicate index value
  }
  if (k == x || k == y) {                                    //checks if the value in k is repeated
    return false;                                            //return false if theres a duplicate index value
  }
  if (x == y) {                                              //checks if the value in x is repeated
    return false;                                            //return false if theres a duplicate index value
  }
  return true;                                               //returns true if the current permutation is unique
}

//---------------------------------------------------------------------------
//this function generates (exactly) all permutations of the tour A.
// your solution should be hard-coded to only work for an array of length 5.
// the optimal tour should be returned in A.  the number of permutations
// tested should be returned.

long bruteForce5Loops(double A[][2], int n) {                //function definition to brute force a tour of 5 cities
  assert(n == 5);                                            //only works for n=5
  long count = 0, countValid = 0;                            //initializes count and countValid, which keep track of total permutations(n**n) and the total valid(non repeating, n!) permutations
  double currCost = 0, bestCost = INT_MAX;                   //initializes current cost and best cost
  double(*tmp)[2] = new double[n][2];                        //creates a temp array to store the best tour so far
  double(*cpy)[2] = new double[n][2];                        //creates a copy array to store the current permutation of array A
  for (int i = 0; i < n; i++) {                              //first element
    for (int j = 0; j < n; j++) {                            //second element
      for (int k = 0; k < n; k++) {                          //third element
        for (int x = 0; x < n; x++) {                        //fourth element
          for (int y = 0; y < n; y++) {                      //fifth element
            if (isValidPermutation(i,j,k,x,y)) {             //if-statement to check if the permutation is valid before altering the arrays
              cpy[0][0] = A[i][0];                           //copys the x coordinate from current permutation into cpy
              cpy[0][1] = A[i][1];                           //copys the y coordinate from current permutation into cpy
              cpy[1][0] = A[j][0];                           //copys the x coordinate from current permutation into cpy
              cpy[1][1] = A[j][1];                           //copys the y coordinate from current permutation into cpy
              cpy[2][0] = A[k][0];                           //copys the x coordinate from current permutation into cpy
              cpy[2][1] = A[k][1];                           //copys the y coordinate from current permutation into cpy
              cpy[3][0] = A[x][0];                           //copys the x coordinate from current permutation into cpy
              cpy[3][1] = A[x][1];                           //copys the y coordinate from current permutation into cpy
              cpy[4][0] = A[y][0];                           //copys the x coordinate from current permutation into cpy
              cpy[4][1] = A[y][1];                           //copys the y coordinate from current permutation into cpy

                                                             //cout << i << ", " << j << ", " << k << ", " << x << ", " << y << endl; //simple check to verify the permutations
              currCost = cost(cpy, n);                       //calculates the cost of the current permutation
              countValid++;                                  //increments the valid counter
              if (currCost <= bestCost) {                    //if-statement to check if the current cost is lower than the best so far
                bestCost = currCost;                         //updates best cost
                copy(tmp,n,cpy);                             //copys the current best permutation into tmp
              }
            }
            count++;                                         //increments count
          }
        }
      }
    }
  }
  copy(A, n, tmp);                                           //copys the best tour into A
  return countValid;                                         //returns the total number of tours tested (n! not n**n)
}
//---------------------------------------------------------------------------