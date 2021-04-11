class Solution {
public:
     bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (size_t i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] && p[i-1] == '*';
        }
        
        for (size_t i = 1; i <= m; ++i) {
            vector<bool> tmp(n + 1, false);
            for (size_t j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    tmp[j] = tmp[j-1] || dp[j];
                }
                else {
                    tmp[j] = dp[j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
            dp = tmp;
        }

        return dp[n];
     }
};