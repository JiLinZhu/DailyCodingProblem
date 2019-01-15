/* 1. Google
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
Bonus: Can you do this in one pass?
*/
bool twoSum( vector<int> a, int k ) {
	unordered_set<int> set;
	for( int i : a ) {
		if( set.find( k - i ) != set.end() ) return true;
		set.add(i);
	}
	return false;
}
