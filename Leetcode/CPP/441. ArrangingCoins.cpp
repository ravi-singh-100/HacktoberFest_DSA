// QUESTION LINK: https://leetcode.com/problems/arranging-coins/

// You have n coins and you want to build a staircase with these coins. 
//The staircase consists of k rows where the ith row has exactly i coins. 
//The last row of the staircase may be incomplete.

// Given the integer n, 
//return the number of complete rows of the staircase you will build.

//SOLUTION:
class Solution {
 public:
  int arrangeCoins(long n) {
    return (-1 + sqrt(8 * n + 1)) / 2;
  }
};