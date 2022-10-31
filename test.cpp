#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> test = {"Hello \n", "World!"};
    for (int i = 0; i < test.size(); i++) {
        cout << test[i];
    }
    cout << endl;
    string name;
    cin >> name;
    cout << "Hello " << name << "!\n";
    return 0;
}