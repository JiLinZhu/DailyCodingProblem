/* 63. Microsoft
Given a 2D matrix of characters and a target word, write a function that 
returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
['O', 'B', 'Q', 'P'],
['A', 'N', 'O', 'B'],
['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true, since it's the leftmost column. 
Similarly, given the target word 'MASS', you should return true, since it's the last row.
*/

bool backtrack(vector<vector<char>>& board, string word, int index, int row, int col) {
  if( index >= word.size() ) return true;
  if( row >= board.size() || col >= board[0].size() || row < 0 || col < 0 || board[row][col] != word[index] ) return false;
  char temp = board[row][col];
  board[row][col] = '-';
  
  if( backtrack(board, word, index+1, row-1, col) 
     || backtrack(board, word, index+1, row+1, col) 
     || backtrack(board, word, index+1, row, col-1) 
     || backtrack(board, word, index+1, row, col+1)) {
      return true;
  }
  board[row][col] = temp;
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  int rows = board.size();
  int cols = board[0].size();
  
  for( int i = 0; i < rows; i++ ) {
    for( int j = 0; j < cols; j++ ) {
      if( board[i][j] == word[0] ) {
        if( backtrack(board, word, 0, i, j) ) return true;
      }
    }
  }
  return false;
}