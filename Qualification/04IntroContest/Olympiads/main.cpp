#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

void run() {
  int n, b, h, w;
  cin >> n >> b >> h >> w;
  b /= n;
  int bestP=INF;
  for (int i = 0; i < h; i++) {
    int p;
    cin >> p;
    bool a = false;
    for (int j = 0; j < w; j++) {
      int aj;
      cin >> aj;
      if (aj >= n) {
        a = true;
      }
    }
    if (p > b || !a) {
      continue;
    }
    bestP = min(bestP, p);
  }
  if (bestP < INF) {
    cout << bestP * n;
  } else {
    cout << "stay home";
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