/*
Determine the number of bits needed to be flipped to convert A to B
*/


int conversion(int A, int B) {
  int num = A ^ B;
  int count = 0;
  while( num != 0 ) {
    count++;
    num &= (num - 1);

  }
  return count;
}
