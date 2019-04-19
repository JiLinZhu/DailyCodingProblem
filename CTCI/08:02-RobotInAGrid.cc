/*
Count the number of ways for a robot to move from top left to bottom right of a grid.
Certain cells are off limits.
*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int size = obstacleGrid.size();
  if(size == 0) return 0;
  int length = obstacleGrid[0].size();

  vector<unsigned long long> paths(length, 0);
  paths[0] = 1;

  for( int i = 0; i < size; i++ ) {
    for( int j = 0; j < length; j++ ) {
      if(obstacleGrid[i][j] == 1) paths[j] = 0;
      else paths[j] = (j == 0 ? 0 : paths[j-1]) + paths[j];
    }
  }

  return paths[length-1];
}
