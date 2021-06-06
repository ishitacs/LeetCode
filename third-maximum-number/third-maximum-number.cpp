class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> m;
        for(auto i:nums )
        {
            m.insert(i);
        }
       
        if(m.size() < 3){
            return *m.rbegin();
        }
        set<int>:: iterator it = m.begin();
        advance(it, m.size() - 3);
        return *it;
        
    }
};