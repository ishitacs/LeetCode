class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        { int in=abs(nums[i]);
            if(in>=0 && in<nums.size() && nums[in]<0)
                return in;
         nums[in]= -nums[in];
        } return -1;
        
    }
};


    