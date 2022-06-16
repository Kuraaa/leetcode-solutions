#include "template.h"

class Solution {
public:
    int start;
    int length;

    string longestPalindrom (string s) {
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i), expand(s, i, i + 1);
        }
        return s.substr(start, length);
    }

    void expand(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--, r++;
        }

        int len = r - l - 1;

        if (length < len) {
            start = l + 1;
            length = len;
        }
    }

    string longestPalindromeSlow(string s) {
        int size = s.length();
        while (size > 0) {
            int offset = 0;
            while (offset + size <= s.length()) {
                std::cout << size << " : " << offset << std::endl;
                string sub = s.substr(offset, size);
                if (isPalindrome(sub)) {
                    return sub;
                }
                offset++;
            }
            size--;
        }
        return "";
    }

    bool isPalindrome(string s) {
        if (s.length() < 1) {
            return true;
        }

        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }

        return true;
    }
};

