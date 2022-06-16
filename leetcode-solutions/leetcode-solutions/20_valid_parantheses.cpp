#include "template.h"
#include <stack>

class Solution {
public:
    unordered_map<char, char> m = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;

        stack<char> c;
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            if (curr == '}' || curr == ']' || curr == ')') {
                if (c.empty() || m[c.top()] != curr) return false;
                c.pop();
            }
            else {
                c.push(s[i]);
            }
        }
        return c.empty();
    }
};