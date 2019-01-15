/* 13. Amazon
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
*/

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if( k == 0 ) return 0;
    queue<char> q;
    unordered_map<char, int> u;
    int maxLen = 0;
    int start = -1;
    char temp;
    for( int i = 0; i < s.length(); i++ ) {
        q.push(s[i]);
        if( u.find(s[i]) == u.end()  ) {
            while( u.size() > k-1 ) {
                temp = q.front();
                q.pop();
                start++;
                u[temp]--;
                if( u.at(temp) == 0 ) u.erase(temp);
            }
        }
        u[s[i]]++;
        maxLen = max(maxLen, i - start );
    }
    return maxLen;
}