 class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int sumn= (n*(n+1))/2;
        for(auto i:nums)
        {sum+=i;}
        return sumn-sum;
    }
};