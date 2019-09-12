/* 99. Microsoft
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
*/


int longestConsecutive(vector<int>& nums) {
  unordered_set<int> s(nums.begin(), nums.end());

  int res = 0, curStreak, num;
  for (const auto& elem: s) {
    if( s.find(elem-1) != s.end() ) {
      continue;
    }
    curStreak = 1;
    num = elem;
    while(s.find(num+1) != s.end()) {
      curStreak++;
      num++;
    }

    res = max(res, curStreak);
  }
  return res;
}
