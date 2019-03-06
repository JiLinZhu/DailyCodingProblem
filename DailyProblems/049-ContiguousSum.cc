/* 49. Amazon
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
*/

int maxContiguousSum( vector<int> v ) {
	int res = 0;
	int cur = 0;
	for( int i: v ) {
		cur += i;
		res = max(res, cur);
		if( cur < 0 ) cur = 0;
	}
	return res;
}

