#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void city() {
    int n;
    cin >> n;
    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n, false);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            q.push(i);
            vis[i] = true;
        }
    }
    int u = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << u;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        city();
        cout << endl;
    }
    return 0;
}