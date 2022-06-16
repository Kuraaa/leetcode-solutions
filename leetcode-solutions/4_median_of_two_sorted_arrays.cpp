#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArraysSlow(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> merged;
        vector<int> nums;
        for (int i = 0; i < max(nums1.size(), nums2.size()); i++) {
            if (i < nums1.size()) merged[nums1[i]]++;
            if (i < nums2.size()) merged[nums2[i]]++;
        }

        int cnt = 0;
        double med = 0.0;

        for (auto const& pair: merged) {
            for (int i = 0; i < pair.second; i++) {
                nums.push_back(pair.first);
            }
        }

        return nums.size() % 2 == 1 ? nums.at(nums.size() / 2) : (nums.at(nums.size() / 2) + nums.at(nums.size() / 2 - 1)) / 2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        vector<int> merged(size, 0);

        int i = 0, j = 0, k = 0;

        while (i < nums1.size() && j < nums2.size())
            merged[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        
        while (i < nums1.size())
            merged[k++] = nums1[i++];

        while (j < nums2.size())
            merged[k++] = nums2[j++];

        return size % 2 == 1 ? merged[size / 2] : (merged[size / 2] + merged[size / 2 - 1]) / 2.0;
    }
};
