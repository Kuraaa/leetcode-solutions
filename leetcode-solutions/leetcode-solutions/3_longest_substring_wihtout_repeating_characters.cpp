#include "template.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0, i = 0;
        vector<int> lastIndex(256, -1);
        for (int j = 0; j < n; j++) {
            i = max(i, lastIndex[s[j]] + 1);
            res = max(res, j - i + 1);
            lastIndex[s[j]] = j;
        }
        return res;
    }

    int lengthOfLongestSubstring2(string s) {
        unordered_set<char> c;
        int l = 0, r = 0;
        int m = 0;
        while (l < s.length() && r < s.length()) {
            if (!c.count(s[r])) {
                c.insert(s[r++]);
                m = max((int)c.size(), m);
            }
            else {
                c.erase(s[l++]);
            }
        }
        return m;
    }
};