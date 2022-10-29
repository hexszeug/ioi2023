#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9
#define ll long long

using namespace std;

int main() {
  int d, price, priceNext;
  ll b = 100, s = 0;
  cin >> d >> price;
  for (int i = 1; i < d; i++) {
    cin >> priceNext;
    b += s*price; s = 0; //sell stocks
    if (priceNext > price && b >= price) { //profitable and affordable
      s = min(b / price, 100000ll); b -= s*price; //buy as many as possible
    }
    price = priceNext;
  }
  b += s*price; //sell stocks
  cout << b;
  return 0;
}