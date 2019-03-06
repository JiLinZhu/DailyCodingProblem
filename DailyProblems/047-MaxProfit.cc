/* 47. Facebook
Given a array of numbers representing the stock prices of a company in chronological order, 
write a function that calculates the maximum profit you could have made from buying and selling that stock once. 
You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, 
since you could buy the stock at 5 dollars and sell it at 10 dollars.
*/

int maxProfit( vector<int> x ) {
	int size = x.size();
	if( size == 0 ) return 0;
	int m = x[0];
	int r = 0;
	for( int i : x ) {
		m = min(i, m);
		r = max(r, i-m);
	}
	return r;
}