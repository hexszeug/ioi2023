#include <bits/stdc++.h>

using namespace std;

bool run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> d[i];
    }
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    auto pa = a.begin(), pd = d.begin();
    while (pa != a.end())
    {
        if (k > 0) {
            pa++;
            k--;
            continue;
        }
        if (*pa < *pd) {
            return false;
        }
        pd++;
        k++;
    }
    return true;
}

int main() {
    cout << (run() ? "possible" : "impossible");
    return 0;
}