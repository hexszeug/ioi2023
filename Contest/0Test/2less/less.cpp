#include <bits/stdc++.h>

#define MAX 1e9
#define MIN 0

using namespace std;

int main() {
    int top = MAX + 1, bot = MIN, mid;
    char c;
    while (bot + 1 != top) {
        mid = (top + bot) / 2;
        cout << "Q " << mid << endl;
        cin >> c;
        if (c == 'y') {
            top = mid;
        } else {
            bot = mid;
        }
    }
    cout << "A " << bot << endl;
    return 0;
}