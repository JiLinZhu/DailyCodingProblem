/* 18. Google
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
Do this in O(n) time and O(k) space.
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> results;
    deque<pair<int,int>> d;
    for( int i = 0; i < k - 1; i++ ) {                          // Push initial k - 1 elements
        while( !d.empty() && d.back().first <= nums[i] ) {
            d.pop_back();
        }
        d.push_back({nums[i], i});
    }
    for( int i = k - 1; i < nums.size(); i++ ) {
        while( !d.empty() && d.back().first <= nums[i] ) {
            d.pop_back();
        }
        d.push_back({nums[i], i});
        if( d.front().second <= i-k ) {
            d.pop_front();
        }
        results.push_back(d.front().first);
    }
    return results;
}