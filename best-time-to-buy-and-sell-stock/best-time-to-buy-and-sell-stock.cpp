class Solution {
public:
    int maxProfit(vector<int>& prices) { int msf=INT_MAX; int p; int mp=INT_MIN;
        for(auto x:prices)
        {
            msf=min(msf,x);
            p=x-msf;
            mp=max(p,mp);
        } return mp;
        
    }
};