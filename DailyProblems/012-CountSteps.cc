/* 12. Amazon
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. 
Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

int countSteps( int n ) {
	if ( n == 0 || n == 1 ) return 1;
	int lower = 1;
	int higher = 2;
	for( int i = 3; i <= n; i++ ) {
		temp = lower;
		lower = higher;
		higher = lower + temp;
	}
	return higher;
}

int countStepsExtend( vector<int> x, int n ) {
	vector<int> count(n+1);
	count[0] = 1;
	for( int i = 1; i <= n; i++ ) {
		for( int denom : x ) {
			if( i - denom >= 0 ) {
				count[i] += count[i - denom];
			}
		}
	}
	return count[n];
}