/* 95. Palantir
Given a number represented by a list of digits, find the next greater permutation of a number, in terms of lexicographic ordering. If there is not greater permutation possible, return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the input memory)?
*/


void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    if(size == 0) return;

    int index = -1;
    for( int i = size - 1 ; i > 0; i++ ) { // Find first a[j-1] > a[j] from end of array
      if( nums[i] < nums[i-1] ) {
        index = i-1;
        break;
      }
    }
    if( index != -1 ) { // Find first larger number that is smaller than a[j-1] (this will be the first number since its reverse ordered)
      int num = nums[index];
      int minIndex = size-1;
      for( int i = index+1; i < size; i++ ) {
        if( nums[i] < num ) {
          minIndex = i;
          break;
        }
      }
      swap(nums, minIndex, index); // Swap
    }

    reverse(nums, index+1, size-1); // Reverse array (this is equivalent of sorting that portion of the array
    return nums;
  }
