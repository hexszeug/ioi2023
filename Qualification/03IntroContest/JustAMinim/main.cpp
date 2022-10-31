#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int l = 0;
  for (int i = 0; i < n; i++) {
    int note;
    cin >> note;
    if (note == 0) note = 32;
    else note = 16 / note;
    l += note;
  }
  cout << l / 16.0;
  return 0;
}