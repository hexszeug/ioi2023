#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool match(vector<int> s1, vector<int> s2) {
    for (int i = 0; i < 5; i++) {
        if (s1[i] == s2[i]) continue;
        return s1[i] < s2[i];
    }
    return 0;
}

void chessTournament() {
    int n;
    cin >> n;
    vector<vector<int> > s(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> s[i][j];
        }
        stable_sort(s[i].rbegin(), s[i].rend());
    }
    stable_sort(s.rbegin(), s.rend(), match);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cout << s[i][j] << " ";
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