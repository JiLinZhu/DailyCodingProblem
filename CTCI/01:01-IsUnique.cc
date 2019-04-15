/*
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
*/

bool isUnique( string s ) {
  unordered_set<char> c;

  for( char x : s ) {
    if( c.find(x) != c.end() ) return false;
    c.insert(x);
  }

  return true;
}

// We can also store each value in a bit to save space
// For no additional data structures, either compare every value or sort if allowed
