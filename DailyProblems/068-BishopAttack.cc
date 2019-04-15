/* 68. Google
On our special chessboard, two bishops attack each other if they share the same diagonal.
This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard. Write a function to count
the number of pairs of bishops that attack each other. The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).
*/

int countBishopAttacks( vector<pair<int, int>> v ) {
  unordered_map<int, int> diff;
  unordered_map<int, int> sum;

  int total = 0;
  int temp;
  for( pair<int, int> x : v ) {
    temp = x.first - x.second;
    total += diff[temp];
    diff[temp]++;

    temp = x.first + x.second;
    total += sum[temp];
    sum[temp]++;
  }

  return total;
}
