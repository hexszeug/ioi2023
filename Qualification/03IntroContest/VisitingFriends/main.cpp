#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

long long run() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n, vector<int>(n, INF));
  long long total = 0;
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    a--, b--;
    if (dist[a][b] > d) {
      if (dist[a][b] != INF)
        total -= dist[a][b];
      total += d;
      dist[a][b] = d;
      dist[b][a] = d;
    }
  }
  for (int w = 0; w < n; w++) {
    for (int u = 0; u < n; u++) {
      if (w == u) continue;
      for (int v = u+1; v < n; v++) {
        if (w == v) continue;
        if (dist[u][w] + dist[w][v] < dist[u][v]) {
          int d = dist[u][w] + dist[w][v];
          if (dist[u][v] != INF)
            total -= dist[u][v];
          total += d;
          dist[u][v] = d;
          dist[v][u] = d;
        }
      }
    }
  }
  return 4*total;
} 

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
    cout << "Case #" << (i) << ": " << run() << "\n";
  return 0;
}