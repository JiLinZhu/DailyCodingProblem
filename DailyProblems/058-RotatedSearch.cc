/* 58. Amazon
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
*/

int rec( vector<int>& nums, int target, int start, int end ) {
    if( end < start ) return -1;
    int mid = start + (end-start)/2;
    if( nums[mid] == target) return mid;
    if ( nums[mid] > target) {
        if( nums[end] >= nums[mid] ) {

            return rec( nums, target, start, mid - 1 );
        } else {
            if( nums[end] >= target ) {
                return rec( nums, target, mid + 1, end );
            } else {
                return rec( nums, target, start, mid - 1 );
            }
            
        }
    } else {
        if( nums[start] <= nums[mid] ) {
            return rec( nums, target, mid + 1, end ) ;
        } else {
            if( nums[end] >= target ) {
                return rec( nums, target, mid + 1, end ) ;
            } else {
                return rec( nums, target, start, mid - 1 );
            }
        }
    }
}
int search(vector<int>& nums, int target) {
    return rec( nums, target, 0, nums.size()-1);
}