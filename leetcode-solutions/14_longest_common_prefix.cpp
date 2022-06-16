#include "template.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0, i = 0;
        string p = "";

        while (j <= 200) {
            char c = strs[0][j];

            for (int i = 0; i < strs.size(); i++) {
                if (j >= strs[i].size() || c != strs[i][j])
                    return p;
            }

            p += c;

            j++;
        }

        return p;
    }
};