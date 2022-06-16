#include <iostream>
#include <vector>

using namespace std;
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/


class Solution {
public:
    void rotate3(vector<int>& nums, int k) {
        while (k > 0) {
            int t = nums[nums.size() - 1];
            for (int i = nums.size() - 1; i > 0; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = t;
            k--;
        }
    }

    void rotate2(vector<int>& nums, int k) {
        while (k > 0) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
            k--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> rotated(n);
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];
        }
        nums = rotated;
    }

    void rotateInPlace(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums, l, r);
            l++, r--;
        }
    }

    void swap(vector<int>& nums, int l, int r) {
        int n = nums[l];
        nums[l] = nums[r];
        nums[r] = n;
    }
};