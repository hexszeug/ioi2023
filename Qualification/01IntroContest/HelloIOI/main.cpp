#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long max = 0;
  long long in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    if (in > max)
      max = in;
  }
  cout << max * max * max;
  return 0;
}