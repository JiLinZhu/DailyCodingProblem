/* 51. Facebook
Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, 
write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*/

void shuffle( vector<string> &v ) {
  int size = v.size();
  int rand, temp;
  for( int i = 0; i < size; i++ ) {
    rand = random(size-i) - 1;
    temp = v[i];
    v[i] = v[i+rand];
    v[i+rand] = temp;
  }
}