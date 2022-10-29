#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

void run() {
  int n, c;
  cin >> n >> c;
  vector<int> v(n), bufN(c+1);
  vector<vector<int>> bufC(c+1, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= c; i++) {
    int bestN = INF, bestC;
    for (int j = 0; v[j] <= i && j < n; j++) {
      if (bufN[i-v[j]] + 1 < bestN) {
        bestN = bufN[i-v[j]] + 1;
        bestC = j;
      }
    }
    bufN[i] = bestN;
    bufC[i] = bufC[i-v[bestC]];
    bufC[i][bestC]++;
  }
  for (int i = 0; i < n; i++) {
    cout << bufC[c][i] << " ";
  }
}

int main() {
  int t = 0;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    run();
    cout << endl;
  }
  return 0;
}