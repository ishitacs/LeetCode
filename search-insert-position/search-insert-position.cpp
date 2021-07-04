class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        if(target<nums[l]) return 0;
        if(target>nums[h]) return nums.size();
        while(l<h)
        { int m=(l+h)/2;
          if(nums[m]<target)l++;
          
            else if(nums[m]>target) h--;
        else   return m;
        } return l;
    }
};