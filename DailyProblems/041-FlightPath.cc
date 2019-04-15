/* 41. Facebook
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs,
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null.
If there are multiple possible itineraries, return the lexicographically smallest one.
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM',
you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A',
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C']
is also a valid itinerary. However, the first one is lexicographically smaller.
*/


// Topological sort, handling lexicograph with a priority queue.

class myComparator
{
public:
    int operator() (const string p1, const string p2)
    {
        return p1 > p2;
    }
};

class Solution {
public:
    void topoSort(vector<string> &result, string cur) {
        while(p[cur].size() > 0) {
            string x = p[cur].top();
            p[cur].pop();
            topoSort(result, x);
        }
        result.push_back(cur);
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets, string start) {
        for (const auto& elem: tickets) {
            if( p.find(elem.first) == p.end() ) {
                priority_queue<string, vector<string>, myComparator> pq;
                p[elem.first] = pq;
            }
            p[elem.first].push(elem.second);
        }

        vector<string> result;
        topoSort(result, start);
        reverse(result.begin(),result.end());
        return result;
    }

private:
    unordered_map<string, priority_queue<string, vector<string>, myComparator>> p;
};
