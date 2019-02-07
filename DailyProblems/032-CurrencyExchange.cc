/* 32. Jane Street
Suppose you are given a table of currency exchange rates, represented as a 2D array. 
Determine whether is some sequence of trades you can make, 
starting with some amount A of any currency, so that you can end up with some amount greater than A 
of that currency.

There are no transaction costs and you can trade fractional quantities.
*/

bool arbitrage( vector<vector<int>> v ) { // Bellman-Ford Algorithm
	int size = v.size();
	vector<double> paths(size, INT_MAX);
	paths[0] = 0;

	for( int i = 1; i < size; i++ ) { // vertex - 1 iterations
		for( int j = 0; j < size; j++ ) { // iterate over all edges
			for( int k = 0; k < size; k++ ) {
				if( paths[j] == INT_MAX ) break;
				paths[k] = min(paths[k], paths[j] - log(v[j][k]));
			}
		}
	}

	for( int j = 0; j < size; j++ ) { // iterate over all edges
		for( int k = 0; k < size; k++ ) {
			if( paths[j] == INT_MAX ) break;
			if( paths[j] - log(v[j][k]) < paths[k] ) return true;
		}
	}
	return false;
}