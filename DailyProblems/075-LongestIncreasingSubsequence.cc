/* 75. Microsoft
Given an array of numbers, find the length of the longest increasing subsequence in the array. The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/

int lengthOfLIS(vector<int>& nums) {
    vector<int> r;
    bool inserted;
    for( int num: nums ) {
        inserted = false;
        for(int i = 0; i < r.size(); i++) {
            if( num == r[i] ) {
                inserted = true;
                break;
            }
            if( num < r[i] ) {
                r[i] = num;
                inserted = true;
                break;
            }
        }
        if(!inserted) {
            r.push_back(num);
        }
    }
    return r.size();
}


int lengthOfLIS(vector<int>& nums) {
    vector<int> r;
    for( int num: nums ) {
        int i = binarySearch(num, r);
        if( i < 0 ) continue;
        else if(i == r.size()) r.push_back(num);
        else {
          r[i] = num;
        }
    }
    return r.size();
}

// binarySearch
// -1 if repeat ( note that 4 4 5 is not an increasing sequence )
// otherwise index to be inserted at (first number larger than it)
