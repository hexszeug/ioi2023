#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool match(vector<int> s1, vector<int> s2) {
    for (int i = 0; i < 5; i++) {
        if (s1[i] == s2[i]) continue;
        return s1[i] > s2[i];
    }
    return 0;
}

void chessTournament() {
    int n;
    cin >> n;
    vector<pair<int, vector<int> > > s(n, make_pair(0, vector<int>(5)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> s[i].second[j];
        }
        stable_sort(s[i].second.rbegin(), s[i].second.rend());
    }
    vector<vector<bool> > won(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            bool res = match(s[i].second, s[j].second);
            won[i][j] = res; won[j][i] = !res;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (won[i][j]) s[i].first++;
        }
    }
    stable_sort(s.rbegin(), s.rend());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cout << s[i].second[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ":\n";
        chessTournament();
    }
    return 0;
}