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
//--------------------------------------------------------------------------
//external function definitions
extern void copy(double A[][2], int n, double B[][2]);
extern double cost(double A[][2], int n);
extern void print(double A[][2], int n);
extern long fact(long n);
extern long factRecursive(long n);
extern void randomize_in_place(double A[][2], int n);

extern void bruteForceRandom(double A[][2], int n, long repeats);
extern long bruteForce5Loops(double A[][2], int n);
//--------------------------------------------------------------------------

extern mt19937_64 g; //our random number generator

//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {               //main method
  g.seed(time(NULL));                            //seeds random number generator with time

//add whatever test your wish here. here are some examples.
  const int  n = 5;                              //defines the number of cities
  double  tour[n][2] = {                         //defines the locations of the cities
      { 0.631980, 0.7925150 },
      { 0.489609, 0.2541210 },
      { 0.975682, 0.0843492 },
      { 0.414236, 0.6135660 },
      { 0.338385, 0.0315477 }
  };
  
  randomize_in_place(tour, n);                   //randomizes tour
  printf("before (cost=%f) : \n", cost(tour, n));//prints initial cost of the tour
  print(tour, n);                                //prints the initial tour
  bruteForce5Loops(tour, n);                     //calls the brute force method
  printf("after (cost=%f) : \n", cost(tour, n)); //prints the cost after brute forcing the tour
  print(tour, n);                                //prints the best tour
  randomize_in_place(tour, n);                   //randomizes the tour
  printf("before (cost=%f) : \n", cost(tour, n));//prints initial cost of the tour
  print(tour, n);                                //prints the starting tour
  bruteForceRandom(tour, n, 240);                //calls the random brute force with 2*n! repeats
  printf("after (cost=%f) : \n", cost(tour, n)); //prints the resulting "best" cost
  print(tour, n);                                //prints the "best" tour
  return 0;                                      //end of main
}
//---------------------------------------------------------------------------
