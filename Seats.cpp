// https://codeforces.com/problemset/problem/2188/B

#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int len;
    string seats;
    cin >> len >> seats;

    seats = '1' + seats + '1';

    long long result = 0;
    int segStart = -1;

    for (int i = 1; i <= len; ++i) {
        char cur   = seats[i];
        char left  = seats[i - 1];
        char right = seats[i + 1];

        if (cur == '1') {
            ++result;
            continue;
        }

        if (left == '1') segStart = i;
        if (right == '1') {
            int segEnd = i;
            int segLen = segEnd - segStart + 1;

            int edgeBonus = (segStart == 1) + (segEnd == len);
            result += (segLen + edgeBonus) / 3;
        }
    }

    cout << result << '\n';

}

int main() {
    int no_testcases;
    cin >> no_testcases;

    while (no_testcases--) solve();
}
