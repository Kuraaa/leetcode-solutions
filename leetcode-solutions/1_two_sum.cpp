#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complements = std::unordered_map<int, int>();
        for (int i = 0; i < nums.size(); i++) {
            if (complements.count(nums[i])) {
                return { complements.at(nums[i]), i };
            }
            complements.insert(std::pair<int, int>(target - nums[i], i));
        }
        return {};
    }
};