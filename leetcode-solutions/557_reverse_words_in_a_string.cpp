#include "template.h"

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j < s.length() + 1) {
            if (s[j] == ' ' || j == s.length()) {
                reverse(s, i, j - 1);
                i = j + 1;
            } 
            j++;
        }
        return s;
    }

    void reverse(string& s, int start, int end) {
        while (start < end) swap(s[start++], s[end--]);
    }
};