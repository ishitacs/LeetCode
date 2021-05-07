 int dp [2][100];
class Solution {
public:
    int superEggDrop(int k, int n) {
        if(k==1||n<=2)
            return n;
        
        int t, i, cur=1, old=0;
        for(i=0; i!=k; ++i){
            dp[0][i]=1;
        }
        
        for(t=1; t!=n; ++t) {
            dp[cur][0] = t+1;
            for(i=1; i!=k; ++i){
                dp[cur][i] = dp[old][i-1]+dp[old][i]+1;
            }
            if(dp[cur][k-1]>=n)
                return t+1;//t=T-1
            old=cur;
            cur^=1;
        }
        return -1;
    }
};