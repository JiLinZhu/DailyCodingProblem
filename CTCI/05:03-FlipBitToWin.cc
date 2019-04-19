/*
Get the length of the longest sequence of 1 bits you can make by flipping only one bit
*/


int flipBitToWin(int i) {
  if( ~i == 0 ) return 32;
  int curCount = 0;
  int prevCount = 0;
  int maxCount = 0;
  while(i > 0) {
    if( i && 1 == 1 ) {
      curCount++;
    } else {
        prevCount = curCount;
        curCount = 0;
    }
    maxCount = max(maxCount, curCount+prevCount+1);
  }

  return maxCount;
}
