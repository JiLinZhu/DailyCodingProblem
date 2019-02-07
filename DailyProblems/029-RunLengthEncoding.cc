/* 29. Amazon
Run-length encoding is a fast and simple method of encoding strings. 
The basic idea is to represent repeated successive characters as a single count and character. 
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. 
You can assume the string to be encoded have no digits and consists solely of alphabetic characters. 
You can assume the string to be decoded is valid.
*/


string encode( string s ) {
	char cur = s[0];
	int count = 0;
	string result = "";
	for( char c : s ) {
		if( c != cur ) {
			result = result + to_string(count) + cur;
			cur = c;
			count = 0;
		} 
		count++;
	}
	result = result + to_string(count) + cur;
}

string decode( string s ) {
	int num = 0;
	string r = "";

	for( char c : s ) {
		if( isNum(c) ) {
			num = num * 10 + toNum(c);
		} else {
			while( num > 0 ) {
				r += c;
				num--;
			}
		}
	}

	return r;
}
