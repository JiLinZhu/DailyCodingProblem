/* 66. Square
Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 50-50 (but also not 0-100 or 100-0). You do not know the bias of the coin.
*/

bool tossUnbiased() {
  bool a = toss_biased();
  bool b = toss_biased();

  while( a == b ) {
    a = toss_biased();
    b = toss_biased();
  }

  return a == 1;
}
