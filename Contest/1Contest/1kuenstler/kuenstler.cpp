#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;

int bfs(vector<vector<int>> &adjList, int start) {
    queue<int> q;
    vector<bool> color(adjList.size()); //false: blue, true: red
    q.push(start);
    color[start] = false;
    vis[start] = true;
    int blue = 1, red = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adjList[v]) {
            if (vis[u]) {
                if (color[v] == color[u]) {
                    return -1; // not possible
                }
                continue;
            }
            if (color[v]) {
                color[u] = false;
                blue++;
            } else {
                color[u] = true;
                red++;
            }
            vis[u] = true;
            q.push(u);
        }
    }
    return max(blue, red);
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vis.resize(N, false);
    vector<vector<int>> adjList(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int blue = 0;
    for (int start = 0; start < N; start++) {
        if (vis[start]) continue;
        int newBlue = bfs(adjList, start);
        if (newBlue == -1) {
            blue = -1;
            break;
        } else {
            blue += newBlue;
        }
    }
    if (blue == -1) {
        cout << "NEIN";
    } else {
        cout << "JA\n" << blue;
    }
    return 0;
}