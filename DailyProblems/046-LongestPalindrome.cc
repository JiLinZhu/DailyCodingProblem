/* 46. Amazon
Given a string, find the longest palindromic contiguous substring. 
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". 
The longest palindromic substring of "bananas" is "anana".
*/


string longestPalindrome(string s) { // There is an O(n) solution using Manacher's Algorithm
    int resultLength = 0;
    string result;
    int size = s.length();
    int numSpots = size * 2 - 1;

    int lower, upper;

    for( int i = 0; i < numSpots; i++ ) {
        lower = i / 2;
        upper = lower + i % 2;
        while( lower >= 0 && upper < size ) {
            if( s[lower] != s[upper] ) {
                break;
            }
            lower--;
            upper++;
        }

        if( upper - lower - 1 > resultLength ) {
            resultLength = upper - lower - 1;
            result = s.substr(lower+1, resultLength);
        }
    }

    return result;
}