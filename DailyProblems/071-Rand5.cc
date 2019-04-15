/* 71. Two Sigma
Using a function rand7() that returns an integer from 1 to 7 (inclusive) with uniform probability,
implement a function rand5() that returns an integer from 1 to 5 (inclusive).
*/


int rand5() {
  int num = rand7()
  while( num > 5 ) {
    num = rand7()
  }
  return num;
}
