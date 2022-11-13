#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int, int> rotated(int x, int y, uint8_t dir) {
    int fx, fy, rx, ry;
    switch (dir) {
        case 0: fx = x, fy = y-1, rx = x-1, ry = y; break;
        case 1: fx = x+1, fy = y, rx = x, ry = y-1; break;
        case 2: fx = x, fy = y+1, rx = x+1, ry = y; break;
        case 3: fx = x-1, fy = y, rx = x, ry = y+1; break;
    }
    return {fx, fy, rx, ry};
};

vector<vector<int>> mordor;
int n, m;

bool getField(int x, int y) {
    if (x < 1 || x > m || y < 1 || y > n) return false;
    if (mordor[x-1][y-1] == -1) {
        cout << "1 " << x << " " << y << endl;
        cin >> mordor[x-1][y-1];
    }
    return mordor[x-1][y-1];
}

int main() {
    int startX, startY;
    cin >> m >> n >> startX >> startY;
    mordor.resize(m, vector<int>(n, -1));
    mordor[startX-1][startY-1] = 1;
    //part with coords [1, max]
    while (getField(startX, startY-1)) startY--;
    int x = startX, y = startY;
    uint8_t dir = 1; // 0 = -y (d)   1 = +x (r)   2 = +y (u)   3 = -x (l)
    do {
        int fx, fy, rx, ry;
        dir = (dir - 1) % 4;
        do {
            dir = (dir + 1) % 4;
            tie(fx, fy, rx, ry) = rotated(x, y, dir);
        } while (!getField(fx, fy));
        x = fx, y = fy;
        tie(fx, fy, rx, ry) = rotated(x, y, dir);
        if (getField(rx, ry)) {
            x = rx, y = ry;
            dir = (dir - 1) % 4;
        }
    } while (x != startX || y != startY);
    //part with coords [0, max)
    for (x = 1, y = 0; x < m; x++) {
        if (mordor[x][y] == -1) mordor[x][y] = 0;
    }
    for (x = 1, y = n-1; x < m; x++) {
        if (mordor[x][y] == -1) mordor[x][y] = 0;
    }
    for (x = 0, y = 1; y < n; y++) {
        if (mordor[x][y] == -1) mordor[x][y] = 0;
    }
    for (x = m-1, y = 1; y < n; y++) {
        if (mordor[x][y] == -1) mordor[x][y] = 0;
    }
    for (y = 1; y < n-1; y++) {
        for (x = 1; x < m-1; x++) {
            if (mordor[x][y] != -1) continue;
            if (mordor[x-1][y] == 0 || mordor[x][y-1] == 0 || mordor[x+1][y] == 0 || mordor[x][y+1] == 0) mordor[x][y] = 0;
            else mordor[x][y] = 1;
        }
    }
    cout << "2" << endl;
    for (y = 0; y < n; y++) {
        for (x = 0; x < m; x++) {
            cout << ((mordor[x][y] == 1) ? "1" : "0") << ((x < m-1) ? " " : "\n");
        }
    }
    return 0;
}