#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums.at(m) > target)
                h = m - 1;
            else if (nums.at(m) < target)
                l = m + 1;
            else
                return m;
        }
        return l;
    }
};