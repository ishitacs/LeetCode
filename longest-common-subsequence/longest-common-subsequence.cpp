class Solution {
public:
    int lcs(string s1, string s2, int i,int j)
    {if(i==s1.length() || j==s2.length()) return 0;
    if(s1[i]==s2[j]) return 1+lcs(s1,s2,i+1,j+1);
     int op1=lcs(s1,s2,i+1,j);
     int op2=lcs(s1,s2,i,j+1);
     return max(op1,op2);
    }
    int longestCommonSubsequence(string t1, string t2) {
       int n1=t1.length(),n2=t2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++) dp[i][0]=0;
        for(int i=0;i<=n2;i++) dp[0][i]=0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
             if(t1[i-1]==t2[j-1]) dp[i][j]=dp[i-1][j-1]+1; 
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            
            }
        } return dp[n1][n2];
        
    }
};
                 