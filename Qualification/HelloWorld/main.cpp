#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        string name; cin >> name;
        cout << "Case #" << i + 1 << ": Hello " << name << "!\n";
    }
}
