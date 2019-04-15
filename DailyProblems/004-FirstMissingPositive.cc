/* 4. Stripe
Given an array of integers, find the first missing positive integer in linear time and constant space.
*/


// Swap while value cur value != cur index and index within index of array
// Then iterate and find first value that is not equal to index

void swap( vector<int>& v, int i, int j ) {
    int temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

int firstMissingPositive( vector<int> v  ) {
	int val, nextVal;
	for( int i = 0; i < v.size(); i++ ) {
		if( v[i] <= 0 && v[i] > v.size() ) continue;

		val = v[i];

		while( v[val-1] != val ) { // swap wrong vals into correct place
			nextVal = v[val-1];
			v[val-1] = val;
			val = nextVal;
			if( val <= 0 || val > n ) break; // non existent
		}
	}

	for(int i = 0; i < n; i++) {
		if( v[i] != i + 1 ) return i + 1; // return first value that is missing
	}

	return v.size() + 1;
}
