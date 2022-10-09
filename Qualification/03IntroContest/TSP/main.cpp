#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

void best(vector<int> *begin, vector<int> *b, int *dis, int depth, int n, vector<vector<int>> *dist) {
  if (depth == n) {
    int cdis = 0;
    for (int i = 1; i < n; i++)
      cdis += (*dist)[(*begin)[i-1]][(*begin)[i]];
    cdis += (*dist)[(*begin)[0]][(*begin)[n-1]];
    if (cdis < *dis) {
      *dis = cdis;
      *b = *begin;
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    bool skip = false;
    for (int j = 0; j < depth; j++)
      if ((*begin)[j] == i) skip = true;
    if (skip) continue;
    begin->push_back(i);
    best(begin, b, dis, depth+1, n, dist);
    begin->pop_back();
  }
}

vector<int> run() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n, vector<int>(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      int w;
      cin >> w;
      adj[r][c] = w;
    }
  }
  vector<int> begin(0), b(0);
  int dis = INF;
  best(&begin, &b, &dis, 0, n, &adj);
  return b;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case #" << (i+1) << ": ";
    vector<int> res = run();
    int s = res.size();
    for (int j = 0; j < s; j++) {
      cout << (res[j]+1) << " ";
    }
    cout << "\n";
  }
  return 0;
}