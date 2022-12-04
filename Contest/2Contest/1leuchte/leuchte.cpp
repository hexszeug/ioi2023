#include <bits/stdc++.h>

using namespace std;

int popFirstAvailable(list<int> &a, list<int> &b, list<int> &c) {
    if (!a.empty()) {int res = a.back(); a.pop_back(); return res;}
    if (!b.empty()) {int res = b.back(); b.pop_back(); return res;}
    int res = c.back(); c.pop_back(); return res;
}

int main() {
    short n;
    cin >> n;
    vector<signed char> sockets(n, 0), bulbs(n, 0); //0 = unknown, 1 = does not work, 2 = works
    vector<vector<bool>> worksNotWithMatrix(n, vector<bool>(n, false));
    bool unknownExist = true;
    while (unknownExist) {
        //ask
        vector<short> question(n, -1);
        list<short> unknownBulbs, notWorkingBulbs, workingBulbs;
        for (int i = 0; i < n; i++) {
            switch (bulbs[i]) {
                case 0: unknownBulbs.push_back(i); break;
                case 1: notWorkingBulbs.push_back(i); break;
                case 2: workingBulbs.push_back(i); break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (unknownBulbs.empty()) break;
            if (sockets[i] != 2) continue;
            question[i] = unknownBulbs.front();
            unknownBulbs.pop_front();
        }
        for (int i = 0; i < n; i++) {
            if (workingBulbs.empty()) break;
            if (sockets[i] != 0) continue;
            question[i] = workingBulbs.front();
            workingBulbs.pop_front();
        }
        workingBulbs.splice(workingBulbs.end(), unknownBulbs);
        workingBulbs.splice(workingBulbs.end(), notWorkingBulbs);
        for (int i = 0; i < n; i++) {
            if (question[i] != -1) continue;
            auto bulb = workingBulbs.begin();
            bool miss = true;
            while (bulb != workingBulbs.end()) {
                if (worksNotWithMatrix[i][*bulb]) {
                    bulb++;
                    continue;
                }
                question[i] = *bulb;
                bulb = workingBulbs.erase(bulb);
                miss = false;
                break;
            }
            if (miss) {
                question[i] = -2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (question[i] == -2) {
                question[i] = workingBulbs.front();
                workingBulbs.pop_front();
            }
        }
        cout << "Q";
        for (auto i : question) cout << " " << i+1;
        cout << endl;
        //read
        for (int i = 0; i < n; i++) {
            bool works;
            cin >> works;
            if (works) {
                if (sockets[i] == 0) {
                    for (int j = 0; j < n; j++) {
                        if (worksNotWithMatrix[i][j]) bulbs[j] = 1;
                    }
                }
                if (bulbs[question[i]] == 0) {
                    for (int j = 0; j < n; j++) {
                        if (worksNotWithMatrix[j][question[i]]) sockets[j] = 1;
                    }
                }
                sockets[i] = 2;
                bulbs[question[i]] = 2;
            } else {
                worksNotWithMatrix[i][question[i]] = true;
                if (sockets[i] == 2) bulbs[question[i]] = 1;
                if (bulbs[question[i]] == 2) sockets[i] = 1;
                bool bulbBroken = true, socketBroken = true;
                for (int j = 0; j < n; j++) {
                    if (!worksNotWithMatrix[j][question[i]]) {
                        bulbBroken = false;
                        break;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (!worksNotWithMatrix[i][j]) {
                        socketBroken = false;
                        break;
                    }
                }
                if (bulbBroken) bulbs[question[i]] = 1;
                if (socketBroken) sockets[i] = 1;
            }
        }
        //check for done
        unknownExist = false;
        for (int i = 0; i < n; i++) {
            if (bulbs[i] == 0) {
                unknownExist = true;
                break;
            }
            if (sockets[i] == 0) {
                unknownExist = true;
                break;
            }
        }
    }
    stack<short> workingBulbs, otherBulbs;
    for (int i = 0; i < n; i++) {
        if (bulbs[i] == 2) workingBulbs.push(i);
        else otherBulbs.push(i);
    }
    cout << "A";
    for (int i = 0; i < n; i++) {
        if (sockets[i] == 2) {
            if (!workingBulbs.empty()) {
                cout << " " << workingBulbs.top()+1;
                workingBulbs.pop();
                continue;
            }
        }
        cout << " " << otherBulbs.top()+1;
        otherBulbs.pop();
    }
    cout << endl;
    return 0;
}