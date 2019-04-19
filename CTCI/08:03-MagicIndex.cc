/*
Return the index where A[i] = i in a sorted distinct array
What about for non distinct?
*/


int magicIndex(vector<int> v, int lower, int upper) {
  if( lower == upper ) return v[lower] == lower ? lower : -1;

  int mid = lower + (upper - lower)/2;

  if(v[mid] == mid) return mid;

  if(v[mid] > mid) return magicIndex(v, lower, mid - 1);
  else return magicIndex(v, mid + 1, upper);
}


// If distinct, we would have to look both ways



-3 1 3 4 6
