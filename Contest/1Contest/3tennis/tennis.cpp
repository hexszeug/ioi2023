#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> us(N), op(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        us[i] = {a, i+1};
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        op[i] = {a, i+1};
    }
    sort(us.rbegin(), us.rend());
    sort(op.rbegin(), op.rend());
    stack<int> usb;
    stack<pair<int, int>> games;
    int usp = 0, opp = 0;
    for (; opp < N; opp++, usp++) {
        while (usp < N && us[usp].first > op[opp].first) {
            usb.push(us[usp].second);
            usp++;
        }
        if (usp >= N) break;
        games.push(make_pair(us[usp].second, op[opp].second));
    }
    cout << games.size() << endl;
    while (!games.empty()) {
        cout << games.top().first << " " << games.top().second << "\n";
        games.pop();
    }
    for (; opp < N; opp++) {
        cout << usb.top() << " " << op[opp].second << "\n";
        usb.pop();
    }
    return 0;
}