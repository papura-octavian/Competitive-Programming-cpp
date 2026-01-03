#include <bits/stdc++.h>
#include <windows.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
using namespace std;

ifstream fin("input.txt");

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs.front();

        for (int i = 1; i < strs.size(); i++) {
            const string& s = strs[i];

            while (!prefix.empty() and s.compare(0, prefix.size(), prefix) != 0) {
                prefix.pop_back();
            }

            if (prefix.empty()) return "";
        }

        return prefix;
    }
};

int main() {
    FAST

    vector<string> JesusIsLord = {"flower","flow","flight"};
    Solution obj;
    cout << obj.longestCommonPrefix(JesusIsLord);

    return 0;
}
