/*
Swap the even and odd bits of a number
1001 -> 0110
*/
int pairwiseSwap(int x) {
  int even = x & 0xAAAAAAAA;
  int odd = x & 0x55555555

  even >>= 1;
  odd <<= 1;
  return even | odd;
}
