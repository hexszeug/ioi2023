#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9
#define ll long long
#define pli pair<ll, int>

using namespace std;

vector<ll> dijkstra(vector<vector<int>> &adj, int start) {
  int n = adj.size();
  vector<ll> dist(n, INF);
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  pq.push({0, start});
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
  return dist;
}

ll run() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    a--, b--;
    if (adj[a][b] > d) {
      adj[a][b] = d;
      adj[b][a] = d;
    }
  }
  ll total = 0;
  for (int v = 0; v < n; v++) {
    vector<ll> dist = dijkstra(adj, v);
    for (int i = 0; i < n; i++) {
      total += dist[i];
    }
  }
  return 2*total;
} 

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
    cout << "Case #" << (i) << ": " << run() << "\n";
  return 0;
}