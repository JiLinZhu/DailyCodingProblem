/* 35. Google
Given an array of strictly the characters 'R', 'G', and 'B', 
segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/


void sortColors(vector<int>& nums) {
    int i = 0, j = 0, k = nums.size() - 1;
    while( j <= k ) {
        if( nums[j] == 2 ) {
            nums[j] = nums[k];
            nums[k] = 2;
            k--;
        } else if ( nums[j] == 0 ) {
            nums[j] = nums[i];
            nums[i] = 0;
            j++;
            i++;
        } else {
            j++;
        }
    }
}