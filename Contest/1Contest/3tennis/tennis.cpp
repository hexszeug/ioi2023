#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> eta(N), pwa(N), games;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        eta[i] = {a, i+1};
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pwa[i] = {a, i+1};
    }
    sort(eta.rbegin(), eta.rend());
    sort(pwa.rbegin(), pwa.rend());
    list<pair<int, int>> us, op;
    for (int i = 0; i < N; i++) {
        us.push_back(eta[i]);
        op.push_back(pwa[i]);
    }
    vector<int> usb, opb;
    for (auto opp : op) {
        bool flag = true;
        for (auto usp = us.begin(); usp != us.end();) {
            auto last = usp;
            usp++;
            if (last->first < opp.first) {
                games.emplace_back(last->second, opp.second);
                us.erase(last);
                flag = false;
                break;
            }
            usb.push_back(last->second);
            us.erase(last);
        }
        if (flag) {
            opb.push_back(opp.second);
        }
    }
    cout << games.size() << endl;
    for (auto game : games) {
        cout << game.first << " " << game.second << endl;
    }
    for (int i = 0; i < usb.size(); i++) {
        cout << usb[i] << " " << opb[i] << endl;
    }
    return 0;
}