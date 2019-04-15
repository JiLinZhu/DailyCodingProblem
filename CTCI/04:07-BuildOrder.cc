/*
Given a list of projects and a list of dependencies, return a valid build order
*/


class BuildOrder {
  bool topoSort(char c) {
    if(processed.find(c) != processed.end()) return true;
    if(map.find(c) == map.end()) {
      topoSort.push_back(c);
      return processing.find(c) == processing.end();
    }
    vecto<char> curList = map[c];
    map.erase(c);
    processing.insert(c);

    for(char x : curList) {
      if(!topoSort(x)) return false;
    }
    topoSort.push_back(c);
    processed.push_back(c);
    processing.erase(c);
    return true;
  }

  vector<char> buildOrder(vector<char> projects, vector<pair<char, char>> dep) {
    for( pair<char, char> d : dep ) {
      map[d.first].push_back(d.second);
    }

    for(char c: projects) {
      if(!topoSort(c)) return null;
    }

    return results;
  }

  unordered_set<char> processed;
  unordered_set<char> processing;
  unordered_map<char, vector<char>> map;
  vector<char> results;
}
