/* 84. Amazon
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
*/

// Disjoint-Set Data Structure
// Union Find


// DFS
int numIslands(vector<vector<char>>& grid) {
  int count = 0;
  int numRows = grid.size();
  if( numRows == 0 ) return 0;
  int numCols = grid[0].size();

  for( int i = 0; i < numRows; i++ ) {
    for( int j = 0; j < numCols; j++ ) {
      if( grid[i][j] == '1' ) {
        count++;
        stack<pair<int,int>> s;
        s.push({i, j});
        pair<int,int> temp;
        while(!s.empty()) {
          temp = s.top();
          s.pop();
          grid[temp.first][temp.second] = '0';
          if(temp.first > 0 && grid[temp.first-1][temp.second] == '1') s.push({temp.first-1, temp.second});
          if(temp.first < numRows - 1 && grid[temp.first+1][temp.second] == '1') s.push({temp.first+1, temp.second});
          if(temp.second > 0 && grid[temp.first][temp.second-1] == '1') s.push({temp.first, temp.second-1});
          if(temp.second < numCols - 1 && grid[temp.first][temp.second+1] == '1') s.push({temp.first, temp.second+1});
        }
      }
    }
  }
  return count;
}

// Union-Find

class UnionFind {

  vector<int> parent; // parent[i] represents the parent of the ith grid element (if the 2D array were 1D)
  vector<int> rank; // The number of children (We choose the one with higher rank when we merge sets)
  int count; // Num Disjoint Sets

  UnionFind(vector<vector<char>> grid) {
    int numRows = grid.size();
    if( numRows == 0 ) return;
    int numCols = grid[0].size();
    for( int i = 0; i < numRows; i++ ) {
      for( int j = 0; j < numCols; j++ ) {
        if( grid[i][j] == '1' ) {
          count++;
          parent.push_back(i * numCols + j);
        } else {
          parent.push_back(-1);
        }
        rank.push_back(0);
      }
    }
  }

  int find(int i) {
    while( i != parent[i] ) {
      parent[i] = find(parent[i]); // The extra step here is path compression
    }
    return i;
  }

  void Union(int x, int y) {
    int parX = find(x);
    int parY = find(y);

    if(parX == parY) return;
    if( rank[parX] > rank[parY] ) {
      parent[parY] = parX;
    } else if ( rank[parY] > rank[parX] ) {
      parent[parX] = parY;
    } else {
      parent[parY] = parX;
      rank[parX]++;
    }
    count--;
  }

};

int numIslands(vector<vector<char>>& grid) {
  int count = 0;
  int numRows = grid.size();
  if( numRows == 0 ) return 0;
  int numCols = grid[0].size();

  UnionFind unionFind = UnionFind(grid)

  for( int i = 0; i < numRows; i++ ) {
    for( int j = 0; j < numCols; j++ ) {
      if( grid[i][j] == '1' ) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i-1][j] == '1') unionFind.Union(i * numCols + j, (i-1) * numCols + j);
        if (j - 1 >= 0 && grid[i][j-1] == '1') unionFind.Union(i * numCols + j, i * numCols + j - 1);
      }
    }
  }

  return unionFind.count;
}
