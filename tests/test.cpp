#include "pch.h"
#include "../btsp/main.h"
#include "../btsp/brutes.h"
#include "../btsp/utes.h"

void bruteForceRandom(double A[][2], int n, int repetitions);
long bruteForce5Loops(double A[][2], int n);

TEST(TestCaseName, TestName) {
  const int n = 5;
  double  tour[n][2] = {
      { 0, 0 },
      { 1, 3 },
      { 0, 2 },
      { 2, 0 },
      { 2, 2 }
  };
  double ans = 8.828427125;
  double allowedVariation = 0.0001;
  bruteForceRandom(tour, n, 4*fact(n));
  print(tour, n);
  double randCost = cost(tour, n);
  randomize_in_place(tour, n);
  bruteForce5Loops(tour, n);
  double loopCost = cost(tour, n);
  bool isCloseRand = (abs(randCost - ans) > 0 && abs(randCost - ans) < allowedVariation);
  bool isCloseLoop = (abs(loopCost - ans) > 0 && abs(loopCost - ans) < allowedVariation);
  EXPECT_TRUE(isCloseRand);
  EXPECT_TRUE(isCloseLoop);
}