class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int k=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int m=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
                    
        if(k==m) return {-1,-1};
        
        return{k,m-1};
    }
};
 
            