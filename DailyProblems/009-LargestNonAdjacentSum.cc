/* 9. Airbnb
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. 
Assume vector is of size 2+. Can you do this in O(N) time and constant space? 
*/

int largestSum( vector<int> v ) { // DP
	int a = 0;
	int b = 0;
	int temp;
	for( int i = 0; i < v.size(); i++ ) {
		temp = max(a, b);
		if( v[i] > 0 ) b = v[i] + a; 
		a = temp;
	}
	return max(a,b);
}