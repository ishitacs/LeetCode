 class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> sums({{0, -1}});  
            for(int i = 0, sum = 0; i < nums.size(); ++i)
            {
                sum = k ? (sum+nums[i])%k : sum+nums[i];
                if(!sums.count(sum)) sums[sum] = i;
                else if(i-sums[sum] > 1) return true;
            }
            return false;
        }
};