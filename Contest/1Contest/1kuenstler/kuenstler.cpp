#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> adjList, int start) {
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
                    return vector<int>(); // not possible
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
    if (red > blue) {
        for (int i = 0; i < color.size(); i++) {
            if (color[i] == 0) continue;
            color[i] = (color[i] == 1) ? 2 : 1;
        }
    }
    return color;
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
    int vis = 0, blue = 0, start = 0;
    vector<int> color(N, 0);
    while (vis < N) {
        vector<int> newColor = bfs(adjList, start);
        if (newColor.empty()) {
            blue = -1;
            break;
        }
        vis = 0, blue = 0;
        for (int i = 0; i < N; i++) {
            if (newColor[i] != 0) {
                color[i] = newColor[i];
            }
            if (color[i] == 0) {
                start = i;
                continue;
            }
            if (color[i] == 1) blue++;
            vis++;
        }
    }
    if (blue == -1) {
        cout << "NEIN" << endl;
    } else {
        cout << "JA\n" << blue << endl;
    }
    return 0;
}