// https://codeforces.com/problemset/problem/2126/B

#include <bits/stdc++.h>
#include <windows.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
using namespace std;

// ifstream fin("input.txt");

void solve() {
    int no_days, days_spent_hiking;
    cin >> no_days >> days_spent_hiking;

    int ans = 0, day, cnt = 0;
    bool rest_day = false;
    for (int i = 0; i < no_days; ++i) {
        cin >> day;

        // skip restday
        if (rest_day) {
            rest_day = false;
            continue;
        }

        // if it rains you cannot hike
        if (day) {
            cnt = 0;
            continue;
        }

        // if we are here it means no rain (CAN YOU REMEMBEEEEEEER, THE RAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIN?!)
        cnt++;

        if (cnt == days_spent_hiking) {
            ans++;
            cnt = 0;
            rest_day = true; // skip one day, cause need to rest after a trip make bath eat good
        }
    }

    cout << ans << endl;

}

int main() {
    FAST
    int no_testcases;
    cin >> no_testcases;
    while (no_testcases--) solve();

    return 0;
}