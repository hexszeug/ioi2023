#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n), c(n);
    vector<vector<int> > adj(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            x--;
            adj[i].push_back(x);
        }
    }
    int p, next = 0, max = b[0], cats = 0;
    do {
        p = next;
        cats += c[p];
        for (auto x : adj[p]) {
            if (b[x] > max) {
                max = b[x];
                next = x;
            }
        }
    } while (next != p);
    cout << cats;
    return 0;
}