// https://codeforces.com/problemset/problem/2180/B
 
#include <bits/stdc++.h>
using namespace std;
 
// ifstream fin("input.txt");
 
void solve () {
    string ans;
    int no_str;
    cin >> no_str;
 
    while (no_str--) {
        string temp;
        cin >> temp;
 
        if (ans.empty()) ans = temp;
        else {
            string front = temp + ans;
            string back = ans + temp;
 
            ans = min(front, back);
        }
    }
 
    cout << ans << endl;
}
 
int main (){
    int no_testcases;
    cin >> no_testcases;
 
    while(no_testcases--) {
        solve();
    }
}