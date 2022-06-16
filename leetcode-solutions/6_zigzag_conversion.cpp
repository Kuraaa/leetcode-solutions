#include "template.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        int i = 0, r = 0;
        bool d = true;

        vector<string> rows = vector<string>(numRows);
        
        for (int i = 0; i < s.length(); i++) {
            rows[r] += s[i];

            if (r == numRows - 1) 
                d = false;
            else if (r == 0) 
                d = true;

            d ? r++ : r--;
        }
       
        string o = "";

        for (string const& str : rows) {
            o += str;
        }

        return o;
    }
};

