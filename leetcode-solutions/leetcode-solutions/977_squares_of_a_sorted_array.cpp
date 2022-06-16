#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //Input: nums = [-7, -3, 2, 3, 11]
    //Output : [4, 9, 9, 49, 121]
    //Don't use insert here instead iterate from end
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        int i = 0, j = n - 1, k = n - 1;

        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                output[k--] = nums[i] * nums[i];
                i++;
            }
            else {
                output[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return output;
    }
};

