/* 70. Microsoft
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/


int perfectNum(int n) {
  int num = 19 + (n-1)*9;
  return num + 9 * (int)(log10(num) - 1);
}
