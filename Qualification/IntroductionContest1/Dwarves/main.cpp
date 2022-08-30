#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename K, typename V>
void insertIfAbsent(unordered_map<K, V> *map, K key, V val) {
  if (map->find(key) == map->end())
    map->insert(pair<K, V>(key, val));
}

bool run() {
  int n;
  cin >> n;

  unordered_map<string, unordered_set<string>> adjList;
  unordered_map<string, int> revEdgCnt;

  for (int i = 0; i < n; i++) {
    string bigger, op, smaller;
    cin >> bigger >> op >> smaller;
    if (op == "<") {
      string tmp = smaller;
      smaller = bigger;
      bigger = tmp;
    }
    insertIfAbsent(&adjList, bigger, unordered_set<string>());
    insertIfAbsent(&adjList, smaller, unordered_set<string>());
    insertIfAbsent(&revEdgCnt, bigger, 0);
    insertIfAbsent(&revEdgCnt, smaller, 0);
    adjList[smaller].insert(bigger);
    revEdgCnt[bigger]++;
  }

  unordered_set<string> checked;
  for (auto entry : revEdgCnt) {
    if (entry.second == 0) {
      string curr = entry.first;
      vector<string> pathStack;
      pathStack.push_back(curr);
      unordered_set<string> pathSet;
      pathSet.insert(curr);
      while (!pathStack.empty())
      {
        bool chk = true;                            //
        for (auto v : adjList[curr]) {              //
          if (checked.find(v) == checked.end()) {   //
            curr = v;                               // Not quite sure about that
            chk = false;                            //
            break;                                  //
          }                                         //
        }                                           //
        if (chk) {
          checked.insert(curr);
          pathStack.pop_back();
          curr = pathStack.back();
          pathSet.erase(curr);
          continue;
        }
        if (pathSet.find(curr) != pathSet.end()) {
          return false;
        }
        pathStack.push_back(curr);
        pathSet.insert(curr);
      }
    }
  }
  return checked.size() == adjList.size();
}

int main() {
  cout << (run() ? "possible" : "impossible");
  return 0;
}