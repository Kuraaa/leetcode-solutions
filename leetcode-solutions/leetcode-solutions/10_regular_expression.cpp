#include "template.h"

class Solution {
public:
    bool isMatch2(string s, string p) {
        return dfs(s, p, 0, 0);
    }

    bool dfs(string s, string p, int i, int j) {
        if (i >= s.length() && j >= p.length()) 
            return true;

        if (j >= p.length())
            return false;

        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.length() && p[j + 1] == '*') {
            return dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j));
        }
            
        if (match) {
            return dfs(s, p, i + 1, j + 1);
        }

        return false;
    }

	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= m; i++)
			dp[i][0] = false;
		for (int j = 1; j <= n; j++)
			dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
				}
				else
				{
					dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};