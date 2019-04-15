/*
Write an algo such that if an element in an MxN matrix is 0, its entire row + column is set to 0
Can you do this with O(1) space.
*/


void zeroMatrix( vector<vector<int>> &v ) {
  bool shouldZeroRow, shouldZeroCol;
  int rowSize = v[0].size();
  int colSize = v.size();
  for( int i = 0; i < rowSize; i++ ) {
    if( v[0][i] == 0 ) {
      shouldZeroRow = true;
      break;
    }
  }

  for( int i = 0; i < colSize; i++ ) {
    if( v[i][0] == 0 ) {
      shouldZeroCol = true;
      break;
    }
  }

  for( int i = 1; i < rowSize; i++ ) {
    for( int j = 1; j < colSize; j++ ) {
      if( v[i][j] == 0 ) {
        v[0][j] = 0;
        v[i][0] = 0;
      }
    }
  }

  for( int i = 1; i < rowSize; i++ ) {
    if( v[0][i] == 0 ) {
      for( int j = 1; j < colSize; j++ ) {
        v[j][i] = 0;
      }
    }
  }

  for( int i = 1; i < colSize; i++ ) {
    if( v[i][0] == 0 ) {
      for( int j = 1; j < rowSize; j++ ) {
        v[i][j] = 0;
      }
    }
  }

  if(shouldZeroRow) {
    for( int i = 0; i < rowSize; i++ ) {
      v[0][i] = 0;
    }
  }

  if(shouldZeroCol) {
    for( int i = 0; i < colSize; i++ ) {
      v[i][0] = 0;
    }
  }
}
