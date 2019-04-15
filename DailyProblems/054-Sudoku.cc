/* 54. Dropbox
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. 
The objective is to fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) 
must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.
*/

class Solution {
public:
    
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if( j == 9 ) {
            j = 0;
            i++;
        }
        if( i == 9 ) return true;
        if( board[i][j] != '.' ) return backtrack( board, i, j+1 );
        for( int a = 0; a < 9; a++ ) {
            if( rows[i][a] == 1 || cols[j][a] == 1 || squares[i/3*3+j/3][a] == 1 ) continue; 
            board[i][j] = '1'+ a;
            rows[i][a] = 1;
            cols[j][a] = 1;
            squares[i/3*3+j/3][a] = 1;
            if( backtrack(board, i, j+1) ) return true;
            rows[i][a] = 0;
            cols[j][a] = 0;
            squares[i/3*3+j/3][a] = 0;
        }
        board[i][j] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(9, vector<int>(9,0));
        cols = vector<vector<int>>(9, vector<int>(9,0));
        squares = vector<vector<int>>(9, vector<int>(9,0));
        
        for( int i = 0; i < 9; i++ ) {
            for( int j = 0; j < 9; j++ ) {
                if( board[i][j] != '.') {
                    rows[i][board[i][j]-'1'] = 1;
                    cols[j][board[i][j]-'1'] = 1;
                    squares[i/3*3+j/3][board[i][j]-'1'] = 1;
                }
            }
        }
        backtrack(board, 0, 0);
    }
private:
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> squares;
};