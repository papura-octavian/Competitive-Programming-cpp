#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
using namespace std;

ifstream fin("input.txt");

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> gate;
        gate_init(gate);

        string ans = "";
        int unit = 10;
        while (num) {
            int digit = num % unit;
            pair<int, string> temp = {digit, ""};

            while (temp.first) {
                pair<int, string> last = {0, ""};
                for (const auto& it : gate) {
                    if (temp.first >= it.first) last = it;
                    else break;
                }

                temp.first -= last.first;
                temp.second += last.second;
            }
            ans = temp.second + ans;
            num -= digit;
            unit *= 10;
        }

        return ans;
    }

    private: void gate_init(map<int, string>& gate) {
        gate[1] = "I";
        gate[4] = "IV";
        gate[5] = "V";
        gate[9] = "IX";
        gate[10] = "X";
        gate[40] = "XL";
        gate[50] = "L";
        gate[90] = "XC";
        gate[100] = "C";
        gate[400] = "CD";
        gate[500] = "D";
        gate[900] = "CM";
        gate[1000] = "M";
    }
};

int main() {
    FAST
    Solution obj;
    cout << obj.intToRoman(3749);

    return 0;
}
