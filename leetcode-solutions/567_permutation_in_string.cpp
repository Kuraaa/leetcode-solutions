#include "template.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool b;
        int k = s1.length(), l = 0, r = k - 1;
        int m1[26], m2[26];

        if (s1.length() > s2.length())
            return false;

        for (int i = 0; i < s1.length(); i++) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }

        while (r < s2.length()) {
            for (int i = l; i <= r; i++) {
                m2[s2[i] - 'a']++;
            }

            b = true;

            for (auto const& e : m1) {
                if (m2[e.first] != m1[e.first])
                    b = false;
            }

            if (b)
                return true;

            l++, r++;
        }

        return false;
    }
};

int main() {
    Solution sol;
    sol.checkInclusion("ab", "ba");
}