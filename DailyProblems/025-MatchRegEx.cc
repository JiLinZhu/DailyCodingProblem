/* 25. Facebook
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.
*/

bool dp( vector<vector<bool>> &v, int x, int y, string s, string p ) { // DP + a bit of logic
    if( y == p.length() ) return x == s.length();
    if( v[x][y] == false ) return false;
    
    bool match = x < s.length() && ( s[x] == p[y] || p[y] == '.' );
    
    bool ans = y < p.length() - 1 && p[y+1] == '*' ?
        match && dp( v, x + 1, y, s, p ) || dp( v, x, y + 2, s, p )
        :
        match && dp( v, x + 1, y + 1, s, p );
    
    v[x][y] = ans;
    return ans;
}

bool isMatch(string s, string p) {
    vector<bool> patt;
    vector<vector<bool>> v;
    for( int i = 0; i <= p.length(); i++ ) {
        patt.push_back(true);
    }
    for( int i = 0; i <= s.length(); i++ ) {
        v.push_back(patt);
    }
    
    return dp( v, 0, 0, s, p );
}