#include "template.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto const& n : nums) {
            auto i = s.insert(n);
            if (!i.second) {
                return true;
            }
        }
        return false;
    }
};