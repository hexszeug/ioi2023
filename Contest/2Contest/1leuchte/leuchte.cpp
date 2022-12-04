#include <bits/stdc++.h>

using namespace std;

int main() {
    short n;
    cin >> n;
    vector<signed char> sockets(n, 0), bulbs(n, 0); //0 = unknown, 1 = broken, 2 = works
    vector<vector<bool>> worksNotWithMatrix(n, vector<bool>(n, false));
    vector<short> question(n, -1);
    list<short> unknownBulbs, brokenBulbs, workingBulbs;
    bool unknownExist = true;
    while (unknownExist) {
        //ask
        question.clear();
        question.resize(n);
        unknownBulbs.clear();
        brokenBulbs.clear();
        workingBulbs.clear();
        //prepare lists
        for (int i = 0; i < n; i++) {
            switch (bulbs[i]) {
                case 0: unknownBulbs.push_back(i); break;
                case 1: brokenBulbs.push_back(i); break;
                case 2: workingBulbs.push_back(i); break;
            }
        }
        //match working sockets with unknown bulbs
        for (int i = 0; i < n; i++) {
            if (unknownBulbs.empty()) break;
            if (sockets[i] != 2) continue;
            question[i] = unknownBulbs.front();
            unknownBulbs.pop_front();
        }
        //match unknown sockets with working bulbs
        for (int i = 0; i < n; i++) {
            if (workingBulbs.empty()) break;
            if (sockets[i] != 0) continue;
            question[i] = workingBulbs.front();
            workingBulbs.pop_front();
        }
        //match rest without asking the same thing twice
        workingBulbs.splice(workingBulbs.end(), unknownBulbs);
        workingBulbs.splice(workingBulbs.end(), brokenBulbs);
        for (int i = 0; i < n; i++) {
            if (question[i] != -1) continue;
            auto bulb = workingBulbs.begin();
            while (bulb != workingBulbs.end()) {
                if (worksNotWithMatrix[i][*bulb]) {
                    bulb++;
                    continue;
                }
                question[i] = *bulb;
                bulb = workingBulbs.erase(bulb);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (question[i] == -1) {
                question[i] = workingBulbs.front();
                workingBulbs.pop_front();
            }
        }
        cout << "Q";
        for (int i = 0; i < n; i++) cout << " " << question[i]+1;
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
    for (int i = 0; i < n; i++) {
        if (bulbs[i] == 2) workingBulbs.push_back(i);
        else brokenBulbs.push_back(i);
    }
    cout << "A";
    for (int i = 0; i < n; i++) {
        if (sockets[i] == 2) {
            if (!workingBulbs.empty()) {
                cout << " " << workingBulbs.front()+1;
                workingBulbs.pop_front();
                continue;
            }
        }
        cout << " " << brokenBulbs.front()+1;
        brokenBulbs.pop_front();
    }
    cout << endl;
    return 0;
}