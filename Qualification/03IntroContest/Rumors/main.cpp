#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 1e9

using namespace std;

int run() {
  int n;
  cin >> n;
  vector<int> sums(n, 0);
  vector<vector<int>> adj(n, vector<int>(n));
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++) {
      int v;
      cin >> v;
      sums[r] += v;
      adj[r][c] = v;
    }
  vector<bool> vis(n, false);
  stack<int> s;
  s.push(0);
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (!vis[v] && adj[v][u] != 0) {
        s.push(v);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      sums[i] = INF;
      for (int j = 0; j < n; j++) {
        adj[i][j] = 0;
        adj[j][i] = 0;
      }
    }
  }
  queue<int> q;
  for (int i = 1; i < n; i++) {
    if (sums[i] == 0) {
      q.push(i);
      sums[i] = INF;
      break;
    }
  }
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int r = 0; r < n; r++) {
      sums[r] -= adj[r][c];
      adj[r][c] = 0;
    }
    for (int i = 1; i < n; i++) {
      if (sums[i] == 0) {
        q.push(i);
        sums[i] = INF;
        break;
      }
    }
  }
  int sum = 0;
  for (int r = 1; r < n; r++) {
    int m = 0;
    for (int c = 0; c < n; c++)
      m = max(adj[r][c], m);
    sum += m;
  }
  return sum;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
    cout << "Case #" << (i+1) << ": " << run() << endl;
  // cout << run();
  return 0;
}