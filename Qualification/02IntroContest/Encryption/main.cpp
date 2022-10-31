#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];
    sort(k.begin(), k.end());
    for (int i = 0; i < m; i++) {
        int y, j;
        cin >> y >> j;
        cout << y - k[j - 1] << endl;
    }
    return 0;
}