/* 19. Facebook
A builder is looking to build a row of N houses that can be of K different colors. 
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
*/
int minCostII(vector<vector<int>>& costs) { // Max and second Max w/ DP
    const int a = costs.size();
    if( a == 0 ) return 0;
    const int b = costs[0].size();
    int min = 0, minIndex = -1, min2 = 0;
    int cur, curIndex, cur2;
    for( int i = 0; i < a; i++ ) {
        cur = min;
        curIndex = minIndex;
        cur2 = min2;
        min = INT_MAX;
        min2 = INT_MAX;
        for( int j = 0; j < b; j++ ) {
            if( curIndex != j ) costs[i][j] += cur;
            else costs[i][j] += cur2;
            if( costs[i][j] <= min ) {
                min2 = min;
                min = costs[i][j];
                minIndex = j;
            } else if ( costs[i][j] < min2 ) {
                min2 = costs[i][j];
            }
        }
    }
    return min;
}