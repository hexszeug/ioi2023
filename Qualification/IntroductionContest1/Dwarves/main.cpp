#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string run() {
  int n;
  cin >> n;

  pair<string, string> edges[n];
  unordered_set<string> dwarves;

  for (int i = 0; i < n; i++) {
    string bigger, smaller, op;
    cin >> bigger >> op >> smaller;
    if (op == "<") {
      string tmp = bigger;
      bigger = smaller;
      smaller = tmp;
    }
    edges[i] = pair<string, string>(bigger, smaller);
    dwarves.insert(bigger);
    dwarves.insert(smaller);
  }

  for (auto dwarf : dwarves) {
    
  }



  return "possible";
}

int main() {
  cout << run();
  return 0;
}