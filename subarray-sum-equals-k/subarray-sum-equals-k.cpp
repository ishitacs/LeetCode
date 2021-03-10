class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int cs=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            cs+=nums[i];
            if(cs==k) c++;
            if(m.find(cs-k)!=m.end()) c+=m[cs-k];
            m[cs]++;
            
        }
        return c;
    }
};
