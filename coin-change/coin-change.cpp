class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
dp[0]=0;        
        for(int i=1;i<dp.size();i++){
            for(int j:coins)
            {
                if(j<=i) dp[i]=min(dp[i],dp[i-j]+1);
            }
        }
     return dp[amount]==amount+1? -1 : dp[amount];}
};

 
 
 