#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// https://leetcode.com/problems/first-missing-positive/description/

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> set_nums(begin(nums), end(nums));

        int start = 1;
        for(int it : set_nums) {
            if(it < 1) continue;
            if(start != it) return start;
            start++;
        }

        return start;
    }
};

int main () {

    vector<int> nums = {0,2,2,1,1};

    Solution obj;
    cout << obj.firstMissingPositive(nums);

    cout << "\n\n";

    return 0;
}