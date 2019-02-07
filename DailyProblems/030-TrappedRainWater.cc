/* 30. Facebook
You are given an array of non-negative integers that represents a two-dimensional elevation map 
where each element is unit-width wall and the integer is the height. 
Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, 
and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
*/

int trappedRainWater( vector<int> v ) {
	int left = 0;
	int right = v.size() - 1;
	int leftMax = 0;
	int rightMax = 0;
	int result = 0;
	
	while( left < right ) {
		if( height[left] < height[right] ) { 		// Note that height[right] will always be > leftMax 
			leftMax = max(leftMax, height[left]);	// (or right would not be in its current position)
			result += leftMax - height[left++];		// which means that leftMax will determine the water stored
		} else {
			rightMax = max(rightMax, height[right]);
			result += rightMax - height[right--];
		}
	}

	return result;
}