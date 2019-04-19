


int getPrev( int num ) {
  int temp = num;
  int numOnes = 0;
  int numZeros = 0;

  while((temp & 1) == 1) {
    numOnes++;
    temp >>= 1;
  }

  if( temp == 0 ) return -1; // no smaller number 00000....111

  while((temp & 1) == 0) {
    numZeros++;
    temp >>= 1;
  }

  int posToFlip = numOnes + numZeros;

  n &= ( ~0 << (posToFlip + 1))
  int mask = (1 << (numOnes + 1) - 1) << (numZeros - 1)

  return n | mask;
}


int getNext( int num ) {
  if(num == 0) return -1;
  int temp = num;
  int numZero = 0;
  int numOnes = 0;

  while( (temp & 1) == 0 ) {
    numZero++
    temp >>= 1;
  }

  while( (temp & 1) == 1 ) {
    numOnes++;
    temp >>= 1;
  }

  if( numZero + numOnes == 31 ) {
    return -1;
  }

  int p = numOnes + numZero;

  n |= ( 1 << p );
  n &= ~((1 << p) - 1);
  n |= (1 << (numOnes - 1)) - 1;
  return n;
}
