/*
Rotate a NxN square matrix by 90 degrees clockwise. Can you do it in place?
*/


void rotateMatrix( vector<vector<char>> &v, int n ) {
  for( int i = 0; i < n; i++ ) {
    for( int j = i + 1; j < n; j++ ) {
      int temp = v[i][j];
      v[i][j] = v[j][i];
      temp = v[i][j];
    }
  }


  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n/2; j++ ) {
      int temp = v[i][j];
      v[i][j] = v[i][n-j-1];
      v[i][n-j-1] = temp;
    }
  }
}
