/*
Given a string like "Mr John Smith      ",
Change it to "Mr%20John%20Smith"

You are guarantee an array of sufficient length to do this and also the true length of the string.
*/

void urlify( vector<char> &v, int n ) {
  int k = v.size() - 1;

  for( int i = n - 1; i >= 0; i-- ) {
    if(v[i] == ' ') {
      v[k--] = '0';
      v[k--] = '2';
      v[k--] = '%';
    } else {
      v[k--] = v[i];
    }
  }
}

