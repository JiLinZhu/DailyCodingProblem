/* 62. Facebook
There is an N by M matrix of zeroes. Given N and M, write a function to count 
the number of ways of starting at the top-left corner and getting to the bottom-right 
corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways 
to get to the bottom-right:

Right, then down
Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

int uniquePaths(int m, int n) {
  vector<int> dp(m, 1);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        dp[j] = dp[j] + dp[j-1];
    }
  }
  return dp[m-1];
}