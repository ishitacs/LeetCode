class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++)
        { int h=max(nums[n-1]-k,nums[i]+k);
         int l=min(nums[0]+k,nums[i+1]-k);
         ans=min(ans,h-l);
            
        }return ans;
    }
};