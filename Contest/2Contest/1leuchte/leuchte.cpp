#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sockets(n, 0), bulbs(n, 0); //0 = unknown, 1 = prob broken, 2 = does not work, 3 = works
    while (true) {
        //ask
        stack<int> uB, pB, nB, wB;
        for (int i = 0; i < n; i++) {
            switch(bulbs[i]) {
                case 0: uB.push(i); break;
                case 1: pB.push(i); break;
                case 2: nB.push(i); break;
                case 3: wB.push(i); break;
            }
        }
        vector<int> bulbsOrder(n);
        for (int i = 0; i < n; i++) {
            if (sockets[i] == 3) {
                    if (!uB.empty()) {bulbsOrder[i] = uB.top(); uB.pop(); continue;}
                    if (!pB.empty()) {bulbsOrder[i] = pB.top(); pB.pop(); continue;}
                    if (!nB.empty()) {bulbsOrder[i] = nB.top(); nB.pop(); continue;}
                    if (!wB.empty()) {bulbsOrder[i] = wB.top(); wB.pop(); continue;}
            }
        }
        for (int i = 0; i < n; i++) {
            if (sockets[i] == 0) {
                    if (!wB.empty()) {bulbsOrder[i] = wB.top(); wB.pop(); continue;}
                    if (!uB.empty()) {bulbsOrder[i] = uB.top(); uB.pop(); continue;}
                    if (!pB.empty()) {bulbsOrder[i] = pB.top(); pB.pop(); continue;}
                    if (!nB.empty()) {bulbsOrder[i] = nB.top(); nB.pop(); continue;}
            }
        }
        for (int i = 0; i < n; i++) {
            if (sockets[i] == 1) {
                    if (!wB.empty()) {bulbsOrder[i] = wB.top(); wB.pop(); continue;}
                    if (!uB.empty()) {bulbsOrder[i] = uB.top(); uB.pop(); continue;}
                    if (!pB.empty()) {bulbsOrder[i] = pB.top(); pB.pop(); continue;}
                    if (!nB.empty()) {bulbsOrder[i] = nB.top(); nB.pop(); continue;}
            }
        }
        for (int i = 0; i < n; i++) {
            if (sockets[i] == 2) {
                    if (!uB.empty()) {bulbsOrder[i] = uB.top(); uB.pop(); continue;}
                    if (!pB.empty()) {bulbsOrder[i] = pB.top(); pB.pop(); continue;}
                    if (!nB.empty()) {bulbsOrder[i] = nB.top(); nB.pop(); continue;}
                    if (!wB.empty()) {bulbsOrder[i] = wB.top(); wB.pop(); continue;}
            }
        }
        cout << "Q";
        for (int i = 0; i < n; i++) {
            cout << " " << (bulbsOrder[i] + 1);
        }
        cout << endl;
        //read
        for (int i = 0; i < n; i++) {
            bool works;
            cin >> works;
            if (works) {
                sockets[i] = 3;
                bulbs[bulbsOrder[i]] = 3;
                continue;
            }
            if (sockets[i] < 2 && bulbs[bulbsOrder[i]] < 2) {
                sockets[i] = 1;
                bulbs[bulbsOrder[i]] = 1;
                continue;
            }
            if (sockets[i] < 3 && bulbs[bulbsOrder[i]] < 2) {
                bulbs[bulbsOrder[i]] = 2;
                continue;
            }
            if (bulbs[bulbsOrder[i]] < 3 && sockets[i] < 2) {
                sockets[i] = 1;
                continue;
            }
            if (sockets[i] == 3) {
                bulbs[bulbsOrder[i]] = 2;
                continue;
            }
            if (bulbs[bulbsOrder[i]] == 3) {
                sockets[i] = 2;
                continue;
            }
        }
    }
    return 0;
}