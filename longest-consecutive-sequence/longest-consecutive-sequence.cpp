class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ms=0;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        for(int i=0;i<nums.size();i++) if(s.find(nums[i]-1)==s.end())
        {
            int j=nums[i];
            int len=0;
        while(s.find(j)!=s.end())
        {j++; len++; }        
            ms=max(len,ms);
     }
        return ms;
    }
};

       