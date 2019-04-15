/* 77. Snapchat
Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
*/


bool mySort (Interval i,Interval j) { return (i.start<j.start); }


vector<Interval> merge(vector<Interval>& intervals) {
    int size = intervals.size();
    vector<Interval> results;
    if(size == 0) return results;
    sort(intervals.begin(), intervals.end(), mySort);


    int lower = intervals[0].start;
    int higher = intervals[0].end;

    Interval cur;
    for(int a = 1; a < size; a++) {
        cur = intervals[a];
        if( cur.start <= higher ) {
            higher = max(higher, cur.end);
        } else {
            results.push_back(Interval(lower, higher));
            lower = cur.start;
            higher = cur.end;
        }
    }
    results.push_back(Interval(lower, higher));

    return results;
}
