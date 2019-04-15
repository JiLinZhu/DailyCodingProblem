/*
Given two strings, write a method to decide if one is a permutation of another.
*/

bool checkPermutation(string a, string b) {
  if( b.length() != a.length() ) return false;
  vector<int> x(26,0);

  for( char c : a ) {
    x[c-'a']++;
  }

  for( char c : b ) {
    if( x[c-'a'] == 0 ) return false;
    x[c-'a']--;
  }
  return true;
}

// If not limited to lower case ascii, we can just use a map
