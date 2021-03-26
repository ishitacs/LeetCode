class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0;
        int ms=INT_MIN;
        int mini=INT_MIN;
        bool n=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) n=false;
            if(nums[i]>mini) mini=nums[i];
            cs+=nums[i];
            if(cs<0) cs=0;
            ms=max(cs,ms);
        } if(n) return mini;
        return ms;
    }
};