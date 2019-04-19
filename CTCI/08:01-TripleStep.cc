/*
Count the number of ways someone can climb up n steps if they can take 1, 2, or 3 steps at a time
*/




int tripleStep(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 2;
  if(n == 3) return 4;

  vector<int> numWays(n, 0);
  numWays[0] = 1;
  numWays[1] = 2;
  numWays[2] = 4;

  for( int i = 3; i < n; i++ ) {
    numWays[i] = numWays[i-1] + numWays[i-2] + numWays[i-3];
  }

  return numWays[n-1];
}

// Don't really need array here.
