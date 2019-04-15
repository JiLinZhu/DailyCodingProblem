/* 16. Twitter
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:
record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
*/



class LeastRecentLog {
private:
  int end;
  int size;
  vector<int> log;

  LeastRecentLog(int size) : size(size), start(0) {
    vector<int> log(size, 0);
    this->log = log;
  }

  record(int id) {
    log[++end] = id;
  }

  get_last(int i) {
    return log[(end-i+1)%size]
  }
}
