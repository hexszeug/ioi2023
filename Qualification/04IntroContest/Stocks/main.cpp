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
    if (priceNext < price) {
      b += s*price;
      s = 0;
    } else if (b / price > 0) {
      s = min(b / price, 100000ll);
      b -= s*price;
    }
    price = priceNext;
  }
  b += s*price;
  cout << b;
  return 0;
}