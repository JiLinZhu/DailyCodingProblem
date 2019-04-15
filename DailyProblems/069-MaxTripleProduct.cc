/* 69. Facebook
Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
*/

int maxTripleProduct(vector<int> nums) {
  int min = INT_MAX;
  int min2 = INT_MAX;
  int max = INT_MIN;
  int max2 = INT_MIN;
  int max3 = INT_MIN;

  for( int i: nums ) {
    if( i >= max ) {
      max3 = max2;
      max2 = max;
      max = i;
    } else if ( i >= max2 ) {
      max3 = max2;
      max2 = i;
    } else if ( i > max3 ) {
      max3 = i;
    }

    if( i <= min ) {
      min2 = min;
      min = i;
    } else if ( i < min2 ) {
      min2 = i;
    }
  }

  return max(min2*min1*max, max*max2*max3);
}
