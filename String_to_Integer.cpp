// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <bits/stdc++.h>
#include <windows.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
using namespace std;

ifstream fin("input.txt");

class Solution {
public:
    int myAtoi(string s) {
        string ans; // empty or "-"
        bool sign_found = false, digit_found = false;
        for (const char& c : s) {
            // Whitespace
            if (c == ' ' and !sign_found and !digit_found) continue;

            // Signedness
            if (!sign_found and (c == '-' or c == '+')) {
                ans += c == '-' ? "-" : "";
                sign_found = true;
                continue;
            }

            // Conversion
            if (c == '0' and !digit_found) {
                sign_found = true;
                continue;
            }

            if (!isdigit(c)) break;


            if (sign_found and digit_found and !isdigit(c)) break;

            ans.push_back(c);
            digit_found = true;
            sign_found = true;
        }

        if (ans.empty() or ans == "-") return 0;

        return str_to_int32(ans);
    }

    int32_t str_to_int32(string s) {
        int i = 0, sign = 1;

        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long val = 0;
        for (; i < static_cast<int>(s.size()); i++) {
            int d = s[i] - '0';
            val = val * 10 + d;

            long long signedVal = sign * val;
            if (signedVal > INT_MAX) return INT_MAX;
            if (signedVal < INT_MIN) return INT_MIN;
        }

        return static_cast<int>(sign * val);
    }
};

int main() {
    FAST
    string s = "   +0 123";
    Solution obj;
    cout << obj.myAtoi(s);

    return 0;
}