/* 2. Uber
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division?
*/
vector<int> productArray( vector<int> v ) {
	vector<int> left;
	vector<int> right;
	int leftProd = 1;
	int rightProd = 1;
	
	for( int i = 0; i < v.length(); i++ ) {
		leftProd *= v[i];
		rightProd *= v[v.length()-1-i];
		left.push_back(leftProd);
		right.push_back(rightProd);
	}

	vector<int> result;
	result.push_back(right[1]);
	for( int i = 1; i < v.length()-1; i++ ) {
		result.push_back( left[i-1] * right[i+1] );
	}
	result.push_back( left[v.length()-2] );
	
	return result;
}