#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int middle = l + (h - l) / 2;
            if (nums.at(middle) == target) return middle;
            if (nums.at(middle) < target) {
                l = middle + 1;
            }
            else {
                h = middle - 1;
            }
        }
        
        return -1;
    }
};