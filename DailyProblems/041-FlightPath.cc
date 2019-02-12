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

vector<string> flightPath( unordered_set<pair<string, string>> s, string start ) {
	unordered_map<string, priority_queue<string>> p;
	for (const auto& elem: mySet) {
    	if( p.find(elem.first) == p.end() ) {
    		p[elem.first] = new priority_queue();
    		
    	}
    	p[elem].push(elem.second);
	}

	vector<string> result;
	result.push_back(start);
	string cur = start;
	while( true ) {
		priority_queue<string> curQ = p[cur];
		if( !curQ || curQ.size() == 0 ) break;
		result.push_back(curQ.top());
		cur = curQ.top();
		curQ.pop();
	}
	return result.size() == s.size() + 1 ? result : null;
}