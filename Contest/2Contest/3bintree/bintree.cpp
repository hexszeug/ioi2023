#include <bits/stdc++.h>

using namespace std;

int main() {
    // std::ios_base::sync_with_stdio(false);
    int i = 0;
    int in = 1;
    for (; in == 1; i++) {
        scanf("%1d", &in);
    }
    cout << "0 " << (i + (i % 2)) / 2 << endl;
    return 0;
}