#include <iostream>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int friends[n] = {0}, introverts[n] = {0}, numberOfIntroverts = 0, minFriends = n;
    for (int _ = 0; _ < m; _++) {
        int i, j;
        cin >> i >> j;
        friends[i]++; friends[j]++;
    }
    for (int i = 0; i < n; i++) {
        int f = friends[i];
        if (f < minFriends) {
            numberOfIntroverts = 0;
            minFriends = f;
        }
        if (f == minFriends) {
            introverts[numberOfIntroverts++] = i;
        }
    }
    for (int i = 0; i < numberOfIntroverts; i++) {
        cout << introverts[i] << " ";
    }
    return 0;
}
