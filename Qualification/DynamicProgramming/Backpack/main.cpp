#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<pair<int, int>> lst;

int p(int k, int r) {
  if (k == lst.size() || r == 0) return 0;
  if (r < 0) return -INF;
  return max(p(k + 1, r), lst[k].first + p(k + 1, r - lst[k].second));
}

int main() {
  int c, n;
  cin >> c >> n;
  for (int i = 0; i < n; i++) {
    int v, s;
    cin >> v >> s;
    lst.emplace_back(v, s);
  }
  cout << p(0, c);
  return 0;
}