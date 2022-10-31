#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<int>> adj(n, vector<int>(n, INF));
  vector<tuple<int, int, int>> edges(m);
  int maxS = 0, s = 0;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    if (adj[a][b] > w) {
      adj[a][b] = w;
      adj[b][a] = w;
    }
    edges[i] = {a, b, w};
    s += w;
    if (i < l) {
      maxS += w;
    }
  }
  vector<vector<ll>> dist(n);
  for (int i = 0; i < n; i++) {
    dist[i] = dijkstra(adj, i);
  }
  for (int e = 0; e < m; e++) {
    int a, b, w;
    tie(a, b, w) = edges[e];
    if (w > dist[a][b]) {
      s -= w;
    }
  }
  cout << ((s <= maxS) ? "possible" : "impossible");
  return 0;
}