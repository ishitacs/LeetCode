class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
           if(nums.size()==1) return 1;
        int n=nums.size();
        vector<int>ans(n+1,1);
        int m=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && ans[i]<ans[j]+1)
                {
                    ans[i]=ans[j]+1;
                }
            } m=max(m,ans[i]);
        } return m;
        
    }
};