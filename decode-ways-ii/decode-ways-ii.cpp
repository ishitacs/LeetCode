class Solution {
public:
    int numDecodings(string s)
{
	vector<long> dp(s.size() + 1);
	long mod = pow(10, 9) + 7;
	// base case 前两个字符组成的串单放用
	dp[0] = 1;
	if(s[0] == '*') dp[1] = 9;
	else if((s[0] != '0')) dp[1] = 1;

	for(int i = 2; i <= s.size(); i++)
	{
		if(dp[i - 1] == 0) return 0;
		int num;
		// 单放
		if(s[i - 1] != '*')
		{
			num = stoi(s.substr(i - 1, 1));
			if(num != 0)
				dp[i] += dp[i - 1];
		}
		else
			dp[i] += 9 * dp[i - 1];
		dp[i] %= mod;
		// 拼着放
		if(s[i - 1] != '*' && s[i - 2] != '*')
		{
			num = stoi(s.substr(i - 2, 2));
			if(num >= 10 && num <= 26)
				dp[i] += dp[i - 2];
		}
		else if(s[i - 1] == '*' && s[i - 2] != '*')
		{
			num = stoi(s.substr(i - 2, 1));
			if(num == 1)
				dp[i] += 9 * dp[i - 2];
			else if(num == 2)
				dp[i] += 6 * dp[i - 2];
		}
		else if(s[i - 1] != '*' && s[i - 2] == '*')
		{
			num = stoi(s.substr(i - 1, 1));
			if(num >= 7)
				dp[i] += dp[i - 2];
			else
				dp[i] += 2 * dp[i - 2];
		}
		else
			dp[i] += 15 * dp[i - 2];
		dp[i] %= mod;
	}

	return dp[s.size()];
}
};