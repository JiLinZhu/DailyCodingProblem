/* 79. Facebook
Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying at most 1 element.

For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 to make the array non-decreasing.

Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.
*/

bool checkPossibility(vector<int>& nums) {
    int a = -1;
    int size = nums.size();
    for( int i = 0; i < size - 1; i++ ) {
        if( nums[i] > nums[i+1] ) {
            if(a != -1) return false;
            a = i+1;
        }
    }
    return a <= 1 || a == size-1 || nums[a] >= nums[a-2] || nums[a+1] >= nums[a-1];
}
