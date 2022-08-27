#include <iostream>
#include <set>

using namespace std;

int testCase() {
  int l, n, r, d;
  cin >> l >> n >> r;
  d = 2*r; //max distance between two lit lights

  if (n <= 0)
    return -1; //no street lights at all

  set<int> lights;

  for (int i = 0; i < n; i++) {
    int light;
    cin >> light;
    lights.insert(light);
  }

  int totalLit = 0, lastLit = -r, next;

  if (*lights.begin() > r)
    return -1; //gap at the beginning

  for (auto pLight = lights.begin(); pLight != lights.end();) {
    int light = *pLight;
    pLight++;
    next = (pLight != lights.end()) ? *pLight : l + r;
    if (next - light > d) {
      return -1; //gap
    }
    if (next - lastLit > d) {
      lastLit = light;
      totalLit++;
    }
  }

  return totalLit;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": ";
    int res = testCase();
    if (res != -1)
      cout << res;
    else
      cout << "impossible";
    cout << endl;
  }
  return 0;
}