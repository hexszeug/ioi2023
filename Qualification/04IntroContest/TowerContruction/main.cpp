#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>

#define INF 1e9
#define tiii tuple<int, int, int>

using namespace std;

bool run() {
  int h, n;
  cin >> h >> n;
  vector<tiii> blocks(n*6);
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    blocks.push_back({x, y, z});
    blocks.push_back({x, z, y});
    blocks.push_back({y, x, z});
    blocks.push_back({z, x, y});
    blocks.push_back({y, z, x});
    blocks.push_back({z, y, x});
  }
  vector<list<tiii>> buf(n*6+1);
  vector<int> bufH(n*6+1, 0);
  for (int i = 1; i <= n*6; i++) {
    int newX, newY, newZ;
    tie(newX, newY, newZ) = blocks[i];
    int height = 0;
    bool inserted = false;
    for (auto block : buf[i-1]) {
      int x, y, z;
      tie(x, y, z) = block;
      if (!inserted) {
        if (newX >= x || newY >= y) {
          inserted = true;
          height += newZ;
          buf[i].push_back(blocks[i]);
        } else {
          height += z;
          buf[i].push_back(block);
        }
      }
      if (inserted) {
        if (x < newX && y < newY) {
          height += z;
          buf[i].push_back(block);
        }
      }
    }
    if (!inserted) {
      height += newZ;
      buf[i].push_back(blocks[i]);
    }
    bufH[i] = height;
    if (height < bufH[i-1]) {
      bufH[i] = bufH[i-1];
      buf[i] = buf[i-1];
    }
  }
  return bufH[n*6] >= h;
}

int main() {
  int t = 0; 
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << ((run()) ? "yes" : "no") << endl;
  }
  return 0;
}