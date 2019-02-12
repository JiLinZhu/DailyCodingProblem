/* 38. Microsoft
You have an N by N board. Write a function that, given N, 
returns the number of possible arrangements of the board 
where N queens can be placed on the board without threatening each other, 
i.e. no two queens share the same row, column, or diagonal.
*/

int numWays( int n, vector<int> rows, int curRow ) {
	if( curRow == n ) {
		return 1;
	}

	for( int i = 0; i <= n; i++ ) {
		if( isValid( rows, n, curRow, i ) ) {
			rows[curRow] = i;
			return numWays( n, rows, curRow+1 );
		}
	}
}

int chessBoard( int n ) {
	vector<int> row(n);

	return numWays( n - 1, rows, 0 );
}

