// file  : main.cpp
// author: ...
// desc. : this file initializes (seeds) our random number generator.
//         it also contains code that exercises/tests the following 
//         functions:
//           copy, cost, print, randomize_in_place,
//           bruteForceRandom, bruteForce5Loops
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

extern void copy(double A[][2], int n, double B[][2]);
extern double cost(double A[][2], int n);
extern void print(double A[][2], int n);
extern long fact(long n);
extern long factRecursive(long n);
extern void randomize_in_place(double A[][2], int n);

extern void bruteForceRandom(double A[][2], int n, long repeats);
extern long bruteForce5Loops(double A[][2], int n);

extern mt19937_64 g; //our random number generator
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  g.seed(time(NULL));

  //add whatever test your wish here. here are some examples.
  const int  n = 5;
  double  tour[n][2] = {
      { 0.631980, 0.7925150 },
      { 0.489609, 0.2541210 },
      { 0.975682, 0.0843492 },
      { 0.414236, 0.6135660 },
      { 0.338385, 0.0315477 }
  };

  double tcost =  cost(tour, n);

  cout << tcost << endl;

  /*randomize_in_place(tour, n);
  printf("before (cost=%f) : \n", cost(tour, n));
  print(tour, n);
  bruteForce5Loops(tour, n);
  printf("after (cost=%f) : \n", cost(tour, n));
  print(tour, n);

  randomize_in_place(tour, n);
  printf("before (cost=%f) : \n", cost(tour, n));
  print(tour, n);
  bruteForceRandom(tour, n, 240);
  printf("after (cost=%f) : \n", cost(tour, n));
  print(tour, n);*/

  return 0;
}
//---------------------------------------------------------------------------
