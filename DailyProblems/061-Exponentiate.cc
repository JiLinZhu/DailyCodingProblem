/* 61. Google
Implement integer exponentiation. That is, implement the pow(x, y) function, 
where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/


double myPow(double x, int n) {
  if( n == 0 ) return 1;
  if( n == 1 ) return x;
  if( n == -1 ) return 1 / x;
  double odd = n % 2 == 0 ? 1 : n > 0 ? x : 1/x;
  double val = myPow(x, n/2);
  return val * val * odd; 
}