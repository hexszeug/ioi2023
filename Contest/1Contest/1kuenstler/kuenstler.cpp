#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> adjList, int start) {
    queue<int> q;
    vector<int> color(adjList.size(), 0); //0: none / not vis, 1: blue, 2: red
    q.push(start);
    color[start] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adjList[v]) {
            if (color[u] != 0) {
                if (color[v] == color[u]) {
                    return -1; // not possible
                }
                continue;
            };
            color[u] = (color[v] == 1) ? 2 : 1;
            q.push(u);
        }
    }
    int blue = 0, red = 0;
    for (auto c : color) {
        if (c == 1) blue++;
        if (c == 2) red++;
    }
    return max(blue, red);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjList(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int blue = bfs(adjList, 0);
    if (blue == -1) {
        cout << "NEIN" << endl;
    } else {
        cout << "JA\n" << blue << endl;
    }
    return 0;
}