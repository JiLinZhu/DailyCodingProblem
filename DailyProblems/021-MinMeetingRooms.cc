/* 21. Snapchat
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
*/

int minMeetingRooms(vector<Interval> &intervals) { //With Array
    vector<int> start;
    vector<int> end;
    for( int i = 0; i < intervals.size(); i++ ) {
        start.push_back(intervals[i].start);
        end.push_back(intervals[i].end);
    }
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int maxRoom = 0;
    int curRoom = 0;
    int startIndex = 0;
    int endIndex = 0;
    while( startIndex < start.size() && endIndex < end.size() ) {
        if( start[startIndex] < end[endIndex] ) {
            curRoom++;
            startIndex++;
        }
        else {
            curRoom--;
            endIndex++;
        }
        maxRoom = max(maxRoom, curRoom);
    }
    
    return maxRoom;
}

// Can also use Priority Queue