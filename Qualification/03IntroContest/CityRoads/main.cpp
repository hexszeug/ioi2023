#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

#define INF 1e9

using namespace std;


void run() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> in(n, 0);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    in[b]++;
    adj[a].push_back(b);
  }
  stack<int> antiLeaves;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0)
      antiLeaves.push(i);
  }
  vector<int> topo;
  while (!antiLeaves.empty()) {
    int u = antiLeaves.top();
    antiLeaves.pop();
    topo.push_back(u);
    for (int v : adj[u]) {
      if (--in[v] == 0) {
        antiLeaves.push(v);
      }
    }
  }
  if (topo.size() != n) {
    for (int i = 0; i < l; i++) {
      int a, b;
      cin >> a >> b;
    }
    cout << "no";
    return;
  }
  cout << "yes\n";
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order[topo[i]] = i;
  }
  for (int i = 0; i < l; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (order[a] > order[b]) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    cout << (a + 1) << " " << (b + 1) << "\n";
  }
} 

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case #" << (i+1) << ": ";
    run();
    cout << "\n";
  }
  return 0;
}