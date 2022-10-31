#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() {
  int c, m;
  cin >> c >> m;
  vector<vector<int>> buf(m+1, vector<int>(c+1, 0));
  for (int i = 1; i <= m; i++) { //i: current player (starting at 1)
    vector<int> P(c);
    for (int j = 0; j < c; j++) {
      cin >> P[j];
    }
    for (int j = 1; j <= c; j++) { //j: number of allowed tips
      int best = buf[i-1][j];
      for (int k = 1; k <= j; k++) { //k: number of tips used for current student
        best = max(best, P[k-1] + buf[i-1][j-k]);
      }
      buf[i][j] = best;
    }
  }
  cout << buf[m][c];
  return 0;
}