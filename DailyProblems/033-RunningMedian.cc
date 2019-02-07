/* 33. Microsoft
Compute the running median of a sequence of numbers. 
That is, given a stream of numbers, print out the median of the list so far on each new element.
*/

void runningMedian( vector<int> v ) {
	priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
    int size = v.size();
    for( int i = 0; i < size; i++ ) {
    	maxHeap.push(v[i]);
	    minHeap.push(maxHeap.top());
	    maxHeap.pop();

	    if( maxHeap.size() < minHeap.size() ) {
	        maxHeap.push(minHeap.top());
	        minHeap.pop();
	    }
	    cout << i % 2 == 0 ? maxHeap.top() : (maxHeap.top() + minHeap.top()) * 0.5 << endl;
    }
}