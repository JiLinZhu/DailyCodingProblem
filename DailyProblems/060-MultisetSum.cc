/* 60. Facebook
Given a multiset of integers, return whether it can be partitioned into
two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return
true, since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split
it up into two subsets that add up to the same sum.
*/

bool multisetSum(vector<int> ms) {
  int minSum = getMinSum(ms);
  int maxSum = getMaxSum(ms);
  int sum = getSum(ms);
  if( sum % 2 == 1 ) return false;

  vector<bool> prev(maxSum-minSum+1, false);

  prev[0] = true;

  for( int i : ms ) {
    vector<bool> cur(maxSum-minSum+1, false);
    for( int k = minSum; k <= maxSum; k++ ) {
      if( prev[k+minSum] || isValid(k + minSum - i) && prev[k + minSum - i] == true ) {
        cur[k+minSum] = true;
      }
    }
    prev = cur;
  }

  return prev[sum/2+minSum+1];
}
