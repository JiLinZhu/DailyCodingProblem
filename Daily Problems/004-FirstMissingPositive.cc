/* 4. Stripe
Given an array of integers, find the first missing positive integer in linear time and constant space. 
*/
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

		while( v[val-1] != val ) {
			nextVal = arr[val-1];
			arr[val-1] = val;
			val = nextVal;
			if( val <= 0 || val > n ) break;
		}
	}

	for(int i = 0; i < n; i++){
		if( arr[i] != i + 1 ) return i + 1;
	} 

	return v.size() + 1;
}