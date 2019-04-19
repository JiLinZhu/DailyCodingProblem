/*
Insert M into N (bitwise) at position j and ending at position i
*/


int insertion( int M, int N, int j, int i ) {
  int mask = (~0 << (j + 1)) | (1 << i - 1);

  N = N & mask;
  M = M << j;

  return N | M;
}
