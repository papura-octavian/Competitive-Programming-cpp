// https://codeforces.com/problemset/problem/194/B

#include <iostream>

typedef long long int lli;
using namespace std;

int main() {
    int no_testcases;
    cin >> no_testcases;

    while (no_testcases--) {
        lli side;
        cin >> side;
        if ((side + 1) % 4 == 0) cout << side + 1 << endl;
        else if ((side + 1) % 2 == 0) cout << side * 2 + 1 << endl;
        else cout << side * 4 + 1 << endl;
    }
}