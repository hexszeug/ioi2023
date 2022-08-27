#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string stones;
        cin >> stones;
        int w = 0, b = 0;
        for (int j = 0; j < stones.size(); j++) {
            if (stones[j] == 'W') w++;
            else b++;
        }
        cout << "Case #" << i + 1 << ": " << ((w == b) ? "possible" : "impossible") << endl;
    }

    return 0;
}
