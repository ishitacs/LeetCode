class Solution {
public:
    int minPairSum(vector<int>& nums) { int j=nums.size()-1; int ans=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<=j;i++)
    {
     ans=max(ans,(nums[i]+nums[j]));
        j--;
    }return ans;
    }
};