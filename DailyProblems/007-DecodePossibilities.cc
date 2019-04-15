/* 7. Facebook
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
*/


// DP

int decode( string message, unordered_map<int, char> map ) {
	int prev = 1;
	int tot = 1;
	int temp;
	for( int i = 1; i < message.length(); i++ ) { // DP
		temp = tot;
		if( stoi(message[i-1])*10 + stoi(message[i]) < 27 ) {
			tot += prev;
		}
		prev = temp;
	}
	return tot;
}
