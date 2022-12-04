#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> prizes(N);
    for (int i = 0; i < N; i++) {
        cin >> prizes[i];
    }
    sort(prizes.rbegin(), prizes.rend());
    int f = 0, s = 1, t = 2; // first most expensive, second ..., third...
    long long price = 0;
    while (s < N) {
        int sd = prizes[s], td; //s discont , t discount
        if (t >= N) {
            td = 0;
        } else {
            td = prizes[t] * 2;
        }
        if (sd >= td) {
            price += 2*prizes[f] + sd;
            f = t; s = t+1; t = t+2;
        } else {
            price += 2*prizes[f] + 2*sd;
            f = t+1; s = t+2; t = t+3;
        }
    }
    if (f < N) price += 2*prizes[f];
    long long euro = (price / 2);
    int cent = (price % 2) * 50;
    cout << euro << " Euro " << cent << " Cent" << endl;
    return 0;
}