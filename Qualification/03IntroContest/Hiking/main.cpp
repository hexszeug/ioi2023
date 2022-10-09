#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 1e9
#define ll long long
#define pli pair<ll, int>

using namespace std;

ll run() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int v, w, c;
    cin >> v >> w >> c;
    v--, w--;
    c = min(adj[v][w], c);
    adj[v][w] = c;
    adj[w][v] = c;
  }
  vector<ll> dist(n, INF);
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    ll d; int v;
    tie(d, v) = pq.top();
    pq.pop();
    if (dist[v] <= d) continue;
    dist[v] = d;
    for (int i = 0; i < n; i++)
      if (adj[v][i] < INF)
        pq.push({d + adj[v][i], i});
  }
  return dist[n-1];
} 

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
    cout << "Case #" << (i + 1) << ": " << run() << endl;
  return 0;
}