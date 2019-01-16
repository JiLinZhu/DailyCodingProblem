/* 23. Google
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*/

int minStepsToFinish( vector<vector<bool>> board, pair<int,int> start, pair<int,int> end ) {
	queue<pair<pair<int,int>, int>> bfs; // BFS will always get shortest path
	pair<pair<int,int>, int> top;
	pair<int,int> cur;
	bfs.push(start);

	while( !bfs.empty() ) {
		top = bfs.top();
		bfs.pop();

		if( top.first == end ) return top.second; // If reached destination
		cur = top.first;

		board[cur.first][cur.second] = false; // Set Visited

		if( cur.first - 1 >= 0 && board[cur.first-1][cur.second] ) { // Add all 4 directions if possible
			bfs.push({{cur.first-1, cur.second}, top.second+1});
		}
		if( cur.first + 1 < board[0].size() && board[cur.first+1][cur.second] ) {
			bfs.push({{cur.first+1, cur.second}, top.second+1});
		}
		if( cur.second - 1 >= 0 && board[cur.first][cur.second-1] ) {
			bfs.push({{cur.first, cur.second-1}, top.second+1});
		}
		if( cur.second + 1 < board.size() && board[cur.first][cur.second+1] ) {
			bfs.push({{cur.first, cur.second+1}, top.second+1});
		}
	}
	return -1; // Path not found
}